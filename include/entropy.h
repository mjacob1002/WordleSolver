#pragma once

#include <string>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <vector>
#include <math.h>

class Entropy {
	private:
		std::string  _guess; // the hypothetical answer
		std::unordered_set<std::string> _valid_answers;
		std::unordered_map<std::string, int> _entropy_counts;
		std::vector<std::string> colorings = {"G", "Y", "R"};
		double prob(std::string); // gets the probabilty of a state
	public:
		Entropy(std::string, std::unordered_set<std::string>);
		std::string classify(std::string); // pass in a possible guess, and return the coloring
		std::unordered_map<char, int> getFrequency(std::string);
		void makeEntropyCount();	
		double getEntropy();
		void printEntropyCount();
};
