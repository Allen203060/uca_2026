#include <stdio.h>


int my_strlen(const char *str) {
    int length = 0;
    

    while(str[length] != '\0') {
        
        length++;
    }

    return length;
}

int main() {
    
    char str[256];

    printf("%s\n", "Enter the String: ");
    // will have to use fgets to get the length of the string but will have to use the <string> header, but mentioned in the assignment not to use it
    scanf("%s", str);

    printf("The length of the string is: %d\n", my_strlen(str));

    return 0;
}