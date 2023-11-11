#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <cstdlib>
#include <cstdio>

int main() {
    // CPPLINT SECTION
    system("clang-format -i main.cpp");
    system("cppcheck main.cpp");
    system("cpplint main.cpp");

    std::cout << "try to compile program" << std::endl;

    // Try to compile the program
    int compile_result = system("g++ main.cpp -o main.exe");

    if (compile_result == 0) {
        std::cout << "program build successfully" << std::endl;
    } else {
        std::cout << "compilation errors" << std::endl;
        return 1;
    }

    // TESTS SECTION

    // Function to check if a file exists
    auto fileExists = [](const std::string &filename) {
        std::ifstream file(filename.c_str());
        return file.good();
    };

    auto err = []() {
        std::cerr << "RESULT: Tests Failed" << std::endl;
        exit(1);
    };

    // Tests
    for (int i = 1; i < 100; i++) {
        std::string test_number = (i < 10) ? "0" + std::to_string(i) : std::to_string(i);
        std::string test_input = test_number + ".in";
        std::string test_output = test_number + ".out";
        std::string expected_output = test_number + ".exp";

        if (!fileExists(test_input)) {
            //std::cout << "File not exist" << std::endl;
            break;
        }

        std::string run_command  = "main.exe < " + test_input + " > " + test_output;
        int compile_result = system(run_command.c_str());

        std::string compare_command = "cmp -s " + test_output + " " + expected_output;
        int compare_result = system(compare_command.c_str());

        if (compare_result == 0) {
            std::cout << "Test " << test_number << " passed" << std::endl;
        } else {
            std::cout << "Test " << test_number << " failed" << std::endl;
            err();
        }
    }

    std::cout << "RESULT: All tests passed successfully" << std::endl;
    return 0;
}
