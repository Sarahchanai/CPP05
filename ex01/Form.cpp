#include "Form.hpp"

// CONSTRUCTEUR PAR DEFAUT
Form::Form() : _name("default"), _isSigned(false), _gradeToSign(150), _gradeToExecute(150)
{
    std::cout << "Form default constructor called" << std::endl;
}

// D
Form::~Form()
{
    std::cout << "Form destructor called" << std::endl;
}

// CONSTRUCTEUR W/ VALEURS
Form::Form(const std::string& name, int gradeToSign, int gradeToExecute)
    : _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
    // NB : _isSigned = false obligatoirt à la construct°, cf sujet
{
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw GradeTooHighException();

    if (gradeToSign > 150 || gradeToExecute > 150)
        throw GradeTooLowException();

    std::cout << "Form (value's) constructor called" << std::endl;
}

// CONSTRUCTEUR DE COPIE
Form::Form(const Form& original)
    : _name(original._name), _isSigned(original._isSigned),
      _gradeToSign(original._gradeToSign), _gradeToExecute(original._gradeToExecute)
{
    std::cout << "Form copy constructor called" << std::endl;
}

// OPERATEUR D'ASSIGNATION
// NB : _name, _gradeToSign, _gradeToExecute sont const -> impossible de les réassigner
Form& Form::operator=(const Form& original)
{
    std::cout << "Form copy assignment operator called" << std::endl;

    if (this != &original)
        _isSigned = original._isSigned; // seul attribut non-const -> le seul qu'on peut changer

    return (*this);
}

// GETTERS
const std::string& Form::getName() const
{ 
    return (_name);
}

bool	Form::getIsSigned() const
{
    return (_isSigned);
}


int	Form::getGradeToSign() const
{
	return (_gradeToSign);
}

int	Form::getGradeToExecute() const
{
	return (_gradeToExecute);
}


// Cf sujet, le bureaucrat essaie de signer le formulaire
void Form::beSigned(const Bureaucrat& bureaucrat)
{
    if (bureaucrat.getGrade() > _gradeToSign)
        throw GradeTooLowException(); // grade trop bas -> ps le droit de sign

    _isSigned = true;
}


// EXCEPTIONS
const char*	Form::GradeTooHighException::what() const throw()
{
    return ("Form : grade too high!");
}

const char* Form::GradeTooLowException::what() const throw()
{
    return ("Form : grade too low!");
}

std::ostream& operator<<(std::ostream& flux, const Form& form)
{
    flux << "Form : " << form.getName();
    
    if (form.getIsSigned() == true)
        flux << " | signed : yes";
    else
        flux << " | signed : no";
    
    flux << " | grade to sign : "    << form.getGradeToSign()
         << " | grade to execute : " << form.getGradeToExecute();
    
    return (flux);
}

