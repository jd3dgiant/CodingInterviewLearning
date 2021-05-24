// Strings.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "ReverseWords.h"


void ReverseWordTester(const char *testPhraseChar_, std::string testPhraseStr_, std::string expectedReversePhraseStr_, char delimiter) {
  std::string reversedPhraseResult = ReverseWords(testPhraseStr_, delimiter);

  std::cout << "Reversed Phrase Result: " << reversedPhraseResult << "\n";
  std::cout << "Expected Result: " << expectedReversePhraseStr_ << "\n";

  if (reversedPhraseResult == expectedReversePhraseStr_) {
    // reverse successful
    std::cout << "Reversed Phrase Match" << "\n";
  }
  else {
    std::cout << "Reverse Phrase Did Not Match" << "\n";
  }

  // testing char wrapper function
  std::string reversedCharPhraseResult = ReverseWords(testPhraseChar_, delimiter);
  if (reversedCharPhraseResult == expectedReversePhraseStr_) {
    // reverse successful
    std::cout << "Reversed Char Phrase Match" << "\n";
  }
  else {
    std::cout << "Reverse Char Phrase Did Not Match" << "\n";
  }
}

int main() {
  const char *testPhraseChar1 = "Do or do not, there is no try.";
  std::string testPhraseStr1 = testPhraseChar1;
  std::string expectedReversePhraseStr1 = "try. no is there not, do or Do";
  const char delimiter1 = ' ';
  ReverseWordTester(testPhraseChar1, testPhraseStr1, expectedReversePhraseStr1, delimiter1);

  std::cout << "\n";


  const char *testPhraseChar2 = "Testing,comma,delimiter,splitting.";
  std::string testPhraseStr2 = testPhraseChar2;
  std::string expectedReversePhraseStr2 = "splitting.,delimiter,comma,Testing,";
  const char delimiter2 = ',';

  ReverseWordTester(testPhraseChar2, testPhraseStr2, expectedReversePhraseStr2, delimiter2);

}

