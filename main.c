#include<stdio.h>
#include"inputDet.h"
#include"game.h"
#include"LeaderBoard.h"

int main() {
    int menu_choice = 0, player_count;

    while(menu_choice != 3) {

        printf("\n\t\t\t***MENU***\n");
        printf("\t\t1 --- Start Game\n");
        printf("\t\t2 --- Leaderboard\n");
        printf("\t\t3 --- Exit\n\n");

        printf("Enter your choice : ");
        scanf("%d", &menu_choice);

        switch (menu_choice) {
            case 1:
                {
                    //Game Entry 
                    printf("\nStarting the game... please input some details...\n");
                    
                    do{
                        printf("\nHow many people are playing this game? : ");
                        scanf("%d", &player_count);
                        if(player_count<2){
                            printf("\nGet some more people to play this game :/ \n");
                            player_count = 0;
                        }else{printf("%d people are playing. How may we call you?", player_count); continue;}   
                    }while(player_count<2);

                    //Declaration of an array of struct of type Player with `player_count` number of players
                    Player players[player_count];

                    //Calling inputDet() function to input data of players
                    inputDet(players, player_count);
                    printf("Game is about to begin, get ready!!\n");

                    //Calling function game.c
                    game(players, player_count);
                    
                    break;
                }
            
            case 2:
                //Display leaderboard
                printf("\nDisplay leaderboard\n");
                display();    //calls the function to display leaderboard
                break;

            case 3:
                //Exit
                printf("\nExit\n");
                break;

            default:
                //Choice out of bound
                printf("\nWrong choice. Please try again :)\n");
        }
    }
    
    return 0;
}