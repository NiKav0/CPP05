#pragma once

#include <iostream>
#include <exception>
#include <cstdlib>
#include <ctime>

class Bureaucrat ;

class Form {
	public :
		Form();
		Form(std::string name, int signgrade, int execgrade);
		~Form();
		Form &operator=(Form const &old);
		std::string GetName();
		bool		GetSigned();
		int		GetSIGNgrade();
		int		GetEXECgrade();
		void	beSigned(Bureaucrat const);
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
		class AlreadySigned: public std::exception {
			public:
				const char *what() const throw();
		};
	private :
		const std::string _name;
		const int _SIGNgrade;
		const int _EXECgrade;
		bool	  _signed;
};
