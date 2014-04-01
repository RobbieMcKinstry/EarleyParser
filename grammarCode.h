#ifndef GRAMMAR_CODE_H
#define GRAMMAR_CODE_H

#define INITIAL_G_BUFFER_SIZE 1000
typedef struct {
	
	char* buffer;
	unsigned int bufferSize;
	unsigned int bufferCap;
	
	// number of productions ?
	// list of production starting points
	// list of production names

} GrammarCode;

GrammarCode* newGrammarCode(); // done
void expandGrammar(GrammarCode* gc); // done, needs encapsulated.
void convertLineToCode(char* line);
void writeString(char* string);
void writeInt(int i);
void writeChar(char c);
void openGrammarFile();

#endif
