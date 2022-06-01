#include <thread>

#include "bot.h"
#include "read.h"
#include "game.h"

// IF YOU WANT: PARALLELIZE THE TESTING FRAMEWORK BY USING THREADS
int main(){
	Read re("../src/words.txt");
	std::vector<std::string> all_words = re.getWords();
	std::vector<int> results;
	int i = 0;
	for(; i < all_words.size(); ++i){
		// std::cout << "----------TARGET=" << all_words[i] << "----------\n";
		std::cout << i << "/" << all_words.size() << " COMPLETED\r";
		Game g("../src/words.txt", all_words[i]);
		size_t rounds = g.play();
		results.push_back(rounds);
		
	}
	std::cout << i << "/" << all_words.size() << " complete \n";
	long sum = 0;
	for(int num : results)
		sum += num;
	std::cout << "AVERAGE SCORE: " << 1.0 * sum / all_words.size();
}
