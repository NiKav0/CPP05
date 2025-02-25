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
	if (executor.GetGrade() <= this->GetEXECgrade())
		std::cout << executor.GetName() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
	else
		throw AForm::GradeTooHighException();
}

AForm	*PresidentialPardonForm::makeForm(AForm *form, std::string const &type, std::string const &target)
{
	if (form == NULL && type == "Presidential_FORM")
		return (new PresidentialPardonForm(target));
	return (form);
}
