#ifndef STRING_TABLE_H
#define STRING_TABLE_H

#include "stdbool.h"

#define INITIAL_STRING_TABLE_SIZE 1000


typedef struct {

	char* characterBuffer;
	int size;
	int capasity;

} StringTable;

StringTable* stringTable;

StringTable* newStringTable();

bool strTableCanFit(StringTable* t, char* str);
void addStrToStrTable(StringTable* t, char* str);
int positionInStrTable(StringTable* t, char* str);
void expandStrTable(StringTable* t);

#endif
