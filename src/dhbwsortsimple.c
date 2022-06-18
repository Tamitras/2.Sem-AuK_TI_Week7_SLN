/*
 ============================================================================
 Aufgabe     : Sortieren - Woche 7
 Autor       : Erik Kaufmann
 Matrikel    : 1390365
 Version     : 1.1
 ============================================================================
 */
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "dhbwsortsimple.h"

 //Ab hier Aufgaben


 //Auf true setzen, damit BubbleSort getestet wird
bool BubbleSortImplemented() {
	return true;
}

//BubbleSort
void BubbleSortArray(Student_p* array, int count)
{
	Student_p* temp;

	//for (int i = 0; i < count; i++)
	//{
	//	printf("%s %d\n", array[i]->lastname, array[i]->matrnr);
	//}

	// count -1 --> array[n] --> [0]->[n-1] --> [n] knallt
	// Äußere Schleife zählt runter,
	for (int k = count - 1; k >= 0; k--)
	{
		for (int i = 1; i <= k; i++)
		{
			if (array[i - 1]->matrnr > array[i]->matrnr) // Prüfe, welche Mat-Nummer größer ist.
			{
				//swap
				temp = array[i];
				array[i] = array[i - 1];
				array[i - 1] = temp;
			}
		}
	}

	//printf("\n--------------------------------\n");

	//for (int f = 0; f < count; f++)
	//{
	//	printf("%s %d\n", array[f]->lastname, array[f]->matrnr);
	//}

	return;
}


//Auf true setzen, damit SelectionSort getestet wird
bool SelectionSortImplemented() {
	return true;
}


void Swap(Student_p* studA, Student_p* studB, int indexA, int indexB)
{
	//printf("\nTausche [%d] %s %d mit [%d]%s %d\n", indexB,(*studB)->lastname, (*studB)->matrnr, indexA,(*studA)->lastname, (*studA)->matrnr);
	Student_p* temp = *studA;
	*studA = *studB;
	*studB = temp;
}

//SelectionSort
void SelectionSortArray(Student_p* array, int count)
{
	//for (int i = 0; i < count; i++)
	//{
	//	printf("%s %d\n", array[i]->lastname, array[i]->matrnr);
	//}

	if (array != NULL)
	{
		int smallestElementIndex = 0;

		bool swap = false;

		for (int i = 0; i < count; i++) // Jedes Element wird geprüft
		{
			for (int k = i + 1; k < count; k++) // Und bis zum Ende durchlaufen
			{
				if (array[i]->matrnr > array[k]->matrnr)
				{
					// new smallest elemment and index
					array[i]->matrnr = array[k]->matrnr;
					smallestElementIndex = k;
					swap = true;
				}
			}

			if (swap)
			{
				//swap pointer
				Swap(&array[smallestElementIndex], &array[i], smallestElementIndex, i);
				swap = false;

				//for (int f = 0; f < count; f++)
				//{
				//	printf("[%d] %s %d\n", f, array[f]->lastname, array[f]->matrnr);
				//}
			}
		}
	}

	//printf("\n--------------------------------\n");

	//for (int f = 0; f < count; f++)
	//{
	//	printf("%s %d\n", array[f]->lastname, array[f]->matrnr);
	//}

	return;
}
