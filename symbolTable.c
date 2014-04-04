#include <stdlib.h>
#include "symbolTable.h"
#include "tokenKindTable.h"
#include "grammarCode.h"
#include "stringTable.h"
#include "stringIndexTable.h"

SymbolTable* newSymbolTable() {
	SymbolTable* sym = malloc(sizeof(SymbolTable));
	sym->tokenKindTable = newTokenKindTable();
	sym->grammarCode = newGrammarCode();
	sym->stringTable = newStringTable();
	sym->stringIndexTable = newStringIndexTable();
	return sym;
}
