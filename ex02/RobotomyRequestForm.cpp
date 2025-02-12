#include "RobotomyRequestForm.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"

RobotomyRequestForm::RobotomyRequestForm(): AForm("RobotomyRequestForm", 72, 45), _target("No one") {}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
	: AForm(target, 72, 45), _target(target) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &old) {
	(void)old;
	return (*this);
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const {
	if (this->GetSigned() == false) 
		throw AForm::FormNotSigned();
	if (executor.GetGrade() >  this->GetEXECgrade())
		throw AForm::GradeTooHighException();
	else {
		std::cout << "Bzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz..." << std::endl;
		std::srand(std::time(0));
    	if (std::rand() % 2 == 1)
			std::cout << executor.GetName() << " has been robotomized successfully." << std::endl;
	}
}
