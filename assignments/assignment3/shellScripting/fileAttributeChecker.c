#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <time.h>

void printFileType(mode_t mode) {
    if (S_ISREG(mode)) {
        printf("Regular File");
    }
    else if (S_ISDIR(mode)) {
        printf("Directory");
    }
    else if (S_ISBLK(mode)) {
        printf("Block Device");
    }
    else if (S_ISFIFO(mode)) {
        printf("FIFO (Named Pipe)");
    } 
    else if (S_ISLNK(mode)) {
        printf("Symbolic Link");
    } 
    else if (S_ISSOCK(mode)) {
        printf("Socket");
    } 
    else {
        printf("Unknown");
    }
}

void formatTime(time_t caltime, char *buf, size_t buf_size) {
    
    struct tm *timeinfo = localtime(&caltime);
    strftime(buf, buf_size, "%a %b %d %H:%M:%S %Y", timeinfo);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <file_path>\n", argv[0]);
        exit(-1);
    }
    
    char const *file_path = argv[1];

    struct stat metadata;

    if (stat(file_path, &metadata) != 0) {
        perror("Error calling stat");
        exit(-1);
    }

    char a_time[100];
    char m_time[100];
    char c_time[100];
    
    formatTime(metadata.st_atime, a_time, sizeof(a_time));
    formatTime(metadata.st_mtime, m_time, sizeof(m_time));
    formatTime(metadata.st_ctime, c_time, sizeof(c_time));
    
    printf("=== File Attributes for: %s ===\n", file_path);

    printf("%-21s ", "File Type:");
    printFileType(metadata.st_mode);
    printf("\n");

    printf("%-21s 0%o\n", "Permissions:", metadata.st_mode & 0777);
    printf("%-21s %lld bytes\n", "File Size:", (long long)metadata.st_size);
    printf("%-21s %lu\n", "Hard Links Count:", (unsigned long)metadata.st_nlink);
    printf("%-21s %u\n", "Owner (UID):", metadata.st_uid);
    printf("%-21s %u\n", "Group (GID):", metadata.st_gid);
    printf("%-21s %s\n", "Last Access Time:", a_time);
    printf("%-21s %s\n", "Last Modification:", m_time);
    printf("%-21s %s\n", "Status Change Time:", c_time);

    return 0;
}