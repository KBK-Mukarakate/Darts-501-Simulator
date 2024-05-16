#include "Player.h"
#include <iostream>
using namespace std;

//student no.2303295

// function protoype
void frequency_table(int freq_joe[8], int freq_sid[8], int games);

int main()
{
 // variables
    int Prob = 0;
    int matches = 0;
    int player = 0;
    int set_counter = 0;

    // stores data for frequncy table calculations
    int freq_joe[8] = { 0, 0, 0, 0, 0, 0, 0, 0 };
    int freq_sid[8] = { 0, 0, 0, 0, 0, 0, 0, 0 };

    // Player initilization
    cout << "What is the probability for joe to hit the bull." << endl;
    cin >> Prob;
    Player joe("Joe", Prob);

    cout << "What is the probabaility for sid to hit the bull." << endl;
    cin >> Prob;
    Player sid("Sid", Prob);

    // ask the user to give the simulation size 
    cout << "How many matches do you want to simulate? ";
    cin >> matches;

    // Choosing player 1
    cout << "Who is going to go first?" << endl
        << "1)Joe" << endl << "2)Sid" << endl;
    cin >> player;
    // clear console window for readability 
    system("CLS");

    // Main simulation loop/ No. of matches
    for (int c = 0; c < matches; c++)
    {
        // resets for next match 
        joe.match_reset();
        sid.match_reset();
        // loop for each set 
        while (joe.get_setwins() < 7 && sid.get_setwins() < 7) // Continue until either player wins 7 games
        {
            // Resets game wins and score for the next set 
            joe.set_reset();
            sid.set_reset();

            set_counter++;

            // Set the first player for this set based on the set_counter
            if (set_counter % 2 == 1) {
                // If set_counter is odd, player1 starts
                player = 1;
            }
            else {
                // If set_counter is even, player2 starts
                player = 2;
            }

            // loop for each game in a set
            while (joe.get_gamewins() < 3 && sid.get_gamewins() < 3 )
            {
                // Resets for the next game
                joe.game_reset();
                sid.game_reset();

                // loop for each round in a game
                while (joe.getscore() > 0 && sid.getscore() > 0)
                {
                    // turn loop
                    if (player == 1) {
                        // Joe goes first
                        joe.turn();
                        sid.turn();
                    }
                    else {
                        // Sid goes first
                        sid.turn();
                        joe.turn();
                    }
                }

                //check for winner 
                if (player == 1)
                {   // adds 1 game win to the winner                  
                    if (joe.win_check())
                    {
                       
                        joe.add_gamewins();
                    }
                    else if (sid.win_check())
                    {
                        
                        sid.add_gamewins();
                    }
                }
                else 
                {
                    if (sid.win_check())
                    {
                        sid.add_gamewins();
                    }
                    else if (joe.win_check())
                    {
                        joe.add_gamewins();
                    }
                }               
            }

            // Check if either player has reached 3 game wins and adds a set win for the winner
            if (joe.get_gamewins() == 3)
            {
                joe.add_setwins();
            }
            else if (sid.get_gamewins() == 3)
            {
                sid.add_setwins();
            }
        }

        // Check if either player has reached 7 set wins
        if (joe.get_setwins() == 7)
        {
            // Store Sid's score when Joe wins
            freq_sid[sid.get_setwins()] += 1;
            //stores match wins
            joe.add_matchwins();
        }
        else if (sid.get_setwins() == 7)
        {
            // Store Joe's score when Sid wins
            freq_joe[joe.get_setwins()] += 1;
            //stores match wins
            sid.add_matchwins();
        }
       
    }
    //sim info

    //match win split
    cout << "Joe won " << joe.get_matchwins() << " of the " << matches << " matches." << endl;
    cout << "Sid won " << sid.get_matchwins() << " of the " << matches << " matches." << endl;
    //frequency table output
    frequency_table(freq_joe, freq_sid, matches);
    system("Pause");
}
 // calculates the frequency of each potential game situation for joe and sid    
void frequency_table(int freq_joe[8], int freq_sid[8], int games)
{
    cout << "  Frequency Table" << endl;
    cout << "---------------------" << endl;
    cout << "Joe : Sid   Frequency" << endl;
    // Calculates frequency for Joe	
    for (int j = 7; j > 0; j--) {

        cout << " 7  :  " << j << "        " << ((float)freq_sid[j] / (float)games) * 100.000f << "%" << endl;
    }
    cout << endl;
    // Calculates frequency for Sid
    for (int k = 0; k < 8; k++) {

        cout << " " << k << "  :  7        " << ((float)freq_joe[k] / (float)games) * 100.000f << "%" << endl;
    }
    cout << "---------------------" << endl;
}


