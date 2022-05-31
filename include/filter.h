#pragma once

#include <string>
#include <unordered_set>
#include <vector>


class Filter{
	private:
		std::unordered_set<std::string>& _wordbank;
		const std::string& _ans;
		std::unordered_set<int> _unknown_indices;
	public:
		Filter(std::unordered_set<std::string>&, std::string&);
		// passing in the chars not in it, the chars in it, and their corresponding indices they aren't located at
		void filter(std::vector<char>, std::vector<char>, std::vector<int>);
		void removeUnknownIndex(int idx);
		bool removeBadChars(std::string, std::vector<char>&);
		bool unknownPosChar(std::string word, std::vector<char>, std::vector<int>);
		bool checkHasKnownChars(std::string);
		void filterByFrequency(char, int); // used when there are repeats, for example double ss, and one s is yellow while another is grey. Filter out all of the words that have more than 1 s
		size_t countInUnknown(std::string, char);
		void removeFromWordBank(std::vector<std::string>);
};
