#include <stdio.h>
#include <string.h>

#define MAX_STUDENT 100
struct Student {
    char name[50];
    char surname[50];
    int id;
    int midterm;
    int final;
    double average;
    char letter;
};
struct Class{
    int student_passed;
    int threshold;
};

char calculate_letter(double average, int threshold);
void inputGrades(struct Student *s1,struct Student *s2,struct Student *s3, struct Class *c1) {

    printf("First determine a threshold: ");
    scanf("%d", &c1->threshold);


        printf("Student name: ");
    scanf(" %s", s1->name);

    printf("Student surname: ");
    scanf(" %s", s1->surname);
    

    printf("Student id: ");
    scanf("%d", &s1->id);

    printf("Midterm grade: ");
    scanf("%d", &s1->midterm);

    printf("Final: ");
    scanf("%d", &s1->final);

        printf("Student name: ");
    scanf(" %s", s2->name);

    printf("Student surname: ");
    scanf(" %s", s2->surname);

    printf("Student id: ");
    scanf("%d", &s2->id);

    printf("Midterm grade: ");
    scanf("%d", &s2->midterm);

    printf("Final: ");
    scanf("%d", &s2->final);


        printf("Student name: ");
    scanf(" %s", s3->name);

    printf("Student surname: ");
scanf(" %s", s3->surname);

    printf("Student id: ");
    scanf("%d", &s3->id);

    printf("Midterm grade: ");
    scanf("%d", &s3->midterm);

    printf("Final: ");
    scanf("%d", &s3->final);

     s1->average = (s1->midterm * 0.4)  + (s1->final * 0.6);
     s2->average = (s2->midterm * 0.4)  + (s2->final * 0.6);
     s3->average = (s3->midterm * 0.4)  + (s3->final * 0.6);

     s1->letter = calculate_letter(s1->average, c1->threshold);
     s1->letter = calculate_letter(s1->average, c1->threshold);
     s2->letter = calculate_letter(s2->average, c1->threshold);
     s3->letter = calculate_letter(s3->average, c1->threshold);

     c1->student_passed = 0;
     if (s1->letter == 'P') c1->student_passed++;
     if (s2->letter == 'P') c1->student_passed++;
     if (s3->letter == 'P') c1->student_passed++;
  


}
void sortStudents(struct Student *s1, struct Student *s2, struct Student *s3, struct Class *c1) {
    if (s1->average < s2->average) {
        struct Student temp = *s1;
        *s1 = *s2;
        *s2 = temp;
    }
    if (s1->average < s3->average) {
        struct Student temp = *s1;
        *s1 = *s3;
        *s3 = temp;
    }
    if (s2->average < s3->average) {
        struct Student temp = *s2;
        *s2 = *s3;
        *s3 = temp;
    }
    printf("\n NEW CLASS INFORMATİON:\n");
    printf("--------------------------------------------------------------------------\n");
    printf("| %-10s | %-10s | %-6s | %-8s | %-6s | %-7s | %-5s |\n", "NAME", "SURNAME", "ID", "MIDTERM", "FINAL", "AVERAGE", "GRADE");
    printf("--------------------------------------------------------------------------\n");
    printf("| %-10s | %-10s | %-6d | %-8d | %-6d | %-7.1f | %-5c |\n", 
        s1->name, s1->surname, s1->id, s1->midterm, s1->final, s1->average, s1->letter);
    printf("| %-10s | %-10s | %-6d | %-8d | %-6d | %-7.1f | %-5c |\n", 
        s2->name, s2->surname, s2->id, s2->midterm, s2->final, s2->average, s2->letter);
    printf("| %-10s | %-10s | %-6d | %-8d | %-6d | %-7.1f | %-5c |\n", 
        s3->name, s3->surname, s3->id, s3->midterm, s3->final, s3->average, s3->letter);
    printf("\n--------------------------------------------------------------------------\n");

         c1->student_passed = 0;
     if (s1->letter == 'P') c1->student_passed++;
     if (s2->letter == 'P') c1->student_passed++;
     if (s3->letter == 'P') c1->student_passed++;

    printf("Passing Students: %d\n", c1->student_passed);
    printf("Class Average: %.1f\n", (s1->average + s2->average + s3->average) / 3);
   
}
char calculate_letter(double average, int threshold) {

    if (average >= threshold) {
        return 'P';
    } else {
    return  'F';}
}

int main () {
    struct Student s1,s2,s3;
    struct Class c1;
    inputGrades(&s1,&s2,&s3,&c1);
    
    printf("\n Class information:\n");
    printf("\n--------------------------------------------------------------------------\n");
    printf("| %-10s | %-10s | %-6s | %-8s | %-6s | %-7s | %-5s |\n", "NAME", "SURNAME", "ID", "MIDTERM", "FINAL", "AVERAGE", "GRADE");
    printf("--------------------------------------------------------------------------\n");
    printf("| %-10s | %-10s | %-6d | %-8d | %-6d | %-7.1f | %-5c |\n", 
        s1.name, s1.surname, s1.id, s1.midterm, s1.final, s1.average, s1.letter);
    printf("| %-10s | %-10s | %-6d | %-8d | %-6d | %-7.1f | %-5c |\n", 
        s2.name, s2.surname, s2.id, s2.midterm, s2.final, s2.average, s2.letter);
    printf("| %-10s | %-10s | %-6d | %-8d | %-6d | %-7.1f | %-5c |\n", 
        s3.name, s3.surname, s3.id, s3.midterm, s3.final, s3.average, s3.letter);
    printf("\n--------------------------------------------------------------------------\n");
    printf("Passing Students: %d\n", c1.student_passed);
    printf("Class Average: %.1f\n", (s1.average + s2.average + s3.average) / 3);
    printf("\n--------------------------------------------------------------------------\n");
    sortStudents(&s1,&s2,&s3,&c1);



    int id, new_final;
    printf("If you want update a student final grade, enter student id and new final grade: \n");
    scanf("%d", &id);
    printf("Enter new final grade: ");
    scanf("%d", &new_final);

    if (id == s1.id) {
        s1.final = new_final;
        s1.average = (s1.midterm * 0.4) + (s1.final * 0.6);
        s1.letter = calculate_letter(s1.average, c1.threshold);
    } else if (id == s2.id) {
        s2.final = new_final;
        s2.average = (s2.midterm * 0.4) + (s2.final * 0.6);
        s2.letter = calculate_letter(s2.average, c1.threshold);
    } else if (id == s3.id) {
        s3.final = new_final;
        s3.average = (s3.midterm * 0.4) + (s3.final * 0.6);
        s3.letter = calculate_letter(s3.average, c1.threshold);
    } else {
        printf("There is no student with %d id. \n" , id);
    }
    sortStudents(&s1,&s2,&s3,&c1);
    return 0;
}

