#include "survey.h"

//Mark Grimes
//Survey System
//g00289916

//age demographics
const char* ageDemo[5] = { "18-20","21-30","31-50","51-64","65+"};
//income bracket
const int incomeBracket[7] = { 0,20000,40000,60000,80000,100000,100000};
const char* incomeMessage[7] = { "No Income", "Less Than 20'000","Less Than 40'000","Less Than 60'000","Less Than 80'000","Less Than 100'000","More Than 100'000"};
const char* exerciseBracketMessage[4] = { "None","Less Than 3 Times a Week","Less Than 5 Times a Week","More Than 5 Times a Week" };
const char* cigMessage[4] = { "Non-Smoker","Less Than 20 a Week","Less Than 40 a Week","More Than 40 a Week" };
const char* alcoholMessage[4] = { "Non Drinker","Less Than 2 Units a Week","Less Than 4 Units a Week", "More Than 4 Units a Week" };
//these messages match up with the answers given by the user
//the answers are stored as ints which are used to access the index of the arrays


//exercise bracket
const int exerciseBracket[4] = { 0,3,5,5 };
//alcohol
const int alcoholBracket[4] = { 0,2,4,4 };

//cigarette Intake
const int cigBracket[4] = { 0,20,40,50 };

char setGender() {
	int choice;
	char gender;
	printf("What is your gender?\n");
	do {
		printf("1) Male\n");
		printf("2) Female\n");
		scanf("%d", &choice);
	} while (choice > 2 || choice < 1);
	//they have to be either male or female!
	switch (choice) {
	case 1:
		gender = 'm';
		break;
	case 2:
		gender = 'f';
		break;
	default:
		gender = 'o';
		//not used
		break;

	}//switch
	
	return gender;
	//returns a char
	//stores this as a char!

}

//setAgeBracket
int setAgeBracket() {
	int choice;
	int i, brackets;
	brackets = 5;
	//five age brackets
	do {
		printf("\nChoose Age Bracket\n");
		for (i = 0; i < brackets; i++) {
			printf("%d) %s\n", (i + 1), ageDemo[i]);
			//prints the age demographic options
		}
		scanf("%d", &choice);
		if (choice > 5 || choice < 1)
			printf("\nError\n");
		//checking if within the bounds or not

	} while (choice > 5 || choice < 1);
	//decrement the actual number to -1, so it lines up with array!
	choice--;
	printf("Age Bracket: %s", ageDemo[choice]);
	return choice;
}//set age

int setIncome() {
	int choice;
	do {
		printf("\nWhat is your Income Level?\n");
		printf("1) No Income\n");
		printf("2) Less Than 20000\n");
		printf("3) Less Than 40000\n");
		printf("4) Less Than 60000\n");
		printf("5) Less Than 80000\n");
		printf("6) Less Than 100000\n");
		printf("7) More Than 100000\n");
		scanf("%d", &choice);
	} while (choice > 7 || choice < 1);

	return --choice;
	//decrements to match up with the way they are stored in arrays
	//first element is index 0


}



int setExercise() {
	int choice, i,exercisePerWeek;
	do {
		printf("\nHow often Do you Exercise?\n");
		printf("1) Never\n");
		printf("2) Less than 3 times a week\n");
		printf("3) Less than 5 times a week\n");
		printf("4) 5 or more times a week\n");
		scanf("%d", &choice);
	} while (choice < 0 || choice>4);
	return --choice;
	//decrement to align with associated arrays


	
	

}

int setAlcohol() {
	int choice, i, exercisePerWeek;
	do {
		printf("\nHow Many units of alcohol do you drink a week?\n");
		printf("1) I don't drink alcohol!\n");
		printf("2) Less Than 2 units\n");
		printf("3) Less Than 4 units\n");
		printf("4) More Than 4 units\n");
		scanf("%d", &choice);
	} while (choice < 0 || choice>4);
	return --choice;
	//decremented to line up with associated arrays





}

int setCig() {
	int choice, i;
	do {
		printf("\nHow Many Cigarettes do you smoke a week?\n");
		printf("1) Never! Smokers are Jokers\n");
		printf("2) Less Than 20 a week\n");
		printf("3) Less Than 40 a week\n");
		printf("4) More Than 40 a week\n");
		scanf("%d", &choice);
	} while (choice < 0 || choice>4);
	return --choice;
	//decremented to align with associated array

}



int validateEmail(char* address) {
	int validAddress = 0;
	//make these two variables pointers
	//we will use strchr to find the location of the @ symbol and .com
	//these will point to that location if they are there
	//otherwise empty!
	char *at;
	char *com;
	char containsCom[8] = ".com";


	//first check if address contains @
	//then .com
	at = strchr(address, '@');
	//this will be NULL if its not there
	//otherwise it points to the @
	if (at != NULL) {
		//check if it contains .com
		com = strstr(address, containsCom);
		if (com != NULL) {
			validAddress = 1;
		}//if it points to a location then its valid
	}//if @ is in it
	//no point in checking for.com before @ Needs both after all!
	
	return validAddress;
	//either returns 0 or 1
	//1 is good
	//0 must try again


}//validateEmail


int searchPPSN(struct listelement* head_ptr, int ppsn){
	struct listelement *temp;
	int found = 0;
	//0 means not found
	//1 means found
	if (head_ptr == NULL) {
		return 0;
		//if its the first element, it couldnt possibly be there
		//instantly break out of function

	}

	temp = head_ptr;
	while (temp != NULL && found == 0) {
		
		if (temp->survey.ppsn == ppsn) {
			found = 1;
			//this will also break out of the while loop
			printf("\nPPSN in Database\n");
		}

		temp = temp->next;
		//move onto the next element of the array


	}//while
	return found;
	//returns 1 or 0
	//if 1 its found
	//react accordingly!
}

