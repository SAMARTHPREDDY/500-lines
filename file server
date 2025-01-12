#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 1024

const char *html_content =
    "HTTP/1.1 200 OK\r\n"
    "Content-Type: text/html\r\n\r\n"
    "<!DOCTYPE html>"
    "<html lang='en'>"
    "<head><title>Simple C Server</title></head>"
    "<body style='font-family: Arial; text-align: center;'>"
    "<h1>Welcome to My Server</h1>"
    "<p>This is a multi-threaded HTTP server written in C.</p>"
    "</body></html>";

void *handle_client(void *socket_desc) {
    int client_socket = *(int *)socket_desc;
    char buffer[BUFFER_SIZE] = {0};

    // Read client request
    read(client_socket, buffer, BUFFER_SIZE);
    printf("Client Request:\n%s\n", buffer);

    // Send HTML content
    send(client_socket, html_content, strlen(html_content), 0);
    close(client_socket);

    free(socket_desc);
    return NULL;
}

int main() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int addrlen = sizeof(address);

    // Create socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Bind the socket to the address and port
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("Bind failed");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_fd, 10) < 0) {
        perror("Listen failed");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    printf("Server running on http://localhost:%d\n", PORT);

    // Accept and handle client connections
    while ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t *)&addrlen)) >= 0) {
        printf("New client connected\n");

        // Allocate memory for the socket descriptor to avoid data races
        int *socket_desc = malloc(sizeof(int));
        *socket_desc = new_socket;

        // Create a new thread for each client
        pthread_t thread_id;
        if (pthread_create(&thread_id, NULL, handle_client, (void *)socket_desc) < 0) {
            perror("Thread creation failed");
            free(socket_desc);
            close(new_socket);
        }

        pthread_detach(thread_id); // Detach the thread to free resources automatically
    }

    if (new_socket < 0) {
        perror("Accept failed");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    close(server_fd);
    return 0;
}
//
Creating a fully functional server in C within 250 lines is achievable and can include features like handling multiple clients and serving basic HTML content. Here's an example of a simple multi-threaded HTTP server in C that listens for connections, handles multiple clients, and serves a basic HTML page.

### Multi-threaded HTTP Server in C (Approx. 250 Lines)
```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 1024

const char *html_content =
    "HTTP/1.1 200 OK\r\n"
    "Content-Type: text/html\r\n\r\n"
    "<!DOCTYPE html>"
    "<html lang='en'>"
    "<head><title>Simple C Server</title></head>"
    "<body style='font-family: Arial; text-align: center;'>"
    "<h1>Welcome to My Server</h1>"
    "<p>This is a multi-threaded HTTP server written in C.</p>"
    "</body></html>";

void *handle_client(void *socket_desc) {
    int client_socket = *(int *)socket_desc;
    char buffer[BUFFER_SIZE] = {0};

    // Read client request
    read(client_socket, buffer, BUFFER_SIZE);
    printf("Client Request:\n%s\n", buffer);

    // Send HTML content
    send(client_socket, html_content, strlen(html_content), 0);
    close(client_socket);

    free(socket_desc);
    return NULL;
}

int main() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int addrlen = sizeof(address);

    // Create socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Bind the socket to the address and port
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("Bind failed");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_fd, 10) < 0) {
        perror("Listen failed");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    printf("Server running on http://localhost:%d\n", PORT);

    // Accept and handle client connections
    while ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t *)&addrlen)) >= 0) {
        printf("New client connected\n");

        // Allocate memory for the socket descriptor to avoid data races
        int *socket_desc = malloc(sizeof(int));
        *socket_desc = new_socket;

        // Create a new thread for each client
        pthread_t thread_id;
        if (pthread_create(&thread_id, NULL, handle_client, (void *)socket_desc) < 0) {
            perror("Thread creation failed");
            free(socket_desc);
            close(new_socket);
        }

        pthread_detach(thread_id); // Detach the thread to free resources automatically
    }

    if (new_socket < 0) {
        perror("Accept failed");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    close(server_fd);
    return 0;
}
```

### Features:
1. **Multi-threading**:
   - Each client is handled in a separate thread, allowing multiple clients to connect simultaneously.
2. **HTML Response**:
   - Serves a basic HTML page to the client.
3. **Dynamic Client Handling**:
   - Automatically allocates memory for each client socket descriptor to avoid race conditions.

### How It Works:
1. **Socket Creation**: The server creates a socket for communication.
2. **Binding**: It binds the socket to port 8080.
3. **Listening**: The server listens for incoming connections.
4. **Multi-threaded Client Handling**: Each client connection is handled by a separate thread using `pthread_create`.
5. **HTML Response**: The server responds with a predefined HTML page.

### Steps to Run:
1. Save the code to a file, e.g., `multi_threaded_server.c`.
2. Compile it using:
   ```bash
   gcc multi_threaded_server.c -o server -pthread
   ```
3. Run the server:
   ```bash
   ./server
   ```
4. Open your browser and visit `http://localhost:8080`.

### Notes:
- This code is designed for educational purposes. For production use, consider using established libraries (e.g., libuv) or frameworks.
- You can extend this server to handle different types of requests, serve files, or add logging.
//
