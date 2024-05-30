#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <winsock2.h>

#pragma comment(lib, "ws2_32.lib")

#define PORT 12345

int main() {
  WSADATA wsaData;
  SOCKET listenSocket, clientSocket;
  struct sockaddr_in serverAddr, clientAddr;
  int clientAddrSize;
  char buffer[256];

  // Initialize Winsock
  if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
    printf("WSAStartup failed. Error Code: %d\n", WSAGetLastError());
    return 1;
  }

  // Create socket
  listenSocket = socket(AF_INET, SOCK_STREAM, 0);
  if (listenSocket == INVALID_SOCKET) {
    printf("Socket creation failed. Error Code: %d\n", WSAGetLastError());
    WSACleanup();
    return 1;
  }

  // Prepare the sockaddr_in structure
  serverAddr.sin_family = AF_INET;
  serverAddr.sin_addr.s_addr = INADDR_ANY;
  serverAddr.sin_port = htons(PORT);

  // Bind
  if (bind(listenSocket, (struct sockaddr *)&serverAddr, sizeof(serverAddr)) ==
      SOCKET_ERROR) {
    printf("Bind failed. Error Code: %d\n", WSAGetLastError());
    closesocket(listenSocket);
    WSACleanup();
    return 1;
  }

  // Listen
  listen(listenSocket, 5);
  printf("Server listening on port %d...\n", PORT);

  // Accept and incoming connection
  clientAddrSize = sizeof(clientAddr);
  clientSocket =
      accept(listenSocket, (struct sockaddr *)&clientAddr, &clientAddrSize);
  if (clientSocket == INVALID_SOCKET) {
    printf("Accept failed. Error Code: %d\n", WSAGetLastError());
    closesocket(listenSocket);
    WSACleanup();
    return 1;
  }

  // Receive data from client
  memset(buffer, 0, sizeof(buffer));
  int recvSize = recv(clientSocket, buffer, sizeof(buffer), 0);
  if (recvSize == SOCKET_ERROR) {
    printf("Recv failed. Error Code: %d\n", WSAGetLastError());
  } else {
    printf("Message from client: %s\n", buffer);

    // Send acknowledgment to client
    const char *ack = "Message received";
    send(clientSocket, ack, strlen(ack), 0);
  }

  // Cleanup
  closesocket(clientSocket);
  closesocket(listenSocket);
  WSACleanup();
  return 0;
}
