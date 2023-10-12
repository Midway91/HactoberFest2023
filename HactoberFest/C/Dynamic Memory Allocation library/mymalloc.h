#include <stdio.h>
#include <stdbool.h>
#include <stddef.h>



struct block{
	size_t size;
	bool allocated;
	struct block *next;
}typedef block; 

void *myMalloc(size_t blockSize);
void myFree(void* temp);
void mergeTwoAdjacentFree();
void breakFreeBlockIntoTwo(block *prevBlock,size_t blockSize);
