#include"eliminateOne.h"
#include<stdio.h>
int eliminateOne(Player* players, int* eliminatedIds, int elcount) {
    int  id=0, lowId=0, i, temp = 0,flag=1;
    double minScore;
    //to find minimum score among the eliminated players
    minScore = players[eliminatedIds[0]].netScore; lowId=eliminatedIds[0];
    printf("\n 1st   %f\n",minScore);
    i = 0;
    while (i < elcount)
    {
        id = eliminatedIds[i];
        if(players[id].netScore < minScore ){
             minScore = players[id].netScore;
             lowId = id;
        }
        ++i;
    }
    printf("min score:   %f",minScore);
    printf("\nlow id:   %d",lowId);
    //if more than one eliminated player has same lowest score
    i = 0;
    while(i<elcount) {
        id = eliminatedIds[i];
        if(minScore == players[id].netScore)
        temp++;
        ++i;
    }
    printf("\n counter check temp:  %d \n",temp);
    //if more than one player has same lowest score then no one will be eliminated in this round
    i = 0;
    if(temp > 1) {
        printf("\n TIE !! no one is eliminated in this round :D  \n"); flag=0;
        while(i < elcount) {
            id = eliminatedIds[i];
            players[id].eStatus = 0;        //estatus is reset to 0 - not eliminated
            i++;
        }      
    }
    else {
        while(i < elcount) {
            id = eliminatedIds[i];
            if(id != lowId)                 //Id with lowest score estatus remains unchanged i.e 1
            players[id].eStatus = 0;        //rest of the players are reset to 0
            i++;
        }

    }
    return flag;
}



//LMAO-halfway