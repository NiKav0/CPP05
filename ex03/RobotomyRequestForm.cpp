#include "RobotomyRequestForm.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"

RobotomyRequestForm::RobotomyRequestForm(): AForm("RobotomyRequestForm", 72, 45), _target("No one") {}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &name)
	: AForm(name), _target(name._target) {}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
	: AForm("RobotomyRequestForm", 72, 45), _target(target) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &old) {
	(void)old;
	return (*this);
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const {
	std::cout << "Bzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz..." << std::endl;
	if (executor.GetGrade() >  this->GetEXECgrade())
		throw AForm::GradeTooHighException();
	else {
		std::srand(std::time(0));
    	if (std::rand() % 2 == 1)
			std::cout << executor.GetName() << " has been robotomized successfully." << std::endl;
	}
}

AForm	*RobotomyRequestForm::makeForm(AForm *form, std::string const &type, std::string const &target)
{
	if (form == NULL && type == "Robotomy_FORM")
		return (new RobotomyRequestForm(target));
	return (form);
}
