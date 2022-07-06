/*
 ============================================================================
 Aufgabe     : Datenstrukturen - Woche 10
 Autor       : Erik Kaufmann	
 Matrikel    :
 Version     : 1.0
 ============================================================================
 */
#include <stdbool.h>
#include <stdlib.h>
#include "dhbwgraphsolve.h"

//Ab hier Aufgaben

//Auf true setzen, damit Prim getestet wird
bool primImplemented() {
	return true;
}

//Berechnet den minimalen Spannbaum mittels Prim's Algorithmus
//Ausgabe: Kanten und Knoten, die zum minimalen Spannbaum gehoeren, sind markiert (marked=true)
void primMinimalSpanningTree(AdjNodeP *list)
{
	int length = 0;
	AdjNodeP current = *list;

	//// Länge ermitteln
	//while (current)
	//{
	//	length++;
	//	current = current->next;
	//}

	// Erste Node markiert
	current->marked = true;

	while (current)
	{
		// Prüfe die Wertigkeit der Kanten

	}
}

//Auf true setzen, damit Dijkstra getestet wird
bool dijkstraImplemented() {
	return false;
}

//Berechnet die kuerzesten Wege vom ersten Knoten der Adjazenzliste (meistens:A) zu allen anderen mit Dijkstra's Algorithmus
//Ausgabe: Kanten, die zu einem kuerzesten Weg gehoeren, sind markiert (marked=true)
//Knoten, die vom ersten Knoten erreichbar sind, sind markkiert (marked=true)
//In jedem Knoten steht als result die Distanz vom ersten Knoten der Adjazenzliste
void dijkstraFindShortestFromFirst(AdjNodeP *list) {

}

