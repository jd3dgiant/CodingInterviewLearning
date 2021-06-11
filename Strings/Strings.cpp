// Strings.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "ReverseWords.h"
#include "TypeConverter.h"

void ReverseWordTester(
    const char* testPhraseChar_,
    std::string testPhraseStr_,
    std::string expectedReversePhraseStr_,
    char delimiter) {
  std::string reversedPhraseResult = ReverseWords(testPhraseStr_, delimiter);

  std::cout << "Reversed Phrase Result: " << reversedPhraseResult << "\n";
  std::cout << "Expected Result: " << expectedReversePhraseStr_ << "\n";

  if (reversedPhraseResult == expectedReversePhraseStr_) {
    // reverse successful
    std::cout << "Reversed Phrase Match"
              << "\n";
  } else {
    std::cout << "Reverse Phrase Did Not Match"
              << "\n";
  }

  // testing char wrapper function
  std::string reversedCharPhraseResult = ReverseWords(testPhraseChar_, delimiter);
  if (reversedCharPhraseResult == expectedReversePhraseStr_) {
    // reverse successful
    std::cout << "Reversed Char Phrase Match"
              << "\n";
  } else {
    std::cout << "Reverse Char Phrase Did Not Match"
              << "\n";
  }
}

void reverseWordMainCall() {
  const char* testPhraseChar1 = "Do or do not, there is no try.";
  std::string testPhraseStr1 = testPhraseChar1;
  std::string expectedReversePhraseStr1 = "try. no is there not, do or Do";
  const char delimiter1 = ' ';
  ReverseWordTester(testPhraseChar1, testPhraseStr1, expectedReversePhraseStr1, delimiter1);

  std::cout << "\n";

  const char* testPhraseChar2 = "Testing,comma,delimiter,splitting.";
  std::string testPhraseStr2 = testPhraseChar2;
  std::string expectedReversePhraseStr2 = "splitting.,delimiter,comma,Testing,";
  const char delimiter2 = ',';

  ReverseWordTester(testPhraseChar2, testPhraseStr2, expectedReversePhraseStr2, delimiter2);
}

void convertToIntTest(std::string_view testStr) {
  auto convertedInt = TypeConverter::ToInt(testStr);

  if (convertedInt) {
    std::cout << convertedInt.value() << '\n';
  } else {
    std::cout << "convertedInt conversion failed to int." << '\n';
  }
}

void convertToStrTest(int testInt) {
  std::string convertedStr = TypeConverter::ToString(testInt);

  std::cout << convertedStr << '\n';
}

// convert string to int and int to string tester
void convertStringAndIntTesterMainCall() {
  convertToIntTest("254"); // should print 254
  convertToIntTest("-6791"); // should print -6791
  convertToIntTest("0012"); // should print 12
  convertToIntTest("1b33"); // should print convertedInt conversion failed to int.

  convertToStrTest(45);
  convertToStrTest(-20);
  convertToStrTest(5000001);
  convertToStrTest(0);
}

int main() {
  // reverseWordMainCall();

  convertStringAndIntTesterMainCall();
}
