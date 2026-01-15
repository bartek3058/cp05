#include <iostream>
#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "AForm.hpp"

int main() {
    std::cout << "\n=== EX03: INTERN TEST ===\n" << std::endl;

    try {
        Intern  someRandomIntern;
        Bureaucrat boss("Boss", 1);
        
        // Wskaźnik na formularz (AForm), bo nie wiemy co dostaniemy
        AForm* rrf;

        // --- TEST 1: ROBOTOMY (Poprawny) ---
        std::cout << ">>> 1. Intern tries to create 'robotomy request' <<<" << std::endl;
        rrf = someRandomIntern.makeForm("robotomy request", "Bender");
        
        if (rrf) {
            std::cout << "-> Form created successfully! Address: " << rrf << std::endl;
            boss.signForm(*rrf);
            boss.executeForm(*rrf);
            
            // WAŻNE: Sprzątamy po stażyście
            delete rrf; 
        }

        // --- TEST 2: NIEZNANY FORMULARZ (Błędny) ---
        std::cout << "\n>>> 2. Intern tries to create 'coffee request' <<<" << std::endl;
        rrf = someRandomIntern.makeForm("coffee request", "Boss"); // Nie ma takiego

        if (rrf) {
            std::cout << "Wow, he made coffee!" << std::endl;
            delete rrf;
        } else {
            std::cout << "-> As expected, form was not created." << std::endl;
        }

        // --- TEST 3: SHRUBBERY (Poprawny) ---
        std::cout << "\n>>> 3. Intern tries to create 'shrubbery creation' <<<" << std::endl;
        rrf = someRandomIntern.makeForm("shrubbery creation", "Garden");
        
        if (rrf) {
            boss.signForm(*rrf);
            boss.executeForm(*rrf);
            delete rrf;
        }

    }
    catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return 0;
}