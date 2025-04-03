#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdint.h>


int main(){

	int xa = INT_MAX;
	int xb = 2;
	int num = xa * xb;

	void *ptr;
	if(malloc(num)){
		printf("Allocated %d bytes.\n", num);
		free(ptr);
	}else{
		printf("Failed to allocate %d bytes\n", num);
	}

	return 0;

}
