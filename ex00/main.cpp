#include "Bureaucrat.hpp"

int	main(void) {
	try
	{
		Bureaucrat nabil(150);
		// nabil.IncrementGrade();
		nabil.DecrementGrade();
		std::cout << nabil.GetGrade() << std::endl;
		nabil.DecrementGrade();
		// nabil.IncrementGrade();
	}
	catch(std::exception &e)
	{
		std::cerr << e.what() << std::endl ; 
	}
}