#include <stdio.h>
#include <stdbool.h>
#include <stddef.h>
#include "mymalloc.h"
char heap[25000];
block *initialList=(void*)heap;

void breakFreeBlockIntoTwo(block *prevBlock,size_t blockSize){
	block *restFree=(void*)prevBlock+blockSize+sizeof(block);//setting rest of the block to the address where it should be
	restFree->size=prevBlock->size-blockSize-sizeof(block);
	restFree->allocated=0;
	restFree->next=prevBlock->next; /*prevBlock->next ==NULL when initializing the first block 
	otherwise it contains an adress of a previously allocated block */
	prevBlock->size=blockSize;
	prevBlock->next=restFree;
	prevBlock->allocated=1;
}
void mergeTwoAdjacentFree(){
	block *ptr=initialList;
	while(ptr->next!=NULL){
		if(ptr->allocated==0){
			if(ptr->next->allocated==0){
				ptr->size+=ptr->next->size+sizeof(block);
				ptr->next=ptr->next->next;
				ptr->allocated=0;
				break;
			}
		}
		ptr=ptr->next;
	}
}

void *myMalloc(size_t blockSize){
	block *ptr;
	if(!(initialList->size)){//if head is not initialized yet?
		//creating initial freeblock
		initialList->size=25000-sizeof(block);
		initialList->allocated=0;
		initialList->next=NULL;
	}
	ptr=initialList;
	while(((ptr->size<blockSize)||(ptr->allocated==1))&&(ptr->next!=NULL)){//traverse until find a sufficient freeblock found
		ptr=ptr->next;
	}
	if(ptr->size==blockSize){// if block found is free and equal to blocksize needed
		ptr->allocated=1;
		return (void*)(++ptr);// returning address of allocated block
	}else if((ptr->size)>=(blockSize+sizeof(block))){// if block found is free and >= to blockSize and sizeof(block)
		breakFreeBlockIntoTwo(ptr,blockSize);//passing to break block to two 
		return (void*)(++ptr);// returning address of allocated block 
	}
	else{// if no sufficient freespace found
		return NULL;
	}
		
}

void myFree(void* temp){
	if((temp>=(void*)heap)&&(temp<=(void*)(heap+25000))){/*checking whether the pointer we want to free
	 is in between range of the heap start and end */
		block *ptr=temp;
		--ptr;
		ptr->allocated=0;
		//should call mergeTwoAdjacentFree() twice because there can be three adjacent free blocks
		mergeTwoAdjacentFree();
		mergeTwoAdjacentFree();
	}
}
