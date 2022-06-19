#include "entropy.h"
#include <iostream>
Entropy::Entropy(std::string guess, std::unordered_set<std::string> valid_answers) : _guess(guess), _valid_answers(valid_answers) {
	for(std::string a : colorings){
		for(std::string b : colorings){
			for(std::string c : colorings){
				for(std::string d : colorings){
					for(std::string e : colorings) {
						std::string coloring = a + b + c + d + e;
						_entropy_counts[coloring] = 0;
					}
				}
			}
		}
	}
}

std::string Entropy::classify(std::string hypo_ans){
	std::string res = "_____";
	auto freq_ans = getFrequency(hypo_ans);
	std::unordered_set<int> unknown_indices = {0,1,2,3,4};
	for(int i = 0; i < 5; ++i){
		if(_guess[i] == hypo_ans[i]) 
		{	
			res[i] = 'G';
			freq_ans[_guess[i]]--;
			unknown_indices.erase(i);
		}	
	}
	for(int idx : unknown_indices){
		if(freq_ans.count(_guess[idx]) == 0 || freq_ans[_guess[idx]] <= 0) res[idx] = 'R';
		else{
			freq_ans[_guess[idx]]--;
			res[idx] = 'Y';
		}
	}
	return res;
}


std::unordered_map<char, int> Entropy::getFrequency(std::string s){
	std::unordered_map<char,int> freq;
	for(char ch : s){
		freq[ch]++;
	}
	return freq;
}

void Entropy::makeEntropyCount(){
	for(std::string word : _valid_answers){
		auto classification = classify(word);
		_entropy_counts[classification]++;
	}
}

double Entropy::prob(std::string state){
	return 1.0 * _entropy_counts[state] / _valid_answers.size();
}

double Entropy::getEntropy(){
	double total_entropy = 0;
	makeEntropyCount();
	for(auto p: _entropy_counts){
		std::string state = p.first;
		double p_x  = prob(state);
		if(p_x == 0.0) continue;
		double entropy = -1.0 * p_x * std::log2(p_x);
		// std::cout << "ENTROPY FOR STATE " << state << ": " << entropy << " with probability " << p_x << "\n";
		total_entropy += entropy;
	}
	return total_entropy;
}

void Entropy::printEntropyCount(){
	for(auto p : _entropy_counts){
		if(p.second == 0) continue;
		// std::cout << "(" << p.first << "," << p.second << "), ";
	}
}
