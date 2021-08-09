#!/usr/bin/env python3

import asyncio
import websockets
import os

from protobufs.python import defs_pb2
from protobufs.python import enums_pb2
from protobufs.python import register_viewer_pb2
from protobufs.python import file_info_pb2

#util
from util.message_header import *
from util.message_provider import *

#Fits file reader
from astropy.io import fits

class DaliugeServer:
    
    def __init__(self):
        start_server = websockets.serve(self._host, "localhost", 9001, ping_interval = None)
        asyncio.get_event_loop().run_until_complete(start_server)
        asyncio.get_event_loop().run_forever()


    async def _host(self, websocket, port):
        message = await websocket.recv()
        messageType, messageId, messagePayload = strip_message_header(message)
        print(f"< {messageId}")

        # Using received session ID to get register viewer acknowledge 
        ack, ack_type = construct_register_viewer_ack(int(messageId))
        if(ack.success == True):

            print("Successfully connected with session:", messageId)
        else:
            print("Failed to connect with session:", messageId)

        await websocket.send(add_message_header(ack,ack_type))

        async for message in websocket:
            await self.consumer(websocket, message)

    async def consumer(self, websocket, message):
        
        try:
            messageType, messageId, messagePayload = strip_message_header(message)
            handler = self.MESSAGE_TYPE_CODE_TO_EVENT_HANDLER.get(messageType)
            await handler(self, websocket, messagePayload)
        except:
            print("Unable to process message from client.")

        await websocket.send("hi")
        print("sent hi")
        
    async def __on_file_info_request(self, ws, msg):
        """Handle the FILE_INFO_REQUEST message.

        :param ws: the client websocket object
        :param msg: the client message recieved

        """
        f = './src/backend/'+msg.directory+'/'+msg.file
        fileInfo=[]
        try:
            #fits_image_filename = fits.util.get_testdata_filepath('test0.fits')
            #hdul = fits.open(f)
            with fits.open(f, memmap = True) as hdu:
                print("in")
                fileInfo.append(hdu.filename())
                fileInfo.append(os.path.getsize(f))

                hdu.info()
                date = (hdu[0].header['DATE'])
                fileInfo.append(str(date))
                
        except IOError as e:
            print( e)
        ack, ack_type = construct_file_info_response(fileInfo)
        await ws.send(add_message_header(ack, ack_type))
        
    MESSAGE_TYPE_CODE_TO_EVENT_HANDLER = {
        
        enums_pb2.EventType.FILE_INFO_REQUEST:
            __on_file_info_request,
        
    }
