#pragma once

#include <string>
#include <vector>

/// <summary>
/// Question:
/// Write a function that reverses the order of the words in a string. For example, your function
/// should transform the string "Do or do not, there is no try." to "try. no is there not, do or
/// Do". Assume that all words are space delimited and treat puctuation the same as letters.
/// </summary>

// naive approach is to use a string splitter to get a list of individual strings and then loop
// backwards to reverse them
std::string ReverseWords(const std::string& wordsToReverse_, char delimiter);

// adding wrapper to support char ptr type
std::string ReverseWords(const char* wordsToReverse_, char delimiter);
