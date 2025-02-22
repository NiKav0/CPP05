#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int    main() {
    Bureaucrat    me("AstroBoy", 12);
    try {
        ShrubberyCreationForm    form("home");
        RobotomyRequestForm    robot("dali3");
        PresidentialPardonForm    pardon("bagwago");
        std::cout << form;
        me.signForm(form);
        std::cout << form;
        form.execute(me);
        std::cout << "-------------------------------------\n";
        std::cout << robot;
        me.signForm(robot);
        std::cout << robot;
        robot.execute(me);
        std::cout << "-------------------------------------\n";
        std::cout << pardon;
        me.signForm(pardon);
        std::cout << pardon;
        pardon.execute(me);
    }
    catch ( std::exception &e ) {
        std::cerr << "[+] Exception catched.\n";
        std::cerr << e.what();
    }
    return (0);
}