void displayPPSN(struct listelement* head_ptr) {
	int ppsn,found;
	found = 0;
	struct listelement* temp;
	printf("Enter PPSN: ");
	scanf("%d", &ppsn);

	temp = head_ptr;

	while (temp != NULL && found == 0) {
		if (temp->survey.ppsn == ppsn) {
			found = 1;
			//breaks out of loop
			printf("\nPPSN in Database\n");
			//print it all out
			//display all survey information
			printf("PPSN: %d\n", temp->survey.ppsn);
			printf("Gender: %c\n", temp->survey.gender);
			printf("Name: %s %s\n", temp->survey.firstName, temp->survey.lastName);
			printf("Address: %s\n", temp->survey.address);
			printf("E-mail: %s\n", temp->survey.email);
			printf("Age Bracket: %s\n", ageDemo[temp->survey.ageBracket]);
			//custom words for each

			printf("Income: %s\n", incomeMessage[temp->survey.incomeBracket]);
			printf("Exercise: %s\n", exerciseBracketMessage[temp->survey.exercise]);
			printf("Cigarettes: %s\n", cigMessage[temp->survey.cigaretteIntake]);
			printf("Alcohol: %s\n", alcoholMessage[temp->survey.alcoholIntake]);

		}//if
		temp = temp->next;
	}//while

	if (found == 0) {
		printf("\nNot in Database\n");
	}


}//displayPPSN

void displayName(struct listelement* head_ptr){
	char first[25];
	char last[25];
	int found = 0;
	struct listelement* temp;
	printf("Enter First Name: ");
	scanf("%s", first);
	printf("Enter Last Name: ");
	scanf("%s", last);

	temp = head_ptr;

	while (temp != NULL ) {
		if ((strcmp(temp->survey.firstName, first) == 0) && (strcmp(temp->survey.lastName, last) == 0)) {
			//if the comparison is true for both (returns 0 if equal) then we have found the name
			found = 1;
			//found doesn't break out of loop
			//in case there are multiple instances of the same name
			printf("\nName in Database\n");

			//print it all out
			//display all survey information
			printf("PPSN: %d\n", temp->survey.ppsn);
			printf("Gender: %c\n", temp->survey.gender);
			printf("Name: %s %s\n", temp->survey.firstName, temp->survey.lastName);
			printf("Address: %s\n", temp->survey.address);
			printf("E-mail: %s\n", temp->survey.email);
			printf("Age Bracket: %s\n", ageDemo[temp->survey.ageBracket]);
			//custom words for each

			printf("Income: %s\n", incomeMessage[temp->survey.incomeBracket]);
			printf("Exercise: %s\n", exerciseBracketMessage[temp->survey.exercise]);
			printf("Cigarettes: %s\n", cigMessage[temp->survey.cigaretteIntake]);
			printf("Alcohol: %s\n", alcoholMessage[temp->survey.alcoholIntake]);

		}//if
		temp = temp->next;
	}//while

	if (found == 0) {
		printf("\nName Not in Database\n");
	}


}//display name

void displaySurvey(struct listelement* head_ptr) {
	//this function displays based on a ppsn
	int choice;
	

	//1 runs ppsn search
	//2 runs name search
	do {
		printf("1) Search by PPSN\n");
		printf("2) Search by Name\n");
		scanf("%d", &choice);

		switch (choice) {
		case 1:
			displayPPSN(head_ptr);
			break;
		case 2:
			displayName(head_ptr);
			break;
		default:
			printf("\nError\n");
		}

	} while (choice>2 || choice<0);

}//displaySurvey


void addSurvey(struct listelement** head_ptr) {
	struct listelement *temp;
	struct listelement *oldTemp;
	struct listelement *newNode;
	char email[40];
	int ppsnChoice;
	int found = 0;
	if (*head_ptr == NULL) {
		//this runs if the database is empty
		//stuff
		printf("It begins\n");

		newNode = (struct listelement*)malloc(sizeof(struct listelement));
		printf("\nSurvey System 3000 initializing\n");
		do {
			printf("Enter PPSN: ");
	
			scanf("%d", &ppsnChoice);
		} while (searchPPSN(*head_ptr, ppsnChoice)>0);
		//while the searchPPSN finds that number
		//stops dupes
		newNode->survey.ppsn = ppsnChoice;
		newNode->survey.gender = setGender();
		//set gender returns an int that correlates to an array
		//easier storage

		printf("First Name: ");
		scanf("%s", newNode->survey.firstName);

		printf("Last Name: ");
		scanf("%s", newNode->survey.lastName);

		printf("Address ");
		scanf("%s", newNode->survey.address);
		do {
			printf("Email: ");
			scanf("%s", newNode->survey.email);
		} while (validateEmail(newNode->survey.email) != 1);


		//survey details are gleamed from functions that return integer values
		newNode->survey.ageBracket = setAgeBracket();
		newNode->survey.incomeBracket = setIncome();
		newNode->survey.exercise = setExercise();
		newNode->survey.alcoholIntake = setAlcohol();
		newNode->survey.cigaretteIntake = setCig();
		newNode->next = *head_ptr;
		*head_ptr = newNode;
		//sets the first element as the new node
		
	}
	else {
		//this runs if we are adding to the database
		printf("It continues\n");
		temp = *head_ptr;
		oldTemp = temp;

		



		newNode = (struct listelement*)malloc(sizeof(struct listelement));
		printf("\nSurvey System 3000 initializing\n");
		do {
			printf("Enter PPSN: ");

			scanf("%d", &ppsnChoice);
		} while (searchPPSN(*head_ptr, ppsnChoice)>0);
		//while the searchPPSN finds that number
		//stops dupes
		newNode->survey.ppsn = ppsnChoice;
		
		newNode->survey.gender = setGender();

		printf("First Name: ");
		scanf("%s", newNode->survey.firstName);

		printf("Last Name: ");
		scanf("%s", newNode->survey.lastName);

		printf("Address ");
		scanf("%s", newNode->survey.address);

		do {
			printf("Email: ");
			scanf("%s", newNode->survey.email);
		} while (validateEmail(newNode->survey.email) != 1);
		//runs the validation check to ensure that the user is entering a valid email address
	

		newNode->survey.ageBracket = setAgeBracket();
		newNode->survey.incomeBracket= setIncome();
		newNode->survey.exercise = setExercise();
		newNode->survey.alcoholIntake = setAlcohol();
		newNode->survey.cigaretteIntake = setCig();
		//now we must decide where to place the node
		//we want it to be less
		//we need to move at least once
		//first check to see if its less than the first element
		if (ppsnChoice < temp->survey.ppsn) {
			//make the newNode the new head
			//if its less than the first element
			newNode->next = *head_ptr;
			*head_ptr = newNode;
			found = 1;
			//wont run the while loop

		}
		
		while (temp->next!=NULL&&found!=1) {
			oldTemp = temp;
			temp = temp->next;
			if (ppsnChoice < temp->survey.ppsn) {
				found = 1;
				//wont run again
				newNode->next = temp;
				oldTemp->next = newNode;
				
			}//if
			
			//finds if the ppsn is less than the current
		}//while
		if (found == 0) {
			//if we didnt find one less than the ppsn
			//add to the end of the list
			temp->next = newNode;
			newNode->next = NULL;
		}


	}



}//add

