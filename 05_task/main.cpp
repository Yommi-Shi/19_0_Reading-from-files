#include <iostream>
#include <fstream>
#include <string>
#include <vector>


int main() {
    std::cout << "Implementation of the game \"What? Where? When?\"" << std::endl;

    const int TOTAL_SECTORS = 13;
    int expert_score = 0;
    int player_score = 0;
    std::ifstream questions;
    std::ifstream answers;
    questions.open("D:\\questions.txt");
    answers.open("D:\\answers.txt");

    std::vector<bool> is_sector_played(TOTAL_SECTORS, false);
    std::string question[TOTAL_SECTORS];
    std::string answer[TOTAL_SECTORS];
    int current_sector = 1;
    int new_sector = 0;

    int index = 0;

    if (!questions.is_open() || !answers.is_open()) {
        std::cerr << "Something went wrong check the file path";
        return 1;
    }

    while (!questions.eof() && !answers.eof()) {
        std::string str_q;
        std::string str_a;
        std::getline(questions, str_q);
        std::getline(answers, str_a);

        question[index] = str_q;
        answer[index] = str_a;
        index++;
    }

    questions.close();
    answers.close();

    while (expert_score != 6 && player_score != 6) {
        std::cout << "Spin the drum:";
        int offset;
        std::cin >> offset;

        new_sector = ((current_sector - 1 + offset) % 13) + 1;
        current_sector = new_sector;

        while (is_sector_played[current_sector - 1]) {
            current_sector = (current_sector % 13) + 1;
        }
        is_sector_played[current_sector - 1] = true;

        std::cout << "Question: " << question[current_sector - 1] << std::endl;

        std::cout << "Your answer:";
        std::string ans;
        std::cin >> ans;

        if (ans == answer[current_sector - 1]) {
            expert_score++;
        } else {
            player_score++;
        }
    }

    if (expert_score == 6) {
        std::cout << "Experts win!" << std::endl;
    } else {
        std::cout << "Players win!" << std::endl;
    }
}
