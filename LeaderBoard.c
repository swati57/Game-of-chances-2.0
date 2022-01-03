/* This code accepts 5 players with points
    and sorts them accorgingly. eg
      INPUT FORMAT
      neha 199
      priya 233
      ekka 677
      lul 56
      wuu 46

      OUTPUT

      1 . ekka            677
      2 . priya            233
      3 . neha            199
      4 . lul            56
      5 . wuu            46

    Implementations:  Structure and bubble sort

    Progress on file handling:

        =>read/write files in loop completed
        =>working on sorting within loops in files

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
    LeaderB(player,endofgame);
    return 0;
}
void LeaderB(struct info player[5], int endofgame){
    int i=0,j=0;
    struct info  temp;
    
    if(endofgame==0){
        display();
    }
    else{
        for(i=0; i<5; i++){
        for(j=0; j<5-i-1; j++){
            if(player[j].points < player[j+1].points){
                temp= player[j];
                player[j] = player[j+1];
                player[j+1] = temp;
                
            }
        }
    }
    
    for(i=0; i<5; i++){
        printf("%d . %s            %d \n",i+1,player[i].name,player[i].points);
    }
    }
    
	
}
void display(){
    FILE *fptr;
     fptr= fopen("testt.txt","r+");
     if(fptr==NULL)
     printf("leaderboard file could not be opened :( \n");
    char n[20]; int i=1; char poins[10];
        while(1){
            fscanf(fptr,"%s %s",n,poins);
            printf("%d. %s                   %s \n",i++,n,poins);
            if(feof(fptr))break;
            }
    fclose(fptr);
}