void displayAll(struct listelement* head_ptr) {
	struct listelement *temp;
	temp = head_ptr;


	printf("\nSurveys\n");
	while (temp != NULL) {

		//display all survey information
		printf("PPSN: %d\n", temp->survey.ppsn);
		printf("Gender: %c\n", temp->survey.gender);
		printf("Name: %s %s\n", temp->survey.firstName, temp->survey.lastName);
		printf("Address: %s\n", temp->survey.address);
		printf("E-mail: %s\n", temp->survey.email);
		printf("Age Bracket: %s\n", ageDemo[temp->survey.ageBracket]);
		//custom words for each

		printf("Income: %s\n", incomeMessage[temp->survey.incomeBracket]);
		printf("Exercise: %s\n", exerciseBracketMessage[temp->survey.exercise]);
		printf("Cigarettes: %s\n", cigMessage[temp->survey.cigaretteIntake]);
		printf("Alcohol: %s\n", alcoholMessage[temp->survey.alcoholIntake]);

		printf("===============================================\n");


		

		temp = temp->next;

	}//while


}//displayAll

void printAllSurveysReport(struct listelement* head_ptr) {

	struct listelement *temp;
	int count = 0;
	temp = head_ptr;
	FILE *report = fopen("surveyreport.txt", "w");

	if (report != NULL) {
		fprintf(report, "Surveys System 3000\nSurvey Details\n");
		while (temp != NULL) {

			count++;
			//display all survey information
			fprintf(report, "PPSN: %d\n", temp->survey.ppsn);
			fprintf(report, "Gender: %c\n", temp->survey.gender);
			fprintf(report, "Name: %s %s\n", temp->survey.firstName, temp->survey.lastName);
			fprintf(report, "Address: %s\n", temp->survey.address);
			fprintf(report, "E-mail: %s\n", temp->survey.email);
			fprintf(report, "Age Bracket: %s\n", ageDemo[temp->survey.ageBracket]);
			//custom words for each

			fprintf(report, "Income: %s\n", incomeMessage[temp->survey.incomeBracket]);
			fprintf(report, "Exercise: %s\n", exerciseBracketMessage[temp->survey.exercise]);
			fprintf(report, "Cigarettes: %s\n", cigMessage[temp->survey.cigaretteIntake]);
			fprintf(report, "Alcohol: %s\n", alcoholMessage[temp->survey.alcoholIntake]);
			fprintf(report, "===============================================\n");



			temp = temp->next;

		}//while
		fprintf(report,"Survey Participants: %d\n", count);
		fprintf(report, "===============================================\n");
		fclose(report);
		//close the file
	}//if the file exists

}//printAllSurveys

void updateByPPSN(struct listelement** head_ptr) {
	struct listelement* temp;
	int ppsn;
	int found = 0;

	printf("Enter PPSN: ");
	scanf("%d", &ppsn);


	temp = *head_ptr;
	while (temp != NULL && found == 0) {
		if (temp->survey.ppsn == ppsn) {
			found = 1;
			//breaks out of loop
			printf("\nPPSN in Database\n");

		}
		if (found == 0) {
			temp = temp->next;
		}
	}//while

	 //error message
	if (found == 0) {
		printf("\nNot in Database\n");
	}
	else if (found == 1) {
		//update survey details
		temp->survey.ageBracket = setAgeBracket();
		temp->survey.incomeBracket = setIncome();
		temp->survey.exercise = setExercise();
		temp->survey.alcoholIntake = setAlcohol();
		temp->survey.cigaretteIntake = setCig();
	}


}//updateByPPSN

void updateByName(struct listelement** head_ptr){
	struct listelement* temp;
	char first[25];
	char last[25];
	int found = 0;

	printf("Enter First Name: ");
	scanf("%s", first);
	printf("Enter Last Name: ");
	scanf("%s", last);
	temp = *head_ptr;

	while (temp != NULL) {
		if ((strcmp(temp->survey.firstName, first) == 0) && (strcmp(temp->survey.lastName, last) == 0)) {
			found++;//increments the counter
	

			//breaks out of loop
			printf("\nName in Database\n");
			printf("\nPPSN: %d", temp->survey.ppsn);
			//show the ppsn to differentiate
			//if theres more than one of these names in the database!
			//update survey details
			temp->survey.ageBracket = setAgeBracket();
			temp->survey.incomeBracket = setIncome();
			temp->survey.exercise = setExercise();
			temp->survey.alcoholIntake = setAlcohol();
			temp->survey.cigaretteIntake = setCig();
			

			
}//if
		temp = temp->next;
		//move along and see if the name appears again and offer change

	}//while
	//say if nothing was found
	if (found == 0) {
		printf("\nSorry, Name isn't in the database\n");
	}
	else {
		printf("\n%d instances of this name in the database\n", found);
	}


}//updateByName

