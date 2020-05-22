
#include <stdio.h>
#include <stdlib.h>
#include "heapMin.h"

int main()
{
        // creates objects heap and k from heap.cpp
        struct HEAP heap;
        struct ELEMENT k;

	heap = Initilize(10);
	int arr[10] = {2, 4, 11, 8, 10, 49, 17, 250, 13, 32};
	BuildHeap(&heap, arr, 10);
	printf("Original min heap:");
	PrintHeap(heap);
	
	// tests if element can be inserted if size = capacity; should cause error
	printf("\nInsert: 50\n");
	Insert(&heap, 50);
	printf("\n");

	// deletes heap except for top 2 elements
	printf("Deletion/return min value section\n");
	while(heap.size > 2)
        {
                int min = DeleteMin(&heap);
                printf("\n");
                PrintHeap(heap);
                printf("Min element deleted: %d\n", min);
        }

	
	// inesertion
	printf("\n\nDeletion done; insertion section:\n");
	Insert(&heap, 10);
	PrintHeap(heap);
	Insert(&heap, 20);
	PrintHeap(heap);
	Insert(&heap, 40);
	PrintHeap(heap);
	Insert(&heap, 20);
	PrintHeap(heap);

	printf("\n\nInsertion done; Decrease key section:\n");
	
	PrintHeap(heap);
	DecreaseKey(&heap, 1, 9);
	printf("Element 2, from 20 to 9\n");
	PrintHeap(heap);
	DecreaseKey(&heap, 0, 5);
	printf("Element 1, from 9 to 5\n");
	PrintHeap(heap);
	DecreaseKey(&heap, 5, 10);
	printf("Element 6, from 49 to 10\n"); 
	PrintHeap(heap);

}
