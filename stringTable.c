#include "stringTable.h"
#include "strings.h"


StringTable* newStringTable() {
	char* buff = calloc(INITIAL_STRING_TABLE_SIZE, sizeof(char));
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

void addStrToStrTable(StringTable* t, char* str) {
	char* location = t->characterBuffer + t-size;
	strcpy(location, str);
}


// returns the location of the str if its in the table.
int positionInStrTable(StringTable* t, char* str) {
	
	int result = 0;
	char* pointer = t->charcterBuffer + 1;
	while(true) {
		int test = strcmp(pointer, str);
		if(test) {
			result = pointer - t-characterBuffer;
			break;
		}
		pointer = pointer + strlen(pointer);
	}
	return result;
}

// takes a table, and expends it, returning a table with twice the capasity
void expandStrTable(StringTable* t) {
	
	int size = t->size;
	int capasity = t->capasity * 2;
	char* charBuff = (char*) calloc(capasity, sizeof(char));

	StringTable temp = (StringTable) {.size = size, .capasity = capasity, .characterBuffer = charBuff };
	memcpy(charBuff, t->characterBuff, t->size);
	
	t = &temp;
}
