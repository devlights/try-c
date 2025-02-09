#include <arpa/inet.h>  /* sockaddr_in, inet_addr() */
#include <stdio.h>      /* printf(), fprintf(), perror() */
#include <stdlib.h>     /* atoi(), exit() */
#include <string.h>     /* memset() */
#include <sys/socket.h> /* socket(), connect(), send(), recv() */
#include <unistd.h>     /* close() */

#define RCVBUFSIZE 32

void die_with_error(const char *errorMessage) {
    perror(errorMessage);
    exit(1);
}

int main(int argc, char *argv[]) {
    if ((argc < 3) || (argc > 4)) {
        fprintf(stderr, "Usage: %s <Server IP> <Echo Word> [<Echo Port>]\n", argv[0]);
        exit(1);
    }

    char *srv_ip      = argv[1];
    char *echo_string = argv[2];

    unsigned short echo_srv_port = 7;
    if (argc == 4) {
        echo_srv_port = atoi(argv[3]);
    }

    //
    // ソケット生成
    //
    int sock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (sock < 0) {
        die_with_error("socket() failed");
    }

    //
    // ソケットアドレスを設定
    //
    struct sockaddr_in echo_srv_addr;
    memset(&echo_srv_addr, 0, sizeof(echo_srv_addr));
    echo_srv_addr.sin_family      = AF_INET;
    echo_srv_addr.sin_addr.s_addr = inet_addr(srv_ip);
    echo_srv_addr.sin_port        = htons(echo_srv_port);

    //
    // 接続
    //
    int connRet = connect(sock, (struct sockaddr *)&echo_srv_addr, sizeof(echo_srv_addr));
    if (connRet < 0) {
        die_with_error("connect() failed");
    }

    //
    // 送信
    //
    int echo_len = strlen(echo_string);
    int send_ret = send(sock, echo_string, echo_len, 0);
    if (send_ret != echo_len) {
        die_with_error("send() sent a different number of bytes than expected");
    }

    //
    // 受信
    //
    int  total_bytes_recv = 0;
    char buf[RCVBUFSIZE];
    while (total_bytes_recv < echo_len) {
        int bytes_recv = recv(sock, buf, RCVBUFSIZE - 1, 0);
        if (bytes_recv == 0) {
            break;
        }

        if (bytes_recv < 0) {
            die_with_error("recv() failed");
        }

        total_bytes_recv += bytes_recv;
        buf[bytes_recv] = '\0';
        printf(buf);
    }

    printf("\n");

    //
    // 切断
    //
    int closeRet = close(sock);
    if (closeRet < 0) {
        die_with_error("close() failed");
    }

    return EXIT_SUCCESS;
}
