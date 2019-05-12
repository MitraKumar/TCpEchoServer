#include<netinet/in.h>
#include<netdb.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<unistd.h>
#include<stdio.h>
#include<string.h>

int main()
{
	char str[100];
	int sockfd, commfd, len, ch;
	struct sockaddr_in sa, cli;

	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	printf("Socket id is: %d\n", sockfd);

	bzero(&sa, sizeof(sa));
	sa.sin_port = htons(5600);
	sa.sin_addr.s_addr = htonl(0);

	bind(sockfd, (struct sockaddr *)&sa, sizeof(sa));
	listen(sockfd, 10);

	printf("Socket started listening....\n");

	while(1)
	{
		bzero(str, 100);

		len = sizeof(ch);
		commfd = accept(sockfd, (struct sockaddr *)&cli, &len);

		read(commfd, str, 100);
		printf("Echoing back: %s\n", str);
		write(commfd, str, strlen(str) + 1);
	}
	return 0;
}
