#pragma once

#include <iostream>
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Form;

class Intern
{
	public:
		Intern(void);
		Intern(Intern const &copy);
		~Intern(void);
		Intern const	&operator=(Intern const &copy);
		Form	*makeForm(std::string const &type, std::string const &target);
};
