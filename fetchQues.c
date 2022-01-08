#include<stdio.h>
#include"fetchQues.h"

int fetchQues(int id) {
    char buffer[100] = "", line_text[100] = "", ansStr[3] = "";
    int lineCount = 1;

    FILE *fptr;
    fptr = fopen("Questions.txt", "r");     //Open txt file in r mode

    if(fptr == NULL){
        //error
        printf("Questions.txt file failed to open\n");
    }
    else {
        //File acessed
        while(fgets(buffer, sizeof(buffer), fptr) != NULL) {
            //ques id matched with line number
            if(id == lineCount) {
                //storing the string in line_text from buffer
                fscanf(fptr, "%[^\n]", line_text);
                fclose(fptr);       //file closed
                break;
            }
            lineCount++;       //increment to next line number
        }
    }

    //To print question
    int i = 4, j = 0;
    do {
        printf("%c", line_text[i]);
    } while(line_text[i++] != '?');
    
    //to return the answer value
    j = 0;
    while(line_text[i]) {
        ansStr[j++] = line_text[i++];
    }
    return atoi(ansStr);
}