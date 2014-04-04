typedef enum {
	NONTERMINAL, NUMERIC_LITERAL, STRING_LITERAL, SPECIAL 
} TokenType;

typedef struct {
	FILE* input;
	char* lexeme;
	TokenType currentState;
	char next;
} Lex;

Lex* newLexer();
void lexicalAnalyze(Lex* lex);
