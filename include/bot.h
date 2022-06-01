#pragma once
#include <string>
#include <unordered_set>

#include "filter.h"
#include "read.h"

class Bot {
	private:
		// possible words that comply
		std::unordered_set<std::string> _word_bank;
		std::vector<std::string> guesses; // stores the guesses
		std::vector<std::string> results; // stores the results given back by wordle after 
		std::string _ans = "_____";
		Read _reader;
		bool _first_guess = true;
	public:
		Bot(Read);
		// after getting feedback, filter out the possible words that don't comply
		void filter(std::string guess, std::string res);
		std::string makeGuess();
		void printWordBank();
		size_t size(); // size of the word bank
		size_t count(std::string);
		bool isFinished();
};
