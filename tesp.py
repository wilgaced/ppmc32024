import socket

# Define the IP and port
UDP_IP = "0.0.0.0"  # Listen on all available interfaces
UDP_PORT = 1700  # UDP port to listen on

# Create a UDP socket
sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
sock.bind((UDP_IP, UDP_PORT))

print(f"Listening on UDP port {UDP_PORT}...")

while True:
    data, addr = sock.recvfrom(1024)  # Buffer size is 1024 bytes
    print(f"Received data from {addr}: {data.hex()}")  # Print in hex format
