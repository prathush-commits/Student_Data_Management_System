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


/*---------------------------------------------------------
                Search Student
---------------------------------------------------------*/

void searchStudent()
{
    STUDENT *temp;
    int choice;
    int roll;
    char name[50];
    int found = 0;

    if(head == NULL)
    {
        printf("\nNo Records Found...\n");
        return;
    }

    printf("\nSearch Student By");
    printf("\n1. Roll Number");
    printf("\n2. Name");
    printf("\nEnter Choice : ");
    scanf("%d",&choice);

    temp = head;

    switch(choice)
    {
        case 1:

            printf("\nEnter Roll Number : ");
            scanf("%d",&roll);

            while(temp != NULL)
            {
                if(temp->rollNo == roll)
                {
                    printf("\nStudent Found\n");

                    printf("\nRoll No     : %d",temp->rollNo);
                    printf("\nName        : %s",temp->name);
                    printf("\nPercentage  : %.2f\n",temp->percentage);

                    found = 1;
                    break;
                }

                temp = temp->next;
            }

            break;

        case 2:

            printf("\nEnter Name : ");
            scanf("%49s",name);

            while(temp != NULL)
            {
                if(strcmp(temp->name,name)==0)
                {
                    printf("\nStudent Found\n");

                    printf("\nRoll No     : %d",temp->rollNo);
                    printf("\nName        : %s",temp->name);
                    printf("\nPercentage  : %.2f\n",temp->percentage);

                    found = 1;
                }

                temp = temp->next;
            }

            break;

        default:

            printf("\nInvalid Choice...\n");
            return;
    }

    if(found == 0)
    {
        printf("\nStudent Not Found...\n");
    }
}

/*---------------------------------------------------------
                Modify Student
---------------------------------------------------------*/

void modifyStudent()
{
    STUDENT *temp;
    int roll;
    int found = 0;

    if(head == NULL)
    {
        printf("\nNo Student Records Found...\n");
        return;
    }

    printf("\nEnter Roll Number to Modify : ");
    scanf("%d",&roll);

    temp = head;

    while(temp != NULL)
    {
        if(temp->rollNo == roll)
        {
            found = 1;

            printf("\nCurrent Details");
            printf("\n---------------------------");
            printf("\nRoll No    : %d",temp->rollNo);
            printf("\nName       : %s",temp->name);
            printf("\nPercentage : %.2f\n",temp->percentage);

            printf("\nEnter New Name : ");
            scanf("%49s",temp->name);

            printf("Enter New Percentage : ");
            scanf("%f",&temp->percentage);

            printf("\nStudent Record Updated Successfully...\n");

            return;
        }

        temp = temp->next;
    }

    if(found == 0)
    {
        printf("\nRoll Number Not Found...\n");
    }
}


/*---------------------------------------------------------
                Delete Student
---------------------------------------------------------*/

void deleteStudent()
{
    STUDENT *temp;
    STUDENT *prev;

    int roll;

    if(head == NULL)
    {
        printf("\nNo Student Records Found...\n");
        return;
    }

    printf("\nEnter Roll Number to Delete : ");
    scanf("%d",&roll);

    temp = head;
    prev = NULL;

    while(temp != NULL)
    {
        if(temp->rollNo == roll)
        {
            if(temp == head)
            {
                head = head->next;
            }
            else
            {
                prev->next = temp->next;
            }

            free(temp);

            printf("\nStudent Deleted Successfully...\n");

            return;
        }

        prev = temp;
        temp = temp->next;
    }

    printf("\nRoll Number Not Found...\n");
}







