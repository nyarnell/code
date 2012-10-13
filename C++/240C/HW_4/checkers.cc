// Name: Nathaniel Yarnell
// Date: 5/29/2012
// Description: This file contains the implementation of the class checkers

#include "checkers.h"
#include "colors.h"

namespace main_savitch_14{

	void checkers::restart(){
		for (int i=0; i < 8; i++){
			for (int j=0; j < 8; j++){
				if ( ( i==0 || i==2) && j%2==1 ) board[i][j].set_black(true);
				if ( i==1 && j%2==0 ) board[i][j].set_black(true);
				if ( (i==5 || i==7) && j%2==0 ) board[i][j].set_white(true);
				if ( i==6 && j%2==1 ) board[i][j].set_white(true);
			}
		}
		game::restart();
	}
	
	void checkers::display_status() const{
		//std::cout << std::string( 100, '\n' );
		std::cout << std::setw(6) << " " << "a" << std::setw(8) << " ";
		std::cout << "b" << std::setw(8) << " ";
		std::cout << "c" << std::setw(8) << " ";
		std::cout << "d" << std::setw(8) << " ";
		std::cout << "e" << std::setw(8) << " ";
		std::cout << "f" << std::setw(8) << " ";
		std::cout << "g" << std::setw(8) << " ";
		std::cout << "h" << std::setw(4) << " " << std::endl;
		std::cout << "  " << std::setfill('-') << std::setw(72) << "-" << std::endl;
		for (int q=0; q < 8; q++){
			if ( q%2==0 ){
				std::cout << " |";
				for ( int j = 0; j < 4; j++){
					std::cout << B_WHITE << std::setfill(' ') << std::setw(9) << ' ' << RESET;
					std::cout << B_RED << std::setfill(' ') << std::setw(9) << ' ' << RESET;
				}
				std::cout << "|" << std::endl << q+1 << "|";
				for ( int k=0; k < 4; k++){
					if ( board[q][(k*2)+1].is_black() ){
						// if ( board[q][(k*2)+1].is_king() ){
						
						// }
						// else{
							std::cout << B_WHITE << std::setfill(' ') << std::setw(9) << ' ' << RESET;
							std::cout << B_RED << std::setfill(' ') << std::setw(4) << ' ';
							std::cout << BLACK << "&" << RESET;
							std::cout << B_RED << std::setfill(' ') << std::setw(4) << ' ' << RESET;
							//}
						// }
					}
					else if ( board[q][(k*2)+1].is_white() ){
						// if ( board[q][(k*2)+1].is_king() ){
						
						// }
						// else{
							std::cout << B_WHITE << std::setfill(' ') << std::setw(9) << ' ' << RESET;
							std::cout << B_RED << std::setfill(' ') << std::setw(4) << ' ';
							std::cout << WHITE << "&" << RESET;
							std::cout << B_RED << std::setfill(' ') << std::setw(4) << ' ' << RESET;
							//}
						// }
					}
					else{
						std::cout << B_WHITE << std::setfill(' ') << std::setw(9) << ' ' << RESET;
						std::cout << B_RED << std::setfill(' ') << std::setw(9) << ' ' << RESET;
					}
				}
				std::cout << "|" << std::endl << " |";
				for ( int j = 0; j < 4; j++){
					std::cout << B_WHITE << std::setfill(' ') << std::setw(9) << ' ' << RESET;
					std::cout << B_RED << std::setfill(' ') << std::setw(9) << ' ' << RESET;
				}
				std::cout << "|" << std::endl;
			}
			else{
				std::cout << " |";
				for ( int j = 0; j < 4; j++){
					std::cout << B_RED << std::setfill(' ') << std::setw(9) << ' ' << RESET;
					std::cout << B_WHITE << std::setfill(' ') << std::setw(9) << ' ' << RESET;
				}
				std::cout << "|" << std::endl << q+1 << "|";
				for ( int k=0; k < 4; k++){
					if ( board[q][k*2].is_black() ){
						// if ( board[q][k*2].is_king() ){
						
						// }
						// else{
							//for ( int k=0; k < 4; k++){
								std::cout << B_RED << std::setfill(' ') << std::setw(4) << ' ';
								std::cout << BLACK << "&" << RESET;
								std::cout << B_RED << std::setfill(' ') << std::setw(4) << ' ' << RESET;
								std::cout << B_WHITE << std::setfill(' ') << std::setw(9) << ' ' << RESET;
							//}
						//}
					}
					else if ( board[q][k*2].is_white() ){
						// if ( board[q][k*2].is_king() ){
						
						// }
						// else{
							//for ( int k=0; k < 4; k++){
								std::cout << B_RED << std::setfill(' ') << std::setw(4) << ' ';
								std::cout << WHITE << "&" << RESET;
								std::cout << B_RED << std::setfill(' ') << std::setw(4) << ' ' << RESET;
								std::cout << B_WHITE << std::setfill(' ') << std::setw(9) << ' ' << RESET;
							//}
						//}
					}
					else{
						std::cout << B_RED << std::setfill(' ') << std::setw(9) << ' ' << RESET;
						std::cout << B_WHITE << std::setfill(' ') << std::setw(9) << ' ' << RESET;
					}
				}
				std::cout << "|" << std::endl << " |";
				for ( int j = 0; j < 4; j++){
					std::cout << B_RED << std::setfill(' ') << std::setw(9) << ' ' << RESET;
					std::cout << B_WHITE << std::setfill(' ') << std::setw(9) << ' ' << RESET;
				}
				std::cout << "|" << std::endl;
			}
		}
		std::cout << "  " << std::setfill('-') << std::setw(72) << "-" << std::endl;
		std::cout << std::setfill(' ') << std::setw(30) << ' ' << "Movement: c6d5"; 
		std::cout << std::setfill(' ') << std::setw(34) << ' ' << std::endl;
		if ( next_mover() == 0 ){
			std::cout << std::setfill(' ') << std::setw(30) << ' ' << "Your turn!";
			std::cout << std::setfill(' ') << std::setw(34) << ' ' << std::endl;
		}
		else if ( next_mover() == 2 ){
			std::cout << std::setfill(' ') << std::setw(30) << ' ' << "Computer's turn!";
			std::cout << std::setfill(' ') << std::setw(34) << ' ' << std::endl;
		}
	}

	bool checkers::is_legal(const std::string& move) const{
		//first sanitize the move
		if ( move.length() == 4 ){ 
			int row, col, destrow, destcol;
			if ( isalpha( move[0] ) ) { row = toupper( move[0] ) - 'A'; }
			else return false;
			if ( isdigit ( move[1] ) ) { col = move[1] - '1'; }
			else return false;
			if ( isalpha ( move[2] ) ) { destrow = toupper( move[2] ) - 'A'; }
			else return false;
			if ( isdigit ( move[3] ) ) { destcol = move[3] - '1'; }
			else return false;
			//std::cout << "Column: " << col << std::endl;
			//std::cout << "Row: " << row << std::endl;
			//std::cout << "Destination column: " << destcol << std::endl;
			//std::cout << "Destination row: " << destrow<< std::endl;
			//move has the correct length and form
			if ( ( row > 7 || row < 0 ) || ( col > 7 || col < 0 ) || ( destrow > 7 || destrow < 0 ) || ( destcol > 7 || destcol < 0 ) ){
				std::cout << "Out of bounds!" << std::endl;
				return false;
			}
			if ( col%2==0 ){
				if ( row%2==0 ){
					std::cout << "White spaces are illegal!" << std::endl;
					return false;
				}
			}
			else if ( row%2==1 ){
				std::cout << "White spaces are illegal!" << std::endl;
				return false;
			}
			if ( destcol%2==0 ){
				if ( destrow%2==0 ){
					std::cout << "White spaces are illegal!" << std::endl;
					return false;
				}
			}
			else if ( destrow%2==1 ){
				std::cout << "White spaces are illegal!" << std::endl;
				return false;
			}
			if ( next_mover() == HUMAN ) {
				if ( board[col][row].is_white() && board[destcol][destrow].is_empty() ){
					bool jump = false;
					piece testboard[8][8];
					for ( int x = 0; x < 8; x++ ){
						for ( int y = 0; y < 8; y++ ){
							if ( board[x][y].is_white() ) testboard[x][y].set_white(true);
							if ( board[x][y].is_black() ) testboard[x][y].set_black(true);
							if ( board[x][y].is_king() ) testboard[x][y].set_king(true);
						}
					}
					for ( int i = 0; i < 8; i++){
						for ( int j = 0; j < 8; j++){
							if ( board[i][j].is_white() ){
								for ( int testcol = 0; testcol < 8; testcol++ ){
									for ( int testrow = 0; testrow < 8; testrow++ ){
										if ( testcol%2==0 ){
											if ( testrow%2==1 && board[testcol][testrow].is_empty() ){
												if ( legal_jump( i, j, testcol, testrow, testboard )){
													jump = true;
													if ( i == col && j == row && testcol == destcol && testrow == destrow ) return true;
												}
											}
										}
										else if ( testrow%2==0 && board[testcol][testrow].is_empty() ){
											if ( legal_jump( i, j, testcol, testrow, testboard )){
												jump = true;
												if ( i == col && j == row && testcol == destcol && testrow == destrow ){
													return true;
												}
											}
										}
									}
								}
							}
						}
					}
					if ( jump == true ){
						//std::cout << "You must take a jump!" << std::endl;
						return false;
					}
					if ( ( col-1 == destcol && row-1 == destrow ) || ( col-1 == destcol && row+1 == destrow ) ) return true;
					if ( board[col][row].is_king() ){
						if ( ( col+1 == destcol && row-1 == destrow ) || ( col+1 == destcol && row+1 == destrow ) ){
							return true;
						}
					}
					return ( legal_jump( col, row, destcol, destrow, testboard ) );
				}
				else {
					std::cout << "Either that piece isn't yours or your destination isn't empty!" << std::endl;
					return false;
				}
			}
			else if ( next_mover() == COMPUTER) {
				if ( board[col][row].is_black() && board[destcol][destrow].is_empty() ){
					bool jump = false;
					piece testboard[8][8];
					for ( int x = 0; x < 8; x++ ){
						for ( int y = 0; y < 8; y++ ){
							if ( board[x][y].is_white() ) testboard[x][y].set_white(true);
							if ( board[x][y].is_black() ) testboard[x][y].set_black(true);
							if ( board[x][y].is_king() ) testboard[x][y].set_king(true);
						}
					}
					for ( int i = 0; i < 8; i++){
						for ( int j = 0; j < 8; j++){
							if ( board[i][j].is_black() ){
								for ( int testcol = 0; testcol < 8; testcol++ ){
									for ( int testrow = 0; testrow < 8; testrow++ ){
										if ( testcol%2==0 ){
											if ( testrow%2==1 && board[testcol][testrow].is_empty() ){
												if ( legal_jump( i, j, testcol, testrow, testboard )){
													jump = true;
													if ( i==col && j==row && testcol == destcol && testrow == destrow ) return true;
												}
											}
										}
										else if ( testrow%2==0 && board[testcol][testrow].is_empty() ){
											if ( legal_jump( i, j, testcol, testrow, testboard )){
												jump = true;
												if ( i == col && j == row && testcol == destcol && testrow == destrow ){
													return true;
												}
											}
										}
									}
								}
							}
						}
					}
					if ( jump == true ){
						//std::cout << "You must take a jump!" << std::endl;
						return false;
					}
					if ( ( col+1 == destcol && row-1 == destrow ) || ( col+1 == destcol && row+1 == destrow ) ) return true;
					if ( board[col][row].is_king() ){
						if ( ( col-1 == destcol && row-1 == destrow ) || ( col-1 == destcol && row+1 == destrow ) ){
							return true;
						}
					}
					return ( legal_jump( col, row, destcol, destrow, testboard ) );
				}
				else {
					std::cout << "Either that piece isn't yours or your destination isn't empty!" << std::endl;
					return false;
				}
			}
			else return false;
		}
		else return false;
	}
	
