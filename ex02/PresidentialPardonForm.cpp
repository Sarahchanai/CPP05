#include "PresidentialPardonForm.hpp"

//formulaire concret qui herite de AForm 

// C par defaut -> si ds main : PresidentialPardonForm sarah;
PresidentialPardonForm::PresidentialPardonForm() : 
	AForm("PresidentialPardonForm", 25, 5),
	_target("default")
{
	std::cout << "Default PresidentialPardonForm Constructor called" << std::endl;
}
					//D
PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "PresidentialPardonForm's Destructor called" << std::endl;

}
						//C w/ valeurs -> si ds main : PresidentialPardonForm sarah ("mb");
						// NB : target recoit "megatron" -> _target = megatron
PresidentialPardonForm::PresidentialPardonForm(const std::string& target) :
	AForm("PresidentialPardonForm", 25, 5),
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



//cf sujet
// PresidentialPardonForm: Required grades: sign 25, exec 5 Informs that <target> has been pardoned by Zaphod Beeblebrox.
void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	checkRequirements(executor);
	std::cout << _target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}
