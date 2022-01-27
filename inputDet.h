#ifndef INPUTDET
#define INPUTDET

#include<stdlib.h>

//struct def of each player
typedef struct Player {
	char name[20];
	int eStatus;          //0 - Not eliminated,  1 - Eliminated
	double netScore;
} Player;
double minScore;
void inputDet(Player*, int);

#endif