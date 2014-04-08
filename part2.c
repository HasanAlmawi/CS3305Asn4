#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>

int main(int argc, char **argv){
	if(argc<3){
		printf("Incorrect number of arguments\n");
		return 0;
	}
	int counter;
	int fd,pagesize;
	char *data;
	int i;
	int current;
	//Character array for the number of ASCII characters
	int countChars[256]={0};
	fd = open(argv[1],O_RDONLY);
	//Getting the file size;
	int size;
	struct stat st;
	stat(argv[1], &st);
	size = st.st_size;
	pagesize = getpagesize();
	//Mapping the data
	data = mmap((caddr_t)0,size,PROT_READ, MAP_SHARED, fd, 0);
	int sizeArg = argc - 2;
	char *argChar=(char *)malloc(sizeof(char)*size);

//Getting the characters from the command line
	for(i=0;i<sizeArg;i++){
		argChar[i]=*argv[i+2];
	}

//Go through the data and increment the number of characters every time
	//There is an occurence
	for(i=0;i<size;i++){
		current = data[i];
		countChars[current]++;
	}

//Printing the argument and the number of occurences
	for(i = 0; i<sizeArg;i++){
		counter = argChar[i];
		printf("%c = %i\n",counter, countChars[counter]);
	}
}