#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdint.h>

int main(){
	size_t size1 = 6;
	size_t size2 = SIZE_MAX;

	void *ptr = malloc(size1);
	//Case 1: Nalloc successfull allocate memory and return ptr
	if(ptr == NULL){
		printf("Failed to allocate memory.\n");
		return 1;
	}else{
		printf("Successfull allocated %zu bytes of memory.\n", size1);
		free(ptr);
	}
	
	void *new_ptr = realloc(ptr, size2);
	if(new_ptr == NULL){
		printf("Realloc returned NULL\n");
		free(ptr);
	}else{
		printf("Succeessfull allocated %zu bytes.\n", size2);
		free(new_ptr);
	}

	return 0;

}
