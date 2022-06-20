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

 //Ab hier Aufgaben

 //Auf true setzen, damit Heapsort getestet wird
bool HeapSortImplemented()
{
	return true;
}

//Hilfsfunktionen
void Swap1(Student_p* studA, Student_p* studB, int indexA, int indexB)
{
	printf("\nTausche [%d] %s %d mit [%d]%s %d\n", indexB, (*studB)->lastname, (*studB)->matrnr, indexA, (*studA)->lastname, (*studA)->matrnr);
	Student_p* temp = *studA;	// save studA in a temp variable
	*studA = *studB;			// overwrite studA with studB
	*studB = temp;				// asign studB with the old studA (temp)
}

//Lasse kleinen Knoten nach unten sinken
void HeapBubbleDown(Student_p* array, int nodeIndex, int end)
{
	printf("BubbleDown\n");
	// Initialize max as root
	int max = end;

	int leftChild = 2 * end + 1;
	int rightChild = 2 * end + 2;

	// if leftChild is bigger than parent
	if (leftChild < nodeIndex && array[leftChild]->matrnr > array[max]->matrnr)
	{
		max = leftChild;
	}

	// If rightChild is bigger than parent
	if (rightChild < nodeIndex && array[rightChild]->matrnr > array[max]->matrnr)
	{
		max = rightChild;
	}

	// If max is not root
	if (max != end)
	{
		// swap last mit max, also kleinstes Element mit ParentNode
		Swap1(&array[end], &array[max], end, max);

		// Rekursiver Aufruf, um nach dem Vertauschen weiter zu prüfen.
		HeapBubbleDown(array, nodeIndex, max);
	}
}

//Stellt Heap-Eigenschaft in einem Array (als Binaerbaum interpretiert) her
void Heapify(Student_p* array, int count)
{
	int offset = 1;
	// Kompletten Tree auf MaxHeap bringen (Kein Parent ist kleiner als eines seiner childs)
	// Durchlaufe alle 3er Gruppen (Parent + LeftChild + RightChild)
	// von unten nach oben und schiebe den größeren Knoten nach oben,
	// bzw. tausche den Parent mit dem größten Child
	// i=count / 2 -1 --> 3/2 -1 = 0 --> root
	// 5/2 -1 = 1 --> leftChild von Root
	// 7/2 -1 = 2 --> rightChild von Root
	// 9/2 -1 = 3 --> leftChild von leftChild von Root
	// hiermit wird immer das Parent eines Blocks bzw. einer Gruppe ermittelt.
	for (int i = count / 2 - offset; i >= 0; i--)
	{
		HeapBubbleDown(array, count, i);

		printf("\n------------------------\n");

		for (int f = 0; f < count; f++)
		{
			printf("[%d] %s %d\n", f, array[f]->lastname, array[f]->matrnr);
		}

		printf("\n------------------------\n");
	}

	// Tauschen + Heapify = Sort
	for (int i = count - offset; i > 0; i--) {

		// Tausche Root mit dem letzten element
		Swap1(&array[0], &array[i], 0, i);

		// Heapify ab der Wurzel
		HeapBubbleDown(array, i, 0);

		printf("\n------------------------\n");
		for (int f = 0; f < count; f++)
		{
			printf("[%d] %s %d\n", f, array[f]->lastname, array[f]->matrnr);
		}
		printf("\n------------------------\n");
	}
}

//Heapsort mit Array
//Tipp: Hilfsfunktionen benutzen
void HeapSortArray(Student_p* array, int count)
{
	//for (int f = 0; f < count; f++)
	//{
	//	printf("[%d] %s %d\n", f, array[f]->lastname, array[f]->matrnr);
	//}

	Heapify(array, count);

	//printf("\n------------------------\n");

	//for (int f = 0; f < count; f++)
	//{
	//	printf("[%d] %s %d\n", f, array[f]->lastname, array[f]->matrnr);
	//}
}
