//RangeCheck is to check if player's answer lies in the permissible range//
#include<stdio.h>
#include<conio.h>
#include<stdbool.h>


//Function to check if Guess lies within upper and lower limit 
bool IsInRange(int A, int B, int G){
    if(A<=G&&G<=B){
        return true;
    }
    else{return false;}
}

int main(){
int Guess, QA, round;//These are to be provided
int LowerLim, UpperLim; //These will be generated

Guess=51;round=5;QA=45;//Test values assigned
//Switch statement to be used to assign values to Upper and Lower limit 
switch(round)
{
case 1:
    if(QA>=25){
        LowerLim = (QA - 25);
        UpperLim = (QA + 25);}
    else{
        LowerLim = 0; 
        UpperLim = (QA + 25);}
        break;
case 2:
    if(QA>=20){
        LowerLim = (QA - 20);
        UpperLim = (QA + 20);}
    else{
        LowerLim = 0; 
        UpperLim = (QA + 20);}
        break;
case 3:
    if(QA>=15){
        LowerLim = (QA - 15);
        UpperLim = (QA + 15);}
    else{
        LowerLim = 0; 
        UpperLim = (QA+15);}
        break;
case 4:
    if(QA>=10){
        LowerLim = (QA - 10);
        UpperLim = (QA + 10);}
    else{
        LowerLim = 0; 
        UpperLim = (QA + 10);}
        break;
default:
    if(QA>=5){
        LowerLim = (QA - 5);
        UpperLim = (QA + 5);}
    else{
        LowerLim = 0; 
        UpperLim = (QA + 5);}
        break;
}
printf("Guess:%d\nLower:%d\nUpper:%d\n",Guess,LowerLim,UpperLim); //Testing if logic works
bool p;
p=(IsInRange(LowerLim,UpperLim,Guess));//Testing if Guess lies in range
printf("It's %d",p);//1 means True, 0 means False
return 0;
}
//When attaching this to main file, the return type will be bool