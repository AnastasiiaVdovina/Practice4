#include <stdio.h>
#include <stdlib.h>

int main(){
	void *ptr1 = malloc(16);
	ptr1 = realloc(ptr1, 0);

	if(ptr1 == NULL){
		printf("Memory freed.\n");
	}else{
		printf("Unexpected behavior: pointer is not NULL\n");
	}
	free(ptr1);


	void *ptr2 = realloc(NULL, 32);
	if(ptr2 != NULL){
		printf("Realloc (null, 32) allocated memory successfully.\n");
	}else{
		printf("Unexpexted behavior: realloc(null, 32) returned null.\n");
	}

	free(ptr2);


	
	return 0;

}
