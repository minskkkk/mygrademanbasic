// Grade management system
// Add the Linked List Data Structure
//
// Editted by Minseok Song (2025.01.07)
// Last modified by Minseok Song (2025.01.07 18:49)

#include <stdio.h>
#include <memory.h>
#include <stdlib.h>
#include <string.h>
#include "MyGradeManBasic_linked_list.h"

int main(void)
{
    Run();
 
    return 0;
}

void Run()
{
    int key = 0;
    Student_h* L=CreateStudent_h(); // Initialize the head node
    while ((key = SelectMenu()) != 0)	// Repear if menu is not 0 
    {
        switch (key)			// Select key
        {
        case 1: AddStudent(L); break;
        case 2: RemoveStudent(L); break;
        case 3: FindStudent(L); break;
        case 4: printList(L); break;
        default: printf("Wrong selected.\n"); break;
        }
    }
    freeStudent_h(L);
    printf("Program exit\n");
}
 
int SelectMenu()
{
    int key = 0;
    printf("\n-----------------------------\n");
    printf("Grade management program.\n");
    printf("1: Add student data.   2: Remove student data.  3: Find student.   4: Show list.    0: Quit \n");
    scanf("%d", &key);
    return key;
}

void AddStudent(Student_h* L)
{
    // declare variables for student data
    int num = 0;
    char name[MAX_NLEN + 1];
    int scores[MAX_SUBJECT];
    int s;

    printf("ID number to add: ");
    scanf("%d", &num);
 
    if (IsAvailNum(L, num) == 0)		// Cheak if the ID is vaild and not in use
    {
        printf("Invalid ID number.\n");
        return;
    }

    // Collect student data
    printf("Name: ");
    scanf("%s", name);
 
    for (s = 0; s<MAX_SUBJECT; s++)
    {
        printf("%s Score:", stitles[s]);
        scanf("%d", &scores[s]);
 
        if (IsAvailScore(scores[s]) == 0)    // Check if the score is valid
        {
            scores[s] = -1;
            printf("Invalid score. %s score is not added.\n", stitles[s]);
        }
    }

    insertLastNode(L, name, num, scores); //Add student data to the linked list
    printf("Student added successfully.\n");
}

int IsAvailNum(Student_h* L,int num) //check if the student ID is valid
{
        if (num <= 0) {
        return 0;
    }
    if (searchNode(L, num) != NULL) {
        printf("ID already exists.\n");
        return 0;
    }
    return 1;
}

int IsAvailScore(int score)
{
    return (score >= 0) && (score <= 100);
}

void RemoveStudent(Student_h* L) //Remove student data
{
    int num;
    printf("ID number to remove");
    scanf("%d", &num);

    if (searchNode(L,num)==NULL){ //Check if the student exists
        printf("Student does not exitst.\n");
        return;
    }

    deleteNode(L,num); // Remove student data
}

void FindStudent(Student_h* L) //Search student data
{
    int num = 0;
 
    printf("ID number to find: ");
    scanf("%d", &num);


    Student *stu = searchNode(L,num);
    if (stu == NULL) //if student is not found
    {
        printf("Student does not exist.\n");
        return;
    }

    printf("ID: %d, Name: %s\n", stu->num, stu->name); //Print student data
    for (int i = 0; i<MAX_SUBJECT; i++)
    {
        printf("%s: %d\n", stitles[i], stu->scores[i]);
    }
}

Student_h* CreateStudent_h(void) //Create and initialize the head node
{
    Student_h* L;
    L = (Student_h*)malloc(sizeof(Student_h));
    L->head = NULL;
    return L;
}

void freeStudent_h(Student_h* L) //Free the memory of the linked list
{
    Student* p;
    while (L->head != NULL)
    {
        p = L->head;
        L->head = L->head->link;
        free(p);
        p=NULL;
    }
    free(L);
}

void printList(Student_h* L) //Print the linked list
{
    Student* p;
    printf("ID Name Korean English Math\n");
    for (p = L->head; p != NULL; p = p->link)
    {
        printf("%d %s %d %d %d\n", p->num, p->name, p->scores[0], p->scores[1], p->scores[2]);
    }
}

void insertLastNode(Student_h* L, char* name, int num, int* scores) //Add a student node to the end of the linked list
{
    Student* newnode; //create a new node
    Student* p;
    newnode = (Student*)malloc(sizeof(Student));

    //initialize the new node
    strcpy(newnode->name, name);
    newnode->num = num;
    newnode->scores[0] = scores[0];
    newnode->scores[1] = scores[1];
    newnode->scores[2] = scores[2];
    newnode->link = NULL;

    if (L->head == NULL) //if the list is empty
    {
        L->head = newnode;
        return;
    }

    p = L->head; // if the list isn't empty
    while (p->link != NULL)
    {
        p = p->link;
    }
    p->link = newnode;
}

void deleteNode(Student_h* L, int num) //remove a student node
{
    Student* current = L->head;
    Student* pre = NULL;

    while (current !=NULL){
        if (current->num == num){
            if (pre == NULL){
                L->head = current->link;
        }else{
            pre->link = current->link;
        }
        free(current);
        return;
    }
    pre=current;
    current=current->link;
    }
    printf("Removed.\n");
}

Student* searchNode(Student_h* L, int num)
{
    Student* p;
    for (p = L->head; p != NULL; p = p->link)
    {
        if (p->num == num)
        {
            return p;
        }
    }
    return NULL;
}

/* The following functions are not used in this program

void insertFirstNode(Student_h* L, char* name, int num, int* scores)
{
    Student* newnode;
    newnode = (Student*)malloc(sizeof(Student));
    strcpy(newnode->name, name);
    newnode->num = num;
    newnode->scores[0] = scores[0];
    newnode->scores[1] = scores[1];
    newnode->scores[2] = scores[2];
    newnode->link = L->head;
    L->head = newnode;
}

void insertMiddleNode(Student_h* L, Student* pre, char* name, int num, int* scores)
{
    Student* newnode;
    newnode = (Student*)malloc(sizeof(Student));
    strcpy(newnode->name, name);
    newnode->num = num;
    newnode->scores[0] = scores[0];
    newnode->scores[1] = scores[1];
    newnode->scores[2] = scores[2];
    newnode->link = pre->link;
    pre->link = newnode;
}
*/
