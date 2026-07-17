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


/*---------------------------------------------------------
                Save Records to File
---------------------------------------------------------*/

void saveToFile()
{
    FILE *fp;
    STUDENT *temp;

    fp = fopen("student.dat","wb");

    if(fp == NULL)
    {
        printf("\nUnable to Open File...\n");
        return;
    }

    temp = head;

    while(temp != NULL)
    {
        fwrite(temp,sizeof(STUDENT),1,fp);
        temp = temp->next;
    }

    fclose(fp);

    printf("\nRecords Saved Successfully...\n");
}


/*---------------------------------------------------------
                Load Records from File
---------------------------------------------------------*/

void loadFromFile()
{
    FILE *fp;
    STUDENT *newNode;
    STUDENT *temp;

    fp = fopen("student.dat","rb");

    if(fp == NULL)
        return;

    while(1)
    {
        newNode = (STUDENT *)malloc(sizeof(STUDENT));

        if(newNode == NULL)
            break;

        if(fread(newNode,sizeof(STUDENT),1,fp) != 1)
        {
            free(newNode);
            break;
        }

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
    }

    fclose(fp);
}


/*---------------------------------------------------------
                Sort Students
---------------------------------------------------------*/

void sortStudents()
{
    STUDENT *p1,*p2;

    int choice;
    int roll;
    char name[50];
    float percentage;

    if(head == NULL || head->next == NULL)
    {
        printf("\nNot Enough Records...\n");
        return;
    }

    printf("\nSort By");
    printf("\n1. Name");
    printf("\n2. Percentage");
    printf("\nEnter Choice : ");
    scanf("%d",&choice);

    if(choice == 1)
    {
        for(p1=head;p1!=NULL;p1=p1->next)
        {
            for(p2=p1->next;p2!=NULL;p2=p2->next)
            {
                if(strcmp(p1->name,p2->name)>0)
                {
                    roll = p1->rollNo;
                    p1->rollNo = p2->rollNo;
                    p2->rollNo = roll;

                    strcpy(name,p1->name);
                    strcpy(p1->name,p2->name);
                    strcpy(p2->name,name);

                    percentage = p1->percentage;
                    p1->percentage = p2->percentage;
                    p2->percentage = percentage;
                }
            }
        }

        printf("\nSorted By Name Successfully...\n");
    }
    else if(choice == 2)
    {
        for(p1=head;p1!=NULL;p1=p1->next)
        {
            for(p2=p1->next;p2!=NULL;p2=p2->next)
            {
                if(p1->percentage > p2->percentage)
                {
                    roll = p1->rollNo;
                    p1->rollNo = p2->rollNo;
                    p2->rollNo = roll;

                    strcpy(name,p1->name);
                    strcpy(p1->name,p2->name);
                    strcpy(p2->name,name);

                    percentage = p1->percentage;
                    p1->percentage = p2->percentage;
                    p2->percentage = percentage;
                }
            }
        }

        printf("\nSorted Successfully...\n");
    }
    else
    {
        printf("\nInvalid Choice...\n");
    }
}

/*---------------------------------------------------------
                Reverse Linked List
---------------------------------------------------------*/

void reverseList()
{
    STUDENT *prev = NULL;
    STUDENT *current = head;
    STUDENT *next;

    if(head == NULL)
    {
        printf("\nNo Records Found...\n");
        return;
    }

    while(current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    head = prev;

    printf("\nLinked List Reversed Successfully...\n");
}

/*---------------------------------------------------------
                Count Students
---------------------------------------------------------*/

void countStudents()
{
    STUDENT *temp = head;
    int count = 0;

    while(temp != NULL)
    {
        count++;
        temp = temp->next;
    }

    printf("\nTotal Students : %d\n", count);
}
/*---------------------------------------------------------
                Highest Percentage
---------------------------------------------------------*/

/*---------------------------------------------------------
                Highest Percentage
---------------------------------------------------------*/

void highestPercentage()
{
    STUDENT *temp;
    STUDENT *highest;

    if(head == NULL)
    {
        printf("\nNo Records Found...\n");
        return;
    }

    highest = head;
    temp = head->next;

    while(temp != NULL)
    {
        if(temp->percentage > highest->percentage)
        {
            highest = temp;
        }

        temp = temp->next;
    }

    printf("\nHighest Percentage Student");
    printf("\n--------------------------");
    printf("\nRoll No    : %d", highest->rollNo);
    printf("\nName       : %s", highest->name);
    printf("\nPercentage : %.2f\n", highest->percentage);
}

/*---------------------------------------------------------
                Lowest Percentage
---------------------------------------------------------*/

/*---------------------------------------------------------
                Lowest Percentage
---------------------------------------------------------*/

void lowestPercentage()
{
    STUDENT *temp;
    STUDENT *lowest;

    if(head == NULL)
    {
        printf("\nNo Records Found...\n");
        return;
    }

    lowest = head;
    temp = head->next;

    while(temp != NULL)
    {
        if(temp->percentage < lowest->percentage)
        {
            lowest = temp;
        }

        temp = temp->next;
    }

    printf("\nLowest Percentage Student");
    printf("\n-------------------------");
    printf("\nRoll No    : %d", lowest->rollNo);
    printf("\nName       : %s", lowest->name);
    printf("\nPercentage : %.2f\n", lowest->percentage);
}
/*---------------------------------------------------------
                Average Percentage
---------------------------------------------------------*/

void averagePercentage()
{
    STUDENT *temp;
    float sum = 0;
    int count = 0;

    if(head == NULL)
    {
        printf("\nNo Records Found...\n");
        return;
    }

    temp = head;

    while(temp != NULL)
    {
        sum += temp->percentage;
        count++;
        temp = temp->next;
    }

    printf("\nAverage Percentage : %.2f\n", sum / count);
}
/*---------------------------------------------------------
                Delete All Students
---------------------------------------------------------*/

void deleteAllStudents()
{
    STUDENT *temp;

    while(head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp);
    }

    printf("\nAll Student Records Deleted Successfully...\n");
}




