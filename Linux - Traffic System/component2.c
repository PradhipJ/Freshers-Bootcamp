#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/ipc.h>
#include<sys/msg.h>

typedef struct {
	long int mtype;
	char mtext[20];
} msgbuf;

int main()
{
	key_t mq_key=0xaabb1122;
	int mq_id;
	msgbuf msg;
	mq_id=msgget(mq_key, 0);
	printf("Message queue id = %d\n", mq_id);
	while(1){
		printf("Enter button to be pushed = ");
		fgets(msg.mtext, 20, stdin);
		msg.mtext[strcspn(msg.mtext, "\n")] = 0;
		printf("Enter message type = ");
		scanf("%ld", &msg.mtype);
		getchar();
		msgsnd(mq_id, &msg, sizeof(msg), 0);
		printf("Message sent\n");
	}
}