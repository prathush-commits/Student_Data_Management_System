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




/*---------------------------------------------------------
                Generate Roll Number
---------------------------------------------------------*/

int generateRollNumber()
{
    int roll = 1;
    STUDENT *temp;

    while(1)
    {
        int found = 0;

        temp = head;

        while(temp != NULL)
        {
            if(temp->rollNo == roll)
            {
                found = 1;
                break;
            }

            temp = temp->next;
        }

        if(found == 0)
            return roll;

        roll++;
    }
}

/*---------------------------------------------------------
                Add Student
---------------------------------------------------------*/

void addStudent()
{
    STUDENT *newNode;
    STUDENT *temp;

    newNode = (STUDENT *)malloc(sizeof(STUDENT));

    if(newNode == NULL)
    {
        printf("\nMemory Allocation Failed...\n");
        return;
    }

    newNode->rollNo = generateRollNumber();

    printf("\nAssigned Roll Number : %d", newNode->rollNo);

    printf("\nEnter Student Name : ");
    scanf("%49s", newNode->name);

    printf("Enter Percentage : ");
    scanf("%f", &newNode->percentage);

    newNode->next = NULL;

    if(head == NULL)
    {
        head = newNode;
    }
    else
    {
        temp = head;

        while(temp->next != NULL)
            temp = temp->next;

        temp->next = newNode;
    }

    printf("\nStudent Added Successfully...\n");
}


/*---------------------------------------------------------
                Display Students
---------------------------------------------------------*/

void displayStudents()
{
    STUDENT *temp;

    if(head == NULL)
    {
        printf("\nNo Student Records Found...\n");
        return;
    }

    temp = head;

    printf("\n=========================================================\n");
    printf("%-10s %-25s %-10s\n","Roll No","Name","Percentage");
    printf("=========================================================\n");

    while(temp != NULL)
    {
        printf("%-10d %-25s %-10.2f\n",
                temp->rollNo,
                temp->name,
                temp->percentage);

        temp = temp->next;
    }

    printf("=========================================================\n");
}








