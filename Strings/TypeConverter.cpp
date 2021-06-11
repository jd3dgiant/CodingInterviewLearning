#include "TypeConverter.h"
#include <math.h>
///
/// Take a string_view and convert it to integar values
/// TODO: needs to handle negative numbers
///
std::optional<int> TypeConverter::ToInt(std::string_view stringToConvert) {
  // go through string right to left and grab individual characters
  int strLength = stringToConvert.length();
  if (strLength == 0) {
    return std::optional<int>(); // nothing to convert
  }

  bool isNegative = false;
  int convertIntVal = 0;
  int tensMultiplierCount = 1;
  // Derrick: why does this not work when i is size_t as the first test, strLength = 3 so i should
  // be 2 at begin?
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

std::string TypeConverter::ToString(int intToConvert) {

  std::string convertedStr = intToConvert < 0 ? "-" : "";

  // catching edge case if value to convert is 0 as the while loop later will auto pass and not count properly
  int digitLength = intToConvert == 0 ? 1 : 0;
  int intValue = std::abs(intToConvert);

  while (intValue != 0) {
    intValue /= 10;
    digitLength += 1;
  }

  intValue = std::abs(intToConvert); // probably a way to not do this again

  for (int i = digitLength - 1; i > 0; i--) {
    int decimalSlide = std::pow(10,i);
    int singleDigit = intValue / decimalSlide;
    convertedStr += TypeConverter::LOWESTASCIINUMBERVALUE + singleDigit;
    intValue -= singleDigit * decimalSlide; // removing leftmost digit
  }
  convertedStr += TypeConverter::LOWESTASCIINUMBERVALUE + intValue;

  return convertedStr;
}
