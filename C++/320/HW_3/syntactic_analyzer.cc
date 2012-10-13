//******************************************************************* 
//                                                                    
//  Program:     syntactic_analyzer.cc                                            
//                                                                     
//  Author:      Nathaniel Yarnell
//  Email:       nathanielbyarnell@gmail.com
//                                                                    
//  Lab Section: who needs labs
//                                                                    
//  Description: implementationt to syntactically analyze input                  
//                                                                    
//  Date:        4/30/2012
//                                                                    
//*******************************************************************

#include "syntactic_analyzer.h"
#include<cstdlib>
#include<iostream>

float syntactic_analyzer::expr(){
	float data;
	data = term();
	while ( lexer->nextToken_ == lexer->PLUS_ || lexer->nextToken_ == lexer->MINUS_ ) {
		float t;
		if ( lexer->nextToken_ == lexer->PLUS_ ){
			lexer->lex();
			if ( lexer->nextToken_ == lexer->UNKNOWN_ ) { lexical_error(); }
			if ( lexer->nextToken_ == lexer->EOF_ ) { syntactic_error(); }
			t = term();
			data+=t;
		}
		else if ( lexer->nextToken_ == lexer->MINUS_ ){
			lexer->lex();
			if ( lexer->nextToken_ == lexer->UNKNOWN_ ) { lexical_error(); }
			if ( lexer->nextToken_ == lexer->EOF_ ) { syntactic_error(); }
			t = term();
			data-=t;
		}
	}
	return data;
}

float syntactic_analyzer::term(){
	float data;
	data = factor();
	while ( lexer->nextToken_ == lexer->STAR_ || lexer->nextToken_ == lexer->SLASH_ ) {
		float t;
		if ( lexer->nextToken_ == lexer->STAR_ ){
			lexer->lex();
			if ( lexer->nextToken_ == lexer->UNKNOWN_ ) { lexical_error(); }
			if ( lexer->nextToken_ == lexer->EOF_ ) { syntactic_error(); }
			t = factor();
			data = data * t;
		}
		else if ( lexer->nextToken_ == lexer->SLASH_ ){
			lexer->lex();
			if ( lexer->nextToken_ == lexer->UNKNOWN_ ) { lexical_error(); }
			if ( lexer->nextToken_ == lexer->EOF_ ) { syntactic_error(); }
			t = factor();
			data = data / t;
		}
	}
	return data;
}

// float syntactic_analyzer::term(){
	// float data[0] = element();
	// while ( lexer->nextToken_ == lexer->STAR_ || lexer->nextToken_ == lexer->SLASH_ ) {
		// float t;
		// if ( lexer->nextToken_ == lexer->STAR_ ){
			// lexer->lex();
			// if ( lexer->nextToken_ == lexer->UNKOWN_ ) { lexical_error(); }
			// if ( lexer->nextToken_ == lexer->EOF_ ) { syntactic_error(); }
			// t = element();
			// data[0] = data[0] * t;
		// }
		// else if ( lexer->nextToken_ == lexer->SLASH_ ){
			// lexer->lex();
			// if ( lexer->nextToken_ == lexer->UNKOWN_ ) { lexical_error(); }
			// if ( lexer->nextToken_ == lexer->EOF_ ) { syntactic_error(); }
			// t = element();
			// data[0] = data[0] / t;
		// }
	// }
	// return data[0];
// }

float syntactic_analyzer::factor(){
	float data;
	if ( lexer->nextToken_ == lexer->NUMBER_ ){
		data=atoi( lexer->nextLexeme_.c_str() );
		lexer->lex();
		if ( lexer->nextToken_ == lexer->UNKNOWN_ ) { lexical_error(); }
		else if ( lexer->nextToken_ == lexer->RPAR_ ) { syntactic_error(); }
		else if ( lexer->nextToken_ == lexer->LPAR_ ) { syntactic_error(); }
		return data;
	}
	else if ( lexer->nextToken_ == lexer->LPAR_ ){
		lexer->lex();
		if ( lexer->nextToken_ == lexer->UNKNOWN_ ) { lexical_error(); }
		if ( lexer->nextToken_ == lexer->EOF_ ) { syntactic_error(); }
		data = expr();
		if ( lexer->nextToken_ == lexer->RPAR_ ) lexer->lex();
		else syntactic_error();
		return data;
	}
	else if ( lexer->nextToken_ == lexer->MINUS_ ) {
		lexer->lex();
		if ( lexer->nextToken_ == lexer->UNKNOWN_ ) { lexical_error(); }
		if ( lexer->nextToken_ == lexer->EOF_ ) { syntactic_error(); }
		data = factor();
		return (0-data);
		/* This nicely works out so that multiple minus signs
		cancel each other out */
	}
	else if ( lexer->nextToken_ == lexer->UNKNOWN_ ) { lexical_error(); }
	else syntactic_error();
}

void syntactic_analyzer::syntactic_error(){
	cout << "syntactic error! And fun junk values!" << endl;
}

void syntactic_analyzer::lexical_error(){
	cout << "lexical error! And fun junk values!" << endl;
}