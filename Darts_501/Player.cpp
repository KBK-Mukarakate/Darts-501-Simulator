#include "Player.h"
#include "Board.h"
using namespace std;
#include <iostream>

// Constructors
Player::Player() : name(""), prob(0), set_wins(0), score(501)
{
}
Player::Player(const string& name, int prob)
	: name(name), prob(prob)
{
}

// Destructor
Player::~Player()
{
}

// Methods/ Member functions

int Player::get_gamewins()
{
	return game_wins;
}

int Player::get_setwins()
{
	return set_wins;
}

int Player::get_matchwins()
{
	return match_wins;
}

int Player::getscore()
{
	return score;
}

bool Player::win_check()
{
	return winner;
}

// resets score and win check boolean variable.
void Player::game_reset() {
	score = 501;
	winner = false;
}
// resets score, win check boolean variable and game win counter.
void Player::set_reset()
{
	game_reset();
	game_wins = 0;

}
// resets score, win check boolean variable, game win counter and set win counter.
void Player::match_reset()
{
	set_reset();
	set_wins = 0;

}
// adds 1 game win for loop checks
void Player::add_gamewins()
{
	game_wins++;
}
//adds 1 set win for loop checks
void Player::add_setwins()
{
	set_wins++;
}
//adds 1 match win for simulation data collection
void Player::add_matchwins()
{
	match_wins++;
}




//logic for choosing a target
int Player::aim()
{
	if (score > 81)// rushes 81 
	{
		return board.throw_treble(20, prob);
	}
	else if (score == 81) // aim for 57 to finish with D12 on next dart
	{
		return board.throw_treble(19, prob);
	}
	else if (score == 24)//D12 finish
	{
		return board.throw_double(12);
	}
	else if (score == 61) //aim for 21 to finish on D20 dart
	{
		return board.throw_treble(7, prob);
	}
	else if (score == 50) // bull finish
	{
		return board.throw_bulls(prob);
	}
	else if (score == 40) // D20 finish
	{
		return board.throw_double(20);
	}
	else if (score > 40 && score < 81)
	{
		// Calculate the remaining score after subtracting 40
		int remainingScore = score - 40;
		// Calculate the target double based on the remaining score
		int targetDouble = ceil(static_cast<double>(remainingScore) / 2.0);

		return board.throw_double(targetDouble);
	}
	// handling odd scores below 40 
	else if (score < 40 && (score % 2) != 0)
	{
		// single 1 to get to an even score for a double finish
		return board.throw_single(1);
	}
	// even scores below 40 get double finish
	else if ((score < 40 && (score % 2) == 0))
	{
		return board.throw_double(ceil(score / 2));
	}
	// default target 
	else
	{
		return board.throw_treble(20, prob);
	}

}

//checks to see if the last throw is valid
bool Player::check_finalthrow(int target)
{
	for (int i = 0; i < 21; ++i) {
		if (finalThrows[i] == target) {
			return true; // Value found in the array
		}
	}
	return false; // Value not found in the array
}


//logic for updating the score
void Player::throw_darts()
{
	roundtotal = 0;
	target = 0;

	target = aim();
	roundtotal += target;
	//outputs the target for debugging
	/*cout << target<< endl;*/
	score -= target;

}

// calls all the necessary function for a turn
void Player::turn()
{
	// runs 3 times for 3 darts thrown
	for (int i = 0; i < 3; ++i)
	{
		throw_darts();

		//checks if score value is valid
		if (score > 0)
		{
			//discounts the last set of throws if the score = 1 
			if (score == 1)
			{
				// adds back all points deducted from score and ends the turn
				score += roundtotal;
				roundtotal = 0;
				break;
			}
		}//in case score falls below 0;
		else if (score < 0)
		{
			// adds back all points deducted from score and ends the turn
			score += roundtotal;
			roundtotal = 0;
			break;
		}// checks that the final throw was valid by checking it against all valid final throws
		else if (score == 0)
		{
			//the last set of throws is discounted if the final throw is not valid
			if (check_finalthrow(target))
			{

				// sets winner to true for check and end turn
				winner = true;
				break;
			}
			else
			{
				// adds back all points deducted from score and ends the turn
				score += roundtotal;
				roundtotal = 0;
				break;
			}
		}
	}


}

