#include<stdio.h>
#include<stdlib.h>

int fetchQues(int id) {
    char buffer[200] = "", line_text[200] = "", ansStr[3] = "";
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

void main() {
    printf("\n1... %d\n", fetchQues(1));
    printf("\n2... %d\n", fetchQues(2));
    printf("\n3... %d\n", fetchQues(3));
    printf("\n4... %d\n", fetchQues(4));
    printf("\n5... %d\n", fetchQues(5));
    printf("\n6... %d\n", fetchQues(6));
    printf("\n7... %d\n", fetchQues(7));
    printf("\n8... %d\n", fetchQues(8));
    printf("\n9... %d\n", fetchQues(9));
    printf("\n10.. %d\n", fetchQues(10));
    printf("\n11... %d\n", fetchQues(11));
    printf("\n12... %d\n", fetchQues(12));
    printf("\n13... %d\n", fetchQues(13));
    printf("\n14... %d\n", fetchQues(14));
    printf("\n15... %d\n", fetchQues(15));
    printf("\n16... %d\n", fetchQues(16));
    printf("\n17... %d\n", fetchQues(17));
    printf("\n18... %d\n", fetchQues(18));
    printf("\n19... %d\n", fetchQues(19));
    printf("\n20... %d\n", fetchQues(20));
}