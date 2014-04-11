#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

GrammarCode* newGrammarCode() {
	GrammarCode* result = (GrammarCode*) malloc(sizeof(GrammarCode));
	result->buffer = (char*) calloc(INITIAL_G_BUFFER_SIZE*sizeof(char));
	result->bufferSize = 1;
	result->bufferSize = INITIAL_G_BUFFER_SIZE;
	result->buffer[0] = '0'; // might as well initial the first value, so I don't seg fault on it.
	return result;
}

void expandGrammarCode(GrammarCode* gc) {
	GrammarCode* temp = (GrammarCode*) calloc(1, sizeof(GrammarCode));
	temp->buffer = (char*) calloc(temp->bufferCap*2, sizeof(char));
	temp->bufferSize = gc->bufferSize;
	temp->bufferCap = gc->bufferCap*2;
	(*gc) = (*temp)
}

void writeString(GrammarCode* gc, char* string) {
	int len = strlen(string);
	if (gc->bufferSize + len >= gc->bufferCap) {
		expandGrammar(gc);
	}
	for(int i = 0; i < len - 1; i++) {
		gc->buffer[i] = string[i];
	}
	gc->bufferSize = gc->bufferSize + len - 1;
}	

void writeInteger(GrammarCode* gc, char i) {
	if (gc->bufferSize + 1 >= bufferCap) {
		expandGrammar(gc);
	}
	gc->buffer[gc->bufferSize] = (char) i;
	gc->bufferSize++;
}

void writeChar(GrammarCode* gc, char c) {
	if (gc->bufferSize + 1 >= bufferCap) {
		expandGrammar(gc);
	}

	gc->buffer[gc->bufferSize] = c;
	gc->bufferSize++;
}

void convertLineToCode(GrammarCode* gc, char* line) {
	// write an equals sign, followed by a space into the buffer
	writeString(gc, "= ");
	
	char* line = skipLeadingWhitespace(line); // skip any whitespace/control characters
	// read until you reach another whitespace character, TODO: or until your reach an equals sign.
	char* endOfNonterminal = nextWhiteSpace(line);
	int distance = endOfNonterminal - line; // the number of characters in the nonterminal
	
	char* temp = (char*) malloc( 1 + distance * sizeof(char));
	
	// that string of characters gets written into the buffer next
	while(int i = 0; i < distance; i++) {
		temp[i] = line[i];
	}
	temp[distance + 1] = '\0';
	writeString(gc, temp);

	// now, we read in the equals sign
	equalsSign = skipLeadingWhitespace(endOfNonterminal); 
	if (equalsSign[0] != '=') {
		printf("We expected the next character to be an equals sign, but it was actually %s", equalsSign[0]);
	}
	char nonterminals = equalsSign + 1; // now, we have a bunch of nonterminals, new line terminated.
	int numberAlternatives = countAlternatives(nonterminals);

	for(int i = 0; i < numberAlternatives; i++) {
		// how many characters in this alternative?
		// read the first word in.
		// add it to the symbol table.
		// write it's Token to the grammar code.
	}




	for (int i = 0, char next; next != '\n'; next = line[++i]) {
		// process the alternatives
		// this won't work, because we need to write 0 for the last alternative!!!
		processAlternative(line);
	}
	
		// count the number of vertical bars
		// while you have one left: process alternative
		// shit! won't work because the number of vertical bars is not the number of alternatives!


	// split on the vertical bar character, now you have an array of char*
	// remember NOT to write the null terminator!
	// for each char*:
	// 	get its length, and write that integer to the buffer.
	// 	write the char* to the buffer
	// 	write a bar to the buffer
	//  for the last char*, instead of writing its length, write a 0 instead.
	//  write a period to the buffer
	//
	//  increase the buffer's size when necessary. 
	//  return the location of the first equals sign.
}

// returns a pointer to next non-whitespace non-control character
char* skipLeadingWhitespace(char* line) {
	while(line[0] <= ' ') 
		line = line + 1;
	return line;
}

// returns a pointer to the next whitespace character after the pointer
char* nextWhiteSpace(char* line) {
	while(line[0] > ' ')
		line = line + 1;
	return line;
}

int countAlternatives(char* line) {
	int count = 0;
	while(line[0] != '\n' || line[0] != '.') {
		if(line[0] == '|') {
			count++;
		}
	}
	return count + 1;
}
