#pragma once
#ifndef IO_H
#define IO_H

#include <string>

namespace io {
    void printUsage();
    char** getCommandLineOption(char** begin, char** end, const std::string& option);
    char** getCommandLineOptionParam(char** begin, char** end, const std::string& option);
    std::string& getDictionaryPath(std::string& path);
    bool getValidWordInput(std::string& string);
}

#endif //IO_H
