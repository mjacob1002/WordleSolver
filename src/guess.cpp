#include "guess.h"
#include <iostream>

std::string bestGuess(std::unordered_set<std::string> guess_set, std::unordered_set<std::string> valid_words){
	std::string res = "";
	double max_entropy = INT_MIN;
	for(auto guess : guess_set){
		Entropy e(guess, valid_words);
		double entropy = e.getEntropy();
		// std::cout << "ENTROPY FOR " << guess << ": " << entropy << std::endl;
		if(entropy > max_entropy || (entropy == max_entropy && !valid_words.count(res) && valid_words.count(guess))){
			max_entropy = entropy;
			res = guess;
		}
	}
	return res;
}
