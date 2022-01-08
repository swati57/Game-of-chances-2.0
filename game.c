#include<stdio.h>
#include"game.h"
#include<stdlib.h>
#include<time.h>
#define NOQ 20  //No. of questions available

void generateId(int *quesIds) {
    int id = 0, i = 0, j, found;
    srand(time(0));     //uses current time as seed for random generator

    while(i < 5) {
        id = (rand() % NOQ) + 1;  //generates a random number in the range 1 - 30
        found = 0;              //assumes id does not match with any previous id
        
        //To check if the id is already generated previously
        for(j = 0 ; j < i ; j++){
            //if id already generated before
            if(id == quesIds[j]) {
                found = 1;
                break;
            }
        }

        //a new id is found
        if(!found) {
            quesIds[i] = id;
            i++;
        }
    }
    return;
}


void game(Player *players, Player *Rankwise, int pcount) {
    int round  = 1;
    int quesIds[5] = {0};

    //Generates 5 different question Ids for 5 rounds
    generateId(quesIds);
    printf("\n");
    for(int t = 0 ; t<5 ; t++) {
        printf("-%d-", quesIds[t]);
    }
    printf("\n");

    while(round <= 5) {
        printf("\n----ROUND %d----", round);

        //Fetch question
        FILE *fptr;
        fptr = fopen("Questions.txt", "r");
        
        if(fptr == NULL){
            printf("Questions.txt file failed to open\n");
        }
        else {

            printf("\n*Question* ~\n");
            int ans = fetchQues(quesIds[round-1]);
            printf("\n%d\n", ans);

            round++;    //Increment to next round
        }
    }
    return;    
}
