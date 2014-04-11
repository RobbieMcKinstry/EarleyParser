#include <stdlib.h>
#include <stdio.h>
#include "lex.h"

#define cIsFill (c <= ' ')
#define cIsAlpha (('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z'))
#define cIsDigit (c >= '0' && c <= '9')
#define cIsAlphanum (cIsAlpha || cIsDigit)

Lex* newLexer() {
	Lex* lex = (Lex*) malloc(sizeof(Lex));
	lex->lexeme = NULL;
	lex->next = '\0';
	lex->currentState = 0;
	lex->input = stdin;
}

// determine what kind of token the next lexeme is. 
// store that tokentype as an enum in lex.
// get the whole word.
// store the word in lex
// reallocate the memory.
// store the next character in lex
void lexicalAnalyze(Lex* lex) {

	char c = (*lex).next;
	while(cIsFill) { // removes all whitespace
		c = getchar();
	}
	
	char* word;
	word = (char*) malloc(100*sizeof(char));
	word[0] = c;
	int count = 1;

	if(cIsAlpha) { // scan in a nonterminal.
		(*lex).currentState = NONTERMINAL;
	} 
	
	else if(cIsDigit) { // c is a numeric literal
		(*lex).currentState = NUMERIC_LITERAL;
	} 
	
	else if (c == '"') { // c is a string literal
		(*lex).currentState = STRING_LITERAL;
	}
	
	else { // c is special
		(*lex).currentState = SPECIAL;
	}

	switch((*lex).currentState) {
	
		case NONTERMINAL:
			for(c = getchar(); cIsAlphanum; c = getchar()) {
				word[count] = c;
				count++;
			} // breaks when c is not an alphanum, so lex.next = c
			(*lex).next = c;
			(*lex).lexeme = (char*) realloc(word, count);
			// free call?
			break;

		case NUMERIC_LITERAL:
			for(c = getchar(); cIsDigit; c = getchar()) {
				word[count] = c;
				count++;
			} // breaks when c is not a digit

			// begin floating point case
			if(c == '.') { // then its possible that the lexeme is a decimal...
				char temp = c;
				c = getchar();
				if(cIsDigit)  { // if the char after the . is a digit
					word[count] = temp;
					count++;
					word[count] = c;
					count++;

					// get all digits after the decimal point
					for(c = getchar(); cIsDigit; c = getchar()) {
						word[count] = c;
						count++;
					}
				}
				// but what if its not a digit? 
				else {
					ungetc(c, stdin);
					c = temp;
				}

			} // end floating point case
			
			(*lex).next = c;
			(*lex).lexeme = (char*) realloc(word, count);
			break;

		case STRING_LITERAL:
			for(c = getchar(); c != '"'; c = getchar()) {
				word[count] = c;
				count++;
			} // breaks when c is \"
			word[count] = c;
			count++;
			(*lex).next = getchar(); // notice this is different than in the other cases, because now we know that the lexeme is terminaled when the last character is read, not like in the normal case when the character after the last charcter is read.
			(*lex).lexeme = (char*) realloc(word, count);
			break;
		
		// word is literally going to be only one character long
		case SPECIAL:
			(*lex).next = getchar(); // notice this is different than in the other cases, because now we know that the lexeme is terminaled when the last character is read, not like in the normal case when the character after the last charcter is read.
			(*lex).lexeme = (char*) realloc(word, count); 
			break;
	}
}
