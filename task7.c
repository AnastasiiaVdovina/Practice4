#include <stdio.h>
#include <stdlib.h>

struct sbar{
	int data;
};

int main(){
	struct sbar *ptr, *newptr;
	ptr = calloc(1000, sizeof(struct sbar));
	if(!ptr){
		perror("calloc failed\n");
		return 1;
	}

	//newptr = realloc(ptr, 500*sizeof(struct sbar));
	//if(!newptr){
	//	perror("realloc failed\n");
	//	free(ptr);
	//	return 1;
	//}

	newptr = reallocarray(ptr, 500, sizeof(struct sbar));
	if(!newptr){
		perror("reallocarray failed\n");
		free(ptr);
		return 1;
	}

	free(newptr);
	return 0;

}

	
	
