#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main() {
    char input[256];           
    char str[256];

    const char default_str[] = "C,C++,Java,Python,Rust";
    const char delimiters[] = ", ";

    if (fgets(input, sizeof(input), stdin) != NULL) {

        if (input[0] == '\n') {
            // if input not given then fallback to default
            strcpy(str, default_str);
        }
        else {
            input[strcspn(input, "\n")] = '\0';
            strcpy(str, input); 
        }
    }

    char *token = strtok(str, delimiters);

    while (token != NULL) {
        
        printf("%s\n", token);

        token = strtok(NULL, delimiters);
    }

    return 0;
}