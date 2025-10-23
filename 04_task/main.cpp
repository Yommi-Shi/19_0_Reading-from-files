#include <iostream>
#include <fstream>
#include <string>


int main() {
    std::cout << "Development of a PNG file detector" << std::endl;

    std::ifstream is_png;

    std::cout << "Enter the file path:";
    std::string path;
    std::cin >> path;

    is_png.open(path, std::ios::binary);
    if (!is_png.is_open()) {
        std::cerr << "Something went wrong, check the path to the file";
        return 1;
    }

    char byte[5];
    is_png.read(byte, sizeof(byte));
    byte[4] = 0;

    is_png.close();

    if (static_cast<unsigned char>(byte[0]) == 137 && byte[1] == 'P' &&
        byte[2] == 'N' && byte[3] == 'G' && path.ends_with("png")) {
        std::cout << "The file is a PNG image" << std::endl;
    } else {
        std::cout << "The file is not a PNG image" << std::endl;
    }
}
