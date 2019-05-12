#include<netinet/in.h>
#include<netdb.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<unistd.h>
#include<stdio.h>
#include<string.h>

int main()
{
	char sendline[100], recvline[100];
	int sockfd, commfd, len, ch;
	struct sockaddr_in sa, cli;

	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	printf("Socket opened\n");

	bzero(&sa, sizeof(sa));
	sa.sin_family = AF_INET;
	sa.sin_port = htons(5600);
	connect(sockfd, (struct sockaddr *)&sa, sizeof(sa));
	printf("Connected succesfully...\n");

	while(1)
	{
		bzero(sendline, 100);
		bzero(recvline, 100);

		printf("Enter a message: ");
		fgets(sendline, 100, stdin);
		write(sockfd, sendline, strlen(sendline) + 1);

		read(sockfd, recvline, 100);
		printf("Messsage recieved: %s", recvline);
	}
	return 0;
}
