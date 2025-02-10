#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int	main(void) {
    Bureaucrat lkhatr("Lkhatr", 2);
    Bureaucrat bagwago("Bagwago", 145);
    // PresidentialPardonForm Pform("l3skr");
    // AForm aform("Form 3adya", 23, 20);
    // AForm *form = new PresidentialPardonForm("usine");
	AForm *form2 = new ShrubberyCreationForm("TreeForm");
    try {
        // form->execute(lkhatr);
        // form->execute(bagwago);
        // std::cout << lkhatr.GetGrade() << " lkhatr " << bagwago.GetGrade() << " bagwago\n";
        // std::cout << form->GetEXECgrade() << " execgrade " << 
        //              form->GetSIGNgrade() << " signgrade " << 
        //              form->GetName() << " name.\n";
        // AForm *form2 = new RobotomyRequestForm("Robotomy");
        // form2->execute(lkhatr);
        // form2->execute(bagwago);
		form2->execute(lkhatr);
		form2->execute(bagwago);

    }
    catch (AForm::GradeTooHighException const &e) {
        std::cerr << e.what() << std::endl;
    }
    catch (AForm::GradeTooLowException const &e) {
        std::cerr << e.what() << std::endl;
    }
}
