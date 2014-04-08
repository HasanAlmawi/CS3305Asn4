#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv){
		if(argc<3){
			printf("Incorrect number of arguments\n");
			return 0;
		}
		//Opening the file
		FILE *fp;
		fp = fopen(argv[1],"r");
		//Initialize loop counter
		int i = 0;
		int counter=0;
		char current;
		int currentNum = 0;
		int size = argc - 2;
		//Initializing array to count the existing character
		int countChars[256]={0};
		//int argChar[size];
		char *argChar=(char *)malloc(sizeof(char)*size);
		//Put all the read input into the array
		for(i=0;i<size;i++){
			argChar[i]=*argv[i+2];
		}
		//Scan the file
		while(fscanf(fp,"%c",&current) != EOF){
			currentNum = (int)current;
			countChars[currentNum]++;
		}
		//Print the character numbers
		for(i = 0; i<size;i++){
			counter = argChar[i];
			//temp = (char) asciiChars[i];
			printf("%c = %i\n",counter, countChars[counter]);
		}
		//Close the file
		free(argChar);
		fclose(fp);
		return 0;
	}