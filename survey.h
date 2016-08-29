#ifndef SURVEY_H
#define SURVEY_H
//includes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Mark Grimes
//Advanced Procedural Programming
//Survey System header file
//g00289916

//survey structure
typedef struct {
	int ppsn;
	char gender;
	char firstName[25];
	char lastName[25];
	char address[40];
	char email[40];
	//store survey details as ints
	//used in tandem with char arrays to display to user
	//for example, age bracket 1 means 18-20, 2 means 20-30

	int ageBracket;
	int incomeBracket;
	int exercise;
	int alcoholIntake;
	int cigaretteIntake;




}survey_t;

typedef struct {
	char userName[30];
	char password[30];

}user_t;

struct listelement{
	survey_t survey;
	struct listelement* next;

};

//function declerations
char setGender();
int setAgeBracket();
int setIncome();
int setExercise();
int setAlcohol();
int setCig();

int searchPPSN(struct listelement* head_ptr, int ppsn);
void displayName(struct listelement* head_ptr);
void displayPPSN(struct listelement* head_ptr);
//redundant

void addSurvey(struct listelement** head_ptr);
//done

void displayAll(struct listelement* head_ptr);
//need to add some correllation
//done

void displaySurvey(struct listelement* head_ptr);
//done

void updateSurvey(struct listelement** head_ptr);
void updateByPPSN(struct listelement** head_ptr);
void updateByName(struct listelement** head_ptr);
//done
void deleteSurvey(struct listelement** head_ptr);
//done

int passwordCheck();
//6char
//done

void printToFile(struct listelement* head_ptr);
//done
void readFromFile(struct listelement** head_ptr);
//done

void printReport(struct listelement* head_ptr);

int validateEmail(char* address);
//done
//statistics
//field is Age, Income or Gender
//demo refers to 18-20, M or F etc
void printAllSurveysReport(struct listelement* head_ptr);

void displayGenderStats(struct listelement* head_ptr);

//done 

void displayAgeStats(struct listelement* head_ptr);
//done 

void displayIncomeStats(struct listelement* head_ptr);
//done

int getSurveyLength(struct listelement* head_ptr);


//print all survey details to file?


#endif