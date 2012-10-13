// Name: Nathaniel Yarnell
// Date: 5/29/2012
// Description: This file contains the interface of the class checkers


#ifndef CHECKERS_H
#define CHECKERS_H
#include <iostream>
#include <cctype>
#include <iomanip>
#include "game.h"
#include "piece.h"


namespace main_savitch_14{
	class checkers: public game{
		public:
			game* clone() const { return new checkers(*this); }
			void restart();
			void display_status() const;
			bool is_legal(const std::string& move) const;
			void make_move(const std::string& move);
			bool legal_jump( int curcol, int currow, int destcol, int destrow, piece future[][8] ) const;
			bool make_jump( int curcol, int currow, int destcol, int destrow, piece future [][8] );
			bool is_game_over() const;
			who winning() const;
			int evaluate() const;
			void compute_moves( std::queue<std::string>& moves) const;
			
		private:
			piece board[8][8];
	};
}

#endif