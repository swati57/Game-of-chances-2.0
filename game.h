#ifndef GAME
#define GAME

#include<stdlib.h>
#include"inputDet.h"
#include"fetchQues.h"
#include"evaluate.h"
#include"eliminateOne.h"
#include"LeaderBoard.h"

void generateId(int*);
int input_valid();
void game(Player*, int);

#endif