	/* As this doesn't use evaluate to check for game over,
	it doesn't check for situations where one player cannot move.*/
	
	bool checkers::is_game_over() const{
		// int black = 0;
		// int white = 0;
		// for ( int i = 0; i < 8; i++ ){
			// for ( int j = 0; j < 8; j++ ){
				// if ( board[i][j].is_white() ) white++;
				// if ( board[i][j].is_black() ) black++;
			// }
		// }
		// if ( white == 0 ) return true;
		// if ( black == 0 ) return true;
		// return false;
		if ( next_mover() == HUMAN ){
			//std::cout << "Computing human moves" << std::endl;
			for ( int i = 0; i < 8; i++ ){
				for ( int j = 0; j < 8; j++ ){
					if ( board[i][j].is_white() ){
						for ( int col = 0; col < 8; col++ ){
							for ( int row = 0; row < 8; row++ ){
								if ( col%2==0 ){
									if ( row%2==1 ){
										if ( board[col][row].is_empty() ){
											//generate move and check legality
											std::string move;
											move += char( j + 'A' );
											move += char( i + '1' );
											move += char( row + 'A' );
											move += char( col + '1' );
											if ( is_legal(move) ){ return false; }
										}
									}
								}
								else if ( row%2==0 ){
									if ( board[col][row].is_empty() ){
										//generate move and check legality
										std::string move;
										move += char( j + 'A' );
										move += char( i + '1' );
										move += char( row + 'A' );
										move += char( col + '1' );
										if ( is_legal(move) ) { return false; }
									}
								}
							}
						}
					}
				}
			}
			return true;
		}
		else{
			//std::cout << "Computing computer moves" << std::endl;
			for ( int i = 0; i < 8; i++ ){
				for ( int j = 0; j < 8; j++ ){
					if ( board[i][j].is_black() ){
						//std::cout << "Black piece at ( " << i << ", " << j << " )" << std::endl;
						for ( int col = 0; col < 8; col++ ){
							for ( int row = 0; row < 8; row++ ){
								if ( col%2==0 ){
									if ( row%2==1 ){
										if ( board[col][row].is_empty() ){
											//std::cout << "( " << col << ", " << row << " )" << " is empty" << std::endl;
											//generate move and check legality
											std::string move;
											move += char( j + 'A' );
											move += char( i + '1' );
											move += char( row + 'A' );
											move += char( col + '1' );
											//std::cout << "Trying move " << move << std::endl;
											if ( is_legal(move) ) { return false; }
										}
									}
								}
								else if ( row%2==0 ){
									if ( board[col][row].is_empty() ){
										//std::cout << "( " << col << ", " << row << " )" << " is empty" << std::endl;
										//generate move and check legality
										std::string move;
										move += char( j + 'A' );
										move += char( i + '1' );
										move += char( row + 'A' );
										move += char( col + '1' );
										//std::cout << "Trying move " << move << std::endl;
										if ( is_legal(move) ) { return false; }
									}
								}
							}
						}
					}
				}
			}
			return true;
		}
	}
	
	game::who checkers::winning() const{
		int black = 0;
		int white = 0;
		for ( int i = 0; i < 8; i++ ){
			for ( int j = 0; j < 8; j++ ){
				if ( board[i][j].is_white() ) white++;
				if ( board[i][j].is_black() ) black++;
			}
		}
		if ( white == 0 ){
			std::cout << "The computer has won! Give me points" << std::endl;
			return COMPUTER;
		}
		if ( black == 0 ){
			std::cout << "You've won! Curses" << std::endl;
			return HUMAN;
		}
		return NEUTRAL;
	}
	
	int checkers::evaluate() const{
		int state = 0;
		// if ( next_mover() == COMPUTER ){
			for ( int i = 0; i < 8; i++ ){
				for ( int j = 0; j < 8; j++ ){
					if ( board[i][j].is_white() ){
						state-=4;
						if ( board[i][j].is_king() ) state-=1;
					}
					else if ( board[i][j].is_black() ){
						state+=3;
						if ( board[i][j].is_king() ) state++;
					}
				}
			}
		return state;
	}
	
	void checkers::compute_moves( std::queue<std::string>& moves ) const{
		if ( next_mover() == HUMAN ){
			//std::cout << "Computing human moves" << std::endl;
			for ( int i = 0; i < 8; i++ ){
				for ( int j = 0; j < 8; j++ ){
					if ( board[i][j].is_white() ){
						for ( int col = 0; col < 8; col++ ){
							for ( int row = 0; row < 8; row++ ){
								if ( col%2==0 ){
									if ( row%2==1 ){
										if ( board[col][row].is_empty() ){
											//generate move and check legality
											std::string move;
											move += char( j + 'A' );
											move += char( i + '1' );
											move += char( row + 'A' );
											move += char( col + '1' );
											if ( is_legal(move) ) moves.push(move);
										}
									}
								}
								else if ( row%2==0 ){
									if ( board[col][row].is_empty() ){
										//generate move and check legality
										std::string move;
										move += char( j + 'A' );
										move += char( i + '1' );
										move += char( row + 'A' );
										move += char( col + '1' );
										if ( is_legal(move) ) moves.push(move);
									}
								}
							}
						}
					}
				}
			}
		}
		else{
			//std::cout << "Computing computer moves" << std::endl;
			for ( int i = 0; i < 8; i++ ){
				for ( int j = 0; j < 8; j++ ){
					if ( board[i][j].is_black() ){
						//std::cout << "Black piece at ( " << i << ", " << j << " )" << std::endl;
						for ( int col = 0; col < 8; col++ ){
							for ( int row = 0; row < 8; row++ ){
								if ( col%2==0 ){
									if ( row%2==1 ){
										if ( board[col][row].is_empty() ){
											//std::cout << "( " << col << ", " << row << " )" << " is empty" << std::endl;
											//generate move and check legality
											std::string move;
											move += char( j + 'A' );
											move += char( i + '1' );
											move += char( row + 'A' );
											move += char( col + '1' );
											//std::cout << "Trying move " << move << std::endl;
											if ( is_legal(move) ) moves.push(move);
										}
									}
								}
								else if ( row%2==0 ){
									if ( board[col][row].is_empty() ){
										//std::cout << "( " << col << ", " << row << " )" << " is empty" << std::endl;
										//generate move and check legality
										std::string move;
										move += char( j + 'A' );
										move += char( i + '1' );
										move += char( row + 'A' );
										move += char( col + '1' );
										//std::cout << "Trying move " << move << std::endl;
										if ( is_legal(move) ) moves.push(move);
									}
								}
							}
						}
					}
				}
			}
		}
	}
	
	void checkers::make_move(const std::string& move){
		int row, col, destrow, destcol;
		row = toupper( move[0] ) - 'A';
		col = move[1] - '1';
		destrow = toupper( move[2] ) - 'A';
		destcol = move[3] - '1';
		int trip = 0;
		if ( next_mover() == HUMAN ) {
			if ( board[col][row].is_king() ){
				if ( col+1 == destcol && row-1 == destrow ){
					board[col][row].set_white(false);
					board[col][row].set_king(false);
					board[col+1][row-1].set_white(true);
					board[col+1][row-1].set_king(true);
					trip=1;
				}
				else if ( col+1 == destcol && row+1 == destrow ){
					board[col][row].set_white(false);
					board[col][row].set_king(false);
					board[col+1][row+1].set_white(true);
					board[col+1][row+1].set_king(true);
					trip=1;
				}
			}
			if ( col-1 == destcol && row-1 == destrow ){
				board[col][row].set_white(false);
				if ( board[col][row].is_king() ){
					board[col-1][row-1].set_king(true);
					board[col][row].set_king(false);
				}
				board[col-1][row-1].set_white(true);
				if ( destcol == 0 ) board[col-1][row-1].set_king(true);
				trip=1;
			}
			else if ( col-1 == destcol && row+1 == destrow ){
				board[col][row].set_white(false);
				if ( board[col][row].is_king() ){
					board[col-1][row+1].set_king(true);
					board[col][row].set_king(false);
				}
				board[col-1][row+1].set_white(true);
				if ( destcol == 0 ) board[col-1][row+1].set_king(true);
				trip=1;
			}
			if ( 1 != trip ){ //dirty jump case
				if ( destcol == 0 ) board[destcol][destrow].set_king(true);
				make_jump( col, row, destcol, destrow, board );
			}
		}
		else{
			if ( col+1 == destcol && row+1 == destrow ){
				board[col][row].set_black(false);
				if ( board[col][row].is_king() ){
					board[col+1][row+1].set_king(true);
					board[col][row].set_king(false);
				}
				board[col+1][row+1].set_black(true);
				if ( destcol == 7 ) board[col+1][row+1].set_king(true);
				trip=1;
			}
			else if ( col+1 == destcol && row-1 == destrow ){
				board[col][row].set_black(false);
				if ( board[col][row].is_king() ){
					board[col+1][row-1].set_king(true);
					board[col][row].set_king(false);
				}
				board[col+1][row-1].set_black(true);
				if ( destcol == 7 ) board[col+1][row-1].set_king(true);
				trip=1;
			}
			else if ( board[col][row].is_king() ){
				if ( col-1 == destcol && row+1 == destrow ){
					board[col][row].set_black(false);
					board[col][row].set_king(false);
					board[col-1][row+1].set_black(true);
					board[col-1][row+1].set_king(true);
					trip=1;
				}
				else if ( col-1 == destcol && row-1 == destrow ){
					board[col][row].set_black(false);
					board[col][row].set_king(false);
					board[col-1][row-1].set_black(true);
					board[col-1][row-1].set_king(true);
					trip=1;
				}
			}
			if ( 1 != trip ){
				if ( destcol == 7 ) board[destcol][destrow].set_king(true);
				make_jump( col, row, destcol, destrow, board );
			}
		}
		game::make_move(move);
	}
	
