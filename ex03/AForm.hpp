#pragma once

#include <iostream>
#include <exception>
#include <cstdlib>
#include <ctime>
// #include "PresidentialPardonForm.hpp"
// #include "RobotomyRequestForm.hpp"
// #include "ShrubberyCreationForm.hpp"

class Bureaucrat ;

class AForm {
	public :
		AForm();
		AForm(std::string name, int signgrade, int execgrade);
		AForm(AForm const &old);
		virtual ~AForm();
		AForm &operator=(AForm const &old);
		std::string GetName() const;
		bool		GetSigned() const;
		int			GetSIGNgrade() const;
		int			GetEXECgrade() const;
		void		beSigned(Bureaucrat const);
		void		beExecuted(Bureaucrat const);
		static AForm		*makeForm(std::string const &type, std::string const &target);
		virtual void execute(Bureaucrat const &executor) const = 0;
		class GradeTooHighException: public std::exception {
			public:
				const char *what() const throw();
		};
		class GradeTooLowException: public std::exception {
			public:
				const char *what() const throw();
		};
		class AlreadySigned: public std::exception {
			public:
				const char *what() const throw();
		};
		class FormNotSigned: public std::exception {
			public:
				const char *what() const throw();
		};
	private :
		const std::string _name;
		const int _SIGNgrade;
		const int _EXECgrade;
		bool	  _signed;
};
