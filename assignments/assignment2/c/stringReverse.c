#include <stdio.h>
#include <string.h>

void swap(char *str, int i, int j) {

    char temp = str[i];
    str[i] = str[j];
    str[j] = temp;
} 

int my_strlen(const char *str) {

    int length = 0;

    while(str[length] != '\0') {
        length++;
    }

    return length;
}

char* reverse_string(char *str) {

    int len = my_strlen(str);
    int left = 0, right = len-1;
    
    while(left < right) {
        swap(str, left, right);
        left++;
        right--;
    }

    return str;
}

int main() {
    char str[100];
    printf("Enter the string: ");
    scanf("%99s", str);
    printf("Reversed String %s\n", reverse_string(str));
}