#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdint.h>

int main(){
	void *ptr = malloc(10);
	if(!ptr){
		printf("Failed to allocate memory~\n");
		return 1;
	}
	
	printf("Memory allocated at %p\n", ptr);

	void *new_ptr = realloc(ptr, SIZE_MAX);
	if(!new_ptr){
		printf("Realloc failed. Original pointer is still valid at %p\n", ptr);
		free(ptr);
	}else{
		printf("Realloc succeeded. New pointer at %p\n", new_ptr);
		free(new_ptr);

	}

	return 0;
}		

