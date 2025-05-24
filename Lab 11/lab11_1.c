#include <stdio.h>
#include <string.h>

struct Type_I {
    char name[50];
    char surname[50];
    char department[50];
    char class1[50];
    char class2[50];
    double salary;
};

struct Type_E {
    char name[50];
    char surname[50];
    double salary;
    char degree; 
};

union PersonUnion {
    struct Type_I instructor;
    struct Type_E employee;
};

struct CombinedType {
    char type;  
    union PersonUnion person;
};



double calculateAnnualSalary(struct CombinedType* person) {
    double annualSalary = 0.0;
    
    if (person->type == 'I') {
        annualSalary = person->person.instructor.salary * (1 + 5.3/100);
        person->person.instructor.salary = annualSalary;
    }
    else if (person->type == 'E') {
        double rate = 0.0;
        switch (person->person.employee.degree) {
            case 'a':  
                rate = 17.5;
                break;
            case 'b':  
                rate = 12.0;
                break;
            case 'c':  
                rate = 9.0;
                break;
            default:
                printf("Invalid degree type!\n");
                return person->person.employee.salary;
        }
        annualSalary = person->person.employee.salary * (1 + rate/100);
        person->person.employee.salary = annualSalary;
    }
    else {
        printf("Invalid person type!\n");
        return 0.0;
    }
    
    return annualSalary;
}

void displayPerson(struct CombinedType* person) {
    if (person->type == 'I') {
        printf("\n INSTRUCTOR \n");
        printf("Name: %s %s\n", person->person.instructor.name, person->person.instructor.surname);
        printf("Department: %s\n", person->person.instructor.department);
        printf("Classes: %s, %s\n", person->person.instructor.class1, person->person.instructor.class2);
        printf("Salary: %.2f\n", person->person.instructor.salary);
    }
    else if (person->type == 'E') {
        printf("\nEMPLOYEE\n");
        printf("Name: %s %s\n", person->person.employee.name, person->person.employee.surname);
        printf("Degree: %c ", person->person.employee.degree);
        printf("\nSalary: %.2f\n", person->person.employee.salary);
    }
}


struct CombinedType createInstructor(char* name, char* surname, char* department, 
                                   char* class1, char* class2, double salary) {
    struct CombinedType person;
    person.type = 'I';
    
    strcpy(person.person.instructor.name, name);
    strcpy(person.person.instructor.surname, surname);
    strcpy(person.person.instructor.department, department);
    strcpy(person.person.instructor.class1, class1);
    strcpy(person.person.instructor.class2, class2);
    person.person.instructor.salary = salary;
    
    return person;
}

struct CombinedType createEmployee(char* name, char* surname, double salary, char degree) {
    struct CombinedType person;
    person.type = 'E';
    
    strcpy(person.person.employee.name, name);
    strcpy(person.person.employee.surname, surname);
    person.person.employee.salary = salary;
    person.person.employee.degree = degree;
    
    return person;
}

void inputWrites(const char* inputFile, const char* outputFile) {
    FILE* inFile = fopen("input.txt", "r");
    FILE* outFile = fopen(outputFile, "wb");
    
    if (inFile == NULL || outFile == NULL) {
        printf("Error opening files!\n");
        return;
    }

    struct CombinedType person;
    char type, name[50], surname[50], department[50], class1[50], class2[50], degree;
    double salary;

    while (fscanf(inFile, " %c", &type) == 1) {
        if (type == 'I') {
            fscanf(inFile, "%s %s %s %s %s %lf", name, surname, department, class1, class2, &salary);
            person = createInstructor(name, surname, department, class1, class2, salary);
        } else if (type == 'E') {
            fscanf(inFile, "%s %s %lf %c", name, surname, &salary, &degree);
            person = createEmployee(name, surname, salary, degree);
        }
        calculateAnnualSalary(&person);
        fwrite(&person, sizeof(struct CombinedType), 1, outFile);
    }

    fclose(inFile);
    fclose(outFile);
}

int main() {
    printf("UNIVERSITY PERSONNEL MANAGEMENT SYSTEM\n");
    
    struct CombinedType instructor1 = createInstructor("John", "Parker", "Computer Science", 
                                                      "CSE100", "CSE200", 100000);
    
    struct CombinedType employee1 = createEmployee("Marh", "James", 30000.0, 'a'); 


    printf("\nORIGINAL SALARIES");
    displayPerson(&instructor1);
    displayPerson(&employee1);
    

    printf("\n\nCALCULATING ANNUAL SALARIES\n");
    
    double newSalary;
    
    newSalary = calculateAnnualSalary(&instructor1);
    printf("Instructor %s %s: Original -> Updated (%.2f -> %.2f)\n",instructor1.person.instructor.name, instructor1.person.instructor.surname,
           5000.0, newSalary);
    
    newSalary = calculateAnnualSalary(&employee1);
    printf("Employee %s %s (Head): Original -> Updated (%.2f -> %.2f)\n",employee1.person.employee.name, employee1.person.employee.surname,
           8000.0, newSalary);
    
    printf("\nUPDATED SALARIES");
    displayPerson(&instructor1);
    displayPerson(&employee1);

    
    return 0;
}