#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H

typedef struct {
	
	TokenKindTable* tokenKindTable;
	GrammarCode* grammarCode;
	StringTable* stringTable;
	StringIndexTable* stringIndexTable;

} SymbolTable;

SymbolTable* newSymbolTable();
Token* addSentenceToSymbolTable();

#endif
