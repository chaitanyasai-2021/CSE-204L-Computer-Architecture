#AP21110010253
import socket
def start_server():
    host = '127.0.0.1'
    port = 12345

    server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    server_socket.bind((host, port))
    server_socket.listen(5)

    print(f"Server listening on {host}:{port}")

    while True:
        client_socket, addr = server_socket.accept()
        print(f"Connection from {addr}")

        data = client_socket.recv(1024).decode('utf-8')
        print(f"Received data: {data}")

        client_socket.sendall(data.encode('utf-8'))
        print("Data sent back to client")

        client_socket.close()

if __name__ == "__main__":
    start_server()
