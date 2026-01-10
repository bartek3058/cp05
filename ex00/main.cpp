#include <iostream>
#include "Bureaucrat.hpp"

int main() {
    std::cout << "==========================================" << std::endl;
    std::cout << "       BUREAUCRAT EXCEPTION TESTS         " << std::endl;
    std::cout << "==========================================" << std::endl;

    // ------------------------------------------------------------------
    // TEST 1: Standard usage (Success scenario)
    // ------------------------------------------------------------------
    std::cout << "\n[TEST 1] Creating a valid Bureaucrat (Grade 50)" << std::endl;
    try {
        Bureaucrat bob("Bob", 50);
        std::cout << "Success: " << bob << std::endl;

        std::cout << "-> Upgrading Bob (Decrementing grade)..." << std::endl;
        bob.decrementGrade(); // 50 -> 49 (Higher rank)
        std::cout << "Success: " << bob << std::endl;
    }
    catch (std::exception &e) {
        // This block should NOT execute in this test
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    // ------------------------------------------------------------------
    // TEST 2: Instantiation with grade too high
    // ------------------------------------------------------------------
    std::cout << "\n[TEST 2] Creating Bureaucrat with Grade 0 (Too High)" << std::endl;
    try {
        Bureaucrat god("God", 0); // Should throw GradeTooHighException
        std::cout << "Error: This line should not be visible!" << std::endl;
    }
    catch (std::exception &e) {
        // We expect to land here
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    // ------------------------------------------------------------------
    // TEST 3: Instantiation with grade too low
    // ------------------------------------------------------------------
    std::cout << "\n[TEST 3] Creating Bureaucrat with Grade 151 (Too Low)" << std::endl;
    try {
        Bureaucrat intern("Intern", 151); // Should throw GradeTooLowException
        std::cout << "Error: This line should not be visible!" << std::endl;
    }
    catch (std::exception &e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    // ------------------------------------------------------------------
    // TEST 4: Boundary check - Incrementing causing error
    // ------------------------------------------------------------------
    std::cout << "\n[TEST 4] Boundary check: Incrementing Grade 1" << std::endl;
    try {
        Bureaucrat boss("Boss", 1);
        std::cout << "Created: " << boss << std::endl;
        
        std::cout << "-> Trying to increment Grade 1 (should fail)..." << std::endl;
        boss.incrementGrade(); // 1 -> 0 (Error!)
        std::cout << "Error: This line should not be visible!" << std::endl;
    }
    catch (std::exception &e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    // ------------------------------------------------------------------
    // TEST 5: Boundary check - Decrementing causing error
    // ------------------------------------------------------------------
    std::cout << "\n[TEST 5] Boundary check: Decrementing Grade 150" << std::endl;
    try {
        Bureaucrat lazy("Lazy", 150);
        std::cout << "Created: " << lazy << std::endl;

        std::cout << "-> Trying to decrement Grade 150 (should fail)..." << std::endl;
        lazy.decrementGrade(); // 150 -> 151 (Error!)
        std::cout << "Error: This line should not be visible!" << std::endl;
    }
    catch (std::exception &e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "\n==========================================" << std::endl;
    std::cout << "              END OF TESTS                " << std::endl;
    std::cout << "==========================================" << std::endl;

    return 0;
}