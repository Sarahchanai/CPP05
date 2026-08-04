#include "RobotomyRequestForm.hpp"

//formulaire concret qui herite de AForm 

// C par defaut -> si ds main : RobotomyRequestForm optimus;
RobotomyRequestForm::RobotomyRequestForm() : 
	AForm("RobotomyRequestForm", 72, 45),
	_target("default")
{
	std::cout << "Default RobotomyRequestForm Constructor called" << std::endl;
}
					//D
RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm's Destructor called" << std::endl;

}
						//C w/ valeurs -> si ds main : RobotomyRequestForm optimus ("megatron");
						// NB : target recoit "megatron" -> _target = megatron
RobotomyRequestForm::RobotomyRequestForm(const std::string& target) :
	AForm("RobotomyRequestForm", 72, 45),
	_target(target)
{
	std::cout << "Values RobotomyRequestForm Constructor called" << std::endl;
}


					//C de copie
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& original)
	: AForm(original),
	_target(original._target)
{
	std::cout << "Copy RobotomyRequestForm constructor called" << std::endl;
}

				//OPe d'assignat.
RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& original)
{
	if (this != &original)
		// _target = original._target;//impossible pcq const
		AForm::operator=(original); 

	return *this;
}



//cf sujet :
// RobotomyRequestForm: Required grades: sign 72, exec 45
// Makes some drilling noises, then informs that <target> has been robotomized
// successfully 50% of the time. Otherwise, it informs that the robotomy failed.
void RobotomyRequestForm::execute (Bureaucrat const &executor) const
{
	checkRequirements(executor);

	std::cout << "dring dring ( = Drilling noises)" << std::endl;

	if (std::rand() % 2 == 0)
	//nombre pair donne 0 avec % 2
		std::cout << _target << " has been robotomized successfully" << std::endl;
	else
	//nombre impair donne 1 avec % 2
		std::cout << "Robotomy failed for " << _target << std::endl;


}