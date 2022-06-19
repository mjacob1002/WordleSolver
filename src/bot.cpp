#include "bot.h"
#include <algorithm>

Bot::Bot(Read reader): _reader(reader){
	_word_bank = reader.getSetOfWords();
	_guess_set = _word_bank;
	srand(time(NULL));	
}

size_t Bot::size(){return _word_bank.size();}

std::string Bot::makeGuess(){
	// TODO: currently on random guess model, need to add smarter, entropy-based stuff
	if(_first_guess){
		_first_guess = false;
		_guess_set.erase("tares");
		return "tares";
	}

/*
	int random = rand() % size();
	for(std::string word : _word_bank)
	{
		if(random == 0){
			_guess_set.erase(word);
			return word;
		}
		random--;
	}
	return "";
	*/
	// std::cout << "STARTING MAKE GUESS" << std::endl;
	std::string guess = bestGuess(_guess_set, _word_bank);
	// std::cout << "FINISHED MAKING GUESS\n";
	_guess_set.erase(guess);
	return guess;
}

void Bot::filter(std::string guess, std::string res) {
	// TODO
	std::vector<char> not_in_word;
	std::vector<char> chars_in_word; // keeps track of the actual character that is in the word but in wrong position
	std::vector<int> idx; // keeps track of the position that it isn't in
	for(size_t i = 0; i < res.size(); ++i){
		char c = res[i]; // the character in the feedback
		if(c != '_' && c != '-'){
			_ans[i] = c;
		}
		else if(c == '-') { // guessed char contained somwhere in the word, but not in the correct slot as guessed
			chars_in_word.push_back(guess[i]);
			idx.push_back(i);
		} else { // res[i] == '_'
			if(find(chars_in_word.begin(), chars_in_word.end(), guess[i]) == chars_in_word.end()){
				not_in_word.push_back(guess[i]);
				continue;
			} 
			int count = std::count(chars_in_word.begin(), chars_in_word.end(), guess[i]);
			Filter temp(_word_bank, _ans);
			temp.filterByFrequency(guess[i], count);
		}
	}
	Filter f(_word_bank, _ans);
	f.filter(not_in_word, chars_in_word, idx);
}

void Bot::printWordBank() {
	for(auto word : _word_bank){
		std::cout << word << "\n";
	}
}

size_t Bot::count(std::string input){
	return _word_bank.count(input);
}

bool Bot::isFinished(){
	return find(_ans.begin(), _ans.end(), '_') == _ans.end();
}

std::string Bot::getAns(){return _ans;}
