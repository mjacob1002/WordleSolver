#include "filter.h"
#include <algorithm>

Filter::Filter(std::unordered_set<std::string>& wordbank, std::string& ans /*std::string& guess*/) : _wordbank(wordbank), _ans(ans)/*, _guess(guess)*/ {
	for(int i = 0; i < 5; ++i)
		if(_ans[i] == '_')
			_unknown_indices.insert(i);
}

void Filter::removeUnknownIndex(int index){
	_unknown_indices.erase(index);	
}

void Filter::filter(std::vector<char> not_contained, std::vector<char> in_word, std::vector<int> indices){
	std::vector<std::string> to_remove;
	for(std::string s : _wordbank){
		if(removeBadChars(s, not_contained) || unknownPosChar(s, in_word, indices) || checkHasKnownChars(s)) to_remove.push_back(s);	
	}
 	removeFromWordBank(to_remove);	
}


bool Filter::removeBadChars(std::string word, std::vector<char>& not_contained){
	for(int idx : _unknown_indices){
		if(find(not_contained.begin(), not_contained.end(), word[idx]) != not_contained.end()) return true;
	}
	return false;
}

bool Filter::unknownPosChar(std::string word, std::vector<char> in_word, std::vector<int> indices){
	for(int i = 0; i < in_word.size(); ++i){ // contains the letter in the wrong spot, return that it should be removed(true)
		if(word[indices[i]] == in_word[i]) return true;
	}
	// for each character that is contained in the answer, but not in the right spot, check the unknown indices and see if they contain the letter. if they don't return true for to be removed
	bool valid = false;
	for(int i = 0; i < indices.size(); ++i){
		valid = false; // at the start of every character that is checked, set valid to false
		for(int idx : _unknown_indices){
			if(word[idx] == in_word[i]){
				valid = true; // it does contain that letter, search through the rest of them
				break;
			}
		}
		if(!valid) return true;
	}
	return false;
	//return true && in_word.size() != 0; // gone through the word, and it didn't contain a character that was supposed to be in the word
}

bool Filter::checkHasKnownChars(std::string input){
	for(int i = 0; i < _ans.size(); ++i){
		if(_unknown_indices.count(i) == 1) continue;
		if(input[i] != _ans[i]) return true; // return true for filter from the wordbank
	}
	return false;
}

size_t Filter::countInUnknown(std::string s, char ch){
	int count = 0;
	for(int idx : _unknown_indices){
		if(s[idx] == ch) ++count;
	}
	return count;
}

void Filter::removeFromWordBank(std::vector<std::string> to_remove){
	for(std::string s : to_remove){
			_wordbank.erase(s);
		}
}

void Filter::filterByFrequency(char ch, int freq){
	std::vector<std::string> to_remove;
	for(std::string s : _wordbank){
		size_t count = countInUnknown(s, ch);
		if(count != freq) to_remove.push_back(s);
	}
	removeFromWordBank(to_remove);
}
