# Grade management system
# Written by Minseok Song

class Student:
    MAX_SUBJECT = 3 # Number of subjects
    SUBJECTS = ["Korean", "English", "Math"] # Name of subjects

    def __init__(self, num, name="", scores=None):
        self.num = num # Student ID
        self.name = name # Student Name
        self.scores = scores if scores else [-1] * self.MAX_SUBJECT # Initialize scores / value -1 means not registered.

    def is_valid_score(self, score):
        return 0 <= score <= 100 # Check the score is valid

    def display(self): # Display student information
        print(f"{self.num:7} {self.name:7}", end=" ")
        for score in self.scores:
            print(f"{score:7}", end=" ")
        print()


class GradeManagement:
    MAX_STUDENTS = 10 # Max number of students

    def __init__(self):
        self.students = [Student(i + 1) for i in range(self.MAX_STUDENTS)]

    def initialize(self): # Initialize student data
        for student in self.students:
            student.scores = [-1] * Student.MAX_SUBJECT

    def select_menu(self):
        print("\n-----------------------------")
        print("Grade management program.")
        print("1: Add student data.  2: Remove student data.  3: Find student.  4: Show list.  0: Quit")
        return int(input("Select menu: ")) # Select key

    def add_student(self): #Function to add a new student
        num = int(input(f"ID number to add (1~{self.MAX_STUDENTS}): "))
        if not (1 <= num <= self.MAX_STUDENTS):
            print("Invalid ID number.")
            return
        student = self.students[num - 1]
        if student.num and student.name:
            print("Already added.")
            return
        student.name = input("Name: ")
        for i in range(Student.MAX_SUBJECT):
            score = int(input(f"{Student.SUBJECTS[i]} Score: "))
            if student.is_valid_score(score):
                student.scores[i] = score
            else:
                student.scores[i] = -1
                print(f"Invalid score. {Student.SUBJECTS[i]} score is not added.")

    def remove_student(self): #Function to remove student data
        num = int(input(f"ID number to remove (1~{self.MAX_STUDENTS}): "))
        if not (1 <= num <= self.MAX_STUDENTS):
            print("Invalid ID.")
            return
        student = self.students[num - 1]
        if not student.name:
            print("No data.")
            return
        student.name = ""
        student.scores = [-1] * Student.MAX_SUBJECT
        print("Removed.")

    def find_student(self): # Function to find and display student information
        num = int(input(f"ID number to find (1~{self.MAX_STUDENTS}): "))
        if not (1 <= num <= self.MAX_STUDENTS):
            print("Invalid ID.")
            return
        student = self.students[num - 1]
        if not student.name:
            print("No data.")
            return
        student.display()

    def list_students(self): # Function to display all student information
        print(f"{'ID':7} {'Name':7}", end=" ")
        for subject in Student.SUBJECTS:
            print(f"{subject:7}", end=" ")
        print("(Score -1 : no info)")
        for student in self.students:
            if student.name:
                student.display()

    def run(self): #Main execution function
        while True:
            choice = self.select_menu()
            if choice == 0:
                print("Program exit")
                break
            elif choice == 1:
                self.add_student()
            elif choice == 2:
                self.remove_student()
            elif choice == 3:
                self.find_student()
            elif choice == 4:
                self.list_students()
            else:
                print("Wrong selection.")


if __name__ == "__main__":
    system = GradeManagement()
    system.initialize()
    system.run()