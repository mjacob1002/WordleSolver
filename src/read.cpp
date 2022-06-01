#include "read.h"

Read::Read(std::string filename){
	std::ifstream ifs;
	ifs.open(filename);
	if(!ifs.is_open()){
		std::cout << "EXITING PREMATURELY" << std::endl;
		return;
	}
	std::string word;
	while(getline(ifs, word)){
		_words.push_back(word);
		_set_of_words.insert(word);
	}
}


std::vector<std::string> Read::getWords(){
	return _words;
}

std::unordered_set<std::string> Read::getSetOfWords(){
	return _set_of_words;
}
