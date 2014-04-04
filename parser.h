#ifndef PARSER_H
#define PARSER_H

typedef struct {
	Lex* lexer;
	SymbolTable* symbolTable;
	FILE* grammarFile;
	FILE* sentenceFile;
} Parser;

void setGrammarFile(Parser* p, char* path);
void setSentenceFile(Parser* p, char* path);
Parser* newParser();
bootstrapGrammar(Parser* parser);

#endif
