#include "read.h"
#include "bot.h"
#include "game.h"
int main(){
	Read re("../src/words.txt");
	Bot b(re);
	std::cout << b.size() << std::endl;

	for(int i = 0; i < 6 && !b.isFinished(); ++i)
	{
		std::cout << "WORDBANK SIZE: " << b.size() << std::endl;
		size_t contains_boil = b.count("diner");
		std::cout << "CONTAINS diner: " << contains_boil << std::endl;
		std::string guess = b.makeGuess();
		std::cout << "DONE WITH GUESS " << i << "\n";
		std::cout << "BOT SAYS: " << guess << "\n";
		std::string feedback;
		std::getline(std::cin, feedback);
		b.filter(guess, feedback);
		std::cout << b.getAns() << std::endl;
	}
	std::cout << "PROGRAM EXIT\n";
}
