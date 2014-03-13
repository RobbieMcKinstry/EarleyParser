#include "tokenKindTable.h"
#include <stdbool.h>

#define INITIAL_TK_TABLE_SIZE 1000

TokenKindTable* newTokenKindTable() {
	TokenKind* temp = (TokenKind*) calloc(INITIAL_TK_TABLE_SIZE, sizeof(TokenKind));
	TokenKindTable result = {.table = temp, .size = 1, .capasity = INITIAL_TK_TABLE_SIZE};
	return &result;
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

// TODO implement
void expandTKTable(TokenKindTable* table) {
	
}

bool TKTableIsFull(TokenKindTable* table) { 
	bool result = true;
	for(int i = 1; i < size; i++) {
		if(!table=->table[i]) {
			result = false;
			break;
		}
	}
	return result;
}
