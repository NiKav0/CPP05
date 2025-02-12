#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main(void) {
	try {
		Bureaucrat b1("Lelouche", 1);
		Bureaucrat b2("Bureaucrat2", 1);
		Form f1("form1", 15, 58);
		Form f2("form2", 149, 149);
		b1.signForm(f1);
		// b1.signForm(f1);
		b2.signForm(f2);
	}
	catch(std::exception &e) {
		std::cerr << "[+] " <<  e.what() << std::endl ;
	}
}
