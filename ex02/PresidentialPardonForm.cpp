#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm(): AForm("PresidentialPardonForm", 25, 5), _target("No one") {}


PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
	: AForm(target, 25, 5), _target(target) {}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &old) {
	(void)old;
	return (*this);
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	if (this->GetSigned() == false) 
		throw AForm::FormNotSigned();
	if (this->GetSigned() == true) {
		if (executor.GetGrade() <= this->GetEXECgrade())
			std::cout << executor.GetName() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
	}
	else
		throw AForm::GradeTooHighException();
}
