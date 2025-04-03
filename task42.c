#include <stdio.h>
#include <stdlib.h>

int main(){
	void *ptr[5];
	int counter = 0;

	while(counter < 5){
		ptr[counter] = malloc(10);
		if(!ptr[counter]){
			printf("Failed to allocate memory!\n");
			return 1;
		}
		
		printf("Using memory at %p (iteration %d)\n", ptr[counter], counter);

		counter++;

	}

	for(int i = 0; i < 5; i++){
		free(ptr[i]);
	}


	return 0;

}
