#include"LeaderBoard.h"
#include<stdio.h>
#include<string.h>
/*  Module: LeaderBoard 
    Implementations:  Structure ,bubble sort & File handling.
     
    LeaderB function takes Current players info as argument.
    Display function displays the leaderboard from file.
*/
void LeaderB(Player *player, int pcount){
    int i=0,j=0; 

        //first counting the number of players in file
        FILE *fptr = fopen("./textfiles/leaderboard.txt", "r");
	    int count = 0, size =0;
	    if ( fptr != NULL ){
            char line[256];
            while (fgets(line, sizeof line, fptr) != NULL){
                count++;
            }
        }

        size= count+pcount; //space for extra new players
        struct Player a[size]; //new structure var for new leaderboard
        
        rewind(fptr); //takes file pointer to the beginning of file

        //reading and storing data from file to struct variable

        if(fptr != NULL){
                char line[256];int i=0;
                while (1){
                if(feof(fptr))break;
                fscanf(fptr,"%s",a[i].name);
                fscanf(fptr,"%lf",&a[i].netScore);
                i++;
            }
        }
        fclose(fptr);

        //adding present players to fresh leaderboard
        for(i= count,j=0; j<pcount; i++, j++){
            if(i==-1)i=0;
            strcpy(a[i].name,player[j].name);
            a[i].netScore= player[j].netScore;
        }

        //sorting...

        struct Player  temp; 
        for(i=0; i<size; i++){
            for(j=0; j<size-i-1; j++){
                if(a[j].netScore < a[j+1].netScore){
                    temp= a[j];
                    a[j] = a[j+1];
                    a[j+1] = temp;   
                }
            }
        }
        
    //writing the fresh leaderboard in file...
    fptr = fopen("./textfiles/leaderboard.txt", "w"); //'w' mode to overwrite file

    for(i=0; i<size-1; i++){
        fprintf(fptr,"%s            %lf\n",a[i].name,a[i].netScore);
    }
    /*line 69 because above loop takes an extra line
        and throws garbage value*/
    fprintf(fptr,"%s            %lf",a[size-1].name,a[size-1].netScore);
    fclose(fptr);

    //display fresh leaderboard in the end

    display();
    
    //end of funtion :)
}
void sortCurrent(Player *players, int size){
    int i,j;
    struct Player  temp; 
    for(i=0; i<size; i++){
        for(j=0; j<size-i-1; j++){
            if(players[j].netScore < players[j+1].netScore){
                temp= players[j];
                players[j] = players[j+1];
                players[j+1] = temp;
                
            }
        }
    }
}
void display(){
    FILE *fptr;
     fptr= fopen("./textfiles/leaderboard.txt","r");
     if(fptr==NULL){
         printf("Leaderboard file could not be opened :( \n");
     }
     else{  
            char buffer[100];
            int i = 1;
            if(fgets(buffer, sizeof(buffer), fptr) == NULL)
            printf("\n LeaderBoard is empty :( \n enter 1 to start a game now!! \n");
            else{
                printf("\n*******LEADERBOARD*********\n");
                rewind(fptr);
                while(fgets(buffer, sizeof(buffer), fptr) != NULL) {
                    printf("%d. %s \n",i++,buffer);
                }
            }  
        }  
    fclose(fptr);
} 