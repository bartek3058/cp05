#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    try {
        Bureaucrat bob("Bob", 50);
        Form taxForm("Tax Return", 40, 100);

        std::cout << bob << std::endl;
        std::cout << taxForm << std::endl;

        bob.signForm(taxForm); 
        
        std::cout << "--- Promoting Bob ---" << std::endl;
        for(int i=0; i<15; i++) bob.incrementGrade();
        
        bob.signForm(taxForm);
        std::cout << taxForm << std::endl;
    }
    catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    return 0;
}