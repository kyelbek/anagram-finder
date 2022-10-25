#include "io.h"

#include <iostream>
#include <algorithm>
#include "helpers/WordFuncs.h"

namespace io {
    void printUsage() {
        std::cout << R"(Usage: anagram-solver [OPTIONS]

Available options:
--help          - Displays this help information.
--dict [PATH]   - Loads dictionary file from the provided path.)";
    }

    char** getCommandLineOption(char **begin, char **end, const std::string &option) {
        auto it{std::find(begin, end, option)};
        return (it != end) ? it : nullptr;
    }

    char** getCommandLineOptionParam(char **begin, char **end, const std::string &option) {
        auto it{getCommandLineOption(begin, end, option)};
        if (!it) return nullptr;
        return (it + 1 != end) ? it + 1 : nullptr;
    }

    std::string& getDictionaryPath(std::string& path) {
        std::cout << "Enter path to dictionary file: " << '\n';
        std::cin >> path;
        return path;
    }

    bool getValidWordInput(std::string& string) {
        std::cout << "Enter a 3-letter word to find anagram chain for: " << '\n';
        std::cin >> string;

        return word::isValid(string);
    }
}