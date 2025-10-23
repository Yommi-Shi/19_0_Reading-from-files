#include <iostream>
#include <fstream>
#include <string>


int main() {
    std::cout << "Development of a program for searching words in a file" << std::endl;

    std::ifstream words;
    words.open("D:\\words.txt");

    std::string word_find;
    std::cin >> word_find;

    int count = 0;
    while (!words.eof()) {
        std::string word;
        words >> word;
        if (word_find == word) {
            count++;
        }
    }

    std::cout << "Number of word repetitions: " << count;
    words.close();
}