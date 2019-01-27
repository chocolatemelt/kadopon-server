#!/usr/bin/env python2
from websocket import create_connection

ws = create_connection("ws://localhost:8080/poc")
print "Sending 'YO KADOPON YOU THERE??'"

ws.send("YO KADOPON YOU THERE??")
print "Sent"
print "Receiving..."
result = ws.recv()

print "Received: '%s'".format(result)
ws.close()
