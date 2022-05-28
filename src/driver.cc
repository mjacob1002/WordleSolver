#include "read.h"

int main(){
	Read re("../src/words.txt");
	auto words = re.getWords();
	for(std::string word : words)
		std::cout << word << " " << std::endl;
}
