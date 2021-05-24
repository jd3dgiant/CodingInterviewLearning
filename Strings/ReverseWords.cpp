#include "ReverseWords.h"
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
