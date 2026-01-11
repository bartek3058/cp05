#include <iostream>
#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time()

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
    // 1. Seed the random number generator (essential for Robotomy randomness)
    std::srand(std::time(NULL));

    std::cout << "\n=== WELCOME TO THE BUREAUCRACY HELL (EX02) ===\n" << std::endl;

    try {
        // --- CREATING BUREAUCRATS ---
        // Boss (Grade 1) - Can do everything
        Bureaucrat boss("Zaphod Beeblebrox", 1);
        
        // Manager (Grade 45) - Can handle Robotomy and Shrubbery, but not Presidential
        Bureaucrat manager("Middle Manager", 45);
        
        // Intern (Grade 150) - Can't do anything meaningful
        Bureaucrat intern("Poor Intern", 150);

        std::cout << "--- STAFF CREATED ---" << std::endl;
        std::cout << boss << std::endl;
        std::cout << manager << std::endl;
        std::cout << intern << std::endl;
        std::cout << "---------------------\n" << std::endl;


        // --- TEST 1: SHRUBBERY CREATION FORM (Req: Sign 145, Exec 137) ---
        std::cout << ">>> TEST 1: SHRUBBERY CREATION FORM <<<" << std::endl;
        
        ShrubberyCreationForm shrub("Home");
        
        // Scenario A: Intern (150) tries to sign (Grade too low - should fail)
        std::cout << "[1] Intern tries to sign Shrubbery:" << std::endl;
        intern.signForm(shrub);

        // Scenario B: Intern (150) tries to execute (Grade too low - should fail)
        std::cout << "[2] Intern tries to execute Shrubbery:" << std::endl;
        intern.executeForm(shrub); 

        // Scenario C: Manager (45) signs and executes (Success)
        std::cout << "[3] Manager signs Shrubbery:" << std::endl;
        manager.signForm(shrub);
        
        std::cout << "[4] Manager executes Shrubbery:" << std::endl;
        manager.executeForm(shrub); 
        // At this point, check your project folder for 'Home_shrubbery' file!
        std::cout << "(Check your directory for 'Home_shrubbery' file!)" << std::endl;


        // --- TEST 2: ROBOTOMY REQUEST FORM (Req: Sign 72, Exec 45) ---
        std::cout << "\n>>> TEST 2: ROBOTOMY REQUEST FORM <<<" << std::endl;
        
        RobotomyRequestForm robot("Bender");

        // Scenario A: Attempt to execute before signing (Should fail)
        std::cout << "[1] Boss tries to execute UNSIGNED Robotomy:" << std::endl;
        boss.executeForm(robot); // Expecting: "Form not signed" error

        // Scenario B: Boss signs the form
        std::cout << "[2] Boss signs Robotomy:" << std::endl;
        boss.signForm(robot);

        // Scenario C: Testing 50% success rate
        std::cout << "[3] Drilling Loop (Testing 50% chance):" << std::endl;
        for (int i = 0; i < 4; i++) {
            std::cout << "Attempt " << i + 1 << ": ";
            boss.executeForm(robot);
            std::cout << "---" << std::endl;
        }


        // --- TEST 3: PRESIDENTIAL PARDON FORM (Req: Sign 25, Exec 5) ---
        std::cout << "\n>>> TEST 3: PRESIDENTIAL PARDON FORM <<<" << std::endl;
        
        PresidentialPardonForm pardon("Ford Prefect");

        // Scenario A: Manager (45) tries to sign (Grade too low - requires 25)
        std::cout << "[1] Manager tries to sign Pardon:" << std::endl;
        manager.signForm(pardon);

        // Scenario B: Boss signs
        std::cout << "[2] Boss signs Pardon:" << std::endl;
        boss.signForm(pardon);

        // Scenario C: Manager (45) tries to execute (Grade too low - requires 5)
        std::cout << "[3] Manager tries to execute Pardon:" << std::endl;
        // Using executeForm, which catches the exception internally and prints the error
        manager.executeForm(pardon);

        // Scenario D: Boss executes (Success)
        std::cout << "[4] Boss executes Pardon:" << std::endl;
        boss.executeForm(pardon);

    }
    catch (std::exception &e) {
        // This catch block handles exceptions thrown during object CREATION (constructors).
        // Exceptions thrown during signForm/executeForm are handled inside those methods.
        std::cout << "CRITICAL ERROR: " << e.what() << std::endl;
    }

    std::cout << "\n=== END OF TESTS ===" << std::endl;
    return 0;
}