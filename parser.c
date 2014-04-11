#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "symbolTable.h"
#include "frame.h"

void setGramarFile(Parser* p, char* path) {
	p->grammarFile = fopen(path, "r");
}
void setSentenceFile(Parser* p, char* path) {
	p->sentenceFile = fopen(path, "r");
}

Parser* newParser() {
	Parser* p = (Parser*) malloc(sizeof(Parser));
	p->symbolTable = newSymbolTable();
	p->lexer = newLexer();
	return p;
}

void bootstrapGrammar(Parser* parser) {
	FILE* grammar = parser->grammarFile;
	char* nextLine;
	if (fgets(nextLine, 1000, grammar) != NULL) {
		convertLineToCode(parser->grammarCode, nextLine);
	}
	fclose(grammar);
}

Token* addSentenceToSymbolTable(Parser* p) {

	Token* result = calloc(10, sizeof(Token));
	unsigned int size = 0;
	unsigned int cap = 10;

	Lex* lex = p->lexer;
	lex->input = p->sentenceFile;
	while(lex->next != NULL) {
		lexicallyAnalyze(lex);
		Token t = addStrToStrIndexTablep(p->symbolTable, p->stringTable, lex->lexeme);
	
		if(size == cap) {
			cap *= 2;
			Token* temp = calloc(cap, sizeof(Token));
			memcpy(temp, result, sizeof(Token) * size);
			result = temp;
			size++;
		}
			result[size] = t;
	}
	return result;
}

/*
int main(int argc, char *argv[]) {
	
	if(argc < 3) { // assert that the user send two command line arguments, the path to the grammar specification and the path to the sentence.
		printf("Not enough arguments.\n");
		printf("%s\n%s", argv[0], argv[1]);
		return 1;
	}

	Parser* p = (Parser*) malloc(sizeof(Parser));
	setGrammarFile(p, argv[1]);
	setSentenceFile(p, argv[2]);

	Frame* q1 = newFrame(); //TODO: does newFrame() exist?
	Frame* q2 = newFrame();

	// TODO: first, bootstrap your grammar. bootstrap implemented, but convertLineToCode, required for bootstrap, not implemented
	bootstrapGrammar(p);
	Token* userInput = addSentenceToSymbolTable(p->symbolTable);

	// now, make the initial frame, pointing to the sentence root.
	Frame* frameNaut = newFrame(); 
	frameNaut->ic = 1; // set the grammar code to point to the sentence production. -- that should be position 1
	frameNaut->column = 0;

	while(q1.qLink != NULL || q2.q:ink != NULL) {
		if(q1.qLink != NULL) {
			Frame* currentFrame = q1->qLink;
			char* instruction = p->symbolTable->grammarCode->buffer + currentFrame->ic; // instruction points to the next instruction in the  grammarBuffer
			bool isAlternative = instruction[0] == '='; // its an alternative if the character at that spot is an equals sign.
			if (isAlternative) {
				
				char distanceToNextAlternative = (instruction+ 2)[0]; // grab the ic + 2, the character two positions after the = is the distance to the second alternative.
				while(distanceToNextAlternative) {
					Frame* nextAlt = newFrame(); // that means we're not on the last alternative for that production yet.
					nextAlt->ic = instruction - parser->symbolTable->grammarCode->buffer; // distance into the buffer is (the current - the start of the buffer)
					nextAlt->caller = currentFrame; // //// TODO use a switch statement!
					nextAlt->qLink = currentFrame->qLink;
					q1->qLink = nextAlt;
					distanceToNextAlternative = (instruction + distanceToNextAlternative)[1]; // uses index 1 because otherwise we'd point directly to a |
				}
			} else { // then its a sequence
					// 	if its a sequence: 
					// 		if its an $: its a terminal:
					// 		if its a period, 
					// 			return.
					// 		else
					// 			test if the user token matches on that terminal.
					// 		if its not a $, then its a nonterminal, 
					// 			check memo,
					// 			if no return exists, 
					// 				find the location in the grammar of that token, and point to it in a new frame.
			}



			// what if you recognize but youre not at the end of the input? you recognize a prefix of what the user input
			// what if its ambiguous? and there are more returns to the highest level thing?2

		} else { // handle the case where we advance the input token, and swap the queues.
			free(*q1); // will this actually do the job recursively?
			q1 = q2;
			q2 = newFrame();
			userInput++;
		}
	}
	// then there is no valid parse. return a failure to recognize command.

	return 0;
}
*/
