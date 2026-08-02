#include <iostream>
#include <cstdlib>
#include <ctime>

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"


int main()
{
    std::srand(static_cast<unsigned int>(std::time(NULL)));


	// 1 ->  Exceptions du constructeur Bureaucrat
	std::cout << "\nBureaucrat construction exceptions " << std::endl;

	try
	{
		Bureaucrat invalidHigh("TooHigh", 0);
	}
	catch (std::exception & e)
	{
		std::cout << "Caught: " << e.what() << std::endl;
	}

	try
	{
		Bureaucrat invalidLow("TooLow", 151);
	}
	catch (std::exception & e)
	{
		std::cout << "Caught: " << e.what() << std::endl;
	}

	Bureaucrat boss("Boss", 1);
	Bureaucrat rookie("Rookie", 150);


	// 2 -> ShrubberyCreationForm

	std::cout << "\nShrubberyCreationForm" << std::endl;

	// -- scenario normal, via Bureaucrat (catch interne, message affiche) --
	ShrubberyCreationForm shrubbery("garden");
	boss.signForm(shrubbery);
	boss.executeForm(shrubbery);

	// demonstration brute de l'exception : grade insuffisant pour sign
	ShrubberyCreationForm secondShrubbery("backyard");
	try
	{
		secondShrubbery.beSigned(rookie); // rookie grade 150 > 145 requis
	}
	catch (std::exception & e)
	{
		std::cout << "Caught: " << e.what() << std::endl;
	}

	
	// 3 -> RobotomyRequestForm
	std::cout << "\n RobotomyRequestForm " << std::endl;

	RobotomyRequestForm robotomy("Bender");
	boss.signForm(robotomy);
	boss.executeForm(robotomy);

	// demonstration brute : execution sans signature prealable
	RobotomyRequestForm unsignedRobotomy("Marvin");
	try
	{
		unsignedRobotomy.execute(boss);
	}
	catch (std::exception & e)
	{
		std::cout << "Caught: " << e.what() << std::endl;
	}

	// 4 -> PresidentialPardonForm

	std::cout << "\n PresidentialPardonForm " << std::endl;

	PresidentialPardonForm pardon("Bender");
	boss.signForm(pardon);
	boss.executeForm(pardon);

	// demonstration brute : grade insuffisant pour execute
	PresidentialPardonForm secondPardon("Marvin");
	boss.signForm(secondPardon);
	try
	{
		secondPardon.execute(rookie); // rookie grade 150 > 5 requis
	}
	catch (std::exception & e)
	{
		std::cout << "Caught: " << e.what() << std::endl;
	}

	return 0;
    
}