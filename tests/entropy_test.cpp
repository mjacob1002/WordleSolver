#define CATCH_CONFIG_MAIN
#include <iostream>
#include "catch.hpp"
#include "entropy.h"


TEST_CASE("Small size to compute entropy"){
	std::unordered_set<std::string> valid_words = {"charm", "chair", "joist", "boils"};
	std::string guess = "charm";
	Entropy e(guess, valid_words);
	double entropy = e.getEntropy();
	e.printEntropyCount();
	std::cout << "ENTROPY: " << entropy << "\n";
	REQUIRE(entropy == 1.5);
	std::unordered_set<std::string> setter = {"soils", "boils", "louis"};
	Entropy e2("rumba", setter);
	std::cout << e2.getEntropy();
}
