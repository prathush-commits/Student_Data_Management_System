/*=========================================================
        STUDENT DATA MANAGEMENT SYSTEM
        Developed by : Prathush H
        Language     : C
=========================================================*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*---------------- Student Structure ----------------*/

typedef struct student
{
    int rollNo;
    char name[50];
    float percentage;
    struct student *next;
}STUDENT;

/*---------------- Global Pointer ----------------*/

STUDENT *head = NULL;

/*---------------- Function Prototypes ----------------*/

void menu();
void addStudent();
void displayStudents();
void searchStudent();
void deleteStudent();
void modifyStudent();
void saveToFile();
void loadFromFile();
void sortStudents();
void reverseList();
void deleteAllStudents();
int generateRollNumber();

/*---------------- Main Function ----------------*/

int main()
{
    loadFromFile();

    menu();

    return 0;
}

/*---------------- Menu Function ----------------*/

void menu()
{
    int choice;

    while(1)
    {
        printf("\n============================================");
        printf("\n     STUDENT DATA MANAGEMENT SYSTEM");
        printf("\n============================================");

        printf("\n1. Add Student");
        printf("\n2. Display Students");
        printf("\n3. Search Student");
        printf("\n4. Modify Student");
        printf("\n5. Delete Student");
        printf("\n6. Sort Students");
        printf("\n7. Reverse List");
        printf("\n8. Save Records");
        printf("\n9. Load Records");
        printf("\n10. Delete All Records");
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
                deleteAllStudents();
                break;

            case 0:
                saveToFile();
                printf("\nThank You...\n");
                exit(0);

            default:
                printf("\nInvalid Choice...\n");
        }
    }
}
