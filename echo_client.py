import socket

# Configuration
HOST = "148.101.247.29"  # Change to the server's IP if needed
PORT = 1700
MESSAGE = "Hello, Echo Server!"

def udp_client():
    """UDP client that sends a message and waits for the echoed response."""
    try:
        with socket.socket(socket.AF_INET, socket.SOCK_DGRAM) as udp_sock:
            udp_sock.sendto(MESSAGE.encode(), (HOST, PORT))
            response, _ = udp_sock.recvfrom(1024)
            print(f"UDP Echo: {response.decode()}")
    except Exception as e:
        print(f"UDP Error: {e}")

if __name__ == "__main__":

    print("\nSending UDP message...")
    udp_client()
