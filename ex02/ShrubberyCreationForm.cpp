#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), _filename("no_name") {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &old) : AForm("ShrubberyCreationForm", 145, 137), _filename(old) {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &old) {
	(void)old;
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}