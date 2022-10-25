#include "Dictionary.h"
#include <algorithm>

#include "../helpers/WordFuncs.h"

Dictionary::Dictionary(std::string& path) {
    load(path);
    createWordMap();
}

Dictionary::~Dictionary() {
    unload();
}

void Dictionary::load(std::string &path) {
    if (m_loaded) return;

    m_file.open(path);
    if (m_file.is_open() && m_file.good()){
        createWordMap();
        if (!m_map.empty())
            m_loaded = true;
    }

    m_file.close();
}

void Dictionary::unload() {
    if (!m_loaded) return;

    if (m_file.is_open()) m_file.close();
    m_map.clear();

    m_loaded = false;
}

const Dictionary::DictionaryMap& Dictionary::get() const {
    return m_map;
}

bool Dictionary::ready() const {
    return m_loaded;
}

void Dictionary::createWordMap() {
    if (m_loaded) return;

    while (m_file) {
        std::string string{};
        std::getline(m_file, string);
        if (string.empty() || !word::isValid(string))
            continue;

        word::toLowerCase(string);
        auto sortedString{ string };
        word::sortAlphabetically(sortedString);

        m_map[string] = { sortedString };
    }
}