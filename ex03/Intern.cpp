#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
 
                        // ORTHODOX CANONICAL FORM
 
Intern::Intern()
{
    std::cout << "Intern default constructor called" << std::endl;
}
 
Intern::Intern(const Intern& original)
{
    (void)original;
    std::cout << "Intern copy constructor called" << std::endl;
}
 
Intern& Intern::operator=(const Intern& original)
{
    (void)original;
    std::cout << "Intern copy assignment operator called" << std::endl;
    return (*this);
}
 
Intern::~Intern()
{
    std::cout << "Intern destructor called" << std::endl;
}


//CONTRE EXEMPLE
/*if (formName == "robotomy request")
    return new RobotomyRequestForm(target);
else if (formName == "shrubbery creation")
    return new ShrubberyCreationForm(target);
else if (formName == "presidential pardon")
    return new PresidentialPardonForm(target);*/

AForm* Intern::createShrubbery(const std::string& target) const
{
	return (new ShrubberyCreationForm(target)); //alloc° memR sur heap
}

AForm* Intern::createRobotomy(const std::string& target) const
{
	return (new RobotomyRequestForm(target));
}

AForm* Intern::createPresidential(const std::string& target) const
{
	return (new PresidentialPardonForm(target));
}


AForm* Intern::makeForm(const std::string& formName, const std::string& target) const
{
	const std::string formNames[3] =
	{
		"shrubbery creation", // i = 0
		"robotomy request", // i = 1
		"presidential pardon" // i = 2
	};

	AForm* (Intern::*createForms[3])(const std::string&) const =
	{
		// NB : éléments = fonc°
		&Intern::createShrubbery, // i = 0
		&Intern::createRobotomy, // i = 1
		&Intern::createPresidential // i = 2
	};

	// NB : tabs liés par leux index -> corréla°

	for (int i = 0; i < 3; i++)
	{
		if (formName == formNames[i])
		{
			std::cout << "Intern creates " << formName << std::endl;

			return (this->*createForms[i])(target); //= appelle sur l'obj actuel this, la fonc° pointée par createForms[i] en lui passant target
		}
	}

	std::cout << "Error : Intern could not create " << formName << " : no such form exists" << std::endl;

	return NULL;
}