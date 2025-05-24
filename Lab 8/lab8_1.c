#include <stdio.h>
#include <string.h>

void reversingString(char *string) {
    int i, len = strlen(string);
    char temp;

    for (i = 0; i < len / 2; i++) {
        temp = string[i];
        string[i] = string[len - i - 1];
        string[len - i - 1] = temp;
    }    
    string[len] = '\0'; 
}

int main() {
    char string[100];

    printf("Enter a string: ");
    scanf("%s", string);
    reversingString(string);
    printf("Reversed string: %s\n", string);

    return 0;
}
