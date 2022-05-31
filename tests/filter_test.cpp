#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "filter.h"


 

TEST_CASE("Voila should delete walls"){
	std::string ans = "___l_";
	std::unordered_set<std::string> se = {"walls"};
	std::vector<char> not_allowed = {'v', 'i'};
	std::vector<char> contained = {'o', 'a'};
	std::vector<int> idx = {1, 4};
	Filter f(se, ans);
	f.filter(not_allowed, contained, idx);
	REQUIRE(se.size() == 0);
}

 TEST_CASE("yer"){
 	std::unordered_set<std::string> words;
 	words.insert("catch");
 	words.insert("cbtcd");
 	words.insert("catcs");
 	SECTION("Simple Test: only in_word array"){
 		std::string answer = "c_tc_";
		Filter f(words, answer); // create a filter
		std::vector<char> not_contained; // keep it empty
		std::vector<char> in_word = {'h'};
		std::vector<int> index = {1};
		f.filter(not_contained, in_word, index);
			REQUIRE(words.size() == 1);
	}
	std::string w = "_zame";
	for(char ch = 'a'; ch != 'z'; ++ch){
		w[0] = ch;
		words.insert(w);
	}
	words.insert("hzela");
	SECTION("Filter with letters to not include and wrong position"){
		REQUIRE(words.size() == 29);
		std::vector<char> not_contained = {'b', 'c', 'd', 'f'}; // answer doesn't contain these words
		std::vector<char> wrong_spot = {'h'};
		std::vector<int> idx = {4};
		std::string a = "_zam_";
		Filter f2(words, a);
		f2.filter(not_contained, wrong_spot, idx);
		REQUIRE(words.size() == 1); // hzame and hzela are only ones that must remain, as the only unknown indices are 0 and 4, so that is all they check
	}
	SECTION("Filter out words with a only i.e only one letter. Also had empty not_right_spot"){
		std::vector<char> remove = {'a'};
		std::string ans = "_zam_";
		Filter f3(words, ans);
		std::vector<char> not_right_spot;
		std::vector<int> idx;
		f3.filter(remove, not_right_spot, idx);
		REQUIRE(words.size() == 24);
	}

	SECTION("All parameters are empty. Make sure the set doesn't change"){
		std::string ans = "_____";
		Filter f3(words, ans);
		size_t starting_words = words.size();
		f3.filter(std::vector<char>(), std::vector<char>(), std::vector<int>());
		REQUIRE(words.size() == starting_words);
	}
}
