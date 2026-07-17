/*=========================================================
        STUDENT DATA MANAGEMENT SYSTEM
-----------------------------------------------------------
Author      : Prathush H
Language    : C
Concepts    : Structures, Linked List, File Handling,
              Searching, Sorting, Dynamic Memory
=========================================================*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*---------------------------------------------------------
                Student Structure
---------------------------------------------------------*/

typedef struct student
{
    int rollNo;
    char name[50];
    float percentage;

    struct student *next;

} STUDENT;

/*---------------------------------------------------------
                Global Pointer
---------------------------------------------------------*/

STUDENT *head = NULL;

/*---------------------------------------------------------
            Function Prototypes
---------------------------------------------------------*/

void menu();

int generateRollNumber();

void addStudent();
void displayStudents();
void searchStudent();
void modifyStudent();
void deleteStudent();

void sortStudents();
void reverseList();

void saveToFile();
void loadFromFile();

void deleteAllStudents();

void countStudents();
void highestPercentage();
void lowestPercentage();
void averagePercentage();

/*---------------------------------------------------------
                    MAIN
---------------------------------------------------------*/

int main()
{
    loadFromFile();

    menu();

    return 0;
}

/*---------------------------------------------------------
                    MENU
---------------------------------------------------------*/

void menu()
{
    int choice;

    while(1)
    {
        printf("\n\n==========================================");
        printf("\n   STUDENT DATA MANAGEMENT SYSTEM");
        printf("\n==========================================");

        printf("\n1.  Add Student");
        printf("\n2.  Display Students");
        printf("\n3.  Search Student");
        printf("\n4.  Modify Student");
        printf("\n5.  Delete Student");

        printf("\n6.  Sort Students");
        printf("\n7.  Reverse List");

        printf("\n8.  Save Records");
        printf("\n9.  Load Records");

        printf("\n10. Count Students");
        printf("\n11. Highest Percentage");
        printf("\n12. Lowest Percentage");
        printf("\n13. Average Percentage");

        printf("\n14. Delete All Records");

        printf("\n0. Exit");

        printf("\n\nEnter Choice : ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                addStudent();
                break;

            case 2:
                displayStudents();
                break;

            case 3:
                searchStudent();
                break;

            case 4:
                modifyStudent();
                break;

            case 5:
                deleteStudent();
                break;

            case 6:
                sortStudents();
                break;

            case 7:
                reverseList();
                break;

            case 8:
                saveToFile();
                break;

            case 9:
                loadFromFile();
                break;

            case 10:
                countStudents();
                break;

            case 11:
                highestPercentage();
                break;

            case 12:
                lowestPercentage();
                break;

            case 13:
                averagePercentage();
                break;

            case 14:
                deleteAllStudents();
                break;

            case 0:

                saveToFile();

                printf("\n\nThank You...\n");

                exit(0);

            default:

                printf("\nInvalid Choice...\n");
        }
    }
}
