//cpp
#include "tic_tac_toe.h"

//Public functions 
bool TicTacToe::game_over() //Determines whether the game is over or not
{   
    //If there is a win somewhere, set the winner, end the game
    if(check_column_win()||check_row_win()||check_diagonal_win()) 
    {
        set_winner();
        return true;
    }
    //If the board is full(with no winner), end the game as a draw
    else if(check_board_full())
    {
        winner = "C";
        return true;
    }
    //If there isn't a winner or the board isn't full yet, game isn't over yet
    else
    {
        return false;
    }
   
    
}

//marks the board by using current player name(X or O) to mark index, then switches to opposite player
void TicTacToe::mark_board(int position)
{   
    //Input Validation to check if position is original, not part of assignment though
    /*while(pegs[position-1] == "X" || pegs[position-1] == "O")
    {
        std::cout<<"Please enter a spot that hasn't been taken already: ";
        std::cin>>position;
    }*/

    pegs[position-1] = player;
    set_next_player();
    
}

//Begins the game by setting all index slots to " "
void TicTacToe::start_game(std::string first_player)
{
    player = first_player; 
    clear_board();
}

//Displays the board without changing any values
void TicTacToe::display_board()const
{
    for(std::size_t i=0; i<pegs.size(); i+= 3)
    {
        std::cout<<pegs[i]<<"|"<<pegs[i+1]<<"|"<<pegs[i+2]<<"\n";
    }
}


//Private functions
//Checks for column win without modification
bool TicTacToe::check_column_win()const
{   
    //Colums begin at indexes 0,1,2(Increments by 1 till 3)
    for(std::size_t i=0; i<3; i+=1) 
    {   
        //Column win cannot use blank values, and makes sure that top, middle, bottom slots are equal
        if((pegs[i] != " ") && (pegs[i] == pegs[i+3]) && (pegs[i+3] == pegs[i+6]))
        {   
            //Column win!
            return true;
        }
    }
    return false;
}

//Checks for row win without modification    
bool TicTacToe::check_row_win()const 
{   
    //Rows start at indexes 0,3,6(Increments by 3 till 6)
    for(std::size_t i=0; i<=6; i+=3)
    {   
        //Row win can't have a blank space, and makes sure that left, middle, right slots are all the same values
        if((pegs[i] != " ") && (pegs[i] == pegs[i+1]) && (pegs[i+1] == pegs[i+2]))
        {   
            //Row win!
            return true;
        }
    }
    return false;    
}

//Checks for diagonal win without modification of values
bool TicTacToe::check_diagonal_win() const 
{  
    //If indexes 0,4,8 are equal(excluding cleared board)
   if((pegs[0] != " ") && (pegs[0] == pegs[4]) && (pegs[4] == pegs[8])) 
    {   
        //Diagonal win!
        return true;
    }
    //If indexes 2, 4, 6 are equal(excluding cleared board)
    else if((pegs[2] != " ") && (pegs[2] == pegs[4]) && (pegs[4] == pegs[6]))
    {   
        //Diagonal Win!
        return true;
    }
    //If neither of the above, no diagonal win(yet)!
    else
    {   
        return false;
    }
}

//Sets the winner based on current player(if X should play then O), once win has been determined
void TicTacToe::set_winner()
{
    if(player == "X")
    {
        winner = "O";
    }
    else
    { 
        winner = "X"; 
    }
}

//Same logic as set winner except that this is used for alternating between players
void TicTacToe::set_next_player()
{
    if(player == "X")
    {
        player = "O";
    }
    else
    {
        player = "X";
    }
}

//Checks if the board is full without modifying it, checks whether there are spaces or not
bool TicTacToe::check_board_full()const
{
    for(auto peg: pegs)
    {
        if(peg == " ")
        {
            return false;
        }
    }
    return true;
}

//Makes all board components as a space(as to clear up the board)
void TicTacToe::clear_board()
{
    for(std::size_t i=0; i<pegs.size(); ++i)
    {
        pegs[i] = " ";
    }
}