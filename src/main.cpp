#include "inverted_index.hpp"
#include <iostream>
#include <chrono>

int main() {
    try {
        InvertedIndex index;

        auto start = std::chrono::high_resolution_clock::now();
        index.buildIndex("data/input.txt");
        auto mid = std::chrono::high_resolution_clock::now();
        index.writeIndex("data/output_index.txt");
        auto end = std::chrono::high_resolution_clock::now();

        std::chrono::duration<double> read_time = mid - start;
        std::chrono::duration<double> write_time = end - mid;

        std::cout << " Index built and saved successfully!\n";
        std::cout << "⏱ Build time: " << read_time.count() << " seconds\n";
        std::cout << "💾 Write time: " << write_time.count() << " seconds\n";
    } 
    catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}