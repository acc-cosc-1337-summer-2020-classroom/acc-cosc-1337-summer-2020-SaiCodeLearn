#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "tic_tac_toe.h"

TEST_CASE("Verify Test Configuration", "verification") {
	REQUIRE(true == true);
}
//Tests for get_player function - Checks if X or O is really the current player or not
TEST_CASE("Test First player set to X: ")
{
	TicTacToe match;
	match.start_game("X");
	REQUIRE(match.get_player() == "X");
}

TEST_CASE("Test First player set to O: ")
{
	TicTacToe match;
	match.start_game("O");
	REQUIRE(match.get_player() == "O");
}

//Testing if game_over can verify a draw(no winning positions)
TEST_CASE("Verify game ends when the board is full - With a Draw: ")
{
	TicTacToe tic_tac_toe;
	tic_tac_toe.start_game("X");

	tic_tac_toe.mark_board(1);
	REQUIRE(tic_tac_toe.game_over() == false);

	tic_tac_toe.mark_board(2);
	REQUIRE(tic_tac_toe.game_over() == false);

	tic_tac_toe.mark_board(3);
	REQUIRE(tic_tac_toe.game_over() == false);

	tic_tac_toe.mark_board(4);
	REQUIRE(tic_tac_toe.game_over() == false);

	tic_tac_toe.mark_board(6);
	REQUIRE(tic_tac_toe.game_over() == false);

	tic_tac_toe.mark_board(5);
	REQUIRE(tic_tac_toe.game_over() == false);

	tic_tac_toe.mark_board(7);
	REQUIRE(tic_tac_toe.game_over() == false);

	tic_tac_toe.mark_board(9);
	REQUIRE(tic_tac_toe.game_over() == false);

	tic_tac_toe.mark_board(8);
	REQUIRE(tic_tac_toe.game_over() == true);
	
	REQUIRE(tic_tac_toe.get_winner() == "C");
}	

//Testing if get_winner can detect wins by columns
//First column test case
TEST_CASE("Test win by first column: ")
{
	TicTacToe tic_tac_toe;
	tic_tac_toe.start_game("X");

	tic_tac_toe.mark_board(1);
	REQUIRE(tic_tac_toe.game_over() == false);

	tic_tac_toe.mark_board(2);
	REQUIRE(tic_tac_toe.game_over() == false);

	tic_tac_toe.mark_board(4);
	REQUIRE(tic_tac_toe.game_over() == false);

	tic_tac_toe.mark_board(5);
	REQUIRE(tic_tac_toe.game_over() == false);

	tic_tac_toe.mark_board(7);
	REQUIRE(tic_tac_toe.game_over() == true);

	REQUIRE(tic_tac_toe.get_winner() == "X");
}

//Second Column Test Case
TEST_CASE("Test win by second column: ")
{
	TicTacToe tic_tac_toe;
	tic_tac_toe.start_game("X");

	tic_tac_toe.mark_board(2);
	REQUIRE(tic_tac_toe.game_over() == false);

	tic_tac_toe.mark_board(1);
	REQUIRE(tic_tac_toe.game_over() == false);

	tic_tac_toe.mark_board(5);
	REQUIRE(tic_tac_toe.game_over() == false);

	tic_tac_toe.mark_board(4);
	REQUIRE(tic_tac_toe.game_over() == false);

	tic_tac_toe.mark_board(8);
	REQUIRE(tic_tac_toe.game_over() == true);
	
	REQUIRE(tic_tac_toe.get_winner() == "X");
}

//Third Column Test case
TEST_CASE("Test win by third column: ")
{
	TicTacToe tic_tac_toe;
	tic_tac_toe.start_game("X");

	tic_tac_toe.mark_board(3);
	REQUIRE(tic_tac_toe.game_over() == false);

	tic_tac_toe.mark_board(2);
	REQUIRE(tic_tac_toe.game_over() == false);

	tic_tac_toe.mark_board(6);
	REQUIRE(tic_tac_toe.game_over() == false);

	tic_tac_toe.mark_board(4);
	REQUIRE(tic_tac_toe.game_over() == false);

	tic_tac_toe.mark_board(9);
	REQUIRE(tic_tac_toe.game_over() == true);
	
	REQUIRE(tic_tac_toe.get_winner() == "X");
}

