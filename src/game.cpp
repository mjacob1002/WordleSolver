#include "game.h"

Game::Game(std::string filename, std::string ans): b(Read(filename)), _ans(ans) {
	for(char ch : _ans){
		_freq[ch]++;		
	}
}

size_t Game::play(){
	int i = 0; // the number of rounds played
	for(; i  < 6 && !b.isFinished(); ++i){
		std::string guess = b.makeGuess();
		// std::cout << "GUESS: " << guess << std::endl;
		std::string feedback = evaluate(guess);
		// std::cout << "FEEDBACK: " << feedback << std::endl;
		b.filter(guess, feedback);
	}
	if(i <= 6 && b.isFinished()) // if guessed correctly, return the number of rounds it took
		return i;
	else
		return i + 1 + b.size(); // punishment for not getting it is adding the remaining words in the wordbank
}

std::string Game::evaluate(std::string guess){
	std::string res = "_____";
	auto freq = _freq;
	// put all the correct spots in firsti
	std::vector<int> unvisited;
	for(int i = 0; i < 5; ++i){
		if(guess[i] == _ans[i]){
			res[i] = guess[i];
			freq[guess[i]]--;
		} else {
			unvisited.push_back(i);
		}
	}
	for(int idx : unvisited){
		if(freq.count(guess[idx]) > 0 && freq[guess[idx]] > 0){
			freq[guess[idx]]--;
			res[idx] = '-';
		}
	}
	return res;
}
