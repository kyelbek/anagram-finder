#pragma once
#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <fstream>
#include <map>

class Dictionary {
    using DictionaryMap = std::map<std::string, std::string>;
public:
    Dictionary() = default;
    Dictionary(const Dictionary&) = delete;

    explicit Dictionary(std::string& path);
    ~Dictionary();

    const DictionaryMap& get() const;
    void load(std::string& path);
    void unload();

    bool ready() const;

private:
    void createWordMap();

private:
    std::ifstream m_file{};
    DictionaryMap m_map{};
    bool m_loaded{};
};



#endif //DICTIONARY_H
