#include "tic_tac_toe.h"

using std::cout; using std::cin; //std methods that we will be using a bit

int main() 
{	
	//Create TicTacToe object, player and choice strings
	TicTacToe tic_tac_toe;
	std::string player;
	std::string choice;

	//Post-test loop to allow one tic tac toe game, then users can continue or stop
	do
	{	
		//Player Enters X or O as first player
		cout<<"\nEnter X or O(as first player): ";
		cin>>player;

		//If X or O isn't entered, loop occurs to ensure correct entry
		while (!(player == "O" || player == "X"))
		{
			cout<<"Correctly enter if you want to play X or O(Capital letter): ";
			cin>>player;
		}

		//Tic Tac Toe game begins
		tic_tac_toe.start_game(player);

		//While the game isn't finished yet(no win, or all spots aren't filled)
		while (!(tic_tac_toe.game_over()))
		{
			int position; //Int position declared here

			//Position entered by player and validated for proper range
			cout<<"\nEnter position from 1 to 9: ";
			cin>>position;
			while(position < 1 || position > 9)
			{
				cout<<"\nEnter a valid position from 1 to 9(only): ";
				cin>>position;
			}

			//Position marked in correct spot
			tic_tac_toe.mark_board(position);

			//board is displayed for opponents to see
			tic_tac_toe.display_board();
		}

		//After the game is finished(either because there's a winner or spots are full)
		//A winner is named
		cout<<"\nThe Winner of the game is: "<<tic_tac_toe.get_winner();

		//if the winner isn't X or O, but C, explain what C is
		if (tic_tac_toe.get_winner() == "C")
		{
			cout<<"\nThe match was inconclusive(Draw)\n";
		}
		//If no draw, put newline character(formatting)
		else
		{cout<<"\n";}
		
		//Determines if user wants to keep going or not
		cout<<"\nIf you want to continue playing...\n";
		cout<<"Enter Yes or yes: ";
		cin>>choice;
	} while(choice == "Yes" || choice == "yes");//Condition(s) for program to continue
	
	return 0; //Program success!
}