#ifndef INVERTED_INDEX_HPP
#define INVERTED_INDEX_HPP

#include <string>
#include <unordered_map>
#include <vector>
#include <set>

class InvertedIndex {
public:
    void buildIndex(const std::string &filename);
    void writeIndex(const std::string &outputFilename) const;

private:
    std::unordered_map<std::string, std::vector<size_t>> index;
    std::set<std::string> stopwords = {
        "a", "an", "and", "the", "to", "for", "of", "in", "on", "at",
        "is", "are", "was", "were", "you", "your", "i", "it", "they",
        "this", "that", "be", "by", "as", "from", "with"
    };

    static std::string normalizeWord(const std::string &word);
    bool isStopWord(const std::string &word) const;
};

#endif