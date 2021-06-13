#pragma once
#include <optional>
#include <string>
namespace TypeConverter {
// convert from string to int
// assumes ascii string value
const int LOWESTASCIINUMBERVALUE = '0'; 

std::optional<int> ToInt(const char* charArrConvert);

std::optional<int> ToInt(const std::string_view stringToConvert);

char* ToCharPtr(int intToConvert);

// convert from int to string
std::string ToString(int intToConvert);
} // namespace TypeConverter