	bool checkers::legal_jump( int curcol, int currow, int destcol, int destrow, piece future[8][8]) const{
		
		if ( next_mover() == HUMAN ) {
			if ( curcol <= 5 && curcol >= 2 && currow <= 5 && curcol >= 2 ){
				//Up left check
				if ( future[curcol-1][currow-1].is_black() && future[curcol-2][currow-2].is_empty() ){
					piece testboard[8][8];
					for ( int i = 0; i < 8; i++ ){
						for ( int j = 0; j < 8; j++ ){
							if ( future[i][j].is_white() ) testboard[i][j].set_white(true);
							if ( future[i][j].is_black() ) testboard[i][j].set_black(true);
							if ( future[i][j].is_king() ) testboard[i][j].set_king(true);
						}
					}
					if ( testboard[curcol][currow].is_king() ){
						testboard[curcol][currow].set_king(false);
						testboard[curcol-2][currow-2].set_king(true);
					}
					testboard[curcol-1][currow-1].set_king(false);
					testboard[curcol][currow].set_white(false);
					testboard[curcol-1][currow-1].set_black(false);
					testboard[curcol-2][currow-2].set_white(true);
					if ( legal_jump( curcol-2, currow-2, destcol, destrow, testboard ) ) return true;
				}
				//Up right check
				if ( future[curcol-1][currow+1].is_black() && future[curcol-2][currow+2].is_empty() ){
					piece testboard[8][8];
					for ( int i = 0; i < 8; i++ ){
						for ( int j = 0; j < 8; j++ ){
							if ( future[i][j].is_white() ) testboard[i][j].set_white(true);
							if ( future[i][j].is_black() ) testboard[i][j].set_black(true);
							if ( future[i][j].is_king() ) testboard[i][j].set_king(true);
						}
					}
					if ( testboard[curcol][currow].is_king() ){
						testboard[curcol][currow].set_king(false);
						testboard[curcol-2][currow+2].set_king(true);
					}
					testboard[curcol-1][currow+1].set_king(false);
					testboard[curcol][currow].set_white(false);
					testboard[curcol-1][currow+1].set_black(false);
					testboard[curcol-2][currow+2].set_white(true);
					if ( legal_jump( curcol-2, currow+2, destcol, destrow, testboard ) ) return true;
				}
				if ( future[curcol][currow].is_king() ){
					//Down left check
					if ( future[curcol+1][currow-1].is_black() && future[curcol+2][currow-2].is_empty() ){
						piece testboard[8][8];
						for ( int i = 0; i < 8; i++ ){
							for ( int j = 0; j < 8; j++ ){
								if ( future[i][j].is_white() ) testboard[i][j].set_white(true);
								if ( future[i][j].is_black() ) testboard[i][j].set_black(true);
								if ( future[i][j].is_king() ) testboard[i][j].set_king(true);
							}
						}
						if ( testboard[curcol][currow].is_king() ){
							testboard[curcol][currow].set_king(false);
							testboard[curcol+2][currow-2].set_king(true);
						}
						testboard[curcol+1][currow-1].set_king(false);
						testboard[curcol][currow].set_white(false);
						testboard[curcol+1][currow-1].set_black(false);
						testboard[curcol+2][currow-2].set_white(true);
						if ( legal_jump( curcol+2, currow-2, destcol, destrow, testboard ) ) return true;
					}
					//Down right check
					if ( future[curcol+1][currow+1].is_black() && future[curcol+2][currow+2].is_empty() ){
						piece testboard[8][8];
						for ( int i = 0; i < 8; i++ ){
							for ( int j = 0; j < 8; j++ ){
								if ( future[i][j].is_white() ) testboard[i][j].set_white(true);
								if ( future[i][j].is_black() ) testboard[i][j].set_black(true);
								if ( future[i][j].is_king() ) testboard[i][j].set_king(true);
							}
						}
						if ( testboard[curcol][currow].is_king() ){
							testboard[curcol][currow].set_king(false);
							testboard[curcol+2][currow+2].set_king(true);
						}
						testboard[curcol+1][currow+1].set_king(false);
						testboard[curcol][currow].set_white(false);
						testboard[curcol+1][currow+1].set_black(false);
						testboard[curcol+2][currow+2].set_white(true);
						if ( legal_jump( curcol+2, currow+2, destcol, destrow, testboard ) ) return true;
					}
				}
			}
			else if ( curcol <= 1 ){
				if ( currow <= 1 ){
					if ( future[curcol][currow].is_king() ){
						//Down right check
						if ( future[curcol+1][currow+1].is_black() && future[curcol+2][currow+2].is_empty() ){
							piece testboard[8][8];
							for ( int i = 0; i < 8; i++ ){
								for ( int j = 0; j < 8; j++ ){
									if ( future[i][j].is_white() ) testboard[i][j].set_white(true);
									if ( future[i][j].is_black() ) testboard[i][j].set_black(true);
									if ( future[i][j].is_king() ) testboard[i][j].set_king(true);
								}
							}
							if ( testboard[curcol][currow].is_king() ){
								testboard[curcol][currow].set_king(false);
								testboard[curcol+2][currow+2].set_king(true);
							}
							testboard[curcol+1][currow+1].set_king(false);
							testboard[curcol][currow].set_white(false);
							testboard[curcol+1][currow+1].set_black(false);
							testboard[curcol+2][currow+2].set_white(true);
							if ( legal_jump( curcol+2, currow+2, destcol, destrow, testboard ) ) return true;
						}
					}
				}
				else if ( currow >= 6 ){
					if ( future[curcol][currow].is_king() ){
						//Down left check
						if ( future[curcol+1][currow-1].is_black() && future[curcol+2][currow-2].is_empty() ){
							piece testboard[8][8];
							for ( int i = 0; i < 8; i++ ){
								for ( int j = 0; j < 8; j++ ){
									if ( future[i][j].is_white() ) testboard[i][j].set_white(true);
									if ( future[i][j].is_black() ) testboard[i][j].set_black(true);
									if ( future[i][j].is_king() ) testboard[i][j].set_king(true);
								}
							}
							if ( testboard[curcol][currow].is_king() ){
								testboard[curcol][currow].set_king(false);
								testboard[curcol+2][currow-2].set_king(true);
							}
							testboard[curcol+1][currow-1].set_king(false);
							testboard[curcol][currow].set_white(false);
							testboard[curcol+1][currow-1].set_black(false);
							testboard[curcol+2][currow-2].set_white(true);
							if ( legal_jump( curcol+2, currow-2, destcol, destrow, testboard ) ) return true;
						}
					}
				}
				else {
					if ( future[curcol][currow].is_king() ){
						//Down left check
						//std::cout << "Inside down left king loop" << std::endl;
						if ( future[curcol+1][currow-1].is_black() && future[curcol+2][currow-2].is_empty() ){
							piece testboard[8][8];
							for ( int i = 0; i < 8; i++ ){
								for ( int j = 0; j < 8; j++ ){
									if ( future[i][j].is_white() ) testboard[i][j].set_white(true);
									if ( future[i][j].is_black() ) testboard[i][j].set_black(true);
									if ( future[i][j].is_king() ) testboard[i][j].set_king(true);
								}
							}
							if ( testboard[curcol][currow].is_king() ){
								testboard[curcol][currow].set_king(false);
								testboard[curcol+2][currow-2].set_king(true);
							}
							testboard[curcol+1][currow-1].set_king(false);
							testboard[curcol+1][currow-1].set_king(false);
							testboard[curcol][currow].set_white(false);
							testboard[curcol+1][currow-1].set_black(false);
							testboard[curcol+2][currow-2].set_white(true);
							if ( legal_jump( curcol+2, currow-2, destcol, destrow, testboard ) ) return true;
						}
						//Down right check
						if ( future[curcol+1][currow+1].is_black() && future[curcol+2][currow+2].is_empty() ){
							piece testboard[8][8];
							for ( int i = 0; i < 8; i++ ){
								for ( int j = 0; j < 8; j++ ){
									if ( future[i][j].is_white() ) testboard[i][j].set_white(true);
									if ( future[i][j].is_black() ) testboard[i][j].set_black(true);
									if ( future[i][j].is_king() ) testboard[i][j].set_king(true);
								}
							}
							if ( testboard[curcol][currow].is_king() ){
								testboard[curcol][currow].set_king(false);
								testboard[curcol+2][currow+2].set_king(true);
							}
							testboard[curcol+1][currow+1].set_king(false);
							testboard[curcol][currow].set_white(false);
							testboard[curcol+1][currow+1].set_black(false);
							testboard[curcol+2][currow+2].set_white(true);
							if ( legal_jump( curcol+2, currow+2, destcol, destrow, testboard ) ) return true;
						}
					}
				}
			}
			else if ( curcol >= 6 ){
				if ( currow <=1 ){
					//Up right check
					if ( future[curcol-1][currow+1].is_black() && future[curcol-2][currow+2].is_empty() ){
						piece testboard[8][8];
						for ( int i = 0; i < 8; i++ ){
							for ( int j = 0; j < 8; j++ ){
								if ( future[i][j].is_white() ) testboard[i][j].set_white(true);
								if ( future[i][j].is_black() ) testboard[i][j].set_black(true);
								if ( future[i][j].is_king() ) testboard[i][j].set_king(true);
							}
						}
						if ( testboard[curcol][currow].is_king() ){
							testboard[curcol][currow].set_king(false);
							testboard[curcol-2][currow+2].set_king(true);
						}
						testboard[curcol-1][currow+1].set_king(false);
						testboard[curcol][currow].set_white(false);
						testboard[curcol-1][currow+1].set_black(false);
						testboard[curcol-2][currow+2].set_white(true);
						if ( legal_jump( curcol-2, currow+2, destcol, destrow, testboard ) ) return true;
					}
				}
				else if ( currow >= 6 ){
					//Up left check
					if ( future[curcol-1][currow-1].is_black() && future[curcol-2][currow-2].is_empty() ){
						piece testboard[8][8];
						for ( int i = 0; i < 8; i++ ){
							for ( int j = 0; j < 8; j++ ){
								if ( future[i][j].is_white() ) testboard[i][j].set_white(true);
								if ( future[i][j].is_black() ) testboard[i][j].set_black(true);
								if ( future[i][j].is_king() ) testboard[i][j].set_king(true);
							}
						}
						if ( testboard[curcol][currow].is_king() ){
							testboard[curcol][currow].set_king(false);
							testboard[curcol-2][currow-2].set_king(true);
						}
						testboard[curcol-1][currow-1].set_king(false);
						testboard[curcol][currow].set_white(false);
						testboard[curcol-1][currow-1].set_black(false);
						testboard[curcol-2][currow-2].set_white(true);
						if ( legal_jump( curcol-2, currow-2, destcol, destrow, testboard ) ) return true;
					}
				}
				else {
					//Up left check
					if ( future[curcol-1][currow-1].is_black() && future[curcol-2][currow-2].is_empty() ){
						piece testboard[8][8];
						for ( int i = 0; i < 8; i++ ){
							for ( int j = 0; j < 8; j++ ){
								if ( future[i][j].is_white() ) testboard[i][j].set_white(true);
								if ( future[i][j].is_black() ) testboard[i][j].set_black(true);
								if ( future[i][j].is_king() ) testboard[i][j].set_king(true);
							}
						}
						if ( testboard[curcol][currow].is_king() ){
							testboard[curcol][currow].set_king(false);
							testboard[curcol-2][currow-2].set_king(true);
						}
						testboard[curcol-1][currow-1].set_king(false);
						testboard[curcol][currow].set_white(false);
						testboard[curcol-1][currow-1].set_black(false);
						testboard[curcol-2][currow-2].set_white(true);
						if ( legal_jump( curcol-2, currow-2, destcol, destrow, testboard ) ) return true;
					}
					//Up right check
					if ( future[curcol-1][currow+1].is_black() && future[curcol-2][currow+2].is_empty() ){
						piece testboard[8][8];
						for ( int i = 0; i < 8; i++ ){
							for ( int j = 0; j < 8; j++ ){
								if ( future[i][j].is_white() ) testboard[i][j].set_white(true);
								if ( future[i][j].is_black() ) testboard[i][j].set_black(true);
								if ( future[i][j].is_king() ) testboard[i][j].set_king(true);
							}
						}
						if ( testboard[curcol][currow].is_king() ){
							testboard[curcol][currow].set_king(false);
							testboard[curcol-2][currow+2].set_king(true);
						}
						testboard[curcol-1][currow+1].set_king(false);
						testboard[curcol][currow].set_white(false);
						testboard[curcol-1][currow+1].set_black(false);
						testboard[curcol-2][currow+2].set_white(true);
						if ( legal_jump( curcol-2, currow+2, destcol, destrow, testboard ) ) return true;
					}
				}
			}
			else if ( curcol <= 5 && curcol >=2 ){
				if ( currow <= 1 ){
					//Up right check
					if ( future[curcol-1][currow+1].is_black() && future[curcol-2][currow+2].is_empty() ){
						piece testboard[8][8];
						for ( int i = 0; i < 8; i++ ){
							for ( int j = 0; j < 8; j++ ){
								if ( future[i][j].is_white() ) testboard[i][j].set_white(true);
								if ( future[i][j].is_black() ) testboard[i][j].set_black(true);
								if ( future[i][j].is_king() ) testboard[i][j].set_king(true);
							}
						}
						if ( testboard[curcol][currow].is_king() ){
							testboard[curcol][currow].set_king(false);
							testboard[curcol-2][currow+2].set_king(true);
						}
						testboard[curcol-1][currow+1].set_king(false);
						testboard[curcol][currow].set_white(false);
						testboard[curcol-1][currow+1].set_black(false);
						testboard[curcol-2][currow+2].set_white(true);
						if ( legal_jump( curcol-2, currow+2, destcol, destrow, testboard ) ) return true;
					}
					if ( future[curcol][currow].is_king() ){
						//Down right check
						if ( future[curcol+1][currow+1].is_black() && future[curcol+2][currow+2].is_empty() ){
							piece testboard[8][8];
							for ( int i = 0; i < 8; i++ ){
								for ( int j = 0; j < 8; j++ ){
									if ( future[i][j].is_white() ) testboard[i][j].set_white(true);
									if ( future[i][j].is_black() ) testboard[i][j].set_black(true);
									if ( future[i][j].is_king() ) testboard[i][j].set_king(true);
								}
							}
							if ( testboard[curcol][currow].is_king() ){
								testboard[curcol][currow].set_king(false);
								testboard[curcol+2][currow+2].set_king(true);
							}
							testboard[curcol+1][currow+1].set_king(false);
							testboard[curcol][currow].set_white(false);
							testboard[curcol+1][currow+1].set_black(false);
							testboard[curcol+2][currow+2].set_white(true);
							if ( legal_jump( curcol+2, currow+2, destcol, destrow, testboard ) ) return true;
						}
					}
				}
				else if ( currow >= 6 ){
					//Up left check
					if ( future[curcol-1][currow-1].is_black() && future[curcol-2][currow-2].is_empty() ){
						piece testboard[8][8];
						for ( int i = 0; i < 8; i++ ){
							for ( int j = 0; j < 8; j++ ){
								if ( future[i][j].is_white() ) testboard[i][j].set_white(true);
								if ( future[i][j].is_black() ) testboard[i][j].set_black(true);
								if ( future[i][j].is_king() ) testboard[i][j].set_king(true);
							}
						}
						if ( testboard[curcol][currow].is_king() ){
							testboard[curcol][currow].set_king(false);
							testboard[curcol-2][currow-2].set_king(true);
						}
						testboard[curcol-1][currow-1].set_king(false);
						testboard[curcol][currow].set_white(false);
						testboard[curcol-1][currow-1].set_black(false);
						testboard[curcol-2][currow-2].set_white(true);
						if ( legal_jump( curcol-2, currow-2, destcol, destrow, testboard ) ) return true;
					}
					if ( future[curcol][currow].is_king() ){
						//Down left check
						if ( future[curcol+1][currow-1].is_black() && future[curcol+2][currow-2].is_empty() ){
							piece testboard[8][8];
							for ( int i = 0; i < 8; i++ ){
								for ( int j = 0; j < 8; j++ ){
									if ( future[i][j].is_white() ) testboard[i][j].set_white(true);
									if ( future[i][j].is_black() ) testboard[i][j].set_black(true);
									if ( future[i][j].is_king() ) testboard[i][j].set_king(true);
								}
							}
							if ( testboard[curcol][currow].is_king() ){
								testboard[curcol][currow].set_king(false);
								testboard[curcol+2][currow-2].set_king(true);
							}
							testboard[curcol+1][currow-1].set_king(false);
							testboard[curcol][currow].set_white(false);
							testboard[curcol+1][currow-1].set_black(false);
							testboard[curcol+2][currow-2].set_white(true);
							if ( legal_jump( curcol+2, currow-2, destcol, destrow, testboard ) ) return true;
						}
					}
				}
			}
		}
		else if ( next_mover() == COMPUTER ){
			if ( curcol <= 5 && curcol >= 2 && currow <= 5 && curcol >= 2 ){
				//Down left check
				if ( future[curcol+1][currow-1].is_white() && future[curcol+2][currow-2].is_empty() ){
					piece testboard[8][8];
					for ( int i = 0; i < 8; i++ ){
						for ( int j = 0; j < 8; j++ ){
							if ( future[i][j].is_white() ) testboard[i][j].set_white(true);
							if ( future[i][j].is_black() ) testboard[i][j].set_black(true);
							if ( future[i][j].is_king() ) testboard[i][j].set_king(true);
						}
					}
					if ( testboard[curcol][currow].is_king() ){
						testboard[curcol][currow].set_king(false);
						testboard[curcol+2][currow-2].set_king(true);
					}
					testboard[curcol+1][currow-1].set_king(false);
					testboard[curcol][currow].set_black(false);
					testboard[curcol+1][currow-1].set_white(false);
					testboard[curcol+2][currow-2].set_black(true);
					if ( legal_jump( curcol+2, currow-2, destcol, destrow, testboard ) ) return true;
				}
				//Down right check
				if ( future[curcol+1][currow+1].is_white() && future[curcol+2][currow+2].is_empty() ){
					piece testboard[8][8];
					for ( int i = 0; i < 8; i++ ){
						for ( int j = 0; j < 8; j++ ){
							if ( future[i][j].is_white() ) testboard[i][j].set_white(true);
							if ( future[i][j].is_black() ) testboard[i][j].set_black(true);
							if ( future[i][j].is_king() ) testboard[i][j].set_king(true);
						}
					}
					if ( testboard[curcol][currow].is_king() ){
							testboard[curcol][currow].set_king(false);
							testboard[curcol+2][currow+2].set_king(true);
						}
						testboard[curcol+1][currow+1].set_king(false);
					testboard[curcol][currow].set_black(false);
					testboard[curcol+1][currow+1].set_white(false);
					testboard[curcol+2][currow+2].set_black(true);
					if ( legal_jump( curcol+2, currow+2, destcol, destrow, testboard ) ) return true;
				}
				if ( future[curcol][currow].is_king() ){
					//Up left check
					if ( future[curcol-1][currow-1].is_white() && future[curcol-2][currow-2].is_empty() ){
						piece testboard[8][8];
						for ( int i = 0; i < 8; i++ ){
							for ( int j = 0; j < 8; j++ ){
								if ( future[i][j].is_white() ) testboard[i][j].set_white(true);
								if ( future[i][j].is_black() ) testboard[i][j].set_black(true);
								if ( future[i][j].is_king() ) testboard[i][j].set_king(true);
							}
						}
						if ( testboard[curcol][currow].is_king() ){
							testboard[curcol][currow].set_king(false);
							testboard[curcol-2][currow-2].set_king(true);
						}
						testboard[curcol-1][currow-1].set_king(false);
						testboard[curcol][currow].set_black(false);
						testboard[curcol-1][currow-1].set_white(false);
						testboard[curcol-2][currow-2].set_black(true);
						if ( legal_jump( curcol-2, currow-2, destcol, destrow, testboard ) ) return true;
					}
					//Up right check
					if ( future[curcol-1][currow+1].is_white() && future[curcol-2][currow+2].is_empty() ){
						piece testboard[8][8];
						for ( int i = 0; i < 8; i++ ){
							for ( int j = 0; j < 8; j++ ){
								if ( future[i][j].is_white() ) testboard[i][j].set_white(true);
								if ( future[i][j].is_black() ) testboard[i][j].set_black(true);
								if ( future[i][j].is_king() ) testboard[i][j].set_king(true);
							}
						}
						if ( testboard[curcol][currow].is_king() ){
							testboard[curcol][currow].set_king(false);
							testboard[curcol-2][currow+2].set_king(true);
						}
						testboard[curcol-1][currow+1].set_king(false);
						testboard[curcol][currow].set_black(false);
						testboard[curcol-1][currow+1].set_white(false);
						testboard[curcol-2][currow+2].set_black(true);
						if ( legal_jump( curcol-2, currow+2, destcol, destrow, testboard ) ) return true;
					}
				}
			}
			else if ( curcol <= 1 ){
				if ( currow <= 1 ){
					//Down right check
					if ( future[curcol+1][currow+1].is_white() && future[curcol+2][currow+2].is_empty() ){
						piece testboard[8][8];
						for ( int i = 0; i < 8; i++ ){
							for ( int j = 0; j < 8; j++ ){
								if ( future[i][j].is_white() ) testboard[i][j].set_white(true);
								if ( future[i][j].is_black() ) testboard[i][j].set_black(true);
								if ( future[i][j].is_king() ) testboard[i][j].set_king(true);
							}
						}
						if ( testboard[curcol][currow].is_king() ){
							testboard[curcol][currow].set_king(false);
							testboard[curcol+2][currow+2].set_king(true);
						}
						testboard[curcol+1][currow+1].set_king(false);
						testboard[curcol][currow].set_black(false);
						testboard[curcol+1][currow+1].set_white(false);
						testboard[curcol+2][currow+2].set_black(true);
						if ( legal_jump( curcol+2, currow+2, destcol, destrow, testboard ) ) return true;
					}
				}
				else if ( currow >= 6 ){
					//Down left check
					if ( future[curcol+1][currow-1].is_white() && future[curcol+2][currow-2].is_empty() ){
						piece testboard[8][8];
						for ( int i = 0; i < 8; i++ ){
							for ( int j = 0; j < 8; j++ ){
								if ( future[i][j].is_white() ) testboard[i][j].set_white(true);
								if ( future[i][j].is_black() ) testboard[i][j].set_black(true);
								if ( future[i][j].is_king() ) testboard[i][j].set_king(true);
							}
						}
						if ( testboard[curcol][currow].is_king() ){
							testboard[curcol][currow].set_king(false);
							testboard[curcol+2][currow-2].set_king(true);
						}
						testboard[curcol+1][currow-1].set_king(false);
						testboard[curcol][currow].set_black(false);
						testboard[curcol+1][currow-1].set_white(false);
						testboard[curcol+2][currow-2].set_black(true);
						if ( legal_jump( curcol+2, currow-2, destcol, destrow, testboard ) ) return true;
					}
				}
				else {
					//Down left check
					if ( future[curcol+1][currow-1].is_white() && future[curcol+2][currow-2].is_empty() ){
						piece testboard[8][8];
						for ( int i = 0; i < 8; i++ ){
							for ( int j = 0; j < 8; j++ ){
								if ( future[i][j].is_white() ) testboard[i][j].set_white(true);
								if ( future[i][j].is_black() ) testboard[i][j].set_black(true);
								if ( future[i][j].is_king() ) testboard[i][j].set_king(true);
							}
						}
						if ( testboard[curcol][currow].is_king() ){
							testboard[curcol][currow].set_king(false);
							testboard[curcol+2][currow-2].set_king(true);
						}
						testboard[curcol+1][currow-1].set_king(false);
						testboard[curcol][currow].set_black(false);
						testboard[curcol+1][currow-1].set_white(false);
						testboard[curcol+2][currow-2].set_black(true);
						if ( legal_jump( curcol+2, currow-2, destcol, destrow, testboard ) ) return true;
					}
					//Down right check
					if ( future[curcol+1][currow+1].is_white() && future[curcol+2][currow+2].is_empty() ){
						piece testboard[8][8];
						for ( int i = 0; i < 8; i++ ){
							for ( int j = 0; j < 8; j++ ){
								if ( future[i][j].is_white() ) testboard[i][j].set_white(true);
								if ( future[i][j].is_black() ) testboard[i][j].set_black(true);
								if ( future[i][j].is_king() ) testboard[i][j].set_king(true);
							}
						}
						if ( testboard[curcol][currow].is_king() ){
							testboard[curcol][currow].set_king(false);
							testboard[curcol+2][currow+2].set_king(true);
						}
						testboard[curcol+1][currow+1].set_king(false);
						testboard[curcol][currow].set_black(false);
						testboard[curcol+1][currow+1].set_white(false);
						testboard[curcol+2][currow+2].set_black(true);
						if ( legal_jump( curcol+2, currow+2, destcol, destrow, testboard ) ) return true;
					}
				}
			}
			else if ( curcol >= 6 ){
				if ( currow <=1 ){
					if ( future[curcol][currow].is_king() ){
						//Up right check
						if ( future[curcol-1][currow+1].is_white() && future[curcol-2][currow+2].is_empty() ){
							piece testboard[8][8];
							for ( int i = 0; i < 8; i++ ){
								for ( int j = 0; j < 8; j++ ){
									if ( future[i][j].is_white() ) testboard[i][j].set_white(true);
									if ( future[i][j].is_black() ) testboard[i][j].set_black(true);
									if ( future[i][j].is_king() ) testboard[i][j].set_king(true);
								}
							}
							if ( testboard[curcol][currow].is_king() ){
								testboard[curcol][currow].set_king(false);
								testboard[curcol-2][currow+2].set_king(true);
							}
							testboard[curcol-1][currow+1].set_king(false);
							testboard[curcol][currow].set_black(false);
							testboard[curcol-1][currow+1].set_white(false);
							testboard[curcol-2][currow+2].set_black(true);
							if ( legal_jump( curcol-2, currow+2, destcol, destrow, testboard ) ) return true;
						}
					}
				}
				else if ( currow >= 6 ){
					if ( future[curcol][currow].is_king() ){
						//Up left check
						if ( future[curcol-1][currow-1].is_white() && future[curcol-2][currow-2].is_empty() ){
							piece testboard[8][8];
							for ( int i = 0; i < 8; i++ ){
								for ( int j = 0; j < 8; j++ ){
									if ( future[i][j].is_white() ) testboard[i][j].set_white(true);
									if ( future[i][j].is_black() ) testboard[i][j].set_black(true);
									if ( future[i][j].is_king() ) testboard[i][j].set_king(true);
								}
							}
							if ( testboard[curcol][currow].is_king() ){
								testboard[curcol][currow].set_king(false);
								testboard[curcol-2][currow-2].set_king(true);
							}
							testboard[curcol-1][currow-1].set_king(false);
							testboard[curcol][currow].set_black(false);
							testboard[curcol-1][currow-1].set_white(false);
							testboard[curcol-2][currow-2].set_black(true);
							if ( legal_jump( curcol-2, currow-2, destcol, destrow, testboard ) ) return true;
						}
					}
				}
				else {
					if ( future[curcol][currow].is_king() ){
						//Up left check
						if ( future[curcol-1][currow-1].is_white() && future[curcol-2][currow-2].is_empty() ){
							piece testboard[8][8];
							for ( int i = 0; i < 8; i++ ){
								for ( int j = 0; j < 8; j++ ){
									if ( future[i][j].is_white() ) testboard[i][j].set_white(true);
									if ( future[i][j].is_black() ) testboard[i][j].set_black(true);
									if ( future[i][j].is_king() ) testboard[i][j].set_king(true);
								}
							}
							if ( testboard[curcol][currow].is_king() ){
								testboard[curcol][currow].set_king(false);
								testboard[curcol-2][currow-2].set_king(true);
							}
							testboard[curcol-1][currow-1].set_king(false);
							testboard[curcol][currow].set_black(false);
							testboard[curcol-1][currow-1].set_white(false);
							testboard[curcol-2][currow-2].set_black(true);
							if ( legal_jump( curcol-2, currow-2, destcol, destrow, testboard ) ) return true;
						}
						//Up right check
						if ( future[curcol-1][currow+1].is_white() && future[curcol-2][currow+2].is_empty() ){
							piece testboard[8][8];
							for ( int i = 0; i < 8; i++ ){
								for ( int j = 0; j < 8; j++ ){
									if ( future[i][j].is_white() ) testboard[i][j].set_white(true);
									if ( future[i][j].is_black() ) testboard[i][j].set_black(true);
									if ( future[i][j].is_king() ) testboard[i][j].set_king(true);
								}
							}
							if ( testboard[curcol][currow].is_king() ){
								testboard[curcol][currow].set_king(false);
								testboard[curcol-2][currow+2].set_king(true);
							}
							testboard[curcol-1][currow+1].set_king(false);
							testboard[curcol][currow].set_black(false);
							testboard[curcol-1][currow+1].set_white(false);
							testboard[curcol-2][currow+2].set_black(true);
							if ( legal_jump( curcol-2, currow+2, destcol, destrow, testboard ) ) return true;
						}
					}
				}
			}
			else if ( curcol <= 5 && curcol >=2 ){
				if ( currow <= 1 ){
					//Down right check
					if ( future[curcol+1][currow+1].is_white() && future[curcol+2][currow+2].is_empty() ){
						piece testboard[8][8];
						for ( int i = 0; i < 8; i++ ){
							for ( int j = 0; j < 8; j++ ){
								if ( future[i][j].is_white() ) testboard[i][j].set_white(true);
								if ( future[i][j].is_black() ) testboard[i][j].set_black(true);
								if ( future[i][j].is_king() ) testboard[i][j].set_king(true);
							}
						}
						if ( testboard[curcol][currow].is_king() ){
							testboard[curcol][currow].set_king(false);
							testboard[curcol+2][currow+2].set_king(true);
						}
						testboard[curcol+1][currow+1].set_king(false);
						testboard[curcol][currow].set_black(false);
						testboard[curcol+1][currow+1].set_white(false);
						testboard[curcol+2][currow+2].set_black(true);
						if ( legal_jump( curcol+2, currow+2, destcol, destrow, testboard ) ) return true;
					}
					if ( future[curcol][currow].is_king() ){
						//Up right check
						if ( future[curcol-1][currow+1].is_white() && future[curcol-2][currow+2].is_empty() ){
							piece testboard[8][8];
							for ( int i = 0; i < 8; i++ ){
								for ( int j = 0; j < 8; j++ ){
									if ( future[i][j].is_white() ) testboard[i][j].set_white(true);
									if ( future[i][j].is_black() ) testboard[i][j].set_black(true);
									if ( future[i][j].is_king() ) testboard[i][j].set_king(true);
								}
							}
							if ( testboard[curcol][currow].is_king() ){
								testboard[curcol][currow].set_king(false);
								testboard[curcol-2][currow+2].set_king(true);
							}
							testboard[curcol-1][currow+1].set_king(false);
							testboard[curcol][currow].set_black(false);
							testboard[curcol-1][currow+1].set_white(false);
							testboard[curcol-2][currow+2].set_black(true);
							if ( legal_jump( curcol-2, currow+2, destcol, destrow, testboard ) ) return true;
						}
					}
				}
				else if ( currow >= 6 ){
					//Down left check
					if ( future[curcol+1][currow-1].is_white() && future[curcol+2][currow-2].is_empty() ){
						piece testboard[8][8];
						for ( int i = 0; i < 8; i++ ){
							for ( int j = 0; j < 8; j++ ){
								if ( future[i][j].is_white() ) testboard[i][j].set_white(true);
								if ( future[i][j].is_black() ) testboard[i][j].set_black(true);
								if ( future[i][j].is_king() ) testboard[i][j].set_king(true);
							}
						}
						if ( testboard[curcol][currow].is_king() ){
							testboard[curcol][currow].set_king(false);
							testboard[curcol+2][currow-2].set_king(true);
						}
						testboard[curcol+1][currow-1].set_king(false);
						testboard[curcol][currow].set_black(false);
						testboard[curcol+1][currow-1].set_white(false);
						testboard[curcol+2][currow-2].set_black(true);
						if ( legal_jump( curcol+2, currow-2, destcol, destrow, testboard ) ) return true;
					}
					if ( future[curcol][currow].is_king() ){
						//Up left check
						if ( future[curcol-1][currow-1].is_white() && future[curcol-2][currow-2].is_empty() ){
							piece testboard[8][8];
							for ( int i = 0; i < 8; i++ ){
								for ( int j = 0; j < 8; j++ ){
									if ( future[i][j].is_white() ) testboard[i][j].set_white(true);
									if ( future[i][j].is_black() ) testboard[i][j].set_black(true);
									if ( future[i][j].is_king() ) testboard[i][j].set_king(true);
								}
							}
							if ( testboard[curcol][currow].is_king() ){
								testboard[curcol][currow].set_king(false);
								testboard[curcol-2][currow-2].set_king(true);
							}
							testboard[curcol-1][currow-1].set_king(false);
							testboard[curcol][currow].set_black(false);
							testboard[curcol-1][currow-1].set_white(false);
							testboard[curcol-2][currow-2].set_black(true);
							if ( legal_jump( curcol-2, currow-2, destcol, destrow, testboard ) ) return true;
						}
					}
				}
			}
		}
		if ( curcol == destcol && currow == destrow ) return true;
		else return false;
	}

bool checkers::make_jump( int curcol, int currow, int destcol, int destrow, piece future[8][8]){
		
		if ( next_mover() == HUMAN ) {
			if ( curcol <= 5 && curcol >= 2 && currow <= 5 && curcol >= 2 ){
				//Up left check
				if ( future[curcol-1][currow-1].is_black() && future[curcol-2][currow-2].is_empty() ){
					piece testboard[8][8];
					for ( int i = 0; i < 8; i++ ){
						for ( int j = 0; j < 8; j++ ){
							if ( future[i][j].is_white() ) testboard[i][j].set_white(true);
							if ( future[i][j].is_black() ) testboard[i][j].set_black(true);
							if ( future[i][j].is_king() ) testboard[i][j].set_king(true);
						}
					}
					if ( testboard[curcol][currow].is_king() ){
						testboard[curcol][currow].set_king(false);
						testboard[curcol-2][currow-2].set_king(true);
					}
					testboard[curcol-1][currow-1].set_king(false);
					testboard[curcol][currow].set_white(false);
					testboard[curcol-1][currow-1].set_black(false);
					testboard[curcol-2][currow-2].set_white(true);
					if ( make_jump( curcol-2, currow-2, destcol, destrow, testboard ) ) return true;
				}
				//Up right check
				if ( future[curcol-1][currow+1].is_black() && future[curcol-2][currow+2].is_empty() ){
					piece testboard[8][8];
					for ( int i = 0; i < 8; i++ ){
						for ( int j = 0; j < 8; j++ ){
							if ( future[i][j].is_white() ) testboard[i][j].set_white(true);
							if ( future[i][j].is_black() ) testboard[i][j].set_black(true);
							if ( future[i][j].is_king() ) testboard[i][j].set_king(true);
						}
					}
					if ( testboard[curcol][currow].is_king() ){
						testboard[curcol][currow].set_king(false);
						testboard[curcol-2][currow+2].set_king(true);
					}
					testboard[curcol-1][currow+1].set_king(false);
					testboard[curcol][currow].set_white(false);
					testboard[curcol-1][currow+1].set_black(false);
					testboard[curcol-2][currow+2].set_white(true);
					if ( make_jump( curcol-2, currow+2, destcol, destrow, testboard ) ) return true;
				}
				if ( future[curcol][currow].is_king() ){
					//Down left check
					if ( future[curcol+1][currow-1].is_black() && future[curcol+2][currow-2].is_empty() ){
						piece testboard[8][8];
						for ( int i = 0; i < 8; i++ ){
							for ( int j = 0; j < 8; j++ ){
								if ( future[i][j].is_white() ) testboard[i][j].set_white(true);
								if ( future[i][j].is_black() ) testboard[i][j].set_black(true);
								if ( future[i][j].is_king() ) testboard[i][j].set_king(true);
							}
						}
						if ( testboard[curcol][currow].is_king() ){
							testboard[curcol][currow].set_king(false);
							testboard[curcol+2][currow-2].set_king(true);
						}
						testboard[curcol+1][currow-1].set_king(false);
						testboard[curcol][currow].set_white(false);
						testboard[curcol+1][currow-1].set_black(false);
						testboard[curcol+2][currow-2].set_white(true);
						if ( make_jump( curcol+2, currow-2, destcol, destrow, testboard ) ) return true;
					}
					//Down right check
					if ( future[curcol+1][currow+1].is_black() && future[curcol+2][currow+2].is_empty() ){
						piece testboard[8][8];
						for ( int i = 0; i < 8; i++ ){
							for ( int j = 0; j < 8; j++ ){
								if ( future[i][j].is_white() ) testboard[i][j].set_white(true);
								if ( future[i][j].is_black() ) testboard[i][j].set_black(true);
								if ( future[i][j].is_king() ) testboard[i][j].set_king(true);
							}
						}
						if ( testboard[curcol][currow].is_king() ){
							testboard[curcol][currow].set_king(false);
							testboard[curcol+2][currow+2].set_king(true);
						}
						testboard[curcol+1][currow+1].set_king(false);
						testboard[curcol][currow].set_white(false);
						testboard[curcol+1][currow+1].set_black(false);
						testboard[curcol+2][currow+2].set_white(true);
						if ( make_jump( curcol+2, currow+2, destcol, destrow, testboard ) ) return true;
					}
				}
			}
			else if ( curcol <= 1 ){
				if ( currow <= 1 ){
					if ( future[curcol][currow].is_king() ){
						//Down right check
						if ( future[curcol+1][currow+1].is_black() && future[curcol+2][currow+2].is_empty() ){
							piece testboard[8][8];
							for ( int i = 0; i < 8; i++ ){
								for ( int j = 0; j < 8; j++ ){
									if ( future[i][j].is_white() ) testboard[i][j].set_white(true);
									if ( future[i][j].is_black() ) testboard[i][j].set_black(true);
									if ( future[i][j].is_king() ) testboard[i][j].set_king(true);
								}
							}
							if ( testboard[curcol][currow].is_king() ){
								testboard[curcol][currow].set_king(false);
								testboard[curcol+2][currow+2].set_king(true);
							}
							testboard[curcol+1][currow+1].set_king(false);
							testboard[curcol][currow].set_white(false);
							testboard[curcol+1][currow+1].set_black(false);
							testboard[curcol+2][currow+2].set_white(true);
							if ( make_jump( curcol+2, currow+2, destcol, destrow, testboard ) ) return true;
						}
					}
				}
				else if ( currow >= 6 ){
					if ( future[curcol][currow].is_king() ){
						//Down left check
						if ( future[curcol+1][currow-1].is_black() && future[curcol+2][currow-2].is_empty() ){
							piece testboard[8][8];
							for ( int i = 0; i < 8; i++ ){
								for ( int j = 0; j < 8; j++ ){
									if ( future[i][j].is_white() ) testboard[i][j].set_white(true);
									if ( future[i][j].is_black() ) testboard[i][j].set_black(true);
									if ( future[i][j].is_king() ) testboard[i][j].set_king(true);
								}
							}
							if ( testboard[curcol][currow].is_king() ){
								testboard[curcol][currow].set_king(false);
								testboard[curcol+2][currow-2].set_king(true);
							}
							testboard[curcol+1][currow-1].set_king(false);
							testboard[curcol][currow].set_white(false);
							testboard[curcol+1][currow-1].set_black(false);
							testboard[curcol+2][currow-2].set_white(true);
							if ( make_jump( curcol+2, currow-2, destcol, destrow, testboard ) ) return true;
						}
					}
				}
				else {
					if ( future[curcol][currow].is_king() ){
						//Down left check
						if ( future[curcol+1][currow-1].is_black() && future[curcol+2][currow-2].is_empty() ){
							piece testboard[8][8];
							for ( int i = 0; i < 8; i++ ){
								for ( int j = 0; j < 8; j++ ){
									if ( future[i][j].is_white() ) testboard[i][j].set_white(true);
									if ( future[i][j].is_black() ) testboard[i][j].set_black(true);
									if ( future[i][j].is_king() ) testboard[i][j].set_king(true);
								}
							}
							if ( testboard[curcol][currow].is_king() ){
								testboard[curcol][currow].set_king(false);
								testboard[curcol+2][currow-2].set_king(true);
							}
							testboard[curcol+1][currow-1].set_king(false);
							testboard[curcol][currow].set_white(false);
							testboard[curcol+1][currow-1].set_black(false);
							testboard[curcol+2][currow-2].set_white(true);
							if ( make_jump( curcol+2, currow-2, destcol, destrow, testboard ) ) return true;
						}
						//Down right check
						if ( future[curcol+1][currow+1].is_black() && future[curcol+2][currow+2].is_empty() ){
							piece testboard[8][8];
							for ( int i = 0; i < 8; i++ ){
								for ( int j = 0; j < 8; j++ ){
									if ( future[i][j].is_white() ) testboard[i][j].set_white(true);
									if ( future[i][j].is_black() ) testboard[i][j].set_black(true);
									if ( future[i][j].is_king() ) testboard[i][j].set_king(true);
								}
							}
							if ( testboard[curcol][currow].is_king() ){
								testboard[curcol][currow].set_king(false);
								testboard[curcol+2][currow+2].set_king(true);
							}
							testboard[curcol+1][currow+1].set_king(false);
							testboard[curcol][currow].set_white(false);
							testboard[curcol+1][currow+1].set_black(false);
							testboard[curcol+2][currow+2].set_white(true);
							if ( make_jump( curcol+2, currow+2, destcol, destrow, testboard ) ) return true;
						}
					}
				}
			}
			else if ( curcol >= 6 ){
				if ( currow <=1 ){
					//Up right check
					if ( future[curcol-1][currow+1].is_black() && future[curcol-2][currow+2].is_empty() ){
						piece testboard[8][8];
						for ( int i = 0; i < 8; i++ ){
							for ( int j = 0; j < 8; j++ ){
								if ( future[i][j].is_white() ) testboard[i][j].set_white(true);
								if ( future[i][j].is_black() ) testboard[i][j].set_black(true);
								if ( future[i][j].is_king() ) testboard[i][j].set_king(true);
							}
						}
						if ( testboard[curcol][currow].is_king() ){
							testboard[curcol][currow].set_king(false);
							testboard[curcol-2][currow+2].set_king(true);
						}
						testboard[curcol-1][currow+1].set_king(false);
						testboard[curcol][currow].set_white(false);
						testboard[curcol-1][currow+1].set_black(false);
						testboard[curcol-2][currow+2].set_white(true);
						if ( make_jump( curcol-2, currow+2, destcol, destrow, testboard ) ) return true;
					}
				}
				else if ( currow >= 6 ){
					//Up left check
					if ( future[curcol-1][currow-1].is_black() && future[curcol-2][currow-2].is_empty() ){
						piece testboard[8][8];
						for ( int i = 0; i < 8; i++ ){
							for ( int j = 0; j < 8; j++ ){
								if ( future[i][j].is_white() ) testboard[i][j].set_white(true);
								if ( future[i][j].is_black() ) testboard[i][j].set_black(true);
								if ( future[i][j].is_king() ) testboard[i][j].set_king(true);
							}
						}
						if ( testboard[curcol][currow].is_king() ){
							testboard[curcol][currow].set_king(false);
							testboard[curcol-2][currow-2].set_king(true);
						}
						testboard[curcol-1][currow-1].set_king(false);
						testboard[curcol][currow].set_white(false);
						testboard[curcol-1][currow-1].set_black(false);
						testboard[curcol-2][currow-2].set_white(true);
						if ( make_jump( curcol-2, currow-2, destcol, destrow, testboard ) ) return true;
					}
				}
				else {
					//Up left check
					if ( future[curcol-1][currow-1].is_black() && future[curcol-2][currow-2].is_empty() ){
						piece testboard[8][8];
						for ( int i = 0; i < 8; i++ ){
							for ( int j = 0; j < 8; j++ ){
								if ( future[i][j].is_white() ) testboard[i][j].set_white(true);
								if ( future[i][j].is_black() ) testboard[i][j].set_black(true);
								if ( future[i][j].is_king() ) testboard[i][j].set_king(true);
							}
						}
						if ( testboard[curcol][currow].is_king() ){
							testboard[curcol][currow].set_king(false);
							testboard[curcol-2][currow-2].set_king(true);
						}
						testboard[curcol-1][currow-1].set_king(false);
						testboard[curcol][currow].set_white(false);
						testboard[curcol-1][currow-1].set_black(false);
						testboard[curcol-2][currow-2].set_white(true);
						if ( make_jump( curcol-2, currow-2, destcol, destrow, testboard ) ) return true;
					}
					//Up right check
					if ( future[curcol-1][currow+1].is_black() && future[curcol-2][currow+2].is_empty() ){
						piece testboard[8][8];
						for ( int i = 0; i < 8; i++ ){
							for ( int j = 0; j < 8; j++ ){
								if ( future[i][j].is_white() ) testboard[i][j].set_white(true);
								if ( future[i][j].is_black() ) testboard[i][j].set_black(true);
								if ( future[i][j].is_king() ) testboard[i][j].set_king(true);
							}
						}
						if ( testboard[curcol][currow].is_king() ){
							testboard[curcol][currow].set_king(false);
							testboard[curcol-2][currow+2].set_king(true);
						}
						testboard[curcol-1][currow+1].set_king(false);
						testboard[curcol][currow].set_white(false);
						testboard[curcol-1][currow+1].set_black(false);
						testboard[curcol-2][currow+2].set_white(true);
						if ( make_jump( curcol-2, currow+2, destcol, destrow, testboard ) ) return true;
					}
				}
			}
			else if ( curcol <= 5 && curcol >=2 ){
				if ( currow <= 1 ){
					//Up right check
					if ( future[curcol-1][currow+1].is_black() && future[curcol-2][currow+2].is_empty() ){
						piece testboard[8][8];
						for ( int i = 0; i < 8; i++ ){
							for ( int j = 0; j < 8; j++ ){
								if ( future[i][j].is_white() ) testboard[i][j].set_white(true);
								if ( future[i][j].is_black() ) testboard[i][j].set_black(true);
								if ( future[i][j].is_king() ) testboard[i][j].set_king(true);
							}
						}
						if ( testboard[curcol][currow].is_king() ){
							testboard[curcol][currow].set_king(false);
							testboard[curcol-2][currow+2].set_king(true);
						}
						testboard[curcol-1][currow+1].set_king(false);
						testboard[curcol][currow].set_white(false);
						testboard[curcol-1][currow+1].set_black(false);
						testboard[curcol-2][currow+2].set_white(true);
						if ( make_jump( curcol-2, currow+2, destcol, destrow, testboard ) ) return true;
					}
					if ( future[curcol][currow].is_king() ){
						//Down right check
						if ( future[curcol+1][currow+1].is_black() && future[curcol+2][currow+2].is_empty() ){
							piece testboard[8][8];
							for ( int i = 0; i < 8; i++ ){
								for ( int j = 0; j < 8; j++ ){
									if ( future[i][j].is_white() ) testboard[i][j].set_white(true);
									if ( future[i][j].is_black() ) testboard[i][j].set_black(true);
									if ( future[i][j].is_king() ) testboard[i][j].set_king(true);
								}
							}
							if ( testboard[curcol][currow].is_king() ){
								testboard[curcol][currow].set_king(false);
								testboard[curcol+2][currow+2].set_king(true);
							}
							testboard[curcol+1][currow+1].set_king(false);
							testboard[curcol][currow].set_white(false);
							testboard[curcol+1][currow+1].set_black(false);
							testboard[curcol+2][currow+2].set_white(true);
							if ( make_jump( curcol+2, currow+2, destcol, destrow, testboard ) ) return true;
						}
					}
				}
				else if ( currow >= 6 ){
					//Up left check
					if ( future[curcol-1][currow-1].is_black() && future[curcol-2][currow-2].is_empty() ){
						piece testboard[8][8];
						for ( int i = 0; i < 8; i++ ){
							for ( int j = 0; j < 8; j++ ){
								if ( future[i][j].is_white() ) testboard[i][j].set_white(true);
								if ( future[i][j].is_black() ) testboard[i][j].set_black(true);
								if ( future[i][j].is_king() ) testboard[i][j].set_king(true);
							}
						}
						if ( testboard[curcol][currow].is_king() ){
							testboard[curcol][currow].set_king(false);
							testboard[curcol-2][currow-2].set_king(true);
						}
						testboard[curcol-1][currow-1].set_king(false);
						testboard[curcol][currow].set_white(false);
						testboard[curcol-1][currow-1].set_black(false);
						testboard[curcol-2][currow-2].set_white(true);
						if ( make_jump( curcol-2, currow-2, destcol, destrow, testboard ) ) return true;
					}
					if ( future[curcol][currow].is_king() ){
						//Down left check
						if ( future[curcol+1][currow-1].is_black() && future[curcol+2][currow-2].is_empty() ){
							piece testboard[8][8];
							for ( int i = 0; i < 8; i++ ){
								for ( int j = 0; j < 8; j++ ){
									if ( future[i][j].is_white() ) testboard[i][j].set_white(true);
									if ( future[i][j].is_black() ) testboard[i][j].set_black(true);
									if ( future[i][j].is_king() ) testboard[i][j].set_king(true);
								}
							}
							if ( testboard[curcol][currow].is_king() ){
								testboard[curcol][currow].set_king(false);
								testboard[curcol+2][currow-2].set_king(true);
							}
							testboard[curcol+1][currow-1].set_king(false);
							testboard[curcol][currow].set_white(false);
							testboard[curcol+1][currow-1].set_black(false);
							testboard[curcol+2][currow-2].set_white(true);
							if ( make_jump( curcol+2, currow-2, destcol, destrow, testboard ) ) return true;
						}
					}
				}
			}
		}
		else if ( next_mover() == COMPUTER ){
			if ( curcol <= 5 && curcol >= 2 && currow <= 5 && curcol >= 2 ){
				//Down left check
				if ( future[curcol+1][currow-1].is_white() && future[curcol+2][currow-2].is_empty() ){
					piece testboard[8][8];
					for ( int i = 0; i < 8; i++ ){
						for ( int j = 0; j < 8; j++ ){
							if ( future[i][j].is_white() ) testboard[i][j].set_white(true);
							if ( future[i][j].is_black() ) testboard[i][j].set_black(true);
							if ( future[i][j].is_king() ) testboard[i][j].set_king(true);
						}
					}
					if ( testboard[curcol][currow].is_king() ){
						testboard[curcol][currow].set_king(false);
						testboard[curcol+2][currow-2].set_king(true);
					}
					testboard[curcol+1][currow-1].set_king(false);
					testboard[curcol][currow].set_black(false);
					testboard[curcol+1][currow-1].set_white(false);
					testboard[curcol+2][currow-2].set_black(true);
					if ( make_jump( curcol+2, currow-2, destcol, destrow, testboard ) ) return true;
				}
				//Down right check
				if ( future[curcol+1][currow+1].is_white() && future[curcol+2][currow+2].is_empty() ){
					piece testboard[8][8];
					for ( int i = 0; i < 8; i++ ){
						for ( int j = 0; j < 8; j++ ){
							if ( future[i][j].is_white() ) testboard[i][j].set_white(true);
							if ( future[i][j].is_black() ) testboard[i][j].set_black(true);
							if ( future[i][j].is_king() ) testboard[i][j].set_king(true);
						}
					}
					if ( testboard[curcol][currow].is_king() ){
						testboard[curcol][currow].set_king(false);
						testboard[curcol+2][currow+2].set_king(true);
					}
					testboard[curcol+1][currow+1].set_king(false);
					testboard[curcol][currow].set_black(false);
					testboard[curcol+1][currow+1].set_white(false);
					testboard[curcol+2][currow+2].set_black(true);
					if ( make_jump( curcol+2, currow+2, destcol, destrow, testboard ) ) return true;
				}
				if ( future[curcol][currow].is_king() ){
					//Up left check
					if ( future[curcol-1][currow-1].is_white() && future[curcol-2][currow-2].is_empty() ){
						piece testboard[8][8];
						for ( int i = 0; i < 8; i++ ){
							for ( int j = 0; j < 8; j++ ){
								if ( future[i][j].is_white() ) testboard[i][j].set_white(true);
								if ( future[i][j].is_black() ) testboard[i][j].set_black(true);
								if ( future[i][j].is_king() ) testboard[i][j].set_king(true);
							}
						}
						if ( testboard[curcol][currow].is_king() ){
							testboard[curcol][currow].set_king(false);
							testboard[curcol-2][currow-2].set_king(true);
						}
						testboard[curcol-1][currow-1].set_king(false);
						testboard[curcol][currow].set_black(false);
						testboard[curcol-1][currow-1].set_white(false);
						testboard[curcol-2][currow-2].set_black(true);
						if ( make_jump( curcol-2, currow-2, destcol, destrow, testboard ) ) return true;
					}
					//Up right check
					if ( future[curcol-1][currow+1].is_white() && future[curcol-2][currow+2].is_empty() ){
						piece testboard[8][8];
						for ( int i = 0; i < 8; i++ ){
							for ( int j = 0; j < 8; j++ ){
								if ( future[i][j].is_white() ) testboard[i][j].set_white(true);
								if ( future[i][j].is_black() ) testboard[i][j].set_black(true);
								if ( future[i][j].is_king() ) testboard[i][j].set_king(true);
							}
						}
						if ( testboard[curcol][currow].is_king() ){
							testboard[curcol][currow].set_king(false);
							testboard[curcol-2][currow+2].set_king(true);
						}
						testboard[curcol-1][currow+1].set_king(false);
						testboard[curcol][currow].set_black(false);
						testboard[curcol-1][currow+1].set_white(false);
						testboard[curcol-2][currow+2].set_black(true);
						if ( make_jump( curcol-2, currow+2, destcol, destrow, testboard ) ) return true;
					}
				}
			}
			else if ( curcol <= 1 ){
				if ( currow <= 1 ){
					//Down right check
					if ( future[curcol+1][currow+1].is_white() && future[curcol+2][currow+2].is_empty() ){
						piece testboard[8][8];
						for ( int i = 0; i < 8; i++ ){
							for ( int j = 0; j < 8; j++ ){
								if ( future[i][j].is_white() ) testboard[i][j].set_white(true);
								if ( future[i][j].is_black() ) testboard[i][j].set_black(true);
								if ( future[i][j].is_king() ) testboard[i][j].set_king(true);
							}
						}
						if ( testboard[curcol][currow].is_king() ){
							testboard[curcol][currow].set_king(false);
							testboard[curcol+2][currow+2].set_king(true);
						}
						testboard[curcol+1][currow+1].set_king(false);
						testboard[curcol][currow].set_black(false);
						testboard[curcol+1][currow+1].set_white(false);
						testboard[curcol+2][currow+2].set_black(true);
						if ( make_jump( curcol+2, currow+2, destcol, destrow, testboard ) ) return true;
					}
				}
				else if ( currow >= 6 ){
					//Down left check
					if ( future[curcol+1][currow-1].is_white() && future[curcol+2][currow-2].is_empty() ){
						piece testboard[8][8];
						for ( int i = 0; i < 8; i++ ){
							for ( int j = 0; j < 8; j++ ){
								if ( future[i][j].is_white() ) testboard[i][j].set_white(true);
								if ( future[i][j].is_black() ) testboard[i][j].set_black(true);
								if ( future[i][j].is_king() ) testboard[i][j].set_king(true);
							}
						}
						if ( testboard[curcol][currow].is_king() ){
							testboard[curcol][currow].set_king(false);
							testboard[curcol+2][currow-2].set_king(true);
						}
						testboard[curcol+1][currow-1].set_king(false);
						testboard[curcol][currow].set_black(false);
						testboard[curcol+1][currow-1].set_white(false);
						testboard[curcol+2][currow-2].set_black(true);
						if ( make_jump( curcol+2, currow-2, destcol, destrow, testboard ) ) return true;
					}
				}
				else {
					//Down left check
					if ( future[curcol+1][currow-1].is_white() && future[curcol+2][currow-2].is_empty() ){
						piece testboard[8][8];
						for ( int i = 0; i < 8; i++ ){
							for ( int j = 0; j < 8; j++ ){
								if ( future[i][j].is_white() ) testboard[i][j].set_white(true);
								if ( future[i][j].is_black() ) testboard[i][j].set_black(true);
								if ( future[i][j].is_king() ) testboard[i][j].set_king(true);
							}
						}
						if ( testboard[curcol][currow].is_king() ){
							testboard[curcol][currow].set_king(false);
							testboard[curcol+2][currow-2].set_king(true);
						}
						testboard[curcol+1][currow-1].set_king(false);
						testboard[curcol][currow].set_black(false);
						testboard[curcol+1][currow-1].set_white(false);
						testboard[curcol+2][currow-2].set_black(true);
						if ( make_jump( curcol+2, currow-2, destcol, destrow, testboard ) ) return true;
					}
					//Down right check
					if ( future[curcol+1][currow+1].is_white() && future[curcol+2][currow+2].is_empty() ){
						piece testboard[8][8];
						for ( int i = 0; i < 8; i++ ){
							for ( int j = 0; j < 8; j++ ){
								if ( future[i][j].is_white() ) testboard[i][j].set_white(true);
								if ( future[i][j].is_black() ) testboard[i][j].set_black(true);
								if ( future[i][j].is_king() ) testboard[i][j].set_king(true);
							}
						}
						if ( testboard[curcol][currow].is_king() ){
							testboard[curcol][currow].set_king(false);
							testboard[curcol+2][currow+2].set_king(true);
						}
						testboard[curcol+1][currow+1].set_king(false);
						testboard[curcol][currow].set_black(false);
						testboard[curcol+1][currow+1].set_white(false);
						testboard[curcol+2][currow+2].set_black(true);
						if ( make_jump( curcol+2, currow+2, destcol, destrow, testboard ) ) return true;
					}
				}
			}
			else if ( curcol >= 6 ){
				if ( currow <=1 ){
					if ( future[curcol][currow].is_king() ){
						//Up right check
						if ( future[curcol-1][currow+1].is_white() && future[curcol-2][currow+2].is_empty() ){
							piece testboard[8][8];
							for ( int i = 0; i < 8; i++ ){
								for ( int j = 0; j < 8; j++ ){
									if ( future[i][j].is_white() ) testboard[i][j].set_white(true);
									if ( future[i][j].is_black() ) testboard[i][j].set_black(true);
									if ( future[i][j].is_king() ) testboard[i][j].set_king(true);
								}
							}
							if ( testboard[curcol][currow].is_king() ){
								testboard[curcol][currow].set_king(false);
								testboard[curcol-2][currow+2].set_king(true);
							}
							testboard[curcol-1][currow+1].set_king(false);
							testboard[curcol][currow].set_black(false);
							testboard[curcol-1][currow+1].set_white(false);
							testboard[curcol-2][currow+2].set_black(true);
							if ( make_jump( curcol-2, currow+2, destcol, destrow, testboard ) ) return true;
						}
					}
				}
				else if ( currow >= 6 ){
					if ( future[curcol][currow].is_king() ){
						//Up left check
						if ( future[curcol-1][currow-1].is_white() && future[curcol-2][currow-2].is_empty() ){
							piece testboard[8][8];
							for ( int i = 0; i < 8; i++ ){
								for ( int j = 0; j < 8; j++ ){
									if ( future[i][j].is_white() ) testboard[i][j].set_white(true);
									if ( future[i][j].is_black() ) testboard[i][j].set_black(true);
									if ( future[i][j].is_king() ) testboard[i][j].set_king(true);
								}
							}
							if ( testboard[curcol][currow].is_king() ){
								testboard[curcol][currow].set_king(false);
								testboard[curcol-2][currow-2].set_king(true);
							}
							testboard[curcol-1][currow-1].set_king(false);
							testboard[curcol][currow].set_black(false);
							testboard[curcol-1][currow-1].set_white(false);
							testboard[curcol-2][currow-2].set_black(true);
							if ( make_jump( curcol-2, currow-2, destcol, destrow, testboard ) ) return true;
						}
					}
				}
				else {
					if ( future[curcol][currow].is_king() ){
						//Up left check
						if ( future[curcol-1][currow-1].is_white() && future[curcol-2][currow-2].is_empty() ){
							piece testboard[8][8];
							for ( int i = 0; i < 8; i++ ){
								for ( int j = 0; j < 8; j++ ){
									if ( future[i][j].is_white() ) testboard[i][j].set_white(true);
									if ( future[i][j].is_black() ) testboard[i][j].set_black(true);
									if ( future[i][j].is_king() ) testboard[i][j].set_king(true);
								}
							}
							if ( testboard[curcol][currow].is_king() ){
								testboard[curcol][currow].set_king(false);
								testboard[curcol-2][currow-2].set_king(true);
							}
							testboard[curcol-1][currow-1].set_king(false);
							testboard[curcol][currow].set_black(false);
							testboard[curcol-1][currow-1].set_white(false);
							testboard[curcol-2][currow-2].set_black(true);
							if ( make_jump( curcol-2, currow-2, destcol, destrow, testboard ) ) return true;
						}
						//Up right check
						if ( future[curcol-1][currow+1].is_white() && future[curcol-2][currow+2].is_empty() ){
							piece testboard[8][8];
							for ( int i = 0; i < 8; i++ ){
								for ( int j = 0; j < 8; j++ ){
									if ( future[i][j].is_white() ) testboard[i][j].set_white(true);
									if ( future[i][j].is_black() ) testboard[i][j].set_black(true);
									if ( future[i][j].is_king() ) testboard[i][j].set_king(true);
								}
							}
							if ( testboard[curcol][currow].is_king() ){
								testboard[curcol][currow].set_king(false);
								testboard[curcol-2][currow+2].set_king(true);
							}
							testboard[curcol-1][currow+1].set_king(false);
							testboard[curcol][currow].set_black(false);
							testboard[curcol-1][currow+1].set_white(false);
							testboard[curcol-2][currow+2].set_black(true);
							if ( make_jump( curcol-2, currow+2, destcol, destrow, testboard ) ) return true;
						}
					}
				}
			}
			else if ( curcol <= 5 && curcol >=2 ){
				if ( currow <= 1 ){
					//Down right check
					if ( future[curcol+1][currow+1].is_white() && future[curcol+2][currow+2].is_empty() ){
						piece testboard[8][8];
						for ( int i = 0; i < 8; i++ ){
							for ( int j = 0; j < 8; j++ ){
								if ( future[i][j].is_white() ) testboard[i][j].set_white(true);
								if ( future[i][j].is_black() ) testboard[i][j].set_black(true);
								if ( future[i][j].is_king() ) testboard[i][j].set_king(true);
							}
						}
						if ( testboard[curcol][currow].is_king() ){
							testboard[curcol][currow].set_king(false);
							testboard[curcol+2][currow+2].set_king(true);
						}
						testboard[curcol+1][currow+1].set_king(false);
						testboard[curcol][currow].set_black(false);
						testboard[curcol+1][currow+1].set_white(false);
						testboard[curcol+2][currow+2].set_black(true);
						if ( make_jump( curcol+2, currow+2, destcol, destrow, testboard ) ) return true;
					}
					if ( future[curcol][currow].is_king() ){
						//Up right check
						if ( future[curcol-1][currow+1].is_white() && future[curcol-2][currow+2].is_empty() ){
							piece testboard[8][8];
							for ( int i = 0; i < 8; i++ ){
								for ( int j = 0; j < 8; j++ ){
									if ( future[i][j].is_white() ) testboard[i][j].set_white(true);
									if ( future[i][j].is_black() ) testboard[i][j].set_black(true);
									if ( future[i][j].is_king() ) testboard[i][j].set_king(true);
								}
							}
							if ( testboard[curcol][currow].is_king() ){
								testboard[curcol][currow].set_king(false);
								testboard[curcol-2][currow+2].set_king(true);
							}
							testboard[curcol-1][currow+1].set_king(false);
							testboard[curcol][currow].set_black(false);
							testboard[curcol-1][currow+1].set_white(false);
							testboard[curcol-2][currow+2].set_black(true);
							if ( make_jump( curcol-2, currow+2, destcol, destrow, testboard ) ) return true;
						}
					}
				}
				else if ( currow >= 6 ){
					//Down left check
					if ( future[curcol+1][currow-1].is_white() && future[curcol+2][currow-2].is_empty() ){
						piece testboard[8][8];
						for ( int i = 0; i < 8; i++ ){
							for ( int j = 0; j < 8; j++ ){
								if ( future[i][j].is_white() ) testboard[i][j].set_white(true);
								if ( future[i][j].is_black() ) testboard[i][j].set_black(true);
								if ( future[i][j].is_king() ) testboard[i][j].set_king(true);
							}
						}
						if ( testboard[curcol][currow].is_king() ){
							testboard[curcol][currow].set_king(false);
							testboard[curcol+2][currow-2].set_king(true);
						}
						testboard[curcol+1][currow-1].set_king(false);
						testboard[curcol][currow].set_black(false);
						testboard[curcol+1][currow-1].set_white(false);
						testboard[curcol+2][currow-2].set_black(true);
						if ( make_jump( curcol+2, currow-2, destcol, destrow, testboard ) ) return true;
					}
					if ( future[curcol][currow].is_king() ){
						//Up left check
						if ( future[curcol-1][currow-1].is_white() && future[curcol-2][currow-2].is_empty() ){
							piece testboard[8][8];
							for ( int i = 0; i < 8; i++ ){
								for ( int j = 0; j < 8; j++ ){
									if ( future[i][j].is_white() ) testboard[i][j].set_white(true);
									if ( future[i][j].is_black() ) testboard[i][j].set_black(true);
									if ( future[i][j].is_king() ) testboard[i][j].set_king(true);
								}
							}
							if ( testboard[curcol][currow].is_king() ){
							testboard[curcol][currow].set_king(false);
							testboard[curcol-2][currow-2].set_king(true);
							}
							testboard[curcol-1][currow-1].set_king(false);
							testboard[curcol][currow].set_black(false);
							testboard[curcol-1][currow-1].set_white(false);
							testboard[curcol-2][currow-2].set_black(true);
							if ( make_jump( curcol-2, currow-2, destcol, destrow, testboard ) ) return true;
						}
					}
				}
			}
		}
		if ( curcol == destcol && currow == destrow ){
			for ( int i = 0; i < 8; i++ ){
				for ( int j = 0; j < 8; j++ ){
					if ( future[i][j].is_white() ) board[i][j].set_white(true);
					if ( future[i][j].is_black() ) board[i][j].set_black(true);
					if ( future[i][j].is_king() ) board[i][j].set_king(true);
					if ( future[i][j].is_empty() ){
						board[i][j].set_white(false);
						board[i][j].set_black(false);
						board[i][j].set_king(false);
					}
				}
			}
			return true;
		}
		else return false;
	}
}