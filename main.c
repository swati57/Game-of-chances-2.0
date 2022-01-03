#include<stdio.h>
#include"inputDet.h"
#include"game.h"

int main() {
    int menu_choice = 0, player_count;

    while(menu_choice != 3) {

        printf("\n\t\t\t***MENU***\n");
        printf("\t\t1 --- Start Game\n");
        printf("\t\t2 --- Leaderboard\n");
        printf("\t\t3 --- Exit\n\n");

        printf("Enter your choice as per the menu:\n");
        scanf("%d", &menu_choice);

        switch (menu_choice) {
            case 1:
                {
                    //Game Entry 
                    printf("\nGame Starts\n");
                    
                    printf("\nEnter the number of players: ");
                    scanf("%d", &player_count);

                    //Declaration of an array of struct with `player_count` number of players
                    Player players[player_count];
                    Player rankwise[player_count];

                    //Calling inputDet() function to input data of players
                    inputDet(players, player_count);

                    game(players, rankwise, player_count);
                    
                    break;
                }
            
            case 2:
                //Display leaderboard
                printf("\nDisplay leaderboard\n");
                //Leaderboard();    //calls the function to display leaderboard
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