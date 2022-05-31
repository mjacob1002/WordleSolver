#pragma once

#include "read.h"
#include "bot.h"



class Game{
	public:
		void play();
		Game(std::string filename);
	private:
		Bot b;

};
