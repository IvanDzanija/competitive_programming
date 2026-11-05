#include <cstring>
#include <iostream>
#include <map>
#include <set>
#include <utility>

using ll = int64_t;

std::set<std::string> cache;
void generate(std::string word, ll level) {
    ll pivot = level;
    for (ll i = level; i < word.length(); ++i) {
        std::string newWord = word;
        newWord.at(pivot) = word.at(i);
        newWord.at(i) = word.at(pivot);
        if (cache.count(newWord) == 0) {
            cache.insert(newWord);
        }
        generate(newWord, level + 1);
    }
}

int main(void) {
    std::string input;
    std::cin >> input;

    std::map<char, int> charCount;
    for (char c : input) {
        if (charCount.count(c)) {
            ++charCount.at(c);
        } else {
            charCount[c] = 1;
        }
    }

    ll numerator = 1;
    for (ll i = 1; i < input.length() + 1; ++i) {
        numerator *= i;
    }
    ll denominator = 1;
    for (std::pair<char, int> item : charCount) {
        for (ll i = 1; i < item.second + 1; ++i) {
            denominator *= i;
        }
    }
    std::cout << numerator / denominator << std::endl;
    generate(input, 0);
    for (std::string word : cache) {
        std::cout << word << std::endl;
    }

    return 0;
}
