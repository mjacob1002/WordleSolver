#pragma once

#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <unordered_set>


class Read{
	private:
		std::vector<std::string> _words;
		std::unordered_set<std::string> _set_of_words;
	public:
		Read(std::string); // filename
		std::vector<std::string> getWords();
		std::unordered_set<std::string> getSetOfWords();
		

};
