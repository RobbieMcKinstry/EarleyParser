#include <stdlib.h>
#include <stdio.h>
#include "symbolTable.h"

void setGramarFile(Parser* p, char* path) {
	p->grammarFile = fopen(path, "r");
}
void setSentenceFile(Parser* p, char* path) {
	p->sentenceFile = fopen(path, "r");
}

Parser* newParser() {
	Parser* p = (Parser*) malloc(sizeof(Parser));
	p->symbolTable = newSymbolTable();
	p->lexer = 
}

void bootstrapGrammar(Parser* parser) {
	FILE* grammar = parser->grammarFile;
	char* nextLine;
	if (fgets(nextLine, 1000, grammar) != NULL) {
		convertLineToCode(parser->grammarCode, nextLine);
	}
	fclose(grammar);
}

int main(int argc, char *argv[]) {
	
	if(argc < 3) {
		printf("Not enough arguments.\n");
		printf("%s\n%s", argv[0], argv[1]);
		return 1;
	}

	Parser* p = (Parser*) malloc(sizeof(Parser));
	setGrammarFile(argv[1]);
	setSentenceFile(argv[2]);

	// implement earley's algorithm.
	
	// TODO: first, bootstrap your grammar.
	bootstrapGrammar(p);

	// second, open a text file with the Sentence in it.
	// TODO: Add every lexeme in the file to the symbol table, and maintain a list of tokens in the sentence.
	Token* userInput = addSentenceToSymbolTable(parser->symbolTable);
	
	Frame* frameNaut = newFrame();
	frameNaut->
	// set the grammar code to point to the sentence production. -- that should be position 1
	
	Frame* q1 = newFrame(); //TODO: does newFrame() exist?
	Frame* q2 = newFrame();

	while(q1.qlink != NULL || q2.qlink != NULL) {
		if(q1.qlink != NULL) {
			
		} else { // handle the case where we advance the input token, and swap the queues.
		}
	}

	return 0;
}
