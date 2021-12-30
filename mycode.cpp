#include<stdio.h>
#include<conio.h>
//function definition
void input_data(struct Player *ptr);
void game_start(struct Player *ptr);
void print_data(struct Player *ptr);
//structure definition
struct Player{
	char name[20];
	bool E=false;
	double netScore=0;
};

//number of players will be stored in n and it is declared as global to be used in different function calls
int n;
int main()
{
	//array of struct instance creation
	struct Player p[5];
	//call function to input data
	input_data(p);
	//function to print the player's details just to check if code works or not
	print_data(p);
	//	game_start(p);
}
//function definition
void input_data(struct Player *ptr)
{
	//input number of players
	printf("Enter the number of players: ");
	scanf("%d",&n);
	int count=1;
	//repeat the loop for n times
	while(count<=n)
	{
		printf("Enter the name of player %d: ",count);
		//clear the buffer before inputting string 
		fflush(stdin);
		//input name
		gets(ptr->name);
		//increment count and ptr to point to next struct instance
		count++;
		ptr++;
	}
	return;
}
//function definiton to print struct values for testing purpose
void print_data(struct Player *ptr)
{
	for(int i=0;i<n;i++)
	{
		printf("\n\nPlayer %d",i+1);
		printf("\nName: %s",ptr->name);
		printf("  Elimination status: %d",ptr->E);
		printf("  Score: %d",ptr->netScore);
		ptr++;
	}
}
//this is the function from where the game starts
void game_start(struct Player *ptr)
{
	int round=1;
	while(round<=5)
	{
		//generate a random question and print it
	//	round();
	}
}
