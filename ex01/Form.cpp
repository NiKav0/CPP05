#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : _name("SampleForm"), _SIGNgrade(150), _EXECgrade(150), _signed(false) { 

}

Form::Form(std::string name, int signgrade, int execgrade) : _name(name), _SIGNgrade(signgrade), _EXECgrade(execgrade), _signed(false) {
	if (this->_SIGNgrade < 1)
		throw (Form::GradeTooHighException());
	else if (this->_SIGNgrade > 150)
		throw (Form::GradeTooLowException());
	if (this->_EXECgrade < 1)
		throw (Form::GradeTooHighException());
	else if (this->_EXECgrade > 150)
		throw (Form::GradeTooLowException());
}

Form::~Form() {

}

Form &Form::operator=(Form const &old) {
	this->_signed = old._signed;
	return (*this);
}

std::string Form::GetName() {
	return (this->_name);
}

bool	Form::GetSigned() {
	return this->_signed;
}

int	Form::GetSIGNgrade() {
	return (this->_SIGNgrade);
}

int	Form::GetEXECgrade() {
	return (this->_EXECgrade);
}

void Form::beSigned(Bureaucrat const _Name) {
	if (_Name.GetGrade() <= this->_SIGNgrade) {
		this->_signed = true;
	}
	else
		throw Form::GradeTooLowException();
}

const char	*Form::GradeTooHighException::what() const throw()
{
	return ("Grade too high, must be greater than what the form requires.");
}

const char	*Form::GradeTooLowException::what() const throw()
{
	return ("Grade too low, must be less than what the form requires.");
}

const char	*Form::AlreadySigned::what() const throw() {
	return ("Form already signed.");
}
