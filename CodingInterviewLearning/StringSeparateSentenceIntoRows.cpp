//Given a string s, return the longest palindromic substring in s.
//
//
//
//Example 1:
//
//Input: s = "babad"
//  Output : "bab"
//  Note : "aba" is also a valid answer.
//  Example 2 :
//
//  Input : s = "cbbd"
//  Output : "bb"
//  Example 3 :
//
//  Input : s = "a"
//  Output : "a"
//  Example 4 :
//
//  Input : s = "ac"
//  Output : "a"

//Constraints:
//
//1 <= s.length <= 1000
//s consist of only digits and English letters.

class Solution {
public:

  std::optional<string> findPalindrome(std::string_view s, uint16_t startIndex, uint16_t endIndex) {
    uint16_t startSubStrIndex = 0;
    uint16_t endSubStrIndex = endIndex - startIndex;
    char substring[endSubStrIndex + 2];
    substring[endSubStrIndex + 1] = '\0';

    while (startIndex <= endIndex) {
      if (s[startIndex] != s[endIndex]) {
        return {};
      }
      substring[startSubStrIndex++] = s[startIndex++];
      substring[endSubStrIndex--] = s[endIndex--];
    }
    return std::string(substring);
  }

  string longestPalindrome(string s) {
    // search through entire list and find pairs 
    std::unordered_map<char, std::vector<int>> map;
    uint16_t longestLength = 1; // has to be a at least one letter to be used as pandrome
    std::string r_string{ s[0] };

    for (uint16_t i = 0; i < s.length(); ++i) {
      if (map.find(s[i]) != map.end()) {
        map[s[i]].emplace_back(i);
      }
      else {
        map[s[i]] = vector<int>{ i };
      }
    }

    for (const auto &[key, value] : map) {
      uint16_t startIndex = 0;
      uint16_t endIndex = value.size() - 1;
      vector<int> newV{ value[startIndex], value[endIndex] };
      if (value.size() > 2) {

        while (startIndex < endIndex) {
          if (value[startIndex] + 1 != value[startIndex + 1] ) {
            newV.emplace_back(value[++startIndex]);
          }
          if (value[endIndex] - 1 != value[endIndex - 1]) {
            newV.emplace_back(value[--endIndex]);
          }
        }
      }
    }

    // loop through found letters/numbers only if they have more than one count
    for (const auto &[key, value] : map) {
      if (value.size() > 1) {
        for (uint16_t i = 0; i < value.size() - 1; i++) {
          for (uint16_t j = value.size() - 1; j > i; j--) {
            auto foundPal = findPalindrome(s, value[i], value[j]);
            if (foundPal) {
              if (foundPal.value().length() > longestLength) {
                r_string = foundPal.value(); // bad copy
                longestLength = r_string.length();
                break;
              }

            }
          }
        }
      }
    }
    return r_string;
  }
};