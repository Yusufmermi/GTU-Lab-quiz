#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 100


typedef struct {
    char name[50];
    char surname[50];
    int id;
    int midterm;
    int final;
    double average;
    char letter_grade; 
} Student;

typedef struct {
    Student students[MAX_STUDENTS];
    int student_count;
} Class;

double calculate_average(int midterm, int final) {
    return midterm * 0.4 + final * 0.6;
}

char calculate_letter_grade(double average) {
    return (average >= 50.0) ? 'P' : 'F';
}



int main() {
    Class myClass;
    myClass.student_count = 3;

  
    strcpy(myClass.students[0].name, "Alice");
    strcpy(myClass.students[0].surname, "Smith");
    myClass.students[0].id = 101;
    myClass.students[0].midterm = 70;
    myClass.students[0].final = 80;
    myClass.students[0].average = calculate_average(myClass.students[0].midterm, myClass.students[0].final);
    myClass.students[0].letter_grade = calculate_letter_grade(myClass.students[0].average);

  
    strcpy(myClass.students[1].name, "Bob");
    strcpy(myClass.students[1].surname, "Jones");
    myClass.students[1].id = 102;
    myClass.students[1].midterm = 50;
    myClass.students[1].final = 55;
    myClass.students[1].average = calculate_average(myClass.students[1].midterm, myClass.students[1].final);
    myClass.students[1].letter_grade = calculate_letter_grade(myClass.students[1].average);


    strcpy(myClass.students[2].name, "Clara");
    strcpy(myClass.students[2].surname, "Lee");
    myClass.students[2].id = 103;
    myClass.students[2].midterm = 65;
    myClass.students[2].final = 75;
    myClass.students[2].average = calculate_average(myClass.students[2].midterm, myClass.students[2].final);
    myClass.students[2].letter_grade = calculate_letter_grade(myClass.students[2].average);


    for (int i = 0; i < myClass.student_count; i++) {
        printf("Student %d:\n", i + 1);
        printf("Name: %s %s\n", myClass.students[i].name, myClass.students[i].surname);
        printf("ID: %d\n", myClass.students[i].id);
        printf("Midterm: %d\n", myClass.students[i].midterm);
        printf("Final: %d\n", myClass.students[i].final);
        printf("Average: %.2f\n", myClass.students[i].average);
        printf("Letter Grade: %c\n", myClass.students[i].letter_grade);
        printf("--------------------------\n");
    }

    return 0;
}
