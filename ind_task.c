#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/mman.h>
#include <errno.h>

#define PAGE_SIZE 4096

//using brk()
void *malloc_brk(size_t size){
	printf("Using brk...\n");
	static void *brk_end = NULL;
	if(brk_end == NULL){
		brk_end = sbrk(0);
	}

	void *ptr = brk_end;
	if(brk(ptr+size) == -1){
		perror("Error incrementing brk");
		return NULL;
	}

	brk_end+= size;
	return ptr;

}

void *malloc_mmap(size_t size){
	printf("Using mmap...\n");
	return mmap(NULL,size,PROT_READ | PROT_WRITE, MAP_ANONYMOUS | MAP_PRIVATE, -1, 0);
}

void *custom_malloc(size_t size){
	if(size <= PAGE_SIZE){
		return malloc_brk(size);
	}else{
		return malloc_mmap(size);
	}
}

void custom_free(void *ptr, size_t size){
	if(ptr == NULL) return;
	munmap(ptr, size);
}

int main(){
	int *arr = custom_malloc(1100 * sizeof(int));
	if(!arr){
		perror("malloc_custom failed\n");
		return 1;
	}

	for(int i =0; i < 1100; i++){
		arr[i] = i;
	}

	custom_free(arr, 1100*sizeof(int));
	return 0;

}
