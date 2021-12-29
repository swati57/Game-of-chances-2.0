#include<stdio.h>

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
                //Game start 
                printf("\nGame Starts\n");
                
                printf("\nEnter the number of players: ");
                scanf("%d", &player_count);

                //playerDet(player_count);   //calls player_det function
                
                break;
            
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
                break;
        }

    }
    
return 0;
}