void updateSurvey(struct listelement** head_ptr) {
	struct listelement* temp;
	int ppsn;
	char first[25];
	char last[25];
	int found = 0;
	int choice;
	//we will assign a choice to get the person to choose!
	//for a message if we dont find it

	//1 runs ppsn search
	//2 runs name search
	do {
		printf("1) Search by PPSN\n");
		printf("2) Search by Name\n");
		scanf("%d", &choice);

		switch (choice) {
		case 1:
			updateByPPSN(head_ptr);
			break;
		case 2:
			updateByName(head_ptr);
			break;
		default:
			printf("\nError\n");
		}

	} while (choice>2 || choice<0);

}//updateSurvey

void deleteSurvey(struct listelement** head_ptr) {
	struct listelement* temp;
	struct listelement* oldTemp;
	int ppsn;
	int found = 0;
	int count = 0;
	int choice;

	printf("Enter PPSN: \n");
	scanf("%d", &ppsn);


	temp = *head_ptr;
	//need a special case if its found in the first case
	while (temp != NULL && found == 0) {

		if (temp->survey.ppsn == ppsn&&count==0) {
			//its the first element of the array
			//so we need to remove the head and set it it to temp next
			*head_ptr = temp->next;
			free(temp);

			found = 1;
			//breaks out of loop
			printf("\nPPSN in Database\n");

		}
		else if (temp->survey.ppsn == ppsn) {
			found = 1;
			//break out of loop
			oldTemp->next = temp->next;
			free(temp);

			//skips over temp and links to the next element
			//frees temp
			//now print message
			printf("\nSurvey PPSN: %d Removed\n", ppsn);

		}
		else {
			//didn't find it, so continue to move along the array
				oldTemp = temp;
				temp = temp->next;
				count++;
				//once count is incremented once
				//we know that its not at the beginning of the array
		}
		

	}//while
	if (found == 0) {
		//error message
		printf("\nCould Not Find PPSN\n");
	}

}//delete








int passwordCheck() {
	int validUserYN = 0;
	char name[25];
	//if they pass the check
	int i = 0;
	int end = 0;
	//defaults to 0
	//if they hit enter
	//change to 1
	int fileFound = 0;
	int userCount;
	char ch;
	user_t* users;
	//defaults to 0
	//if they pass the password check
	//change to 1

	char password[25];
	FILE *file = fopen("passwords.txt", "r");
	if (file != NULL) {
		fileFound = 1;
		//if the file exists run this protocol
		fscanf(file,"%d", &userCount);
		//printf("%d\n",userCount);
		//test code for printing user count
		//get the amount of users
		users= (user_t*)malloc(sizeof(user_t)*userCount);
		for (i = 0; i < userCount; i++) {
			fscanf(file,"%s", (users + i)->userName);
			fscanf(file,"%s", (users + i)->password);
			//printf("\nUser: %s Pass: %s", (users + i)->userName, (users + i)->password);
			//test code to ensure everything was imported correctly!

		}//for
		
		fclose(file);


	}//if theres a file

	//first we must read in the passwords


	i = 0;
	if (fileFound == 1) {
		//first get the username
		//no need to censor this
		printf("\nEnter Username: ");
		scanf("%s", name);
		//now get password

		puts("Enter password: ");

		while (1) {
			if (i < 0) {
				i = 0;

			}
			ch = getch();
			//gets the next character

			if (ch == '\r') {
				//if user hits enter
				break;

			}
			if (ch == '\b')
			{
				//if user tries to go back a space
				putch('\b');
				//go back
				putch(NULL);
				//set null
				putch('\b');
				//go back again
				//should be empty for another input

				i--;
				continue;
			}

			password[i++] = ch;
			//sets the password character at i and then moves along to the next
			ch = '*';
			putch(ch);
			//outputs the * to the screen
		}

		password[i] = '\0';
		//terminator to ensure the string ends correctly!
		//now check to see that they entered the right password
		//do it with a loop
		i = 0;
		while(i<userCount&&validUserYN!=1) {
			if (strcmp((users + i)->userName, name) == 0 && strcmp((users + i)->password, password) == 0) {
				validUserYN = 1;
				printf("\nWelcome! %s\n", (users + i)->userName);
				printf("\nLogging you in....\n");
			}
			i++;
		}//while

		//printf("\nPassword Entered : %s", password);
		//test code to ensure password filled up properly
		if (validUserYN == 0) {
			printf("\nInvalid Login\n");
		}
	}
	else {
		printf("\nCannot Find Password File. Guess you're out of luck!\n");
		printf("Comment out this function in the main code to bypass password system\n");
		printf("\nYes, I understand the irony of telling you how to bypass the password system in the password system\n");
		validUserYN = 999;

		
	}//no file

	return validUserYN;

}

