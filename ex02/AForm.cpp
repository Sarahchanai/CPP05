#include "AForm.hpp"
#include "Bureaucrat.hpp"

                            // CONSTRUCTEUR PAR DEFAUT
AForm::AForm() : _name("default"), _isSigned(false), _gradeToSign(150), _gradeToExecute(150)
{
    std::cout << "AForm default constructor called" << std::endl;
}

                                // D
AForm::~AForm()
{
    std::cout << "AForm destructor called" << std::endl;
}

                    // CONSTRUCTEUR W/ VALEURS
AForm::AForm(const std::string& name, int gradeToSign, int gradeToExecute)
    : _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
    // NB : _isSigned = false obligatoirt à la construct°, cf sujet
{
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw GradeTooHighException();

    if (gradeToSign > 150 || gradeToExecute > 150)
        throw GradeTooLowException();

    std::cout << "AForm (value's) constructor called" << std::endl;
}

                            // CONSTRUCTEUR DE COPIE
AForm::AForm(const AForm& original)
    : _name(original._name), _isSigned(original._isSigned),
      _gradeToSign(original._gradeToSign), _gradeToExecute(original._gradeToExecute)
{
    std::cout << "AForm copy constructor called" << std::endl;
}

                // OPERATEUR D'ASSIGNATION
// NB : _name, _gradeToSign, _gradeToExecute sont const -> impossible de les réassigner
AForm& AForm::operator=(const AForm& original)
{
    std::cout << "AForm copy assignment operator called" << std::endl;

    if (this != &original)
        _isSigned = original._isSigned; // seul attribut non-const -> le seul qu'on peut changer

    return (*this);
}

                        // GETTERS
const std::string& AForm::getName() const
{ 
    return (_name);
}

bool	AForm::getIsSigned() const
{
    return (_isSigned);
}


int	AForm::getGradeToSign() const
{
	return (_gradeToSign);
}

int	AForm::getGradeToExecute() const
{
	return (_gradeToExecute);
}


// Cf sujet, le bureaucrat essaie de signer le AFormulaire
void AForm::beSigned(const Bureaucrat& bureaucrat)
{
    if (bureaucrat.getGrade() > _gradeToSign)
        throw GradeTooLowException(); // grade trop bas -> ps le droit de sign

    _isSigned = true;
}


                        // EXCEPTIONS
const char*	AForm::GradeTooHighException::what() const throw()
{
    return ("AForm : grade too high!");
}

const char* AForm::GradeTooLowException::what() const throw()
{
    return ("AForm : grade too low!");
}
const char* AForm::FormNotSignedException::what() const throw()
{
    return ("AForm : form can not be signed !");
}

//cf suje redef operateur
std::ostream& operator<<(std::ostream& flux, const AForm& AForm)
{
    flux << "AForm's name : " << AForm.getName();
    
    if (AForm.getIsSigned() == true)
        flux << " | signed : yes";
    else
        flux << " | signed : no";
    
    flux << " | grade to sign : "    << AForm.getGradeToSign()
         << " | grade to execute : " << AForm.getGradeToExecute();
    
    return (flux);
}

// fonct commune a tt les filles donc -> aForm
void	AForm::checkRequirements (const Bureaucrat& executor) const
{
	if (_isSigned == false)
	{
		throw FormNotSignedException();
	}

	if (executor.getGrade() > _gradeToExecute)
	{
		throw GradeTooLowException();
	}
	
}

