#include "Bureaucrat.hpp"
#include "Form.hpp"

						// TEST DE LA SIGNATURE

int	main()
{
	std::cout << "APPROUVED SIGNATURE" << std::endl;

	try
	{
		Form idkForm ("IdkForm", 67, 67);
		//Type obj; nom obj("nom Form", grade min. requis 2 sign, grade min. requis 2 execute);	

		Bureaucrat boss ("BossLewis", 1);

		std::cout << "Form's status be4 signing -> " << idkForm << std::endl;
		std::cout << "Infos about the Bureaucrat : " << boss << std::endl;
		std::cout << "Attempting 2 sign..." << std::endl;

		boss.signForm(idkForm);

		std::cout << "Form's status after signing-> " << idkForm << std::endl;
	}
	catch(const std::exception& exceptioncaught)
	{
		std::cout << exceptioncaught.what() << std::endl;
	}
	std::cout << std::endl;




	std::cout << "REFUSED SIGNATURE (GRADE 2 LOW)" << std::endl;
	try
	{
		Form emergencyForm ("EmergencyForm", 5, 2);

		Bureaucrat stagiR ("normalAgent", 44);
		std::cout << "Form's status be4 signing -> " << emergencyForm << std::endl;
		std::cout << "Infos about the Bureaucrat : " << stagiR << std::endl;
		std::cout << "Attempting 2 sign..." << std::endl;

		stagiR.signForm(emergencyForm);

		std::cout << "Form's status after signing-> " << emergencyForm << std::endl;
		
	}
	catch(const std::exception& exceptioncaught)
	{
		std::cout << exceptioncaught.what() << std::endl;
	}
	std::cout << std::endl;




	std::cout << "2 LOW GRADE REQUIRED " << std::endl;
	try
	{
		Form toolow ("Toolow", 152, 16);

		Bureaucrat anyone ("Anyone", 44);
		std::cout << "Form's status be4 signing -> " << toolow << std::endl;
		std::cout << "Infos about the Bureaucrat : " << anyone << std::endl;
		std::cout << "Attempting 2 sign..." << std::endl;

		anyone.signForm(toolow);

		std::cout << "Form's status after signing-> " << toolow << std::endl;
		
	}
	catch(const std::exception& exceptioncaught)
	{
		std::cout << exceptioncaught.what() << std::endl;
	}
	std::cout << std::endl;
	


	std::cout << "2 HIGH GRADE REQUIRED " << std::endl;
	try
	{
		Form tooHigh ("TooHigh", -4, 16);

		Bureaucrat Devi ("", 44);
		std::cout << "Form's status be4 signing -> " << tooHigh << std::endl;
		std::cout << "Infos about the Bureaucrat : " << Devi << std::endl;
		std::cout << "Attempting 2 sign..." << std::endl;

		Devi.signForm(tooHigh);

		std::cout << "Form's status after signing-> " << tooHigh << std::endl;
		
	}
	catch(const std::exception& exceptioncaught)
	{
		std::cout << exceptioncaught.what() << std::endl;
	}
	std::cout << std::endl;


	std::cout << "IMPOSSIBLE EXECUTION " << std::endl;
	try
	{
		Form impossible ("Impossible", 2, 0);

		Bureaucrat barbie ("Anyone", 44);
		std::cout << "Form's status be4 signing -> " << impossible << std::endl;
		std::cout << "Infos about the Bureaucrat : " << barbie << std::endl;
		std::cout << "Attempting 2 sign..." << std::endl;

		barbie.signForm(impossible);

		std::cout << "Form's status after signing-> " << impossible << std::endl;
		
	}
	catch(const std::exception& exceptioncaught)
	{
		std::cout << exceptioncaught.what() << std::endl;
	}
	std::cout << std::endl;

}