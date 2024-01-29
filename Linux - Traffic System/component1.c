#include<stdio.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<unistd.h>
#include<string.h>
#define SUCCESS 1
#define FAILURE 0
#define REDCOUNTDOWN 60
#define GREENCOUNTDOWN 40

typedef struct {
	long int mtype;
	char mtext[20];
} msgbuf;

int timer;
int mq_id;
msgbuf msg;

void setTimer(char signal[]){
	if(strcmp(signal, "RED") == 0) timer = 60;
	else if(strcmp(signal, "GREEN") == 0) timer = 40;
	else timer = 20;
	return;
}

void toggle(char signal[]){
	if(strcmp(signal, "RED") == 0){
		strcpy(signal, "GREEN");
		timer = 40;	
	} else {
		strcpy(signal, "RED");
		timer = 60;
	}
	return;
}

void switchSignal(char signal[], char colour[]){
	if(strcmp(colour, "") == 0){
		toggle(signal);
	} else {
		setTimer(colour);
		strcpy(signal, colour);
	}
	return;
}

int checkForButtonPush() {
	int res = msgrcv(mq_id, &msg, sizeof(msg), 0, IPC_NOWAIT);
	if(res != -1) {
		printf("Message type = %ld\n", msg.mtype);
		printf("Message text = %s\n", msg.mtext);
		return SUCCESS;
	} else {
		return FAILURE;
	}
}
	
void showSignal(char signal[]){
	setTimer(signal);
	while(timer){
		if(checkForButtonPush()) {
			printf("%s button is pushed. Changing signal after cooldown\n", msg.mtext);
			sleep(10);
			switchSignal(signal, msg.mtext);
		}
		printf("Current Signal Light: %s\n", signal);
		printf("Count down time: %d\n", timer);
		sleep(1);
		timer--;
	}
	return;
}

int main()
{
	key_t mq_key=0xaabb1122;
	mq_id=msgget(mq_key, IPC_CREAT|0777);
	printf("Message queue id = %d\n", mq_id);
	int type = 0;
	if(mq_id == -1) perror("");
	else {
		timer = 60;
		char signal[20] = "RED";
		while(1){
			showSignal(signal);
			switchSignal(signal, "");
		}
	}
}