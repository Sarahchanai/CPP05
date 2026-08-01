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
