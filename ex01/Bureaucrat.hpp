#pragma once

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <exception>
#include "Form.hpp"

class Bureaucrat 
{
	private :
		const std::string	_name;
		int					_grade;
	public :
		Bureaucrat();
		Bureaucrat(const std::string name);
		Bureaucrat(const std::string name, int grade);
		Bureaucrat(int grade);
		Bureaucrat(Bureaucrat const &old);
		~Bureaucrat();
		Bureaucrat &operator=(Bureaucrat const &old);
		const std::string	GetName(void) const;
		int			GetGrade(void) const;
		void		SetGrade(int grade);
		void		IncrementGrade(void);
		void		DecrementGrade(void);
		void		signForm(Form &form);
		class GradeTooHighException: public std::exception
		{
			public:
				const char *what() const throw();
		};
		class GradeTooLowException: public std::exception
		{
			public:
				const char *what() const throw();
		};
};
