/*
 ============================================================================
 Aufgabe     : Sortieren - Woche 7
 Autor       : Erik Kaufmann
 Matrikel    : 1390365
 Version     :
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

}


//Auf true setzen, damit SelectionSort getestet wird
bool SelectionSortImplemented() {
	return true;
}

//SelectionSort
void SelectionSortArray(Student_p* array, int count)
{
	if (array != NULL)
	{
		int smallestElement = 0;
		int smallestElementIndex = 0;

		int swapElement = -1;
		int swapElementIndex = -1;

		char* smallestLastName = malloc(sizeof(char));
		char* swapLastName = malloc(sizeof(char));

		//for (int i = 0; i < count; i++)
		//{
		//	printf("[%d] %d %s \n", i, array[i]->matrnr, array[i]->lastname);
		//}


		for (int i = 0; i < count; i++) // Jedes Element wird geprüft
		{
			smallestElement = array[i]->matrnr;

			//printf("Weiter mit %d\n", smallestElement);

			for (int k = i+1; k < count; k++) // Und bis zum Ende durchlaufen
			{
				//printf("[%d] Vergleiche %d mit %d\n",k, array[i]->matrnr, array[k]->matrnr);

				int links = array[i]->matrnr;
				int rechts = array[k]->matrnr;

				if (links < rechts)
				{
					if (smallestElement > links)
					{
						//printf("\nNew smallest element found! %d [%d]\n", links, i  );

						swapElement = smallestElement;
						swapElementIndex = smallestElementIndex;

						smallestElement = links;
						smallestElementIndex = i;
					}
				}
				else if(smallestElement > rechts)
				{
					//printf("\nNew smallest element found! %d [%d]\n", rechts, k);

					swapElement = links;
					swapElementIndex = i;

					smallestElement = rechts;
					smallestElementIndex = k;
				}
			}
			

			if (smallestElementIndex == i)
			{
				//printf("Kein Swap noetig, aktuelles Element %d index [%d] ist bereits an der richtigen Stelle\n",smallestElement, smallestElementIndex);
			}
			else
			{
				//swap
				//printf("Tausche %d [%d] mit neuem smallest: %d [%d]\n\n", swapElement, swapElementIndex, smallestElement, smallestElementIndex);

				smallestLastName = array[smallestElementIndex]->lastname;
				swapLastName = array[swapElementIndex]->lastname;

				array[swapElementIndex]->lastname = smallestLastName;
				array[swapElementIndex]->matrnr = smallestElement;

				array[smallestElementIndex]->lastname = swapLastName;
				array[smallestElementIndex]->matrnr = swapElement;


				//for (int i = 0; i < count; i++)
				//{
				//	printf("[%d] %d %s \n", i, array[i]->matrnr, array[i]->lastname);
				//}
			}
		}


		//for (int i = 0; i < count; i++)
		//{
		//	printf("[%d] %d %s \n", i, array[i]->matrnr, array[i]->lastname);
		//}
	}
}
