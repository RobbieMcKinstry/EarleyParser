#ifndef STRING_INDEX_TABLE_H
#define STRING_INDEX_TABLE_H

#include <stdbool.h>

typedef int Token;

typedef struct {

	int* positionTable;
	int size;
	int capasity;

} StringIndexTable;

StringIndexTable stringIndexTable;

StringIndexTable* newStringIndexTable();
Token positionInTable(StringIndexTable* t, char* str);
bool strIndexTableIsFull(StringIndexTable* t);
void expandStrIndexTable(StringIndexTable* t);

#endif
