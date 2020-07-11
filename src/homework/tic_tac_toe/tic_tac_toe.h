//h
//Whatever libraries we need
#include <iostream>
#include <string>
#include <vector>

//header guard
#ifndef TIC_TAC_TOE_H
#define TIC_TAC_TOE_H

class TicTacToe
{
public:
    bool game_over();
    void mark_board(int position);
    void start_game(std::string first_player);
    void display_board()const;
    //Inline functions below to return player or winner, without modification
    std::string get_player()const{return player;}
    std::string get_winner()const{return winner;}
    
private:
    //header for winner checks
    bool check_column_win()const;
    bool check_row_win()const;
    bool check_diagonal_win()const;
    //Setting a player or winner
    void set_winner();
    void set_next_player();
    //Checks for full board, clear_board() erases board slots
    bool check_board_full()const;
    void clear_board();

    //Private variables(player string, vector(board), and winner)
    std::string player;
    std::vector<std::string> pegs{9, " "};
    std::string winner;
    
};

#endif