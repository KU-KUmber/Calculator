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

void printLinesToScreen(const std::vector<std::string>& lines) {
    std::cout << "File contents:" << std::endl;
    std::cout << "==============" << std::endl;
    
    for (size_t i = 0; i < lines.size(); ++i) {
        std::cout << i + 1 << ": " << lines[i] << std::endl;
    }
    
    std::cout << "==============" << std::endl;
    std::cout << "Total lines: " << lines.size() << std::endl;
}

void writeLinesToFile(const std::vector<std::string>& lines, const std::string& filename) {
    std::ofstream file(filename);
    
    if (!file.is_open()) {
        std::cerr << "Error: could not create file " << filename << std::endl;
        return;
    }
    
    for (const auto& line : lines) {
        file << line << std::endl;
    }
    
    file.close();
    std::cout << "Lines successfully written to file: " << filename << std::endl;

int main() {

    std::string inputFilename = "input.txt";
    
    std::vector<std::string> lines = readLinesFromFile(inputFilename);
    
    if (lines.empty()) {
        std::cout << "File is empty or does not exist." << std::endl;
        return 1;
    }
    
    printLinesToScreen(lines);
 
    std::string outputFilename = "output.txt";
    writeLinesToFile(lines, outputFilename);
    
	  return 0;
}