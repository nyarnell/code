// Name: Nathaniel Yarnell
// Date: 5/29/2012
// Description: This file contains the interface of the class piece

#ifndef PIECE_H
#define PIECE_H

namespace main_savitch_14{
	class piece{

		public:
			piece() { white = false; black = false; king = false; }
			
			void set_white(bool w) { white = w; }
			void set_black(bool b) { black = b; }
			void set_king(bool k) {king = k; }
			
			bool is_white()const { return white; }
			bool is_black()const { return black; }
			bool is_king()const { return king; }
			bool is_empty()const { return ( !white && !black ); }
		private:
			bool white;
			bool black;
			bool king;
	};
}

#endif