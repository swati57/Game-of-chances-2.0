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

//function to input valid integer value for playerGuess
int input_valid()
{
    char num[20],ch;
    int number;
    while(1)
    {
        //clear the buffer
        fflush(stdin);
        //input the number/string in num char array
        fgets(num, 20, stdin);
        //remove the trailing newline char
        num[strcspn(num, "\n")] = 0;
        int i=0,flag=0;
        number=0;
        //fetch the chars of num[] one by one
        while(num[i]!='\0')
        {
            ch=num[i];
            //if ch is not in the range of integers ascii value
            if (ch <= 48 || ch >= 57) 
            {
                //print the message, set the flag value and break from the loop
            printf("Please input integer values only!!\n");
            flag=1;
            break;
            }
            else
            // To make a digit
            number = number * 10 + (ch - 48);
            //increment i to access the next char of num[]
            i++;
        }
       // flag=0 means the number is valid integer so break from the loop and return the value
        if(flag==0)
         break;
        // else ask the user to input again and continue the loop
        printf("\nEnter the number: ");
    }
    return number;
}


void game(Player *players, int pcount) {
    int round  = 1, count=0;//Count is the total number of player that's been eleminated so far
    int quesIds[5] = {0};
    int playerGuess[pcount];
    char pStatus[11];

    //Generates 5 different question Ids for 5 rounds
    generateId(quesIds);

    while(round <= 5) {
         if(count==pcount)break; //Check before round if everyone has been eleminated
        printf("\nHere is your question for ROUND %d \n", round);

        // printf("\n~ *Question* ~\n");
        //Displays Question and returns answer to that question
        int ans = fetchQues(quesIds[round-1]);
        
        
        //To store player guessed in each round
        printf("\n\nWarning! Enter your guess within 0 to 100\n\n");
        for(int p = 0 ; p < pcount ; p++) {
            if(players[p].eStatus == 0) {   
                //Input player guess
                printf("Player %d- %s: ", p+1, players[p].name);

                //call function to input valid integer value for playerGuess
                playerGuess[p]=input_valid();
                    
                //to check whether guess is between 0 to 100
                if(playerGuess[p] < 0 || playerGuess[p] > 100 ) {
                    printf("\nError!! Guess is out of range ... try again\n ");
                    --p;                   
                }
            }
        }

        //array to store the player Ids of players who guessed out of range 
        int eliminatedIds[pcount];

        //Score calculation and updating elimination status of each player in this round
        //returns number of player who guessed out of range
        int elcount = evaluate(players, playerGuess, round, ans, pcount, eliminatedIds);
        //If more than one player is out of range in this round 
        //then the player with lesser score will be eliminated
        if(elcount==1)count++;
        if(elcount > 1) {
            count+= eliminateOne(players, eliminatedIds, elcount, minScore); 
        }
        
        printf("The correct answer is : %d%%\n", ans);

        sortCurrent(players, pcount); //to sort current ranking


        //To display player details after each round
        printf("\n\t\t\t---CURRENT TALLY---\n");
        printf("PLAYER\t\t\tELIMINATION STATUS\t\t\tNET SCORE\n");
        for(int t = 0 ; t < pcount ; t++) {
            if(players[t].eStatus == 1)
                strcpy(pStatus,"ELIMINATED");
            else
                strcpy(pStatus, "IN GAME");
            
            printf("\n%d. %-15s\t\t %-15s\t\t  %-15.2f\n",t+1, players[t].name,pStatus,players[t].netScore);
        }

        round++;    //Increment to next round

    }
    LeaderB(players,pcount);

    return;    
}
