#include"evaluate.h"

void selectRange(int round, int ans, int *limits) {
    int range;

    //To select range
    switch(round) {
        case 1:  
            range = 25;
            break;

        case 2: 
            range = 20;
            break;

        case 3:
            range = 15;
            break;
    
        case 4:
            range = 10;
            break;
            
        case 5:
            range = 5;
    }

    //Calculating lowerlimit and upperlimit of the answer in the following round 
    //index 0 stores lowerlimit, index 1 - upperlimit
    limits[0] = ((ans - range) <= 0)? 0 : (ans - range);
    limits[1] = ((ans + range) >= 100)? 100 : (ans + range);

    return;
}

int evaluate(
    Player *players, 
    int *playerGuess, 
    int round, 
    int ans, 
    int pcount,
    int *elIds) {

    int score, elcount = 0;
    int limits[2];
    selectRange(round, ans, limits);

    //evaluating score and updating estatus for each player in this round
    for(int i = 0 ; i < pcount ; i++) {

        if(players[i].eStatus == 0) {
            if(playerGuess[i] < limits[0] || playerGuess[i] > limits[1]) {
                elIds[elcount++] = i;
                players[i].eStatus = 1;
            }
            score = 100 - (0.5 * abs(ans - playerGuess[i]));
            players[i].netScore += score;
        }
    }

    return elcount;
}