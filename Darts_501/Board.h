#pragma once
using namespace std;
#include <iostream>
class Board
{
private:
	// dart board representation for functions
	int dartboard[2][21]= { {0,20,15,17,18,12,13,19,16,14,6,8,9,4,11,10,7,2,1,3,5},
			   {0,18,17,19,13,20,10,16,11,12,15,14,5,6,9,2,8,3,4,7,1} };

	

public:
	Board();
	~Board();

	// provided finctions with minor changes ( mostly just variables)
	int throw_bulls(int);
	int throw_treble(int, int);
	int throw_double(int);
	int throw_single(int) const;

	
};

