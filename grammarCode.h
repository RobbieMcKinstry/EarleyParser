#ifndef GRAMMAR_CODE_H
#define GRAMMAR_CODE_H

#define INITIAL_G_BUFFER_SIZE 1000
typedef struct {
	
	char* buffer;
	unsigned int bufferSize;
	unsigned int bufferCap;

} GrammarCode;

GrammarCode* newGrammarCode();
void expandGrammarCode(GrammarCode*);
void writeString(GrammarCode* gc, char* string);
void writeInteger(GrammarCode* gc, char i);
void writeChar(GrammarCode* gc, char c);
void convertLineToCode(char* line);
char* skipLeadingWhitespace(char* line);
char* nextWhiteSpace(char* line);
void printGrammarCode(GrammarCode* gc);
void openGrammarFile();

	// number of productions ?
	// list of production starting points
	// list of production names

} GrammarCode;

#endif
