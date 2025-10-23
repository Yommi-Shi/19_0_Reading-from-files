#include <iostream>
#include <fstream>
#include <sstream>
#include <string>


int main() {
    std::cout << "Implementation of the statement reading program" << std::endl;

    std::ifstream file;
    file.open("D:\\statement.txt");

    if (!file.is_open()) {
        std::cerr << "Something went wrong, check the file path" << std::endl;
        return 1;
    }

    int total_payments = 0;
    std::string person_max_payment;
    int max_payment = 0;

    while (!file.eof()) {
        std::string str;
        std::getline(file, str);
        std::stringstream input_string(str);
        std::string first_name;
        std::string last_name;
        int amount_payments;
        std::string data;

        input_string >> first_name >> last_name >> amount_payments >> data;

        total_payments += amount_payments;
        if (amount_payments > max_payment) {
            max_payment = amount_payments;
            person_max_payment = "";
            person_max_payment.append(first_name).append(" ").append(last_name);
        }
    }

    file.close();

    std::cout << "Total amount of payments: " << total_payments << std::endl;
    std::cout << "Largest recipient of funds: " << person_max_payment;
}
