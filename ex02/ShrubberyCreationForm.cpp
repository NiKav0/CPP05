#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), _filename("no_name") {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &old) : AForm(old, 145, 137), _filename(old) {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &old) {
	(void)old;
	return (*this);
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const {
	if (this->GetSigned() == false) 
		throw AForm::FormNotSigned();
	if (executor.GetGrade() <= this->GetEXECgrade()) {
		std::string filename = this->_filename + "_shrubbery";
		std::ofstream file;

		file.open(filename.c_str());
		if (!file) {
			std::cerr << "File coudln't be created : No filename." << std::endl;
			std::exit(1);
		}

	    file << "                                                         .\n";
    	file << "                                              .         ;  \n";
    	file << "                 .              .              ;%     ;;   \n";
    	file << "                   ,           ,                :;%  %;   \n";
    	file << "                    :         ;                   :;%;'     .,   \n";
    	file << "           ,.        %;     %;            ;        %;'    ,;\n";
    	file << "             ;       ;%;  %%;        ,     %;    ;%;    ,%'\n";
    	file << "              %;       %;%;      ,  ;       %;  ;%;   ,%;' \n";
    	file << "               ;%;      %;        ;%;        % ;%;  ,%;'\n";
    	file << "                %;.     ;%;     %;'         ;%%;.%;'\n";
    	file << "                 :;%.    ;%%. %@;        %; ;@%;%'\n";
    	file << "                    :%;.  :;bd%;          %;@%;'\n";
    	file << "                      @%:.  :;%.         ;@@%;'   \n";
    	file << "                        @%.  ;@%.      ;@@%;         \n";
    	file << "                          @%%. @%%    ;@@%;        \n";
    	file << "                            ;@%. :@%%  %@@%;       \n";
    	file << "                              %@bd%%%bd%%:;     \n";
    	file << "                                #@%%%%%:;;\n";
    	file << "                                %@@%%%::;\n";
    	file << "                                %@@@%(o);  . '         \n";
    	file << "                                %@@@o%;:(.,'         \n";
    	file << "                            .. %@@@o%::;         \n";
    	file << "                               )@@@o%::;         \n";
    	file << "                                %@@(o)::;        \n";
    	file << "                               .%@@@@%::;         \n";
    	file << "                               ;%@@@@%::;.          \n";
    	file << "                              ;%@@@@%%:;;;. \n";
    	file << "                          ...;%@@@@@%%:;;;;,..\n";
		file.close();

		std::cout << executor.GetName() <<  " created the file \"" << this->_filename + "_shrubbery" << "\", check it out!" << std::endl; 
	}
		else if (this->GetSigned() == false) {
			throw (AForm::FormNotSigned());
		}
	else {
		throw AForm::GradeTooHighException();
	}
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}