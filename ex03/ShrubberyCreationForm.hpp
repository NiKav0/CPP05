#pragma once

#include <iostream>
#include <exception>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm {
	public:
	ShrubberyCreationForm();
	ShrubberyCreationForm(const std::string &old);
	ShrubberyCreationForm &operator=(ShrubberyCreationForm const &old);
	~ShrubberyCreationForm();
	void 	execute(Bureaucrat const &executor) const ;
	static AForm	*makeForm(AForm *form, std::string const &type, std::string const &target);
	private:
		const std::string	_filename;
};