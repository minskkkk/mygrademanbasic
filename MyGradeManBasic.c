// Grade management system
// ID indicates array index (1,2,..,MAX_STUDENT-1)
// Global variable : Structure array
// Max number of students are fixed
 
#include <stdio.h>
#include <memory.h>
#include <stdlib.h>
#include <string.h>
 
#define MAX_NLEN    20		// Name length
#define MAX_SUBJECT 3		// Number of subjects

typedef struct {		// Structure
    char name[MAX_NLEN + 1];	// Name
    int num;			// ID number
    int scores[MAX_SUBJECT];	// Korean, English, Math score
}Student;
 
 
const char *stitles[MAX_SUBJECT] = { "Korean","English","Math" };
 
#define MAX_STUDENT 10		// Max number of students
 
Student stues[MAX_STUDENT];
 
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
 
int SelectMenu();	// Menu print and select
void AddStudent();	// Add student data 
void RemoveStudent();	// Remove student data 
void FindStudent();	// Search student
void ListStudent();	// Show list student

void Run()
{
    int key = 0;
    while ((key = SelectMenu()) != 0)	// Repear if menu is not 0 
    {
        switch (key)			// Select key
        {
        case 1: AddStudent(); break;
        case 2: RemoveStudent(); break;
        case 3: FindStudent(); break;
        case 4: ListStudent(); break;
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
 
int IsAvailNum(int num);	// Check valid ID number
int IsAvailScore(int score);	// Check valid score

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
    strcpy(stu->name, "");
    stu->num = 0;

    for (s = 0; s<MAX_SUBJECT; s++)
    {
        stu->scores[s] = -1;
    }
 
    printf("Removed.\n");
}

void ViewStuData(Student *stu);

void FindStudent()
{
    int num = 0;
    Student *stu = 0;
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
    ViewStuData(stu);
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

