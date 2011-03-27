#include <stdio.h>
#include <stdlib.h>

struct Knoten {
	int zahl;
	struct Knoten *next;
};

void add(struct Knoten **node, int zahl) {
	struct Knoten *mKnoten;
	struct Knoten *it = *node;

	mKnoten = malloc(sizeof(*mKnoten));
	mKnoten->zahl = zahl;
	mKnoten->next = NULL;

	if(it != NULL) {
		while(it->next != NULL) {
			it = it->next;
		}
		it->next = mKnoten;
	} else {
		*node = mKnoten;
	}
}

void ausgeben(struct Knoten *l) {
	struct Knoten *liste;
	liste = l;
	printf("%i\n" , liste->zahl);
	while(liste->next != NULL) {
		liste = liste->next;
		printf("%i\n", liste->zahl);
	}
}

int main() {
	int i = 0;
	struct Knoten *liste;
	liste = NULL;

	add(&liste, 1);
	add(&liste, 3);
	add(&liste, 2);

	ausgeben(liste);
}
