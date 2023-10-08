#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <vector>
#include <string>


char getRandomSpecialChar() {
    const char specialChars[] = "!@#$%^&*()_+-=[]{}|;:,.<>?";
    int randomIndex = rand() % (sizeof(specialChars) - 1);
    return specialChars[randomIndex];
}

std::vector<std::string> readWordsFromFile(const std::string& filename) {
    std::vector<std::string> words;
    std::ifstream inputFile(filename);

    if (inputFile.is_open()) {
        std::string word;
        while (inputFile >> word) {
            words.push_back(word);
        }
        inputFile.close();
    } else {
        std::cerr << "Unable to open file: " << filename << std::endl;
    }

    return words;
}


std::string getRandomWord(const std::vector<std::string>& words) {
    int randomIndex = rand() % words.size();
    return words[randomIndex];
}

int main() {
   
    srand(static_cast<unsigned int>(time(nullptr)));

    
    std::vector<std::string> wordList = readWordsFromFile(" ");

    if (wordList.empty()) {
        std::cerr << "No words found in the wordlist file." << std::endl;
        return 1;
    }


    std::string password = getRandomWord(wordList) + getRandomWord(wordList);
        
    while (password.length() < 10) {
        password += getRandomWord(wordList);
    }

    for (int j = 0; j < 3; ++j) {
        password += std::to_string(rand() % 10);
    }

    password += getRandomSpecialChar();
    std::cout << password << std::endl;

    return 0;
}
