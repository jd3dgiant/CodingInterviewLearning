#pragma once
#include <optional>
#include <string>
namespace TypeConverter {
// convert from string to int
// assumes ascii string value
const int LOWESTASCIINUMBERVALUE = 48; // '0' character

std::optional<int> ToInt(std::string_view stringToConvert);

// convert from int to string
std::string ToString(int intToConvert);
} // namespace TypeConverter