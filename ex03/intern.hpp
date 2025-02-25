#pragma once

#include <iostream>
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class AForm;

class Intern {
	public:
		Intern(void);
		Intern(Intern const &copy);
		~Intern(void);
		Intern const	&operator=(Intern const &copy);
		static AForm	*makeForm(std::string const &type, std::string const &target);
};
