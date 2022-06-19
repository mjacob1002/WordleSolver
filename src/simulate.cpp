#include <thread>
#include <algorithm>
#include <iostream>

#include "bot.h"
#include "read.h"
#include "game.h"

void f(std::string word, int idx, std::vector<int>& res){
		Game g("../src/words.txt", word); 
		size_t rounds = g.play();
		res[idx] = rounds;
		std::cout << idx << " IS DONE\n"; 
}

// IF YOU WANT: PARALLELIZE THE TESTING FRAMEWORK BY USING THREADS
int main(){
	Read re("../src/words.txt");
	std::vector<std::string> all_words = re.getWords();
	std::vector<int> results(all_words.size(), INT_MIN);
	size_t i = 0;
	std::vector<std::thread> _threads;
	
	for(; i < all_words.size(); i += 50){
		// std::cout << "----------TARGET=" << all_words[i] << "----------\n";
		for(int j = i; j < std::min(all_words.size(), i + 50); ++j){
			std::thread t1(&f, all_words[i], j, std::ref(results));	
			_threads.push_back(std::move(t1));
		}
		
		for(int j = i; j < std::min(all_words.size(), i + 50); ++j){
			_threads[j].join();
		}
	}
	long sum = 0;
	for(int num : results)
		sum += num;
	std::cout << "AVERAGE SCORE: " << 1.0 * sum / all_words.size();
}
