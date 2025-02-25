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
		RobotomyRequestForm(RobotomyRequestForm const &name);
		~RobotomyRequestForm();
		RobotomyRequestForm &operator=(RobotomyRequestForm const &old);
		void execute(Bureaucrat const &executor) const ;
		static AForm	*makeForm(AForm *form, std::string const &type, std::string const &target);
	private :
		const std::string	_target;
};