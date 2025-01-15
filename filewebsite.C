#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080
#define BUFFER_SIZE 1024

const char *html_content =
    "HTTP/1.1 200 OK\r\n"
    "Content-Type: text/html\r\n\r\n"
    "<!DOCTYPE html>"
    "<html lang='en'>"
    "<head><title>My C Website</title></head>"
    "<body style='font-family: Arial; text-align: center;'>"
    "<h1>Welcome to My Website</h1>"
    "<p>This is a simple webpage served by a C program.</p>"
    "</body></html>";

int main() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    char buffer[BUFFER_SIZE] = {0};

    // Create socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket failed");
        exit(EXIT_FAILURE);
    }

    // Bind the socket to the address
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("Bind failed");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    // Listen for connections
    if (listen(server_fd, 3) < 0) {
        perror("Listen failed");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    printf("Server running on http://localhost:%d\n", PORT);

    // Accept and handle client connections
    while ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t *)&addrlen)) >= 0) {
        read(new_socket, buffer, BUFFER_SIZE); // Read client request
        send(new_socket, html_content, strlen(html_content), 0); // Send HTML content
        close(new_socket); // Close the connection
    }

    perror("Accept failed");
    close(server_fd);
    return 0;
}
//
Creating a website directly in C programming isn't typical because C is not a web development language. However, using C, you can create a basic HTTP server that serves a webpage. Below is an example of a simple HTTP server in C that serves a basic webpage when accessed through a browser.

### Simple HTTP Server in C (Under 100 Lines)
```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080
#define BUFFER_SIZE 1024

const char *html_content =
    "HTTP/1.1 200 OK\r\n"
    "Content-Type: text/html\r\n\r\n"
    "<!DOCTYPE html>"
    "<html lang='en'>"
    "<head><title>My C Website</title></head>"
    "<body style='font-family: Arial; text-align: center;'>"
    "<h1>Welcome to My Website</h1>"
    "<p>This is a simple webpage served by a C program.</p>"
    "</body></html>";

int main() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    char buffer[BUFFER_SIZE] = {0};

    // Create socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket failed");
        exit(EXIT_FAILURE);
    }

    // Bind the socket to the address
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("Bind failed");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    // Listen for connections
    if (listen(server_fd, 3) < 0) {
        perror("Listen failed");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    printf("Server running on http://localhost:%d\n", PORT);

    // Accept and handle client connections
    while ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t *)&addrlen)) >= 0) {
        read(new_socket, buffer, BUFFER_SIZE); // Read client request
        send(new_socket, html_content, strlen(html_content), 0); // Send HTML content
        close(new_socket); // Close the connection
    }

    perror("Accept failed");
    close(server_fd);
    return 0;
}
```

### How It Works:
1. **Socket Creation**: The program creates a socket to listen for incoming HTTP requests.
2. **Binding**: It binds the socket to a specific port (8080 in this case).
3. **Listening**: The program listens for incoming connections.
4. **Responding**: When a client (browser) connects, it sends a hardcoded HTML response.

### Steps to Run:
1. Save the code as `web_server.c`.
2. Compile it using:
   ```bash
   gcc web_server.c -o web_server
   ```
3. Run the server:
   ```bash
   ./web_server
   ```
4. Open your browser and go to `http://localhost:8080`.

### Output:
You’ll see a webpage with the following content:
- A title: "My C Website"
- A heading: "Welcome to My Website"
- A paragraph: "This is a simple webpage served by a C program."

This is a basic demonstration, and real-world web servers typically use more robust tools and languages like Python, Node.js, or PHP.
//
