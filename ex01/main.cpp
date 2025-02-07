#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main(void) {
	try {
		Bureaucrat b1("Lelouche", 140);
		Bureaucrat b2("Bureaucrat2", 129);
		Form f1(130, 130);
		Form f2(149, 149);
		b1.signForm(f1);
		b1.signForm(f1);
		b2.signForm(f2);
	}
	catch(Form::GradeTooHighException &e) {
		std::cerr << e.what() << std::endl ;
	}
	catch(Form::GradeTooLowException &e) {
		std::cerr << e.what() << std::endl ;
	}
}
