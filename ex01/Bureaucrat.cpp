#include "Bureaucrat.hpp"
#include "Form.hpp"

int	RandomGrade(void) 
{
	srand(time(NULL));
	int grade = (rand() % 150) + 1;
	return grade;
}

Bureaucrat::Bureaucrat() : _name("NoName"), _grade(RandomGrade()) {}

Bureaucrat::Bureaucrat(const std::string name) : _name(name), _grade(RandomGrade()) {}

Bureaucrat::~Bureaucrat() {}

Bureaucrat::Bureaucrat(Bureaucrat const &old) {
	this->_grade = old._grade;
}


Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name), _grade(grade) {
	if (grade < 0)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else
		this->_grade = grade;
}

Bureaucrat::Bureaucrat(int grade) : _name("NoName"), _grade(grade) {
	if (grade < 0)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else
		this->_grade = grade;
}


const std::string Bureaucrat::GetName(void) const{
	return this->_name;
}

int Bureaucrat::GetGrade(void) const {
	return this->_grade;
}

void Bureaucrat::SetGrade(int grade) {
	this->_grade = grade;
}

void Bureaucrat::IncrementGrade() {
	int tmp = _grade;
	tmp--;
	if (tmp <= 0)
		throw GradeTooHighException();
	if (tmp > 150)
		throw GradeTooLowException();
	this->_grade--;
}

void Bureaucrat::DecrementGrade() {
	int tmp = _grade;
	tmp++;
	if (tmp <= 0)
		throw GradeTooHighException();
	if (tmp > 150)
		throw GradeTooLowException();
	this->_grade++;
}

void Bureaucrat::signForm(Form &form) {
	if (this->_grade <= form.GetSIGNgrade()) {
		if (form.GetSigned() == false) {
			form.beSigned(*this);
			std::cout << this->_name << " signed " << form.GetName() << std::endl;
		}
		else if (form.GetSigned() == true) {
			std::cout << this->_name << " has already signed " << form.GetName() + "." << std::endl;
			throw Form::AlreadySigned();
		}
	}
	else
		throw Form::GradeTooLowException();
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &old) {
	this->_grade = old._grade;
	return *this;
}

const char	*Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade too high, must be between 1-150.");
}

const char	*Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade too low, must be between 1-150.");
}
