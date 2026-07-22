#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

#define LOG_FILE "log.log"

int get_length(const char *str) {
    int len = 0;
    while (str[len] != '\0') {
        len++;
    }
    return len;
}

void print_line_number(int num) {
    char buffer[16];
    int i = 0;
    
     
    while (num > 0) {
        buffer[i++] = (num % 10) + '0';
        num /= 10;
    }

    
    while (i > 0) {
        i--;
        write(1, &buffer[i], 1);
    }
}

int is_match(const char *str1, const char *str2) {
    int i = 0;
    while (str1[i] != '\0' && str2[i] != '\0') {
        if (str1[i] != str2[i]) return 0;
        i++;
    }
    return str1[i] == str2[i];
}

 
int main(int argc, char *argv[]) {
    
     
    if (argc < 2) {
        char usage[] = "Usage: ./auditlog --add <message> | --view\n";
        write(1, usage, get_length(usage));
        return 1;
    }
   
     
    if (is_match(argv[1], "--add") && argc == 3) {

        int fd = open(LOG_FILE, O_WRONLY | O_CREAT | O_APPEND, 0644);
        if (fd < 0) return 1;
            
        int msg_len = get_length(argv[2]);

        write(fd, argv[2], msg_len);
        write(fd, "\n", 1);
        
        close(fd);
    }
    else if (is_match(argv[1], "--view")) {
       
        int fd = open(LOG_FILE, O_RDONLY);
        if (fd < 0) return 1; 

        char c;
        int line_num = 1;
        int start_of_line = 1;
        
        while (read(fd, &c, 1) > 0) {
            if (start_of_line) {
                print_line_number(line_num);
                write(1, ": ", 2);
                start_of_line = 0;
            }
            
            write(1, &c, 1);
            
            if (c == '\n') {
                line_num++;
                start_of_line = 1;
            }
        }
        close(fd);
    }
    return 0;
}