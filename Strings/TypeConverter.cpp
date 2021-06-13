#include "TypeConverter.h"
#include <math.h>
///
/// Take a string_view and convert it to integar values
///

// char pointer implementation
std::optional<int> TypeConverter::ToInt(const char* charArrConvert) {
  size_t charLength = strlen(charArrConvert); // unsure how to check if null terminated, currently assumed
  if (charLength == 0) {
    return std::optional<int>(); // nothing to convert
  }

  bool isNegative = false;
  int convertIntVal = 0;
  int tensMultiplierCount = 1;

  for (int i = charLength - 1; i > -1; i--) {
    char pos = charArrConvert[i];
    if (i == 0) { // checking if negative value
      if (pos == '-') {
        isNegative = true;
        continue;
      }
    }
    int val = pos - TypeConverter::LOWESTASCIINUMBERVALUE;
    if (val >= 0 && val <= 9) {
      convertIntVal += val * tensMultiplierCount;
      tensMultiplierCount *= 10;
    }
    else {
      return std::optional<int>(); // not a number was found in string so cannot convert
    }
  }
  if (isNegative) {
    convertIntVal *= -1;
  }

  return std::optional<int>(convertIntVal);
}

std::optional<int> TypeConverter::ToInt(const std::string_view stringToConvert) {
  // go through string right to left and grab individual characters
  int strLength = stringToConvert.length();
  if (strLength == 0) {
    return std::optional<int>(); // nothing to convert
  }

  bool isNegative = false;
  int convertIntVal = 0;
  int tensMultiplierCount = 1;

  for (int i = strLength - 1; i > -1; i--) {
    char pos = stringToConvert.at(i);
    if (i == 0) { // checking if negative value
      if (pos == '-') {
        isNegative = true;
        continue;
      }
    }
    int val = pos - TypeConverter::LOWESTASCIINUMBERVALUE;
    if (val >= 0 && val <= 9) {
      convertIntVal += val * tensMultiplierCount;
      tensMultiplierCount *= 10;
    } else {
      return std::optional<int>(); // not a number was found in string so cannot convert
    }
  }
  if (isNegative) {
    convertIntVal *= -1;
  }

  return std::optional<int>(convertIntVal);
}

char* TypeConverter::ToCharPtr(int intToConvert) {
  // catching edge case if value to convert is 0 as the while loop later will auto pass and not count properly
  int digitLength = intToConvert == 0 ? 1 : 0;
  int intValue = std::abs(intToConvert);

  while (intValue != 0) {
    intValue /= 10;
    digitLength += 1;
  }

  bool negativeNumber = intToConvert < 0 ? true : false;
  int buffer = negativeNumber ? digitLength + 2 : digitLength + 1;
  char* convertedCharArr = (char*) malloc(buffer);

  if (negativeNumber) {
    convertedCharArr[0] = '-';
  }

  intValue = std::abs(intToConvert); // probably a way to not do this again
  int loopStart = negativeNumber ? 1 : 0;
  int loopEnd = negativeNumber ? digitLength : digitLength - 1;

  for (int i = loopStart; i < loopEnd; i++) {
    int singleDigit = intValue % 10;
    convertedCharArr[loopEnd - i + loopStart] = TypeConverter::LOWESTASCIINUMBERVALUE + singleDigit;
    intValue /= 10; // removing rightmost digit
  }

  convertedCharArr[loopStart] = TypeConverter::LOWESTASCIINUMBERVALUE + intValue;
  convertedCharArr[buffer - 1] = '\0';

  return convertedCharArr;
}

std::string TypeConverter::ToString(int intToConvert) {
  return std::string(ToCharPtr(intToConvert));
}
