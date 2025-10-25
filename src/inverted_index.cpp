#include "inverted_index.hpp"
#include <fstream>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <cctype>
#include <regex>

std::string InvertedIndex::normalizeWord(const std::string &word) {
    std::string w;
    for (char c : word) {
        if (std::isalnum(static_cast<unsigned char>(c)) || c == '-') {
            w += std::tolower(static_cast<unsigned char>(c));
        }
    }
    return w;
}

bool InvertedIndex::isStopWord(const std::string &word) const {
    return stopwords.find(word) != stopwords.end();
}

void InvertedIndex::buildIndex(const std::string &filename) {
    std::ifstream file(filename);
    if (!file) {
        throw std::runtime_error("Could not open file: " + filename);
    }

    std::string word;
    size_t position = 0;

    while (file >> word) {
        std::string cleaned = normalizeWord(word);
        if (!cleaned.empty() && !isStopWord(cleaned)) {
            index[cleaned].push_back(position);
        }
        ++position;
    }
}

void InvertedIndex::writeIndex(const std::string &outputFilename) const {
    std::ofstream out(outputFilename);
    if (!out) {
        throw std::runtime_error("Could not write to file: " + outputFilename);
    }

    std::vector<std::string> sortedWords;
    for (const auto &pair : index)
        sortedWords.push_back(pair.first);

    std::sort(sortedWords.begin(), sortedWords.end());

    for (const auto &word : sortedWords) {
        out << word << ": ";
        const auto &positions = index.at(word);
        for (size_t i = 0; i < positions.size(); ++i) {
            out << positions[i];
            if (i < positions.size() - 1)
                out << ", ";
        }
        out << "\n";
    }
}