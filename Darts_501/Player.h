#pragma once
using namespace std;
#include <iostream>
#include "Board.h"

class Player
{
private:

	// Member variables
	string name = "";
	int prob = 0;
	int set_wins = 0;
	int game_wins = 0;
	int match_wins = 0;
	int score = 501;
	// create a board instance
	Board board;
	// stores all possible final throws for validation purposes
	int finalThrows[21] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30, 32, 34, 36, 38, 40, 50};
	//holds the sum of the points earned in a turn by the player 
	int roundtotal = 0;
	int target = 0;
	// used for win check
	bool winner = false;

public:

	// Constructors
	Player();
	Player(const string& name, int prob);
	
	// Destructor
	~Player();

	// Getters
	int get_gamewins();
	int get_setwins();
	int get_matchwins();
	int getscore();
	bool win_check();

	//setters
	void game_reset();
	void set_reset();
	void match_reset();
	void add_gamewins();
	void add_setwins();
	void add_matchwins();


	// game methods
	int aim();
	bool check_finalthrow(int );
	void throw_darts();
	void turn();




};


