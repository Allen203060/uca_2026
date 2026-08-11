#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char base64_table[] =
"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

char *encodeBase64(char *input) {
    int len = strlen(input);
    int output_len = 4 * ((len + 2) / 3);
    char* output = (char*)malloc(output_len + 1);

    int i, j = 0;

    for (i = 0; i < len; i += 3) {

        // Reading up to 3 bytes
        unsigned char b1 = input[i];
        unsigned char b2 = (i + 1 < len) ? input[i + 1] : 0;
        unsigned char b3 = (i + 2 < len) ? input[i + 2] : 0;

        // Combining into 24-bit number
        int num = (b1 << 16) | (b2 << 8) | b3;

        // Extracting 6-bit chunks and map
        output[j++] = base64_table[(num >> 18) & 63];
        output[j++] = base64_table[(num >> 12) & 63];

        if (i + 1 < len)
            output[j++] = base64_table[(num >> 6) & 63];
        else
            output[j++] = '=';

        if (i + 2 < len)
            output[j++] = base64_table[num & 63];
        else
            output[j++] = '=';
    }

    output[j] = '\0';
    return output;
}


int main() {
    char input[] = "AB";
    char* encoded = base64_encode(input);

    printf("Encoded: %s\n", encoded);

    free(encoded);
    return 0;
}