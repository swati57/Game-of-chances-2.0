#include<stdio.h>
#include"game.h"
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include"LeaderBoard.h"

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


void game(Player *players, int pcount) {
    int round  = 1;
    int quesIds[5] = {0};
    int playerGuess[pcount];

    //Generates 5 different question Ids for 5 rounds
    generateId(quesIds);

    // printf("\n");
    // for(int t = 0 ; t<5 ; t++) {
    //     printf("-%d-", quesIds[t]);
    // }
    // printf("\n");

    while(round <= 5) {
        printf("\n----ROUND %d----", round);

        //Fetch question
        FILE *fptr;
        fptr = fopen("Questions.txt", "r");
        
        if(fptr == NULL){
            printf("Questions.txt file failed to open\n");
        }
        else {

            printf("\n~ *Question* ~\n");
            //Displays Question and returns answer to that question
            int ans = fetchQues(quesIds[round-1]);
            float guess_num;
            //To store player guessed in each round
            printf("\nEnter your guess... range is 0 to 100\n");
            for(int p = 0 ; p < pcount ; p++) {
                if(players[p].eStatus == 0) {   
                    //Input player guess
                    printf("Player %d- %s: ", p+1, players[p].name);

                    scanf("%f", &guess_num);
                    if((int)guess_num!=guess_num)
                    {
                        printf("\nError!! Enter integers only ... try again\n ");
                        --p;
                    }
                    else{
                        playerGuess[p]=guess_num;
                        //to check whether guess is between 0 to 100
                        if(playerGuess[p] < 0 || playerGuess[p] > 100 ) {
                            printf("\nError!! Guess is out of range ... try again\n ");
                            --p;
                        }
                    }
                }
            }

            //stores the player Ids of players who guessed out of range 
            int eliminatedIds[pcount];
            //Score calculation and updating elimination status of each player in this round
            //returns number of player who guessed out of range
            int elcount = evaluate(players, playerGuess, round, ans, pcount, eliminatedIds);

            //If more than one player is out of range in this round 
            //then the player with lesser score will be eliminated

            if(elcount > 1) 
                eliminateOne(players, eliminatedIds, elcount);



            printf("\nThe correct answer is : %d%%\n", ans);

            sortCurrent(players,pcount); //to sort current ranking
            //To display player details after each round
            printf("\n\t---Player details---\n");
            printf("PLAYER\t\t\tELIMINATION STATUS\t\tNET SCORE\n");
            for(int t = 0 ; t < pcount ; t++) {
                char eStatus[15]="IN GAME";
                if(players[t].eStatus == 1)
                    strcpy(eStatus,"ELIMINATED");
                
                printf("\n%d. %-15s\t\t %-15s\t\t  %-15.2f\n",t+1, players[t].name,eStatus,players[t].netScore);
            }

            round++;    //Increment to next round


            
        }

    }
    LeaderB(players,pcount);

    return;    
}
