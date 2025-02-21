#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int	main(void) {
    Bureaucrat lkhatr("Lkhatr", 2);
    Bureaucrat bagwago("Bagwago", 140);
    PresidentialPardonForm Pform("l3skr");
    // AForm *aform("Form 3adya", 23, 20);
    // AForm *form = new PresidentialPardonForm("usine");
    // AForm *form2 = new RobotomyRequestForm("Robotomy");
	AForm *form3 = new ShrubberyCreationForm("TreeForm");
    try {
		// // Trying to execute a PresidentialPardonForm
        // form->execute(lkhatr);
        // form->execute(bagwago);
		// // Trying to execute a RobotomyRequestForm
        // form2->execute(lkhatr);
        // form2->execute(bagwago);
		// Trying to execute a ShrubberyCreationForm
		form3->execute(lkhatr);
		form3->execute(lkhatr);
		form3->execute(bagwago);
    }
    catch (AForm::GradeTooHighException const &e) {
        std::cerr << e.what() << std::endl;
    }
    catch (AForm::GradeTooLowException const &e) {
        std::cerr << e.what() << std::endl;
    }
	catch (AForm::FormNotSigned const &e) {
		std::cerr << e.what() << std::endl;
	}
}
