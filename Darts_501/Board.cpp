#include "Board.h"
using namespace std;
#include <iostream>



Board::Board()
{
}

Board::~Board()
{
}

int Board::throw_bulls(int prob)
{
	//  Throw for the bull with percent accuracy (20<p<85)
	int random = rand() % 100 + 1;

	if (random <= (prob - 20))
	{
		return 50;
	}
	else if (random <= 85)
	{
		return 25;
	}
	else
	{
		return rand() % 20 + 1;
	}
}

int Board::throw_treble(int target, int prob)
{
	//  return result of throwing for treble target with accuracy prob%  (o<90)
	// Board neighbours ignoring slot zero

	int r = rand() % 100;

	if (r < prob)
		return 3 * target;
	else if (r < 90)
		return target;
	else if (r < 93)
		return 3 * dartboard[0][target];
	else if (r < 96)
		return 3 * dartboard[1][target];
	else if (r < 98)
		return dartboard[0][target];
	else
		return dartboard[1][target];
}

int Board::throw_double(int target) 
{
	//  return result of throwing for double d with accuracy 80%
	// Board neighbours ignoring slot zero
	int r = rand() % 100;

	if (r < 80)
		return 2 *target;
	else if (r < 85)
		return 0;
	else if (r < 90)
		return target;
	else if (r < 93)
		return 2 * dartboard[0][target];
	else if (r < 96)
		return 2 * dartboard[1][target];
	else if (r < 98)
		return dartboard[0][target];
	else
		return dartboard[1][target];
}

int Board::throw_single(int target) const
{
	//  return result of throwing for single d with accuracy 88% (or 80% for the outer)

		// Board neighbours ignoring slot zero
	int random = rand() % 100;

	if (target == 25) {		// outer  80%
		if (random < 80)
			return 25;
		else if (random < 90)
			return 50;
		else
			return 1 + rand() % 20;
	}
	else			// 1 to 20 single
		if (random < 88)
			return target;
		else if (random < 92)
			return dartboard[0][target];
		else if (random < 96)
			return dartboard[1][target];
		else if (random < 98)
			return 3 * target;
		else
			return 2 * target;
}
