#include "PresidentialPardonForm.hpp"

//formulaire concret qui herite de AForm 

// C par defaut -> si ds main : PresidentialPardonForm optimus;
PresidentialPardonForm::PresidentialPardonForm() : 
	AForm("PresidentialPardonForm", 72, 45),
	_target("default")
{
	std::cout << "Default PresidentialPardonForm Constructor called" << std::endl;
}
					//D
PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "PresidentialPardonForm's Destructor called" << std::endl;

}
						//C w/ valeurs -> si ds main : PresidentialPardonForm optimus ("megatron");
						// NB : target recoit "megatron" -> _target = megatron
PresidentialPardonForm::PresidentialPardonForm(const std::string& target) :
	AForm("PresidentialPardonForm", 72, 45),
	_target(target)
{
	std::cout << "Values PresidentialPardonForm Constructor called" << std::endl;
}


					//C de copie
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& original)
	: AForm(original),
	_target(original._target)
{
	std::cout << "Copy PresidentialPardonForm constructor called" << std::endl;
}

				//OPe d'assignat.
PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& original)
{
	if (this != &original)
		// _target = original._target;//impossible pcq const
		AForm::operator=(original); 

	return *this;
}



//cf sujet :
// PresidentialPardonForm: Required grades: sign 72, exec 45
// Makes some drilling noises, then informs that <target> has been robotomized
// successfully 50% of the time. Otherwise, it informs that the robotomy failed.
void PresidentialPardonForm::execute (Bureaucrat const &executor) const
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