#pragma once
#include <string>
#include <unordered_set>
#include <limits.h>

#include "entropy.h"

std::string bestGuess(std::unordered_set<std::string> guess_set, std::unordered_set<std::string> valid_words);