//Testing if get_winner can detect wins by rows
//First row test case
TEST_CASE("Test win by first row: ")
{
	TicTacToe tic_tac_toe;
	tic_tac_toe.start_game("X");

	tic_tac_toe.mark_board(1);
	REQUIRE(tic_tac_toe.game_over() == false);

	tic_tac_toe.mark_board(4);
	REQUIRE(tic_tac_toe.game_over() == false);

	tic_tac_toe.mark_board(2);
	REQUIRE(tic_tac_toe.game_over() == false);

	tic_tac_toe.mark_board(5);
	REQUIRE(tic_tac_toe.game_over() == false);

	tic_tac_toe.mark_board(3);
	REQUIRE(tic_tac_toe.game_over() == true);
	
	REQUIRE(tic_tac_toe.get_winner() == "X");
}

//Second row test case
TEST_CASE("Test win by second row: ")
{
	TicTacToe tic_tac_toe;
	tic_tac_toe.start_game("X");

	tic_tac_toe.mark_board(4);
	REQUIRE(tic_tac_toe.game_over() == false);

	tic_tac_toe.mark_board(1);
	REQUIRE(tic_tac_toe.game_over() == false);

	tic_tac_toe.mark_board(5);
	REQUIRE(tic_tac_toe.game_over() == false);

	tic_tac_toe.mark_board(2);
	REQUIRE(tic_tac_toe.game_over() == false);

	tic_tac_toe.mark_board(6);
	REQUIRE(tic_tac_toe.game_over() == true);
	
	REQUIRE(tic_tac_toe.get_winner() == "X");
}

//Third row test case
TEST_CASE("Test win by third row: ")
{
	TicTacToe tic_tac_toe;
	tic_tac_toe.start_game("X");

	tic_tac_toe.mark_board(7);
	REQUIRE(tic_tac_toe.game_over() == false);

	tic_tac_toe.mark_board(4);
	REQUIRE(tic_tac_toe.game_over() == false);

	tic_tac_toe.mark_board(8);
	REQUIRE(tic_tac_toe.game_over() == false);

	tic_tac_toe.mark_board(5);
	REQUIRE(tic_tac_toe.game_over() == false);

	tic_tac_toe.mark_board(9);
	REQUIRE(tic_tac_toe.game_over() == true);
	
	REQUIRE(tic_tac_toe.get_winner() == "X");
}

//Testing if get_winner can detect wins by diagonals
//Top left diagonal test case
TEST_CASE("Test win diagonally from top left: ")
{
	TicTacToe tic_tac_toe;
	tic_tac_toe.start_game("X");

	tic_tac_toe.mark_board(1);
	REQUIRE(tic_tac_toe.game_over() == false);

	tic_tac_toe.mark_board(4);
	REQUIRE(tic_tac_toe.game_over() == false);

	tic_tac_toe.mark_board(5);
	REQUIRE(tic_tac_toe.game_over() == false);

	tic_tac_toe.mark_board(6);
	REQUIRE(tic_tac_toe.game_over() == false);

	tic_tac_toe.mark_board(9);
	REQUIRE(tic_tac_toe.game_over() == true);
	
	REQUIRE(tic_tac_toe.get_winner() == "X");
}

//Bottom left diagonal test case
TEST_CASE("Test win diagonally from bottom left: ")
{
	TicTacToe tic_tac_toe;
	tic_tac_toe.start_game("X");

	tic_tac_toe.mark_board(7);
	REQUIRE(tic_tac_toe.game_over() == false);

	tic_tac_toe.mark_board(4);
	REQUIRE(tic_tac_toe.game_over() == false);

	tic_tac_toe.mark_board(5);
	REQUIRE(tic_tac_toe.game_over() == false);

	tic_tac_toe.mark_board(6);
	REQUIRE(tic_tac_toe.game_over() == false);

	tic_tac_toe.mark_board(3);
	REQUIRE(tic_tac_toe.game_over() == true);
	
	REQUIRE(tic_tac_toe.get_winner() == "X");
}