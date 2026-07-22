#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define BUF_SIZE 1024

int main(int argc, char *argv[]){
	int inputFD, outputFD, openFlags;
	mode_t filePerms;
	ssize_t numRead;
	char buf[BUF_SIZE];
	if(argc != 3){
		printf("Wrong number of arguments.");
		exit(-1);
	}
	inputFD = open(argv[1], O_RDONLY);
	if(inputFD == -1){
		printf("Error parsing file %s\n", argv[1]);
		exit(-1);
	}
	openFlags = O_CREAT | O_WRONLY | O_TRUNC;
	filePerms = S_IWUSR | S_IRUSR | S_IRGRP | S_IROTH;
	outputFD = open(argv[2], openFlags, filePerms);

	if(outputFD == -1){
		printf("Error parsing file %s\n", argv[2]);
		close(inputFD);
		exit(-1);
	}
	while((numRead = read(inputFD, buf, BUF_SIZE)) > 0){
		if(write(outputFD, buf, numRead) != numRead){
			printf("Read, Write corruption");
			close(inputFD);
			close(outputFD);
			exit(-1);
		}
	}
	close(inputFD);
	close(outputFD);
}


