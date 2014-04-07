#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>

#define MAX 1000000

int main(int argc, char **argv){
	int counter;
	int fd,pagesize;
	char *data;
	int i;
	int current;
	int countChars[256]={0};
	fd = open(argv[1],O_RDONLY);
	pagesize = getpagesize();
	data = mmap((caddr_t)0,MAX,PROT_READ, MAP_SHARED, fd, 0);
	int size = argc - 2;
	char *argChar=(char *)malloc(sizeof(char)*size);

	for(i=0;i<size;i++){
		argChar[i]=*argv[i+2];
	}

	for(i=0;i<MAX;i++){
		current = data[i];
		countChars[current]++;
	}

	for(i = 0; i<size;i++){
		counter = argChar[i];
		printf("%c = %i\n",counter, countChars[counter]);
	}
}