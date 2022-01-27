//Done

#include<stdio.h>
#include"inputDet.h"
#include<string.h>

void inputDet(Player *P, int pcount) {
    
    // flushes the standard input
    // (clears the input buffer)
    while ((getchar()) != '\n');  

    for(int i = 0 ; i < pcount ; i++) {

        printf("\n\t---Player %d---\n", i+1);
        printf("Name: ");
        //Player name input from the user
        fgets(P[i].name, 20, stdin);

        //removes the trailing newline character
        P[i].name[strcspn(P[i].name, "\n")] = 0;

        //Initialization: 0 - Not eliminated
        P[i].eStatus = 0;           
        P[i].netScore = 0.0;    
    }
    printf("\nThanks for joining!\n");
    return;
}
