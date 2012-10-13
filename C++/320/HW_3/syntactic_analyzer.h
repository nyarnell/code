//******************************************************************* 
//                                                                    
//  Program:     syntactic_analyzer.h                                            
//                                                                     
//  Author:      Nathaniel Yarnell
//  Email:       nathanielbyarnell@gmail.com
//                                                                    
//  Lab Section: who needs labs
//                                                                    
//  Description: interface to syntactically analyze input               
//                                                                    
//  Date:        4/30/2012
//                                                                    
//*******************************************************************

//******************************************************************
//                                                                  
//  Function:   syntactic_analyzer(string input)
//                                                                  
//  Purpose:    initializes a new Lexical Analyzer with the input                                  
//                                                                  
//  Parameters:	input - it's input
//                                                                  
//  Calls:      NONE
//                                                                  
//******************************************************************

//******************************************************************
//                                                                  
//  Function:   expr
//                                                                  
//  Purpose:    begins an expression, which can be a term plus or minus
//				one or more terms.                           
//                                                                  
//  Parameters:	NONE
//                                                                  
//  Calls:      term()
//                    
//	Precondition: input is a valid expr
//
//	Postcondition: return the value of expr as float                                              
//******************************************************************
//******************************************************************
//                                                                  
//  Function:   expr
//                                                                  
//  Purpose:    begins an expression, which can be a term plus or minus
//				one or more terms.                           
//                                                                  
//  Parameters:	NONE
//                                                                  
//  Calls:      term()
//                    
//	Precondition: input is a valid expr
//
//	Postcondition: return the value of expr as float                                              
//******************************************************************
//******************************************************************
//                                                                  
//  Function:   term
//                                                                  
//  Purpose:    begins a term, which can be a factor multiplied or divided by one or more terms                           
//                                                                  
//  Parameters:	NONE
//                                                                  
//  Calls:      factor()
//                    
//	Precondition: input is a valid expr
//
//	Postcondition: return the value of term as float                                              
//******************************************************************
//******************************************************************
//                                                                  
//  Function:   factor
//                                                                  
//  Purpose:    begins a factor, which can be a number or an expr in parenthesis or a minus sign followed by a factor                           
//                                                                  
//  Parameters:	NONE
//                                                                  
//  Calls:      atoi()
//                    
//	Precondition: input is a valid expr
//
//	Postcondition: return the value of factor as a float                                             
//******************************************************************
//******************************************************************
//                                                                  
//  Function:   syntactic_error
//                                                                  
//  Purpose:    outputs some error message                         
//                                                                  
//  Parameters:	NONE
//                                                                  
//  Calls:      NONE
//                    
//	Precondition: NONE
//
//	Postcondition: NONE                                             
//******************************************************************
//******************************************************************
//                                                                  
//  Function:   lexical_error
//                                                                  
//  Purpose:    outputs some error message                         
//                                                                  
//  Parameters:	NONE
//                                                                  
//  Calls:      NONE
//                    
//	Precondition: NONE
//
//	Postcondition: NONE                                             
//******************************************************************

#ifndef SYNTACTIC_ANALYZER_H
#define SYNTACTIC_ANALYZER_H

#include "LexicalAnalyzer.h"

class syntactic_analyzer{
	public:
		LexicalAnalyzer *lexer;
		syntactic_analyzer(string input) { lexer = new LexicalAnalyzer(input);}
		float expr();
		float term();
		float factor();
		void syntactic_error();
		void lexical_error();
	private:
		//float data;
};

#endif