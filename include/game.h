#pragma once

#include <unordered_map>

#include "read.h"
#include "bot.h"



class Game{
	public:
		size_t play();
		Game(std::string filename, std::string ans);
		std::string evaluate(std::string);
	private:
		Bot b;
		std::string _ans;
		std::unordered_map<char, int> _freq;

};
