#include <stdio.h>       /* printf(), fprintf(), perror() */
#include <sys/socket.h>  /* socket(), bind(), connect() */
#include <arpa/inet.h>   /* sockaddr_in, inet_ntoa() */
#include <stdlib.h>      /* atoi(), exit() */
#include <string.h>      /* memset() */
#include <unistd.h>      /* close() */

#define MAXPENDING (5)
#define RCVBUFSIZE (32)

void die_with_error(const char *error_message) {
    perror(error_message);
    exit(1);
}

void handle_tcp_client(int client_sock) {
    char buf[RCVBUFSIZE];
    int bytes_recv = recv(client_sock, buf, RCVBUFSIZE, 0);
    if (bytes_recv ==  0) {
        goto go_to_close;
    }

    if (bytes_recv < 0) {
        die_with_error("client recv() failed");
    }

    while (bytes_recv > 0) {
        int send_ret = send(client_sock, buf, bytes_recv, 0);
        if (send_ret < 0) {
            die_with_error("client send() failed");
        }

        bytes_recv = recv(client_sock, buf, RCVBUFSIZE, 0);
        if (bytes_recv < 0) {
            die_with_error("client recv() failed-2");
        }
    }

go_to_close:
    int close_ret = close(client_sock);
    if (close_ret < 0) {
        die_with_error("client close() failed");
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <Server Port>\n", argv[0]);
        exit(1);
    }

    //
    // サーバソケット生成
    //
    int port = atoi(argv[1]);
    int sock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (sock < 0) {
        die_with_error("socket() failed");
    }

    //
    // ソケットアドレスを設定
    //
    struct sockaddr_in srv_addr;
    memset(&srv_addr, 0, sizeof(srv_addr));
    srv_addr.sin_family = AF_INET;
    srv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    srv_addr.sin_port = htons(port);

    //
    // バインド
    //
    int bind_ret = bind(sock, (struct sockaddr *)&srv_addr, sizeof(srv_addr));
    if (bind_ret < 0) {
        die_with_error("bind() failed");
    }

    //
    // リッスン
    //
    int listen_ret = listen(sock, MAXPENDING);
    if (listen_ret < 0) {
        die_with_error("listen() failed");
    }

    //
    // クライアントからの要求を処理
    //
    for (;;) {
        struct sockaddr_in client_addr;
        unsigned int client_addr_len = sizeof(client_addr);

        int client_sock = accept(sock, (struct sockaddr *)&client_addr, &client_addr_len);
        if (client_sock < 0) {
            die_with_error("accept() failed");
        }

        printf("Handling client %s\n", inet_ntoa(client_addr.sin_addr));
        handle_tcp_client(client_sock);
    }

    return EXIT_SUCCESS;
}