void readFromFile(struct listelement** head_ptr){
	FILE *file = fopen("surveys.txt", "r");
	struct listelement *temp;
	int test = 0;
	
	

	if (file != NULL) {
		
		//read in the file
		//if the head is currently empty we must fill the head

		temp = (struct listelement*)malloc(sizeof(struct listelement));

		fscanf(file, "%d", &temp->survey.ppsn);
		fscanf(file, " %c", &temp->survey.gender);
		//space to ignore white space
		fscanf(file, "%s", temp->survey.firstName);
		fscanf(file, "%s", temp->survey.lastName);
		fscanf(file, "%s", temp->survey.address);
		fscanf(file, "%s", temp->survey.email);

		fscanf(file, "%d", &temp->survey.ageBracket);
		fscanf(file, "%d", &temp->survey.incomeBracket);
		fscanf(file, "%d", &temp->survey.exercise);
	
		fscanf(file, "%d", &temp->survey.alcoholIntake);
		fscanf(file, "%d", &temp->survey.cigaretteIntake);

		
			
		*head_ptr = temp;
		//make the head point at temp
		//this is the start of a list!
		fscanf(file, "%d", &test);
		if (test == -999) {
			temp->next = NULL;
		}
		//need to set nullpointer
		

			
	
		while (!feof(file)&&test!=-999) {
			temp->next = (struct listelement*)malloc(sizeof(struct listelement));
			temp = temp->next;
			//if its 0 its the first entry
			//if its -999 it shouldnt run this in the first place
			//anything else is a ppsn



			temp->survey.ppsn = test;
			//if we are still in the loop, then the "test" took in the ppsn, not -999
			
			fscanf(file, " %c", &temp->survey.gender); 
			//make sure space before c to ignore white space
			fscanf(file, "%s", temp->survey.firstName);
			fscanf(file, "%s", temp->survey.lastName);
			fscanf(file, "%s", temp->survey.address);
			fscanf(file, "%s", temp->survey.email);

			fscanf(file, "%d", &temp->survey.ageBracket);
			fscanf(file, "%d", &temp->survey.incomeBracket);
			fscanf(file, "%d", &temp->survey.exercise);

			fscanf(file, "%d", &temp->survey.alcoholIntake);
			fscanf(file, "%d", &temp->survey.cigaretteIntake);

			//while its not the end of the file
			

			temp->next = NULL;
			

			fscanf(file, "%d", &test);
			//testing the first part of the next line
			if (test == -999) {
				printf("\nSurvey List Populated from file!");
				return;
			}
			
				//sentinel eof
				//sees -999 it ends the while loop
				//otherwise it keeps going
			

		}
		fclose(file);
		printf("Surveys populated from \"surveys.txt\"\n");
	}
	else {
		printf("No Surveys in Database\n");
		//no file!
	}

}//read in function

void printToFile(struct listelement* head_ptr) {
	struct listelement* temp;
	int end = -999;
	int count = 0;
	FILE* file = fopen("surveys.txt", "w");
	if (file != NULL&&(getSurveyLength(head_ptr)>0)) {
		temp = head_ptr;
		while (temp != NULL) {
			//print out
			count++;
			fprintf(file,"%d ", temp->survey.ppsn);
			fprintf(file, "%c ", temp->survey.gender);
			fprintf(file, "%s ", temp->survey.firstName);
			fprintf(file, "%s ", temp->survey.lastName);
			fprintf(file, "%s ", temp->survey.address);
			fprintf(file, "%s ", temp->survey.email);
			fprintf(file, "%d ", temp->survey.ageBracket);
			fprintf(file, "%d ", temp->survey.incomeBracket);
			fprintf(file, "%d ", temp->survey.exercise);
		
			fprintf(file, "%d ", temp->survey.alcoholIntake);
			fprintf(file, "%d\n", temp->survey.cigaretteIntake);
			temp = temp->next;
			//move along
		
		}
		//place end of file sentinel
		fprintf(file, "%d\n", end);

		fclose(file);
		printf("\nSurveys printed to \"surveys.txt\".\n");
	}
	else if (file != NULL&&getSurveyLength(head_ptr) == 0) {
		//if the length of the survey list is 0
		fclose(file);
		remove("surveys.txt");
		printf("\nRemoved \"surveys.txt\" as there are no surveys\n");
	}
	

}//printToFile


