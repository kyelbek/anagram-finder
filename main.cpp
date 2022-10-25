#include <iostream>
#include "Algorithm/Dictionary.h"
#include "io.h"
#include "helpers/WordFuncs.h"

constexpr int inputWordLength{ 3 };

int main(int argc, char** argv) {
    auto argsBegin{argv};
    auto argsEnd {argv + argc};

    // We only show command line parameters with --help option
    if (io::getCommandLineOption(argsBegin, argsEnd, "--help")) {
        io::printUsage();
        return 0;
    }

    std::string dictPath{};
    Dictionary dict;

    // Get dictionary file path from command line argument or directly from user input
    auto dictSwitch {io::getCommandLineOptionParam(argsBegin, argsEnd, "--dict")};
    dictSwitch ? dictPath = *dictSwitch : io::getDictionaryPath(dictPath);
    dict.load(dictPath);

    // If we couldn't open the file, it was empty, or it didn't contain any words in required format.
    // tell user to try again
    while (!dict.ready()) {
        std::cout << "Couldn't load provided dictionary. Try again." << '\n';
        dict.load(io::getDictionaryPath(dictPath));
    }

    // Bind map to a reference to access its functions directly.
    // We can't modify the content since its getter got us a const ref.
    auto& dictWords{ dict.get() };

    // Get input from user. We check
    std::string userString{};
    while (true) {
        if (!io::getValidWordInput(userString)) continue;
        if (userString.length() != inputWordLength) continue;
        word::toLowerCase(userString);
        if (dictWords.find(userString) != dictWords.end()) break;   // If we found a match in our map, we break out.
        std::cout << "Word " << userString << " isn't part of provided dictionary. Try again." << '\n';
    }

    // TBC


    return 0;
}