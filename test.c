#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void generateId(int *usedId) {
    int id = 0, i = 0, j, found;
    srand(time(0));

    while(i < 5) {
        id = (rand() % 7) + 1;  //generates a random number in the range 1 - 30
        found = 0;              //Assumes id does not match with any previous id
        
        //To check if the id is already generated previously
        for(j = 0 ; j < i ; j++){
            //if id already generated before
            if(id == usedId[j]) {
                found = 1;
                break;
            }
        }

        //a new id is found
        if(!found) {
            usedId[i] = id;
            i++;
        }
    }
    return;
}

void main(){
    
    int usedId[5] = {0};
    generateId(usedId);
    for(int i = 0 ; i<5 ; i++){
        printf("%d ", usedId[i] );
    }
    return;
}