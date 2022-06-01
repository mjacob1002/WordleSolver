#include "game.h"

int main(){
	Game g("../src/words.txt", "slaps");
	int rounds = g.play();
	std::cout << "NUM ROUNDS: " << rounds << std::endl;
}
