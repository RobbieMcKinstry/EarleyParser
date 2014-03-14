#include "stringIndexTable.h"
#include <stdbool.h>

#include "stringTable.h"

#define INITIAL_STRING_INDEX_TABLE_CAP 1000 // subject to change

// this is the constructor for a StringIndexTable record. 
// return: a pointer to a new struct, with [0] reseverd.
StringIndexTable* newStringIndexTable() {
	
	StringIndexTable* result = (StringIndexTable*) malloc(sizeof(StringIndexTable));
	result->positionTable = (int*) calloc(INITIAL_STRING_INDEX_TABLE_CAP, sizeof(int));
	result->size = 1;
	result->capasity = INTIAL_STRING_INDEX_TABLE_CAP;

	result->positionTable[0] = 0; // just to initialize the value, and not leave it as NULL.

	return result;
}

// param: t, the stringIndexTable that you're using as a look up.
// param: str, the string who's token you want to find
// return: the token representing the string
Token positionInStrIndexTable(StringIndexTable* t, char* str) { 
	Token result = (Token) 0;
	for(int i = 1; i < size; i++) {
		int index = t->positionTable[i];
		char* tabledString =  stringTable->characterBuffer[index];
		int areEqual = strcmp(elem, str);
		if(areEqual) {
			result = (Token) i;
			break;
		}
	}
}

bool strIndexTableIsFull(StringIndexTable* t) {
	return t->size == t->capasity;
}

void expandStrIndexTable(StringIndexTable* t ) {
	StringIndexTable* result = (StringIndexTable*) malloc(sizeof(StringIndexTable));
	result->positionTable = (int*) calloc(2*t->capasity, sizeof(int));
	result-size = t->size;
	result->capasity = 2*t->capasity;

	result->positionTable[0] = 0; 
	t->positionTable = result->positionTable;
	t->size = result->size;
	t->capasity = result->capasity;
}
