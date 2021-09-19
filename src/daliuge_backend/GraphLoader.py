#!/usr/bin/env python3
import dlg
from dlg.manager.client import NodeManagerClient
import logging
import json

class GraphLoader():
    def __init__(self, sessionId, graphSpec) -> None:
        self.port = 8001
        self.graphSpec = graphSpec
        self.graph = None
        self.firstDrop = None
        self.sessionId = sessionId
        self.manager = NodeManagerClient(port = self.port)
    
    def createSession(self):
        # Read in the JSON Graph File
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
            
        # Append graph
        try:
            self.manager.addGraphSpec(self.sessionId, self.graphSpec)
            print("Successfully appended graph to the Node Manager.")
        except:
            print("Failed to append graph, it is either corrupted or not a Physical Graph.")
            return 0
        
        # Find the first Drop in the graph 
        for l in self.graphSpec:
            if l.get('rank') == [0]:
                if l.get('iid') == '0':
                    self.firstDrop = l.get('oid')
                    break
        # Deploy session using sessionId and a list of Drop ID's that will be executed first
        try:
            self.manager.deploySession(self.sessionId, [self.firstDrop]) 
            print("Successfully deployed session ", self.sessionId)
        except:
            print("Failed to deploy session", self.sessionId)
