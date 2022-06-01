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
		std::cout << "IS BUILD STILL IN WORDBANK: " << b.count("slate") << std::endl;
		std::string guess = b.makeGuess();
		std::cout << "BOT SAYS: " << guess << "\n";
		std::string feedback;
		std::getline(std::cin, feedback);
		b.filter(guess, feedback);
	}
	std::cout << "PROGRAM EXIT\n";
}
