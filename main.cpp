#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include <iomanip>
#include <ctime>
#include <sstream>
#include <filesystem>

std::string get_current_timestamp() {
    auto now = std::chrono::system_clock::now();
    auto now_c = std::chrono::system_clock::to_time_t(now);
    std::stringstream ss;
    ss << std::put_time(std::localtime(&now_c), "%Y-%m-%d_%H-%M-%S");
    return ss.str();
}

int main(int argc, char* argv[]) {
    // Create output filename with timestamp
    std::string filename = "param_dump_" + get_current_timestamp() + ".txt";
    
    // Get absolute path
    std::filesystem::path absolutePath = std::filesystem::absolute(filename);
    
    // Open file for writing
    std::ofstream outFile(filename);
    if (!outFile.is_open()) {
        std::cerr << "Error: Could not open file at absolute path: " << absolutePath << std::endl;
        return 1;
    }

    // Write header
    std::string header = "Parameter Dump - " + get_current_timestamp() + "\n";
    std::string paramCount = "Total parameters: " + std::to_string(argc) + "\n\n";
    std::string paramHeader = "Parameters:\n-----------\n";
    
    outFile << header << paramCount << paramHeader;
    std::cerr << header << paramCount << paramHeader;

    // Write each parameter
    for (int i = 0; i < argc; ++i) {
        std::string paramLine = "[" + std::to_string(i) + "] " + argv[i] + "\n";
        outFile << paramLine;
        std::cerr << paramLine;
    }

    outFile.close();
    std::cout << "Parameters have been dumped to: " << filename << std::endl;
    return 0;
} 