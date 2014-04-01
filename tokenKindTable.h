#ifndef TOKEN_KIND_TABLE_H
#define TOKEN_KIND_TABLE_H

#include <stdbool.h>
#include "stringIndexTable.h"

// TODO identifier, string literal, floating point literal, operator, punctuation...
typedef enum { 
	NONTERMINAL = 1,
	TERMINAL,
	OPERATOR
} TokenKind;

typedef struct {
	
	TokenKind* table;
	int size;
	int capasity;

} TokenKindTable;

TokenKindTable* tkTable;

TokenKindTable* newTokenKindTable();
TokenKind getTokenKind(TokenKindTable* table, Token token);
void addTokenToTKTable(TokenKindTable* table, Token token, TokenKind tk);
void expandTKTable(TokenKindTable* table);
bool TKTableIsFull(TokenKindTable* table);


#endif
