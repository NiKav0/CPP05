#include "AForm.hpp"
#include "Intern.hpp"
#include "Bureaucrat.hpp"

int main() {
	Intern		jfaf;
	Bureaucrat	costume("Lmojahid", 1);

	try {
		AForm *form = jfaf.makeForm("Robotomy_FORM", "Clone01");
		AForm *form2 = jfaf.makeForm("Shrubbery_TREE", "Clone02");
		AForm *form3 = jfaf.makeForm("Presidential_FORM", "Clone03");
		jfaf.makeForm("Random_Form", "Clone04");
		
		std::cout << "------------------------------------" << std::endl;
		costume.signForm(*form);
		costume.executeForm(*form);
		delete form;
		std::cout << "------------------------------------" << std::endl;
		costume.signForm(*form2);
		costume.executeForm(*form2);
		delete form2;
		std::cout << "------------------------------------" << std::endl;
		costume.signForm(*form3);
		costume.executeForm(*form3);
		delete form3;
		std::cout << "------------------------------------" << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "Caught exception: " << e.what() << std::endl;
	}
	return (0);
}
