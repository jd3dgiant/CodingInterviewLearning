#include "ReverseWords.h"
// thoughts to improve
// Scan across the string backwards and track end index of word and the start index of word when finding the delimiter
// then scan back across that range and write to string buffer itself and then add delimiter. Repeat til start of 
// string is found and then write that back to the end of buffer without adding delimiter

// Books implementation
// have a reverse string function that takes in whole str and then start and end index of reversing range
// reverse everything
// parse this reverse string going forward and then call reverse function with the start and end index of the word
// Amend this word to string buffer

// brute force method
std::string ReverseWords(const std::string& wordsToReverse_, char delimiter) {
  unsigned wordsLength = wordsToReverse_.size();
  // checking if string is empty
  if (wordsLength == 0) {
    return wordsToReverse_;
  }

  std::vector<std::string> splitWords;
  std::string strBuilder;
  char charPos;

  // splitting wordsToReverse into separate strings by delimiter
  for (unsigned i = 0; i < wordsLength; i++) {
    charPos = wordsToReverse_.at(i);
    if (charPos == delimiter) {
      splitWords.push_back(strBuilder);
      strBuilder.clear();
    }
    else {
      strBuilder += charPos;
    }
  }

  // catching end of string value
  if (strBuilder != "") {
    splitWords.push_back(strBuilder);
  }

  // if nothing was split, return original string
  int splitWordsSize = splitWords.size();
  if (splitWordsSize == 0) {
    return wordsToReverse_;
  }

  // reporposing builder string for making new return string
  strBuilder.clear();
  strBuilder.reserve(wordsLength);

  // cannot used unsigned here as it wraps to max unsigned int value
  for (int i = splitWordsSize - 1; i >= 1; i--) {
    strBuilder += splitWords[i] + delimiter;
  }
  // cannot have final word have delimiter added after it so adding it at the very end
  strBuilder += splitWords[0];
  return strBuilder;
}

std::string ReverseWords(const char* wordsToReverse_, char delimiter) {
  if (wordsToReverse_ != nullptr) {
    std::string stringWordsToReverse;
    stringWordsToReverse = wordsToReverse_;
    return ReverseWords(stringWordsToReverse, delimiter);
  } else {
    return nullptr;
  }
}
