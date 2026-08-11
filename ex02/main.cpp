#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int	main()
{
	std::srand(std::time(NULL));
	std::cout << "TEST 1 : CONSTRUCTORS\n" << std::endl;

	Bureaucrat boss ("Boss", 1);
	Bureaucrat manager ("Manager", 40);
	Bureaucrat employee ("Employee", 140);
	Bureaucrat intern ("Intern", 150);

	ShrubberyCreationForm shrub("garden");
	RobotomyRequestForm robot("Bender");
	PresidentialPardonForm pardon("Arthur Dent");

	std::cout << "TEST 2 : OPERATOR << \n" << std::endl;

	std::cout << boss << std::endl;
	std::cout << manager << std::endl;
	std::cout << employee << std::endl;
	std::cout << std::endl;

	std::cout << shrub << std::endl;
	std::cout << robot << std::endl;
	std::cout << pardon << std::endl;

	std::cout << "TEST 3 : EXEC. FORM NN SIGNE \n" << std::endl;

	std::cout << "\n EXECUTE WITHOUT SIGNATURE : \n" << std::endl;
	boss.executeForm(shrub);

	std::cout << "TEST 4 : SIGN W/ LOW GRADE \n" << std::endl;

	intern.signForm(shrub);

	std::cout << "TEST 5 : SIGN W/ SUFFISANT GRADE \n" << std::endl;
	boss.signForm(shrub);
	std::cout << shrub << std::endl;

	std::cout << "TEST 6 : EXEC. OF SHRUBBERY \n" << std::endl;
	boss.executeForm(shrub);
	std::cout << "\nCheck for garden_shrubbery in the project folder." << std::endl;


	std::cout << "TEST 7 : ROBOTOMY \n" << std::endl;
	// NB -> Employee ne peut ps signer -> Robotomy demande le grade 72 pr la signature
	employee.signForm(robot);
	std::cout << std::endl;
	
	// A contrario -> Boss peut sign & executer
	boss.signForm(robot);
	std::cout << std::endl;
	
	// Plusieurs executions pr prouver le result aleatoire
	boss.executeForm(robot);
	boss.executeForm(robot);
	boss.executeForm(robot);
	boss.executeForm(robot);
	boss.executeForm(robot);

	std::cout << "TEST 8 : PRESIDENTIAL PARDON \n" << std::endl;
	manager.signForm(pardon);
	std::cout << pardon << std::endl;
	manager.executeForm(pardon);

	std::cout << "TEST 9 : EXECUTION GRADE \n" << std::endl;
	Bureaucrat lowGrade("LowGrade", 140);
	PresidentialPardonForm anotherPardon("Marvin");
	boss.signForm(anotherPardon); // NB : le form demande le grade 5 pour etre execute -> LowGrade = 140
	lowGrade.executeForm(anotherPardon);

	std::cout << "TEST 10 : POLYMORPHISME \n" << std::endl;

	AForm* form;
	form = new ShrubberyCreationForm("polymorphism");
	boss.signForm(*form); boss.executeForm(*form);
	delete form;

	form = new RobotomyRequestForm("Robot");
	boss.signForm(*form);
	boss.executeForm(*form);
	delete form;

	std::cout << "TEST 11 : GRADE EXCEPTIONS \n" << std::endl;

	try
	{
		Bureaucrat tooHigh("TooHigh", 0);
	}
	catch (const std::exception& e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
	try
	{
		Bureaucrat tooLow("TooLow", 151);
	}
	catch (const std::exception& e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	std::cout << "TEST 12 : INCREMENT/DECREMENT \n" << std::endl;

	Bureaucrat testGrade("TestGrade", 2);
	std::cout << testGrade << std::endl;
	testGrade.incrementGrade();
	std::cout << testGrade << std::endl;
	try
	{
		testGrade.incrementGrade();
	}
	catch (const std::exception& e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
	testGrade.decrementGrade();
	std::cout << testGrade << std::endl;


	std::cout << "TEST 14 : ABSTRACT CLASS \n" << std::endl;
	// AForm form; -> AForm abstraite pcq execute() = fonct. virtuelle pure.

	return (0);
}

