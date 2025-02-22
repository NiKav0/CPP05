#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : _name("SampleAForm"), _SIGNgrade(150), _EXECgrade(150), _signed(false) {}

AForm::AForm(std::string name, int signgrade, int execgrade) : _name(name), _SIGNgrade(signgrade), _EXECgrade(execgrade), _signed(false) {
	if (this->_SIGNgrade < 1)
		throw (AForm::GradeTooHighException());
	else if (this->_SIGNgrade > 150)
		throw (AForm::GradeTooLowException());
	if (this->_EXECgrade < 1)
		throw (AForm::GradeTooHighException());
	else if (this->_EXECgrade > 150)
		throw (AForm::GradeTooLowException());
}

AForm::~AForm() {}

AForm::AForm(AForm const &old) : _name("SampleAForm"), _SIGNgrade(150), _EXECgrade(150) {
	this->_signed = old._signed;
	*this = old;
}

AForm &AForm::operator=(AForm const &old) {
	this->_signed = old._signed;
	return (*this);
}

std::ostream    &operator<<(std::ostream &out, AForm const &old){
    out << " Form name: " << old.GetName() << " Grade to sign: " << old.GetSIGNgrade() << " Grade to execute: " << old.GetEXECgrade() << " Signed: " << old.GetSigned() << std::endl;
    return out;
}

std::string AForm::GetName() const{
	return (this->_name);
}

bool	AForm::GetSigned() const{
	return this->_signed;
}

int	AForm::GetSIGNgrade() const {
	return (this->_SIGNgrade);
}

int	AForm::GetEXECgrade() const {
	return (this->_EXECgrade);
}

void AForm::SetSigned(bool sign) {
	this->_signed = sign;
}

void AForm::beSigned(Bureaucrat const name) {
	if (name.GetGrade() <= this->_SIGNgrade) {
		this->_signed = true;
	}
	else
		throw AForm::GradeTooLowException();
}

void AForm::beExecuted(Bureaucrat const name) {
	if (name.GetGrade() <= this->_EXECgrade) {
		std::cout << name.GetName() << "Successfully executed " << this->_name << "." << std::endl;
		this->beExecuted(name);
	}
	else if (!this->_signed)
		throw AForm::FormNotSigned();
	else
		throw AForm::GradeTooHighException();
}

const char	*AForm::GradeTooHighException::what() const throw() {
	return ("Grade too high, must be less than what the form requires.");
}

const char	*AForm::GradeTooLowException::what() const throw() {
	return ("Grade too low, must be greater than what the form requires.");
}

const char	*AForm::AlreadySigned::what() const throw() {
	return ("Form already signed.");
}

const char *AForm::FormNotSigned::what() const throw() {
	return ("Form not signed.");
}