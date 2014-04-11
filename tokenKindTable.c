#include <stdlib.h>
#include "tokenKindTable.h"
#include <stdbool.h>

#define INITIAL_TK_TABLE_SIZE 1000

TokenKindTable* newTokenKindTable() {
	TokenKindTable* result = (TokenKindTable*) malloc(sizeof(TokenKindTable));
	result->table = (TokenKind*) calloc(INITIAL_TK_TABLE_SIZE, sizeof(TokenKind));
	result->size = 1;
	result->capasity = INITIAL_TK_TABLE_SIZE;
	return result;
}

// given a token (which maps to a TK for that token), return it's TK.
TokenKind getTokenKind(TokenKindTable* table, Token token) {
	return table->table[token];
}

// given a token (an index), set it's tk.
void addTokenToTKTable(TokenKindTable* table, Token token, TokenKind tk) {
	if(TKTableIsFull(table)) {
		expandTKTable(table);
	}
	
	table->table[token] = tk;
}


void expandTKTable(TokenKindTable* table) {
	TokenKind* temp = (TokenKind*) calloc(2*table->capasity, sizeof(TokenKind));
	TokenKindTable* result = (TokenKindTable*) malloc(sizeof(TokenKindTable));
	result->table = temp;
	result->size = table->size;
	result->capasity = table-> 2 * capasity;
	*table = *result;
}

bool TKTableIsFull(TokenKindTable* table) { 
	return table->size == table->capasity;
}
