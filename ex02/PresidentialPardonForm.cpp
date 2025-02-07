#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm(): AForm("PresidentialPardonForm", 25, 5), _target("No one") {}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &name)
	: AForm(name), _target(name._target) {}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
	: AForm("PresidentialPardonForm", 25, 5), _target(target) {}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &old) {
	(void)old;
	return (*this);
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	std::cout << executor.GetName() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
