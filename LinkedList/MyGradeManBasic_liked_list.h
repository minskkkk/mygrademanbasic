#define MAX_NLEN    20		// Name length
#define MAX_SUBJECT 3		// Number of subjects
#define MAX_STUDENT 10		// Max number of students

const char *stitles[MAX_SUBJECT] = { "Korean","English","Math" };

Student stues[MAX_STUDENT];

//define the structure of the student node
typedef struct {
    char name[MAX_NLEN + 1];
    int num;
    int scores[MAX_SUBJECT];
    struct Student* link;
}Student;


//define the structure of head node
typedef struct {
    Student* head;
}Student_h;

//function
Student_h* CreateStudent_h(void);
void FreeStudnet_h(Student_h* L);
void PrintList(Student_h* L);
void insertFirstNode(Student_h* L, char* name, int num, int* scores);
void insertMiddleNode(Student_h* L, Student* pre, char* name, int num, int* scores);
void insertLastNode(Student_h* L, char* name, int num, int* scores);
void deleteNode(Student_h* L, Student* pre);
Student* searchNode(Student_h*L, int num);
void reverseList(Student_h* L);
