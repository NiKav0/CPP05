#pragma once

#include <iostream>
#include <exception>
#include <cstdlib>
#include <ctime>
#include "AForm.hpp"

class RobotomyRequestForm : public AForm {
	public :
		RobotomyRequestForm();
		RobotomyRequestForm(const std::string &target);
		~RobotomyRequestForm();
		RobotomyRequestForm &operator=(RobotomyRequestForm const &old);
		void execute(Bureaucrat const &executor) const ;
	private :
		const std::string	_target;
};