#!/usr/bin/env python3
import signal
import sys
from multiprocessing import Process
from websocket import create_connection

ws = create_connection("ws://localhost:8080/poc")


def signal_handler(sig, frame):
    print("ctrl+c received, closing socket")
    ws.close()
    sys.exit(0)


signal.signal(signal.SIGINT, signal_handler)


def receiver():
    while True:
        result = ws.recv()
        print(f"received {result}")


p_recv = Process(target=receiver, args=())
p_recv.start()
while True:
    msg = input("send: ")
    ws.send(msg)
    print(f"sent {msg}")
