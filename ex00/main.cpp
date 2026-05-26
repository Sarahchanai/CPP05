#include "Bureaucrat.hpp"

int	main()
{
	std::cout << "VALID BUREAUCRAT" << std::endl;

	try
	{
		Bureaucrat lewis ("Lewis", 44);
		std::cout << lewis << std::endl;

		lewis.incrementGrade();
		std::cout << "After increment :" << lewis << std::endl;

		lewis.decrementGrade();
		std::cout << "After decrement :" << lewis << std::endl;
	}
	catch (std::exception& exceptioncaught)
	{
		std::cout << "Exception caught :" << exceptioncaught.what() << std::endl;
		//NB : exceptioncaught = obj GradeTooHighException ou GradeTooLowException
		//NB : .what() = fonct. precedemment def -> "Grade too high!"
	}
	


	std::cout << "BUREAUCRAT WITH A TOO HIGH GRADE" << std::endl;

	try
	{
		Bureaucrat max ("Max Verstappen(le comeback)", 1);
		std::cout << max << std::endl;

		max.incrementGrade(); // 1 etant deja le min -> erreur 
		std::cout << "After increment :" << max << std::endl;

		max.decrementGrade(); // 1 + 1 = 2 donc valide ms est ce que cv fonctionner vu que le prems invalide ?
		std::cout << "After decrement" << max << std::endl;
	}
	catch (std::exception& exceptioncaught)
	{
		std::cout << "Exception caught :" << exceptioncaught.what() << std::endl;
	}
	



	std::cout << "BUREAUCRAT WITH A TOO LOW GRADE" << std::endl;

	try
	{
		Bureaucrat 
	}
	catch(const std::exception& exceptioncaught)
	{
		std::cerr << exceptioncaught.what() << std::endl;
	}
	
	

}