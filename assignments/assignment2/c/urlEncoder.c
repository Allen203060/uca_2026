#include <stdio.h>
#include <string.h>

void url_encode(char *str, int true_length) {
    if (str == NULL || true_length <= 0) {
        return;
    }

    int space_count = 0;
    int i;

    for (i = 0; i < true_length; i++) {
        if (str[i] == ' ') {
            space_count++;
        }
    }

    int new_length = true_length + space_count * 2;

    str[new_length] = '\0';

    int j = new_length - 1;
    for (i = true_length - 1; i >= 0; i--) {
        if (str[i] == ' ') {
            str[j] = '0';
            str[j - 1] = '2';
            str[j - 2] = '%';
            j -= 3;
        } else {
            str[j] = str[i];
            j--;
        }
    }
}

int main () {

    char buffer[50] = "Hello World"; 

    int true_length = 11;

    printf("Original string: '%s'\n", buffer);

    url_encode(buffer, true_length);

    printf("Encoded string:  '%s'\n", buffer);

    return 0;
}