#ifndef STRING_INDEX_TABLE_H
#define STRING_INDEX_TABLE_H

typedef int Token;

typedef struct {

	int* positionTable;
	int size;
	int capasity;

} StringIndexTable;

StringIndexTable stringIndexTable;

StringIndexTable* newStringIndexTable();
Token positionInTable(char*);

#endif
