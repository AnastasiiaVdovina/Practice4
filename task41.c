#include <stdio.h>
#include <stdlib.h>

int main(){
	void *ptr = NULL;
	int counter = 0;
	while(counter < 5){
	if(!ptr){
		ptr = malloc(10);
	}
	if(!ptr){
		printf("Failed to allocate memory.\n");
		return 1;
	}

	printf("Using memory at %p (iteration %d)\n", ptr, counter);
	free(ptr); //dangling pointer
	ptr = NULL;

	counter++;

	}

	return 0;

}
