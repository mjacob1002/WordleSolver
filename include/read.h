#pragma once

#include <vector>
#include <string>
#include <fstream>
#include <iostream>

class Read{
	private:
		std::vector<std::string> _words;

	public:
		Read(std::string); // filename
		std::vector<std::string> getWords();
		

};
