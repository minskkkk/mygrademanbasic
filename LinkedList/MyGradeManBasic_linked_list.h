// Grade management system Header file
//
// Written by Minseok Song (2025.01.07 15:19)
// Last modified by Minseok Song (2025.01.07 18:49)

#define MAX_NLEN    20		// Name length
#define MAX_SUBJECT 3		// Number of subjects

const char *stitles[MAX_SUBJECT] = { "Korean","English","Math" };

//define the structure of the student node
typedef struct Student {
    char name[MAX_NLEN + 1];
    int num;
    int scores[MAX_SUBJECT];
    struct Student* link;
}Student;

//define the structure of head node
typedef struct {
    Student* head;
}Student_h;

//function declaration
Student_h* CreateStudent_h(void);
void freeStudent_h(Student_h* L);
void printList(Student_h* L);
void insertLastNode(Student_h* L, char* name, int num, int* scores);
void deleteNode(Student_h* L, int num);
Student* searchNode(Student_h*L, int num);
void Run();
int SelectMenu();	// Menu print and select
void AddStudent(Student_h* L);	// Add student data 
void RemoveStudent(Student_h* L);	// Remove student data 
void FindStudent(Student_h* L);	// Search student
int IsAvailNum(Student_h* L, int num);	// Check valid ID number
int IsAvailScore(int score);	// Check valid score


/*
void insertFirstNode(Student_h* L, char* name, int num, int* scores);
void insertMiddleNode(Student_h* L, Student* pre, char* name, int num, int* scores);
*/