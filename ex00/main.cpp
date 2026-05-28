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
	std::cout << std::endl;


	std::cout << "BUREAUCRAT WITH A TOO HIGH GRADE" << std::endl;

	try
	{
		Bureaucrat max ("Max Verstappen(le comeback)", 1);
		std::cout << max << std::endl;

		max.incrementGrade(); // 1 etant deja le min -> erreur 
		std::cout << "After increment :" << max << std::endl;

		max.decrementGrade(); // 1 + 1 = 2 donc valide ms est ce que cv fonctionner vu que le prems invalide ?
		std::cout << "After decrement :" << max << std::endl;
	}
	catch (std::exception& exceptioncaught)
	{
		std::cout << "Exception caught :" << exceptioncaught.what() << std::endl;
	}
	std::cout << std::endl;



	std::cout << "BUREAUCRAT WITH A TOO HIGH GRADE AT CREATION" << std::endl;

	try
	{
		Bureaucrat zero("lateteatoto", 0); //-> throw dès la créa°
		std::cout << zero << std::endl;

		zero.decrementGrade();
		std::cout << "After decrement :" << zero << std::endl;

	}
	catch(const std::exception& exceptioncaught)
	{
		std::cerr << exceptioncaught.what() << std::endl;
	}
	std::cout << std::endl;


		std::cout << "BUREAUCRAT WITH A TOO LOW GRADE AT CREATION" << std::endl;

	try
	{
		Bureaucrat bigben("big", 151); //-> throw dès la créa°
		std::cout << bigben << std::endl;

		bigben.incrementGrade();
		std::cout << "After increment :" << bigben << std::endl;

	}
	catch(const std::exception& exceptioncaught)
	{
		std::cerr << exceptioncaught.what() << std::endl;
	}
	std::cout << std::endl;


	std::cout << "BUREAUCRAT WITH A TOO LOW GRADE AFTER DECREMENT" << std::endl;
	
	try
	{
    	Bureaucrat bottom("bottom", 150); // grade minimum valide
    	std::cout << bottom << std::endl;

    	bottom.decrementGrade(); // 150 étant déjà le max -> erreur
    	std::cout << "After decrement :" << bottom << std::endl;
	}
	catch (std::exception& exceptioncaught)
	{
    	std::cout << "Exception caught :" << exceptioncaught.what() << std::endl;
	}
	

}