#include <stdlib.h>
#include "stringTable.h"
#include "strings.h"

/////////////////////////////////////////////
bool strTableCanFit(StringTable* t, char* str); 
void expandStrTable(StringTable* t); // encp
//////////////////////////////////////////////


StringTable* newStringTable() {
	char* buff = calloc(INITIAL_STRING_TABLE_SIZE, sizeof(char)); // TODO change to malloc
	StringTable* result = (StringTable*) malloc(sizeof(StringTable));
	
	buff[0] = '\0'; // better just initialize it... just in case...

	result->characterBuffer = buff;
	result->size = 1;
	result->capasity = INITIAL_STRING_TABLE_SIZE;
	return result;
}

// returns if the string can fit into the table
bool strTableCanFit(StringTable* t, char* str) {
	bool result = true;
	
	int len = strlen(str);
	if (len + t->size > t->capasity) {
		result = false;
	}
	return result;
}


// param: t - the table acted upon
// param: str - the string to be added
// return: the position in the array where the string starts
int addStrToStrTable(StringTable* t, char* str) {
	int result = t->size;

	if(!strTableCanFit(t, str)) {
		expandStrTable(t);
	}
	char* location = t->characterBuffer + t->size;
	strcpy(location, str);
	t->size++;
	return result; // the position in the array where the string starts
}


// returns the location of the str if its in the table.
int positionInStrTable(StringTable* t, char* str) {
	
	int result = 0;
	char* pointer = t->characterBuffer + 1;
	while(true) {
		int test = strcmp(pointer, str);
		if(test) {
			result = pointer - t->characterBuffer;
			break;
		}
		pointer = pointer + strlen(pointer); //TODO use stingIndexTable to search.
		if (pointer > (t->characterBuffer + t->size)) {
			break;
		}
	}
	return result;
}


// takes a table, and expends it, returning a table with twice the capasity
void expandStrTable(StringTable* t) {
	
	int size = t->size;
	int capasity = t->capasity * 2;
	char* charBuff = (char*) calloc(capasity, sizeof(char));

	StringTable temp = (StringTable) {.size = size, .capasity = capasity, .characterBuffer = charBuff };
	memcpy(charBuff, t->characterBuffer, t->size);	
	*t = temp;
}
