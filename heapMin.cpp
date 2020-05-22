
#include "heapMin.h"
#include <stdio.h>
#include <stdlib.h>
using namespace std;

HEAP Initilize(int n);
// This is heap.cpp

// creates a heap struct w/ size n and n num of ELEMENTS
// returns empty HEAP
HEAP Initilize(int n)
{
	HEAP* heap = NULL;	// creates new heap obj
	ELEMENT* NE = NULL;	// creates new element obj
	NE = new ELEMENT[n];
	heap = new HEAP;
	heap->capacity = n;
	heap->size = 0;
	heap->H = new ELEMENT[n];

	return *heap;
}

// mainatins max-heap property
void Heapify(HEAP *heap, int n)
{
	int smallest = n;
	int left = 2*n + 1;	// left node
	int right = 2*n + 2;	// right node
	
	// checks if child nodes are smaller than parent; if so-> switches/calls heapify again
	if(left < heap->size && heap->H[left].value < heap->H[smallest].value)
		smallest = left;
	if(right < heap->size && heap->H[right].value < heap->H[smallest].value)
		smallest = right;
	if(smallest != n)
	{
		int temp = heap->H[n].value;
		heap->H[n].value = heap->H[smallest].value;
		heap->H[smallest].value = temp;
		Heapify(heap, smallest);		// calls heapify for next step in heap struct
	} 
}

// takes empty heap and fills w/ elements from an array
// calls Heapify to create min-heap property
void BuildHeap(HEAP *heap, int arr[], int n)
{
	heap->size = n;			
        int i;
        for(i = 0; i < n; i++)			// transfers array to heap
        {       
            	heap->H[i].value = arr[i]; 
	}
	for(i = n/2-1; i >= 0; i--)		// calls heapify to order heap w/ min property
		Heapify(heap, i);
}

// Inserts new element
void Insert(HEAP *heap, int value)
{
	if(heap->size == heap->capacity)		// checks if any elements can be added
	{
		printf("Heap capacity reached. No more elements can be added\n");
		return;
	}
	int index = heap->size;		// for sorting purposes
	heap->size++;			// increases heap size
	heap->H[index].value = value;	// sets new value to last node in heap
	int parent = (index-1)/2;	// same code as in increase key
        // checks to see if parent value is greater than element; switches if so
	while(index > 0 && heap->H[index].value < heap->H[parent].value)
        {
          	int temp = heap->H[index].value;        // switches if parent is greater than
                heap->H[index].value = heap->H[parent].value;
                heap->H[parent].value = temp;
                index = (index-1)/2;
                parent = (index-1)/2;
       	}	
}

// Deletes/returns min value
int DeleteMin(HEAP *heap)
{
	int min = heap->H[0].value;
	heap->H[0].value = heap->H[heap->size-1].value;	// switches first node for last node
	heap->size--;					// deletes last node
	Heapify(heap, 0);				// calls heapify to resort heap
	return min;
}

// Decrease value at index
void DecreaseKey(HEAP *heap, int index, int value)
{
	if(heap->H[index].value < value)		// makes sure new value is smaller
		printf("Error: new key is smaller than current key\n");
	else
	{
		heap->H[index].value = value;		// sets to new value
		int parent = (index-1)/2;		
		while(index > 0 && heap->H[index].value < heap->H[parent].value)	
		{
			int temp = heap->H[index].value;	// switches if parent is greater than
			heap->H[index].value = heap->H[parent].value;
			heap->H[parent].value = temp;
			index = (index-1)/2;
			parent = (index-1)/2;
		}
	}
}

// Prints out Heap
void PrintHeap(HEAP heap)
{
	int i;
	for(i = 0; i < heap.size; i++)
		printf("%d ", heap.H[i].value);
	printf("\n");
}

