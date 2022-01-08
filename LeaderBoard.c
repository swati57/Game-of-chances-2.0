/*  Module: LeaderBoard 
    Implementations:  Structure ,bubble sort & File handling.
     
    LeaderB function takes 2 values as arguements: 
        1. Current players info
        2. endofgame variable(to check whether it is end of game)
*/
#include <stdio.h>
#include <string.h>
struct info{
    int points;
    char name[20];
};

void LeaderB(struct info player[5], int endofgame); 
void display();
int main(void) {
    struct info player[5]; int i=0; int endofgame;
    printf("Enter 1 or 0 for endofgame:    ");
    scanf("%d", &endofgame);
    if(endofgame==1){
        for(i=0; i<5; i++){
        scanf("%s", player[i].name);
        scanf("%d", &player[i].points);
        } 
    }
    LeaderB(player,endofgame); //LeaderB function gets called..
    return 0;
}
void LeaderB(struct info player[5], int endofgame){
    int i=0,j=0;
    struct info  temp; //temp var for sorting purpose
    
    if(endofgame==0){
        /*endofgame=0 implies function is called in the main menu
        that is beginning of game..
        hence no sorting.. simply display leaderboard*/

        display();
    }
    else{

        //endofgame=1

        //first counting the number of players in file
        FILE *fptr = fopen("testt.txt", "r");
	    int count = 0, size =0;
	    if ( fptr != NULL ){
            char line[256];
            while (fgets(line, sizeof line, fptr) != NULL){
                count++;
            }
        }

        size= count+5; //space for 5 extra new players
        struct info a[size]; //new structure var for new leaderboard
        
        rewind(fptr); //takes file pointer to the beginning of file

        //reading and storing data from file to struct variable

        if(fptr != NULL){
                char line[256];int i=0;
                while (1){
                if(feof(fptr))break;
                fscanf(fptr,"%s",a[i].name);
                fscanf(fptr,"%d",&a[i].points);
                i++;
            }
        }
        fclose(fptr);

        //adding present players to fresh leaderboard
        for(i= count,j=0; j<5; i++, j++){
            if(i==-1)i=0;
            strcpy(a[i].name,player[j].name);
            a[i].points= player[j].points;
        }

        //sorting...

        for(i=0; i<size; i++){
        for(j=0; j<size-i-1; j++){
            if(a[j].points < a[j+1].points){
                temp= a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
                
            }
        }
    }

    //writing the fresh leaderboard in file...
    fptr = fopen("testt.txt", "w"); //'w' mode to overwrite file

    for(i=0; i<size-1; i++){
        fprintf(fptr,"%s %d\n",a[i].name,a[i].points);
    }
    /*line 101 because above loop takes an extra line
        and throws garbage value*/
    fprintf(fptr,"%s %d",a[size-1].name,a[size-1].points);
    fclose(fptr);

    //display fresh leaderboard in the end

    display();
    
    //end of funtion :)
    }
    
	
}
void display(){
    FILE *fptr;
     fptr= fopen("testt.txt","r");
     if(fptr==NULL){
         printf("leaderboard file could not be opened :( \n");
     }
     else{
        char n[20]; int i=1; char poins[10];
            printf("\n*******LEADERBOARD*********\n");
            while(1){
            if(feof(fptr))break;
            fscanf(fptr,"%s %s",n,poins);
            printf("%d. %s                   %s \n",i++,n,poins);
            }
            fclose(fptr);
    }  
} 