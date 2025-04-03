#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdint.h>

int main() {
	size_t size = SIZE_MAX;
	void *ptr;

	while(size > 0) {
	ptr = malloc(size);
	if(!ptr) {
		printf("Failed to allocate %zu bytes(%.2f GB), trying less\n", size, size/(double)(1024*1024*1024));
		size /= 2;
	}else{
		printf("Successful allocated %zu bytes(%.2f GB) of memory\n", size, size/(double)(1024*1024*1024));
		free(ptr);
		break;
	}
	}

	return 0;

}
