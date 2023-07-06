import os
import time
import subprocess

eventPipe = os.open("/tmp/event_pipe", os.O_WRONLY)
statePipe = os.open("/tmp/state_pipe", os.O_RDONLY)

# Function to send an event to the C++ program
def send_event(event):
    print("Sending Event:", event)
    os.write(eventPipe, event.encode())

# Function to read the current state from the C++ program
def read_state():
    state = os.read(statePipe, 256).decode().strip()
    return state

def close_pipes():
    os.close(eventPipe)
    os.close(statePipe)

# Example usage
send_event("power on")
time.sleep(1)  # Give the C++ program time to process the event and update the state pipe
current_state = read_state()
print("Current state:", current_state)
send_event("volume up")

   
while True:
    pass
