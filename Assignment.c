#include <stdio.h>
#include <string.h>

int x = 0;
struct record {
	char name [50] ;
	int mark;
};

void display (struct record student[]);
void search (struct record student[]);
void filter (struct record student[]);

int main()//Written by : Iven Low
{
	struct record student [5]; // structure array named student with 5 elements
	int y = 1, menu;
	char answer;
	
	for(x=0;x<5;x++)
	{
		printf("Student #%d\n", y);
		printf("Enter name : ");
		scanf("%s", student[x].name); // prompt user to enter student's name
		printf("Enter mark : ");
		scanf("%d", &student[x].mark); // prompt user to enter student's mark
		y++;
		printf("\n");
	}
	printf("Menu\n");
	printf("1. Display data\n");
	printf("2. Search data \n");
	printf("3. Filter data \n");
	fflush(stdin);
	printf("\n");
	
	do {
		printf("Choose option <1,2,3> : ");
		scanf("%d", &menu); // prompt the user to enter option
		printf("\n");
		
	//i tried using switch case but it does not have proper output so i used if else statement to check which option in the menu the user have key in
	//Written by : Irdina
	switch(menu)
	{
		case 1 : display(student);
				   break;
		case 2 : search(student);
				   break;	
		case 3 : filter(student);
				   break;
		//default  : printf("Invalid option");
		//		   break;		   	   
	}

		
		//Written by : Ng Siew Yang
		fflush(stdin);
		printf("Do you want to continue ? <Y-Yes  N-No> : ");
		scanf("%c", &answer);
		printf("\n");
		}while (answer == 'Y');// the process will repeat as long as the user wants to continue,if the user did not key in character Y, it will display Thank you and terminate the program.
		printf("Thank you.\n");
}

void display(struct record student[])//written by : Ng Siew Yang
{
	//In function display, if user chooses option 1 the output will show all 5 names and marks that the user have entered
	printf("Students Record\n");
	for (x=0; x<5; x++)
	{
		printf("%s \t %d\n", student[x].name, student[x].mark );
	}
	printf("\n");
	return ;
}

void search(struct record student[]) //Lam Jern Herr
{
	int i, error = 0;
	char name[50];
	
	fflush(stdin);
	printf("Enter name to search : "); 
	gets(name); //User is prompt to enter name that they want to search
	for (x=0; x<5; x++)
	{
		if (strcmp(name, student[x].name)==0) //Using strcmp, it will compare the previous infromation and the current entered name, if it matches the output will display "data found", the student's name and mark
		{	
		printf("Data found.\n");
		printf("Name : %s\n",student[x].name);
		printf("Mark : %d\n\n", student[x].mark);
		}
		else
		{
		error++;
		}
	}
	if (error==5) 
	{
		printf("Data not found\n\n"); //if the names does not match, it will display "data not found" and return to the option of choosing the menu
	}
	return ;
}

void filter (struct record student[])//written by : Irdina
{
	int startmark, endmark;
	//In function void filter, user is asked to enter the start mark and end mark to find student with those marks in between
	printf("Enter start mark : ");
	scanf("%d", &startmark);
	printf("Enter end mark   : ");
	scanf("%d", &endmark);
	printf("\n");
	printf("Student records with mark between %d and %d\n", startmark, endmark);
	//Using for loop, output will display the marks between start and end mark that user have entered from the main function of information that have been entered
	for (x=0; x<5; x++)
	{
		if (student[x].mark >= startmark && student[x].mark<= endmark)
		{
		printf("%s \t %d\n", student[x].name, student[x].mark);
		}
	}
	printf("\n");
	return;
}
