#include <stdio.h>
#include <string.h>

void removeDuplicates(char* string) {
    int all[256] = {0};  
    int count = 0;
    int ndex = 0;
    int len = strlen(string);

    while (string[count] != '\0') {
        char current = string[count];
        if (all[current] == 0 ) {
            all[current] = 1;
            string[ndex] = string[count];
            ndex++;
        }
        count++;
    }
    string[ndex] = '\0'; 
}

int main() {
    char string[100];
    char string2[100];
    printf("Enter a string: ");
    fgets(string,100, stdin);
    removeDuplicates(string);

    printf("Duplicates removed string: %s\n", string);
    return 0;
}
