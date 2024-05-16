# Darts-501-Simulator
Year1, Semester 2 CMP102 Darts_501 project

This project simulates a game of Darts 501 between two players, Joe and Sid, using C++ programming. The simulation allows users to input the probability of each player hitting the bullseye and then proceeds to simulate a series of matches based on these probabilities.

## Files Included

- **Darts_501.cpp**: The main program file containing the simulation logic and user interface.
- **Player.h**: Header file defining the `Player` class, which represents a player in the game.
- **Player.cpp**: Source file implementing the member functions of the `Player` class.
- **Board.h**: Header file defining the `Board` class, which represents the dartboard and provides functions for throwing darts.
- **Board.cpp**: Source file implementing the member functions of the `Board` class.

## How to Use

1. **Compile and Run**: Compile the program using a C++ compiler and run the executable. Ensure all files are in the same directory.
   
2. **Input Probabilities**: Enter the probabilities for Joe and Sid to hit the bullseye when prompted.

3. **Simulation Setup**: Specify the number of matches to simulate and choose which player goes first.

4. **Simulation Execution**: The program will simulate the specified number of matches, displaying the results at the end.

## Player Class

- The `Player` class represents a player in the game.
- It stores information such as the player's name, probabilities, set wins, game wins, match wins, and current score.
- The class provides methods for resetting game, set, and match data, checking for a win, aiming for targets, and throwing darts.

## Board Class

- The `Board` class represents the dartboard and provides functions for throwing darts.
- It includes methods for throwing darts at various targets (single, double, treble, and bullseye) with different probabilities.

## Simulation Logic

- The main program file (`Darts_501.cpp`) orchestrates the simulation, including match setup, turn-based gameplay, and result analysis.
- The simulation proceeds through a series of matches, each consisting of multiple sets and games, until a player reaches the winning conditions.

## Additional Notes

- The simulation allows users to customize the probabilities for each player, providing flexibility for experimentation and analysis.
- Users can modify the simulation parameters and logic to explore different scenarios or enhance the simulation with additional features.
- The output includes match results, frequency tables, and simulation information for analysis and interpretation.

