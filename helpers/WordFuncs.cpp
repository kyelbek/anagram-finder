#include <string>
#include <algorithm>

namespace word{
    bool isValid(std::string& string) {
        return std::all_of(string.begin(), string.end(),
                           [=](char ch) {
                               return std::isalpha(ch) && !std::isspace(ch);
                           });
    }

    void toLowerCase(std::string& string) {
        std::transform(string.begin(), string.end(), string.begin(), tolower);
    }

    void sortAlphabetically(std::string& string) {
        std::sort(string.begin(), string.end());    // Defaults to operator<, produces a,...,z
    }
}
