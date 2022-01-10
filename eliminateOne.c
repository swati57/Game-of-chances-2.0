#include"eliminateOne.h"

void eliminateOne(Player* players, int* eliminatedIds, int elcount) {
    int minScore, id, lowId, i, temp = 0;

    //to find minimum score among the eliminated players
    minScore = players[eliminatedIds[0]].netScore;
    i = 1;
    while (i < elcount)
    {
        id = eliminatedIds[i];
        if(minScore < players[id].netScore){
             minScore = players[id].netScore;
             lowId = id;
        }
        ++i;
    }
    //if more than one eliminated player has same lowest score
    i = 0;
    while(i<elcount) {
        id = eliminatedIds[i];
        if(minScore == players[id].netScore)
            ++temp;
        ++i;
    }

    //if more than one player has same lowest score then no one will be eliminated in this round
    i = 0;
    if(temp > 1) {
        while(i < elcount) {
            id = eliminatedIds[i];
            players[id].eStatus = 0;        //estatus is reset to 0 - not eliminated
        }      
    }
    else {
        while(i < elcount) {
            id = eliminatedIds[i];
            if(id == lowId)                 //Id with lowest score estatus remains unchanged i.e 1
                continue;
            players[id].eStatus = 0;        //rest of the players are reset to 0
        }
    }
    return;
}



//LMAO