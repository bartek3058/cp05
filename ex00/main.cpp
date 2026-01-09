#include <iostream>
#include "Bureaucrat.hpp"

int main() {
    std::cout << "--- TEST 1: Creating valid Bureaucrat ---" << std::endl;
    try {
        Bureaucrat bob("Bob", 2);
        std::cout << bob << std::endl;
        
        std::cout << "Incrementing Bob..." << std::endl;
        bob.incrementGrade(); // 2 -> 1
        std::cout << bob << std::endl;
    }
    catch (std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    std::cout << "\n--- TEST 2: Error handling (Grade 0) ---" << std::endl;
    try {
        Bureaucrat god("God", 0); // Błąd! Za wysoko.
    }
    catch (std::exception& e) {
        // Tu powinniśmy wylądować
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "\n--- TEST 3: Error handling (Decrement too much) ---" << std::endl;
    try {
        Bureaucrat intern("Intern", 150);
        std::cout << intern << std::endl;
        
        std::cout << "Decrementing Intern..." << std::endl;
        intern.decrementGrade(); // Powinno rzucić błąd (150 -> 151)
    }
    catch (std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}