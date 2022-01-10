#include<stdio.h>

void display(){
    FILE *fptr;
     fptr= fopen("testt.txt","r");
     if(fptr==NULL){
         printf("leaderboard file could not be opened :( \n");
     }
     else{
         char line_text[100],buffer[100];
        while(fgets(buffer, sizeof(buffer), fptr) != NULL) {
           
            
                //storing the string in line_text from buffer
                fscanf(fptr, "%[^\n]", line_text);
                printf("%s \n",line_text);
                //fclose(fptr);       //file closed
            
            
               //increment to next line number
        }
        fclose(fptr);
}
} 


void main () {
    display();
    return;
}