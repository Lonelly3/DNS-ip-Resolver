#include <stdio.h>
#include <string.h>
#include <winsock2.h>
#include <ws2tcpip.h>
void show_menu()
{
    printf("=== IP RESOLVER ===\n"
           "=== By Long1zz ===\n");
    printf("1.Resolver\n"
           "99.Exit\n");
}
char domain[100];
void input_domain(char domain[], int size)
{
    printf("Enter Domain: \n");
    fgets(domain, size, stdin);

    domain[strcspn(domain, "\n")] = '\0';
}
void resolve_domain(char domain[])
{
    struct addrinfo hints;
    struct addrinfo *result = NULL;

    ZeroMemory(&hints, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    int res = getaddrinfo(domain, NULL, &hints, &result);
    if (res != 0)
    {
        printf("Error: %d\n", WSAGetLastError());
        return;
    }
    for (struct addrinfo *p = result; p != NULL; p = p->ai_next)
    {
        if (p->ai_family == AF_INET)
        {
            struct sockaddr_in *ipv4 = (struct sockaddr_in *)p->ai_addr;
            void *addr = &(ipv4->sin_addr);
            char ipstr[INET6_ADDRSTRLEN];
            inet_ntop(p->ai_family, addr, ipstr, sizeof(ipstr));
            printf("%s\n", ipstr);
        }
    }
    freeaddrinfo(result);
}
void handle_choice()
{
    int choice;
    printf("Choice: ");
    if (scanf("%d", &choice) != 1)
    {
        printf("Error!");
        return;
    }
    while (getchar() != '\n')
        ;
    switch (choice)
    {
    case 1:
        input_domain(domain, sizeof(domain));
        resolve_domain(domain);
        break;
    case 99:
        printf("bye!\n");
        break;
    default:
        printf("Error!");
        break;
    }
}
int init_winsock()
{
    WSADATA WSAData;

    if (WSAStartup(MAKEWORD(2, 2), &WSAData) != 0)
    {
        printf("Failed!");
        return 1;
    }
    else
    {
        return 0;
    }
}
int cleanup_winsock()
{
    WSACleanup();
}

int main()
{
    init_winsock();

    show_menu();
    handle_choice();

    cleanup_winsock();

    printf("Press Enter to exit...");
    getchar();
    return 0;
}