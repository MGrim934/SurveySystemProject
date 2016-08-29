#include "survey.h"
#include <conio.h>

//Mark Grimes
//g00289916
//Advance Procedural Programming "Survey System"

void main() {
	

	struct listelement* top;
	struct listelement* sNode;
	int validUserYN = 0;
	int choice;
	int passCheck;
	do {
		passCheck = passwordCheck();
	} while (passCheck != 1&&passCheck!=999);

		
	top = NULL;


	readFromFile(&top);



	//loops until the user chooses -1 to quit
	do {
		printf("\nSurvey System Main Menu\n");
		printf("===============================================\n");
		printf("1) Add A Survey\n");
		printf("2) Display All Surveys\n");
		printf("3) Search A Survey\n");
		printf("4) Update A Survey\n");
		printf("5) Delete A Survey\n");
		printf("6) Print Surveys To Report File\n");
		printf("-1) To Exit Program\n");
		scanf("%d", &choice);

		switch (choice) {
		case 1:
			addSurvey(&top);
			//adds a survey
			break;
		case 2:
			displayAll(top);
			//displays all surveys
			break;
		case 3:
			displaySurvey(top);
			//displays a specific survey
			break;
		case 4:
			updateSurvey(&top);
			//lets the admin change the answers to a survey
			break;
		case 5:
			deleteSurvey(&top);
			//removes a survey
			break;
		case 6:
			printReport(top);
			//prints stats to screen and to file
			break;
		case -1:
			printf("\nExiting Program\n");
			printToFile(top);
			//prints surveys to file
			break;
		default:
			printf("\nInvalid Input - Try Again\n");
			//error handling
			break;

		}
		

	} while (choice != -1);
	//closes the program

	

	getch();
}//main