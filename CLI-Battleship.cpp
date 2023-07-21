#include <iostream>
#include <string>
#include <random>

int main() {
	
	int minnum{ 0 };
	int maxnum{ 1 };
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> distribution(minnum, maxnum);
	// array denoting where ships are located, 1 == ship; 0 == white space
	int ships[4][4];

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			ships[i][j] = distribution(gen);
		}
	}

	int count1 = 0;
	int count0 = 0;

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			int currentValue{ ships[i][j] };
			if (currentValue == 1) {
				count1++;
			}
			if (currentValue == 0) {
				count0++;
			}
		}
	}
	
	char playerUnidentified { 'o' }, playerHit { 'H' }, playerMiss { 'M' };
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
	// coordinate selection for guess
	int row, column;
	// while loop defining when the game ends
	while (hits < count1) {
		while (numberOfTurns > 0) {
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
		std::cout << "Choose a Row from 1 through 4\n";
		std::cin >> row;
		std::cout << "Choose a Column from 1 through 4\n";
		std::cin >> column;
		numberOfTurns++;
		//if loop defining what to do if player hits a ship
		if (ships[row - 1][column - 1] == 1) {
			hits++;
			std::cout << "Hit! " << (7 - hits) << " left!\n\n";
			ships[row - 1][column - 1] = 0;
			// defines that playerArray array will change and display other characters based on where the hit occurred in the ships array
			playerArray[row - 1][column - 1] = playerHit;
		}
		else {
			std::cout << "Miss!\n\n";
			// defines that playerArray array will change and display other characters based on where the miss occurred in the ships array
			playerArray[row - 1][column - 1] = playerMiss;
		}
	}
	std::cout << "Victory!\n";
	std::cout << "You won in" << numberOfTurns << "Turns!";
}