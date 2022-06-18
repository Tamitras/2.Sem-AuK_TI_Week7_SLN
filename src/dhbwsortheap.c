/*
 ============================================================================
 Aufgabe     : Sortieren - Woche 9
 Autor       : Erik Kaufmann
 Matrikel    : 1390365
 Version     : 1.0
 ============================================================================
 */
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "dhbwsortheap.h"

void heapify(Student_p* array, int count, int max);


//Ab hier Aufgaben

//Auf true setzen, damit Heapsort getestet wird
bool HeapSortImplemented()
{
	return true;
}

//Hilfsfunktionen

//Lasse kleinen Knoten nach unten sinken
void HeapBubbleDown(Student_p* array, int nodeIndex, int end)
{

}

//Stellt Heap-Eigenschaft in einem Array (als Binaerbaum interpretiert) her
void Heapify(Student_p* array, int count)
{
	// Prüfe ob kompletter Baum ge-heapyfied werden muss
	Student_p* root = NULL;
	int max = 0;

	if (array[0] != NULL)
	{
		root = array;
		max = (*root)->matrnr; // Set root element as max

		for (int i = count / 2 - 1; i >= 0; i--)
		{
			int f = count / 2;
			int t = f - 1;

			heapify(array, count, i);
		}
	}
}

void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void heapify(Student_p* array, int count, int max)
{
	// Find largest among root, left child and right child

	// Initialize largest as root
	int largest = max;

	// left = 2*i + 1
	int left = 2 * max + 1;

	// right = 2*i + 2
	int right = 2 * max + 2;

	// If left child is larger than root
	if (left < count && array[left]->matrnr > array[largest]->matrnr)
	{
		largest = left;
	}

	// If right child is larger than largest 
	  // so far
	if (right < count && array[right]->matrnr > array[largest]->matrnr)
	{
		largest = right;
	}

	// Swap and continue heapifying if root is not largest
	// If largest is not root
	if (largest != max) {

		swap(&array[max], &array[largest]);

		// Recursively heapify the affected 
		// sub-tree
		heapify(array, count, largest);
	}

	return;
}


//Heapsort mit Array
//Tipp: Hilfsfunktionen benutzen
void HeapSortArray(Student_p* array, int count)
{
	for (int i = 0; i < count; i++)
	{
		printf("%s %d\n", array[i]->lastname, array[i]->matrnr);
	}
	Heapify(array, count);

	printf("\n------------------------\n");

	for (int i = 0; i < count; i++)
	{
		printf("%s %d\n", array[i]->lastname, array[i]->matrnr);
	}
}