void displayGenderStats(struct listelement* head_ptr) {
	//for each
	//increment a counter for the total
	//this will be used at the end
	//m or f
	//m non smoker 1/4
	//m smokers 3/4 - 75%
	//m smokers 20 2/4 50%
	FILE *report = fopen("surveyreport.txt", "a");
	char whichG[2][20] = { "Male","Female" };
	int i, j;
	double smokeData[2][4] = {0}; 
	double exerciseData[2][4] = { 0 };
	double alcoholData[2][4] = { 0 };
	double smokeStats[2][4] = {0};
	double exerciseStats[2][4] = { 0 };
	double alcoholStats[2][4] = { 0 };
	//refined stats
	//declare and initialise all to 0
	//store males in row 0
	//store females in row 1

	int males, females;
	double smokers[2] = {0};//need to get smokers for male and female
	double  gender[2] = { 0 };
	//store both genders
	males = 0;
	females = 0;
	struct listelement* temp;
	temp = head_ptr;
	while (temp != NULL) {
		//switch on the gender
		//used integers for others
		//must switch on a char in this case
		switch (temp->survey.gender) {
		case 'm':
			males++;
			//check smokeData
			smokeData[0][temp->survey.cigaretteIntake]++;
			exerciseData[0][temp->survey.exercise]++;
			alcoholData[0][temp->survey.alcoholIntake]++;
			//increments the integer of the appropriate value
			//if their smoke answer was 0. 0 0 will be incremented
			//i.e. one person dont smokes
			//if 1 then one person smokes less than 20

			break;
		case 'f':
			females++;
			smokeData[1][temp->survey.cigaretteIntake]++;
			exerciseData[1][temp->survey.exercise]++;
			alcoholData[1][temp->survey.alcoholIntake]++;
			//their intake and exercise etc are stored as integers from 0 - 4
			break;
		default:
			printf("\nError\n");
		}//switch
		//move along to the next list element
		temp = temp->next;
	}//while
	//once we've gotten all the values
	//TIME TO MAKE SOME STAAAAAAAAAAAATS
	//loop
	//fill the genders array
	gender[0] = males;
	gender[1] = females;
	for (i = 0; i < 2; i++) {
		//for each gender
		//i== gender
		//j is the field of answer
		//non smoker, less than 20 etc
		for (j = 0; j < 4; j++) {
			//4 fields in use
			//make sure we dont try to dive 0!
			if (gender[i] != 0) { 
				//if its 0 we don't need to add anything
				//should stay at 0
				if (smokeData[i][j] != 0)
					smokeStats[i][j] = (smokeData[i][j] / gender[i]) * 100;
				//if statement stops issues from dividing by 0
				//same for exercise
				if ( exerciseData[i][j] != 0)
					exerciseStats[i][j] = (exerciseData[i][j] / gender[i]) * 100;

				//same for alcohol
				if ( alcoholData[i][j] != 0)
					alcoholStats[i][j] = (alcoholData[i][j] / gender[i]) * 100;
			}


			
			
		}//for


		}
	//we want the % smokers
	//not % non smokers
	//replace non smoker stat with % smokers
	//get this by adding up the number of smokers
	for (i = 0; i < 2; i++) {
		//make sure the number isn't 0
		if (gender[i] != 0) {
			smokers[i] = smokeData[i][1] + smokeData[i][2] + smokeData[i][3];
			smokeStats[i][0] = (smokers[i] / gender[i])*100;
		}
		//the number of smokers over the gender count
		//we have replaced non smokers with smokers!
	}

		


	 //printing out in table form
	if (report != NULL) {
		printf("\n%% Gender Statistics\n");
		printf("\nSmoking Statistics\n");
		printf("\n%10s %8s %8s %8s %8s\n", "Gender", "Smoker", "<20", "<40", ">40");
		printf("==============================================\n");

		for (i = 0; i < 2; i++) {
			printf("%8s |", whichG[i]);
			//prints out left side
			for (j = 0; j < 4; j++) {
				printf("%8.1f%%", smokeStats[i][j]);

			}
			printf("\n");
		}//for

		printf("\nAlcohol Statistics\n");
		printf("\n%10s %8s %8s %8s %8s\n", "Gender", "None", "<2", "<4", ">4");
		printf("==============================================\n");
		for (i = 0; i < 2; i++) {
			printf("%8s |", whichG[i]);
			//prints out left side
			for (j = 0; j < 4; j++) {
				printf("%8.1f%%", alcoholStats[i][j]);

			}
			printf("\n");
		}//for

		printf("\nExercise Statistics per Week\n");
		printf("\n%10s %8s %8s %8s %8s\n", "Gender", "None", "<3", "<5", ">5");
		printf("==============================================\n");
		for (i = 0; i < 2; i++) {
			printf("%8s |", whichG[i]);
			//prints out left side
			for (j = 0; j < 4; j++) {
				printf("%8.1f%%", exerciseStats[i][j]);

			}
			printf("\n");
		}//for
		//now to file
		fprintf(report,"\n%% Gender Statistics\n");
		fprintf(report, "\nSmoking Statistics\n");
		fprintf(report,"==============================================\n");

		fprintf(report, "\n%10s %8s %8s %8s %8s\n", "Gender", "Smoker", "<20", "<40", ">40");

		for (i = 0; i < 2; i++) {
			fprintf(report, "%8s |", whichG[i]);
			//prints out left side
			for (j = 0; j < 4; j++) {
				fprintf(report, "%8.1f%%", smokeStats[i][j]);

			}
			fprintf(report, "\n");
		}//for

		fprintf(report, "\nAlcohol Statistics\n");
		fprintf(report, "\n%10s %8s %8s %8s %8s\n", "Gender", "None", "<2", "<4", ">4");
		fprintf(report, "==============================================\n");
		for (i = 0; i < 2; i++) {
			fprintf(report, "%8s |", whichG[i]);
			//prints out left side
			for (j = 0; j < 4; j++) {
				fprintf(report, "%8.1f%%", alcoholStats[i][j]);

			}
			fprintf(report, "\n");
		}//for

		fprintf(report, "\nExercise Statistics per Week\n");
		fprintf(report, "\n%10s %8s %8s %8s %8s\n", "Gender", "None", "<3", "<5", ">5");
		fprintf(report, "==============================================\n");
		for (i = 0; i < 2; i++) {
			fprintf(report, "%8s |", whichG[i]);
			//prints out left side
			for (j = 0; j < 4; j++) {
				fprintf(report, "%8.1f%%", exerciseStats[i][j]);

			}
			fprintf(report, "\n");
		}//for
		fclose(report);
	}//file



	//exercise alcohol cigs



}//gender

