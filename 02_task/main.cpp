#include <iostream>
#include <fstream>


int main() {
    std::cout << "Development of a text file viewer" << std::endl;

    std::cout << "Enter file path:";
    std::string path;
    std::cin >> path;

    std::ifstream file;
    file.open(path, std::ios::binary);

    if (!file.is_open()) {
        std::cerr << "Something went wrong, check the file path" << std::endl;
        return 1;
    }

    char buffer[1024];
    while (!file.eof()) {
        file.read(buffer, 1023);
        long long b = file.gcount();
        buffer[b] = 0;

        std::cout << buffer;
    }

    file.close();

}