#!/usr/bin/env python3
import dlg
from dlg.manager.client import NodeManagerClient
import logging
import json

class GraphLoader():
    def __init__(self, sessionId) -> None:
        self.port = 8001
        self.graphSpec = "daliuge.graph"
        self.firstDrop = None
        self.sessionId = sessionId
        self.manager = NodeManagerClient(port = self.port)
    
    def createSession(self):
        # Read in the JSON Graph File
        self.graphSpec = self.read_json(self.graphSpec)

        # Create session 
        try:
            self.manager.createSession(self.sessionId)
            print("Created session:", self.sessionId)
        except dlg.exceptions.SessionAlreadyExistsException:
            # If session already exists, destroy session and recreate
            self.manager.destroySession(self.sessionId)
            self.manager.createSession(self.sessionId)
            print("Recreated session:", self.sessionId)
            
        # Append graph
        try:
            self.manager.addGraphSpec(self.sessionId, self.graphSpec)
            print("Successfully appended graph to the Node Manager.")
        except:
            print("Failed to append graph, it is either corrupted or not a Physical Graph.")
        
        # Find the first Drop in the graph 
        for l in self.graphSpec:
            if l.get('rank') == [0]:
                if l.get('iid') == '0':
                    self.firstDrop = l.get('oid')
                    break
        # Deploy session, execute first Drop to cascade into the rest
        try:
            self.manager.deploySession(self.sessionId, [self.firstDrop])
            print("Successfully deployed session ", self.sessionId)
        except:
            print("Failed to deploy session", self.sessionId)
    
    def read_json(self, file):
        try:
            print("Opening graph file.")
            with open(file, 'r') as f:
                return json.load(f)
        except:
            print("Failed to open graph file.")
