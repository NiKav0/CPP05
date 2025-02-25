#include "Intern.hpp"

Intern::Intern() {}

Intern::Intern(Intern const &copy) {
	*this = copy;
}

Intern::~Intern(void) {}

Intern const	&Intern::operator=(const Intern &copy) {
	(void)copy;
	return (*this);
}

AForm	*Intern::makeForm(const std::string &type, const std::string &target) {
	AForm	*form;
	form = AForm::makeForm(type, target);
	if (!form)
		std::cerr << "Invalid Form." << std::endl;
	else
		std::cout << "Intern created form: " << form->GetName() << std::endl;
	return (form);
}
