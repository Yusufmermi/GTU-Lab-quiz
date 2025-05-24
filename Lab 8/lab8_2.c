#include <stdio.h>
#include <string.h>

void compressString(const char *input, char *output) {
    int i = 0, count;
    int lastNdex = 0;
    int len = strlen(input);

    while (i < len) {
        char current = input[i];
        count = 1;
        while (i + 1 < len && input[i] == input[i + 1]) {
            count++;
            i++;
        }
        output[lastNdex++] = current;
        if (count > 1) {
            lastNdex += sprintf(&output[lastNdex], "%d", count);}
        i++;
    }


    output[lastNdex] = '\0';  
}

int main() {
    char input[100], output[200];

    printf("Enter string: ");
    scanf("%s", input);

    compressString(input, output);

    printf("Compressed string: %s\n", output);

    return 0;
}
