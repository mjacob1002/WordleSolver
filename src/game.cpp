#include "game.h"

Game::Game(std::string filename): b(Read(filename)) {
}

void Game::play(){
	for(int i = 0; i < 6; ++i){
		std::string guess = b.makeGuess();
		std::cout << "GUESS: " << guess << "\n";
		std::cout << "Feedback: ";
		std::string feedback;
		std::getline(std::cin, feedback);
		b.filter(guess, feedback);
	}
}