void displayAgeStats(struct listelement* head_ptr) {

	FILE *report = fopen("surveyreport.txt", "a");
	
	int i, j;
	double smokers[5] = { 0 };
	double smokeData[5][4] = { 0 };
	double exerciseData[5][4] = { 0 };
	double alcoholData[5][4] = { 0 };
	double smokeStats[5][4] = { 0 };
	double exerciseStats[5][4] = { 0 };
	double alcoholStats[5][4] = { 0 };

	double ageCounts[5] = {0};
	//this will store the counts of each age bracket

	struct listelement* temp;
	temp = head_ptr;
	while (temp != NULL) {
		//fill up the array
		//age bracket goes from 0 - 4
		//all the others go from 0-3
		//should line up nicely in the array
		ageCounts[temp->survey.ageBracket]++;
		//gets the count so the stats can be determined
		//sweet sweet percentages

		smokeData[temp->survey.ageBracket][temp->survey.cigaretteIntake]++;
		exerciseData[temp->survey.ageBracket][temp->survey.exercise]++;
		alcoholData[temp->survey.ageBracket][temp->survey.alcoholIntake]++;
		//there are 5 age brackets
		//each array has 5 rows and 4 columns
		//so exerciseData[2][3]
		//fall within the 21-30 range, and exercise more than 5 times a week
		//increment this
		//when calculating the stats
		//we take this number /the total number of people in this range * 100


		temp = temp->next;
		//move along the list
	}//while

	//now to get those stats
	for (i = 0; i < 5; i++) {
		//5 age brackets
		for (j = 0; j < 4; j++) {
			//4 for each survey field
			//make sure nothing is 0 and all that
			if (ageCounts[i] != 0) {
				if (smokeData[i][j] != 0)
					smokeStats[i][j] = (smokeData[i][j] / ageCounts[i]) * 100;

				//same for exercise
				if (exerciseData[i][j] != 0)
					exerciseStats[i][j] = (exerciseData[i][j] / ageCounts[i]) * 100;

				//same for alcohol
				if (alcoholData[i][j] != 0)
					alcoholStats[i][j] = (alcoholData[i][j] / ageCounts[i]) * 100;
			}//there is a count


		}// forsurvey options i.e. never less than x,y,z
	}//for agebrackets

	//replace non smoker array data with smoker array data
	for (i = 0; i < 5; i++) {
		if (ageCounts[i] != 0) {
			smokers[i] = smokeData[i][1] + smokeData[i][2] + smokeData[i][3];
			smokeStats[i][0] = (smokers[i] / ageCounts[i])*100;
		}
		//the number of smokers over the gender count
		//we have replaced non smokers with smokers!
	}




	 //printing out in table form
	printf("\n%% Age Bracket Statistics\n");
	printf("\nSmoking Statistics\n");
	printf("\n%10s %8s %8s %8s %8s\n", "Age", "Smoker", "<20", "<40", ">40");
	printf("==============================================\n");

	for (i = 0; i < 5; i++) {
		printf("%8s |", ageDemo[i]);
		//prints out left side
		for (j = 0; j < 4; j++) {
			printf("%8.1f%%", smokeStats[i][j]);

		}
		printf("\n");
	}//for

	printf("\nAlcohol Statistics\n");
	printf("\n%10s %8s %8s %8s %8s\n", "Age", "None", "<2", "<4", ">4");
	printf("==============================================\n");
	for (i = 0; i < 5; i++) {
		printf("%8s |", ageDemo[i]);
		//prints out left side
		for (j = 0; j < 4; j++) {
			printf("%8.1f%%", alcoholStats[i][j]);

		}
		printf("\n");
	}//for

	printf("\nExercise Statistics per Week\n");
	printf("\n%10s %8s %8s %8s %8s\n", "Age", "None", "<3", "<5", ">5");
	printf("==============================================\n");
	for (i = 0; i < 5; i++) {
		printf("%8s |", ageDemo[i]);
		//prints out left side
		for (j = 0; j < 4; j++) {
			printf("%8.1f%%", exerciseStats[i][j]);

		}
		printf("\n");
	}//for

	//now to file
	if (report != NULL) {
		fprintf(report,"\n%% Age Bracket Statistics\n");
		fprintf(report, "\nSmoking Statistics\n");
		fprintf(report, "\n%10s %8s %8s %8s %8s\n", "Age", "Smoker", "<20", "<40", ">40");
		fprintf(report, "==============================================\n");

		for (i = 0; i < 5; i++) {
			fprintf(report, "%8s |", ageDemo[i]);
			//prints out left side
			for (j = 0; j < 4; j++) {
				fprintf(report, "%8.1f%%", smokeStats[i][j]);

			}
			fprintf(report, "\n");
		}//for

		fprintf(report, "\nAlcohol Statistics\n");
		fprintf(report, "\n%10s %8s %8s %8s %8s\n", "Age", "None", "<2", "<4", ">4");
		fprintf(report, "==============================================\n");
		for (i = 0; i < 5; i++) {
			fprintf(report, "%8s |", ageDemo[i]);
			//prints out left side
			for (j = 0; j < 4; j++) {
				fprintf(report, "%8.1f%%", alcoholStats[i][j]);

			}
			fprintf(report, "\n");
		}//for

		fprintf(report, "\nExercise Statistics per Week\n");
		fprintf(report, "\n%10s %8s %8s %8s %8s\n", "Age", "None", "<3", "<5", ">5");
		fprintf(report, "==============================================\n");
		for (i = 0; i < 5; i++) {
			fprintf(report, "%8s |", ageDemo[i]);
			//prints out left side
			for (j = 0; j < 4; j++) {
				fprintf(report, "%8.1f%%", exerciseStats[i][j]);

			}
			fprintf(report, "\n");
		}//for
		fclose(report);
	}

}//display age statistics

