#AP21110010253
import socket

def start_client():
    host = '127.0.0.1'
    port = 12345

    client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    client_socket.connect((host, port))

    message = input("Enter message to send to server: ")

    client_socket.sendall(message.encode('utf-8'))

    response = client_socket.recv(1024).decode('utf-8')
    print(f"Received response from server: {response}")

    client_socket.close()

if __name__ == "__main__":
    start_client()
