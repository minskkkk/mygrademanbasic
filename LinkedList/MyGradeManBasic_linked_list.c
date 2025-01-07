// Grade management system
// ID indicates array index (1,2,..,MAX_STUDENT-1)
// Global variable : Structure array
// Max number of students are fixed
// 
// Editted by Minseok Song (2025.01.07)
// Add the Linked List functions

#include <stdio.h>
#include <memory.h>
#include <stdlib.h>
#include <string.h>
#include "MyGradeManBasic_liked_list.h"
 
void Initialize();		// Initialize student data
void Run();

int main(void)
{
    Initialize(); 
    Run();
 
    return 0;
}
 
 
void Initialize()
{
    int i = 0;
    int s = 0;
 
    for (i = 0; i<MAX_STUDENT; i++)
    {
        for (s = 0; s<MAX_SUBJECT; s++)
        {
            stues[i].scores[s] = -1;  // Grade -1
        }
    }
}

void Run()
{
    int key = 0;
    Student_h* L=CreateStudent_h();
    while ((key = SelectMenu()) != 0)	// Repear if menu is not 0 
    {
        switch (key)			// Select key
        {
        case 1: AddStudent(); break;
        case 2: RemoveStudent(); break; //Done
        case 3: FindStudent(); break; //Done
        case 4: printList(L); break; //Done
        default: printf("Wrong selected.\n"); break;
        }
    }
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

void AddStudent()
{
    int num = 0;
    Student *stu = 0;
    int s = 0;
 
    printf("ID number to add (1~%d): ", MAX_STUDENT);
    scanf("%d", &num);
 
    if (IsAvailNum(num) == 0)		// ID invalid
    {
        printf("Invalid ID number.\n");
        return;
    }
 
    if (stues[num - 1].num)		// Already ID added
    {
        printf("Already added\n");
        return;
    }
 
    // stues : Memory address student ID 1 
    // stues+(num-1) : Memory address ID num 
    stu = stues + (num - 1);			// Actual stu address = stues address + (size of node) x (num-1)
    stu->num = num;
    printf("Name: ");
    scanf("%s", stu->name);
 
    for (s = 0; s<MAX_SUBJECT; s++)		// s: subject index
    {
        printf("%s Score:", stitles[s]);
        scanf("%d", stu->scores + s); 		// same as &stu->scores[s]
 
        if (IsAvailScore(stu->scores[s]) == 0)	// Invalid score 
        {
            stu->scores[s] = -1;
            printf("Invalid score. %s score is not added.\n", stitles[s]);
        }
    }
}

int IsAvailNum(int num)
{
    return (num >= 1) && (num <= MAX_STUDENT);
}

int IsAvailScore(int score)
{
    return (score >= 0) && (score <= 100);
}

void RemoveStudent()
{
    Student_h* L=CreateStudent_h();
    int num = 0;
    Student *stu = 0;
    int s = 0;
 
    printf("ID number to remove(1~%d): ", MAX_STUDENT);
    scanf("%d", &num);
 
    if (IsAvailNum(num) == 0)		//Invalid ID num
    {
        printf("Invalid ID.\n");
        return;
    }
 
    if (stues[num - 1].num == 0)	// ID not set
    {
        printf("No data.\n");
        return;
    }
 
    stu = stues + (num - 1);
    deleteNode(L,stu);
    printf("Removed.\n");
}

void ViewStuData(Student *stu);

void FindStudent()
{
    int num = 0;
    Student *stu = 0;
    Student_h* L=CreateStudent_h();
    int s = 0;
 
    printf("ID number to find(1~%d): ", MAX_STUDENT);
    scanf("%d", &num);
 
    if (IsAvailNum(num) == 0)		//Invalid ID num
    {
        printf("Invalid ID.\n");
        return;
    }
 
    if (stues[num - 1].num == 0)	//ID not set
    {
        printf("No data.\n");
        return;
    }
 
    stu = stues + (num - 1);
    searchNode(L,stu);
}

void ViewStuData(Student *stu)
{
    int i = 0;
    int s = 0;
 
    printf("%7d %7s ", stu->num, stu->name);
    for (s = 0; s<MAX_SUBJECT; s++)
    {
        printf("%7d ", stu->scores[s]);
    }
    printf("\n");
}

void ListStudent()
{
    int i = 0;
    int s = 0;
 
    printf("%7s %7s ", "ID", "Name");
    for (s = 0; s<MAX_SUBJECT; s++)
    {
        printf("%7s ", stitles[s]);
    }
    printf("(Score -1 : no info)\n");
 
    for (i = 0; i<MAX_STUDENT; i++)
    {
        if (stues[i].num)
        {
            ViewStuData(stues + i);
        }
    }
}

Student_h* CreateStudent_h(void)
{
    Student_h* L;
    L = (Student_h*)malloc(sizeof(Student_h));
    L->head = NULL;
    return L;
}

void freeStudent_h(Student_h* L)
{
    Student* p;
    while (L->head != NULL)
    {
        p = L->head;
        L->head = L->head->link;
        free(p);
        p=NULL;
    }
}

void printList(Student_h* L)
{
    Student* p;
    printf("ID Name Korean English Math\n");
    for (p = L->head; p != NULL; p = p->link)
    {
        printf("%d %s %d %d %d\n", p->num, p->name, p->scores[0], p->scores[1], p->scores[2]);
    }
}

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

void insertLastNode(Student_h* L, char* name, int num, int* scores)
{
    Student* newnode;
    Student* p;
    newnode = (Student*)malloc(sizeof(Student));
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

void deleteNode(Student_h* L, Student* pre)
{
    Student* removed;
    removed = pre->link;
    pre->link = removed->link;
    free(removed);
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