void displayIncomeStats(struct listelement* head_ptr) {

	FILE *report = fopen("surveyreport.txt", "a");

	int i, j;
	double smokers[7] = { 0 };
	char message[50] = "No Income";
	double smokeData[7][4] = { 0 };
	double exerciseData[7][4] = { 0 };
	double alcoholData[7][4] = { 0 };
	double smokeStats[7][4] = { 0 };
	double exerciseStats[7][4] = { 0 };
	double alcoholStats[7][4] = { 0 };

	double incomeCounts[7] = { 0 };
	//this will store the counts of each income bracket

	struct listelement* temp;

	temp = head_ptr;
	while (temp != NULL) {
		//fill up the array
		//income bracket goes from 0 - 7
		//all the others go from 0-3
		//should line up nicely in the array
		incomeCounts[temp->survey.incomeBracket]++;
		//gets the count so the stats can be determined
	

		smokeData[temp->survey.incomeBracket][temp->survey.cigaretteIntake]++;
		exerciseData[temp->survey.incomeBracket][temp->survey.exercise]++;
		alcoholData[temp->survey.incomeBracket][temp->survey.alcoholIntake]++;
		//income bracket is 0-6
		//questions are 0-3
		//so if someone makes no money and isn't a smoker it will increment smokeData[0][0]
		//exerciseData[0] [theiranswer]

		temp = temp->next;
		//move along the list
	}//while


	 //now to get those stats
	for (i = 0; i < 7; i++) {
		//7 income brackets
		for (j = 0; j < 4; j++) {
			//4 for each survey field
			//make sure nothing is 0 and all that
			if (incomeCounts[i] != 0) {
				if (smokeData[i][j] != 0)
					smokeStats[i][j] = (smokeData[i][j] / incomeCounts[i]) * 100;

				//same for exercise
				if (exerciseData[i][j] != 0)
					exerciseStats[i][j] = (exerciseData[i][j] / incomeCounts[i]) * 100;

				//same for alcohol
				if (alcoholData[i][j] != 0)
					alcoholStats[i][j] = (alcoholData[i][j] / incomeCounts[i]) * 100;
			}//there is a count


		}// forsurvey options i.e. never less than x,y,z
	}//for incomebrackets

	 //replace non smoker array data with smoker array data
	for (i = 0; i < 7; i++) {
		if (incomeCounts[i] != 0) {
			//can't divide by 0

			smokers[i] = smokeData[i][1] + smokeData[i][2] + smokeData[i][3];
			//add up all the smokers
			smokeStats[i][0] = (smokers[i] / incomeCounts[i])*100;
		}
		//the number of smokers over the gender count
		//we have replaced non smokers with smokers!
	}

	printf("\nStatistics by Income Bracket\n");

	//printing out in table form
	printf("\n%% Income Bracket Statistics\n");
	printf("\nSmoking Statistics\n");
	printf("\n%11s %8s %8s %8s %8s\n", "Income", "Smoker", "<20", "<40", ">40");
	printf("===============================================\n");

	for (i = 0; i < 7; i++) {
		if (i == 0)
			printf("%9d |", incomeBracket[i]);
		else if (i<6)
			printf("<%8d |", incomeBracket[i]);
		else
			printf(">%8d |", incomeBracket[i]);


		//prints out left side
		for (j = 0; j < 4; j++) {
			printf("%8.1f%%", smokeStats[i][j]);

		}
		printf("\n");
	}//for

	printf("\nAlcohol Statistics\n");
	printf("\n%11s %8s %8s %8s %8s\n", "Income", "None", "<2", "<4", ">4");
	printf("===============================================\n");
	for (i = 0; i < 7; i++) {
		if (i == 0)
			printf("%9d |", incomeBracket[i]);
		else if (i<6)
			printf("<%8d |", incomeBracket[i]);
		else
			printf(">%8d |", incomeBracket[i]);
		//prints out left side
		for (j = 0; j < 4; j++) {
			printf("%8.1f%%", alcoholStats[i][j]);

		}
		printf("\n");
	}//for

	printf("\nExercise Statistics per Week\n");
	printf("\n%11s %8s %8s %8s %8s\n", "Income", "None", "<3", "<5", ">5");
	printf("===============================================\n");
	for (i = 0; i < 7; i++) {
		if (i == 0)
			printf("%9d |", incomeBracket[i]);
		else if (i<6)
			printf("<%8d |", incomeBracket[i]);
		else
			printf(">%8d |", incomeBracket[i]);
		//prints out left side
		for (j = 0; j < 4; j++) {
			printf("%8.1f%%", exerciseStats[i][j]);

		}
		printf("\n");
	}//for
	//now to file
	if (report != NULL) {

		fprintf(report,"\n%% Income Bracket Statistics\n");
		fprintf(report, "\nSmoking Statistics\n");
		fprintf(report, "\n%11s %8s %8s %8s %8s\n", "Income", "Smoker", "<20", "<40", ">40");
		fprintf(report, "===============================================\n");

		for (i = 0; i < 7; i++) {
			if (i == 0)
				fprintf(report, "%9d |", incomeBracket[i]);
			else if (i<6)
				fprintf(report, "<%8d |", incomeBracket[i]);
			else
				fprintf(report, ">%8d |", incomeBracket[i]);


			//prints out left side
			for (j = 0; j < 4; j++) {
				fprintf(report, "%8.1f%%", smokeStats[i][j]);

			}
			fprintf(report, "\n");
		}//for

		fprintf(report, "\nAlcohol Statistics\n");
		fprintf(report, "\n%11s %8s %8s %8s %8s\n", "Income", "None", "<2", "<4", ">4");
		fprintf(report, "===============================================\n");
		for (i = 0; i < 2; i++) {
			if (i == 0)
				fprintf(report, "%9d |", incomeBracket[i]);
			else if (i<6)
				fprintf(report, "<%8d |", incomeBracket[i]);
			else
				fprintf(report, ">%8d |", incomeBracket[i]);
			//prints out left side
			for (j = 0; j < 4; j++) {
				fprintf(report, "%8.1f%%", alcoholStats[i][j]);

			}
			fprintf(report, "\n");
		}//for

		fprintf(report, "\nExercise Statistics per Week\n");
		fprintf(report, "\n%11s %8s %8s %8s %8s\n", "Income", "None", "<3", "<5", ">5");
		fprintf(report, "===============================================\n");
		for (i = 0; i < 7; i++) {
			if (i == 0)
				fprintf(report, "%9d |", incomeBracket[i]);
			else if (i<6)
				fprintf(report, "<%8d |", incomeBracket[i]);
			else
				fprintf(report, ">%8d |", incomeBracket[i]);
			//prints out left side
			for (j = 0; j < 4; j++) {
				fprintf(report, "%8.1f%%", exerciseStats[i][j]);

			}
			fprintf(report, "\n");
		}//for

		fclose(report);
	}

}//function

void printReport(struct listelement* head_ptr) {
	
	printAllSurveysReport(head_ptr);
	//prints all surveys currently in the database before printing stats
	displayGenderStats(head_ptr);
	displayAgeStats(head_ptr);
	displayIncomeStats(head_ptr);
	printf("\nReport File Created!\n");


}

int getSurveyLength(struct listelement* head_ptr) {
	int count = 0;
	struct listelement* temp;
	temp = head_ptr;
	while (temp != NULL) {
		count++;
		temp = temp->next;
		//get the count
	}
	return count;

}



