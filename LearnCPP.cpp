#include <iostream>
#include <string>

int main() {
	// array denoting where ships are located, 1 == ship; 0 == white space
	int ships[4][4] = {
	{0, 1, 1, 1},
	{1, 0, 0, 0},
	{1, 0, 0, 0},
	{0, 1, 1, 0}
	};
	char playerUnidentified = 'o', playerHit = 'h', playerMiss = 'm';
	// array that will be shown to player
	char playerArray[4][4] = {
		{playerUnidentified, playerUnidentified, playerUnidentified, playerUnidentified},
		{playerUnidentified, playerUnidentified, playerUnidentified, playerUnidentified},
		{playerUnidentified, playerUnidentified, playerUnidentified, playerUnidentified},
		{playerUnidentified, playerUnidentified, playerUnidentified, playerUnidentified}
	};
	// define number of hits, will be raised whenever player input corresponds with location of a ship
	int hits = 0;
	// define number of turns, will be raised on every iteration of while loop.
	int numberOfTurns = 0;
	// coordinate selection for hit
	int row, column;
	// while loop defining when the game ends
	while (hits < 4) {
		while (numberOfTurns> 0) {
			std::cout << "____________________________________\n";
			break;
		}
		std::cout << "Battleship | Select your coordinates\n";
		
		//display array
		for (int i = 0; i < 4; i++ ) {
			for (int j = 0; j < 4; j++) {
				std::cout << playerArray[i][j] << " ";
			}
			std::cout << std::endl;
		}		
		std::cout << "Choose a row from 1 through 4\n";
		std::cin >> row;
		std::cout << "Choose a Column from 1 through 4\n";
		std::cin >> column;
		numberOfTurns++;
		//if loop defining what to do if player hits a ship
		if (ships[row+1][column+1] == 1) {
			hits++;
			std::cout << "Hit! " << (7 - hits) << " left!\n\n";
			ships[row+1][column+1] = 0;
			playerArray[row + 1][column + 1] = playerHit;
		}
		else {
			std::cout << "Miss!\n\n";
			playerArray[row + 1][column + 1] = playerMiss;
		}
	}
	std::cout << "Victory!\n";
	std::cout << "You won in" << numberOfTurns << "Turns!";
}