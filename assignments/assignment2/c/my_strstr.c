#include <stdio.h>

int find_substring(const char *haystack, const char *needle) {
    int i = 0;
    
  
    while (haystack[i] != '\0'){
        int j = 0;
        
        while (haystack[i+j] != '\0' && haystack[i+j] == needle[j]) {
            j++;        
        }

        if (needle[j] == '\0') {
            return i;
        }

        i++;
    }
    return -1;
}

int main () {
    char haystack[256];
    char needle[256];

    printf("Enter the String: \n");
    scanf(" %[^\n]", haystack); 
    printf("\n");

    printf("Enter the Substring: \n");
    scanf(" %[^\n]", needle);

    int index = find_substring(haystack, needle);

    if (index != -1) {
        printf("%d\n", index);
    }
    else {
        printf("%d\n", index);
    }

}