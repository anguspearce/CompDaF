#!/usr/bin/env python3
import dlg
from dlg.manager.client import NodeManagerClient
import logging
import json
import traceback

class GraphLoader():
    def __init__(self, sessionId, graphSpec, ramSplit) -> None:
        self.port = 8001
        self.graphSpec = graphSpec
        self.graph = None
        self.firstDrop = None
        self.sessionId = str(sessionId)
        self.manager = NodeManagerClient(port = self.port)
        self.ramSplit = ramSplit
    
    def createSession(self, file):
        # Read in the JSON Graph File definition
        try:
            print("Opening graph file.")
            with open(self.graphSpec, 'r') as f:
                self.graph = json.load(f)
        except:
            print("Failed to open graph file.")
            return 0
        
        # Create session 
        try:
            self.manager.createSession(self.sessionId)
            print("Created session:", self.sessionId)
        except dlg.exceptions.SessionAlreadyExistsException:
            # If session already exists, destroy session and recreate
            self.manager.destroySession(self.sessionId)
            self.manager.createSession(self.sessionId)
            print("Recreated session:", self.sessionId)
        except:
            return 0
        
        # Find the first Drop in the graph 
        for drop in self.graph:
            if drop.get('nm') == 'SplitStatsApp':
                self.firstDrop = drop.get('oid')
                drop["fileName"] = file # Changing the fileName parameter to the clients input
                drop["ramSplit"] = self.ramSplit # Changing the number of splits inside each node based on terminal input
                break
        # Ensure that the Drop was found
        if self.firstDrop == None:
            print("Drop not found.")
            return 0
        
        # Append graph
        try:
            self.manager.addGraphSpec(self.sessionId, self.graph)
            print("Successfully appended graph to the Node Manager.")
        except Exception:
            print(traceback.format_exc())
            print("Failed to append graph, it is either corrupted or not a Physical Graph.")
            return 0
        
        # Deploy session using sessionId with a list of Drop ID's that will be executed first
        try:
            self.manager.deploySession(self.sessionId, [self.firstDrop]) 
            print("Successfully deployed session", self.sessionId)
        except:
            print("Failed to deploy session", self.sessionId)
            return 0
        
        return 1
