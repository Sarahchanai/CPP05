#include "Bureaucrat.hpp"
#include "Intern.hpp"

int main()
{
	std::cout << "Intern creation\n" << std::endl;
    Intern stagiaire;

    
	std::cout << "\nForms creation\n" << std::endl;
	AForm* shrubbery;
	AForm* robotomy;
	AForm* presidential;

	shrubbery = stagiaire.makeForm("shrubbery creation", "citron");
	robotomy = stagiaire.makeForm("robotomy request", "Bender");
	presidential = stagiaire.makeForm("presidential pardon", "Arthur Dent");

	std::cout << "\n Sign & execution of forms\n" << std::endl;

	Bureaucrat boss("Boss", 1);
	std::cout << boss << std::endl;
	boss.signForm(*shrubbery);
	boss.signForm(*robotomy);
	boss.signForm(*presidential);
	boss.executeForm(*shrubbery);
	boss.executeForm(*robotomy);
	boss.executeForm(*presidential);

	std::cout << "\n Unknown form\n" << std::endl;
	AForm* invalidname;
	invalidname = stagiaire.makeForm("citron", "desert");
	std::cout << invalidname << std::endl;

	std::cout << "\n clean\n" << std::endl;
	delete shrubbery;
	delete robotomy;
	delete presidential;
	delete invalidname;



}