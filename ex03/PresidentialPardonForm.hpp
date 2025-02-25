#pragma once

#include <iostream>
#include <exception>
#include <cstdlib>
#include <ctime>
#include "AForm.hpp"

class Bureaucrat;
// class AForm;

class PresidentialPardonForm : public AForm {
	public :
		PresidentialPardonForm();
		PresidentialPardonForm(const std::string &target);
		PresidentialPardonForm(PresidentialPardonForm const &name);
		~PresidentialPardonForm();
		PresidentialPardonForm &operator=(PresidentialPardonForm const &old);
		void execute(Bureaucrat const &executor) const ;
		static AForm	*makeForm(AForm *form, std::string const &type, std::string const &target);
	private :
		const std::string	_target;
};
