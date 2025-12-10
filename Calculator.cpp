#include <iostream>
#include <fstream>
#include <vector>
#include <string>

std::vector<std::string> readLinesFromFile(const std::string& filename) {
    std::vector<std::string> lines;
    std::ifstream file(filename);

    if (!file.is_open()) {
        std::cerr << "Ошибка: не удалось открыть файл " << filename << std::endl;
        return lines;
    }

    std::string line;
    while (std::getline(file, line)) {
        lines.push_back(line);
    }

    file.close();
    return lines;
}

void printLinesToScreen() {

}

void writeLinesToFile() {

}


int main() {
    std::string inputFilename = "input.txt";

   
    std::vector<std::string> lines = readLinesFromFile(inputFilename);

    
	return 0;
}