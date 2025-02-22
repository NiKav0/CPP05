#pragma once

#include <iostream>
#include <exception>
#include <cstdlib>
#include <ctime>
#include "AForm.hpp"

class Bureaucrat;

class PresidentialPardonForm : public AForm {
	public :
		PresidentialPardonForm();
		PresidentialPardonForm(const std::string &target);
		~PresidentialPardonForm();
		PresidentialPardonForm &operator=(PresidentialPardonForm const &old);
		void execute(Bureaucrat const &executor) const ;
	private :
		const std::string	_target;
};
