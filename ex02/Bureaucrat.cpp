#include "Bureaucrat.hpp"

// NB : seul travail = signer et executer les forms
//    : ne fait 0 verif lui même (cf AForm)

                // CONSTRUCTEUR PAR DEFAUT
Bureaucrat::Bureaucrat() : _name("default"), _grade(150)
{
    std::cout<< "Bureaucrat's default constructor called"<< std::endl;
    //NB : rappel prototype : const std::string& name -> donc obligatoire de faire 1 liste d'initialisa°
    //NB : wrong -> _name = "default"
}
                        // D default
Bureaucrat::~Bureaucrat()
{
    std::cout << "Bureaucrat's Destructor called"<< std::endl;
}

                    //  C w/ valeurs
Bureaucrat::Bureaucrat (const std::string& name, int grade) : _name(name), _grade(grade)
{
    if (grade < 1)
        throw GradeTooHighException();

    if (grade > 150)
        throw GradeTooLowException();

    std::cout << "Bureaucrat's (value's) constructor called" << std::endl;
    
}
                            //C DE COPIE
Bureaucrat::Bureaucrat (const Bureaucrat& original) : _name(original._name), _grade(original._grade)
{
    std::cout << "Copy Constructor called" << std::endl;

}

                        //OPE ASSIGNA°
//NB : _name -> const std::string _name -> impossible _name = original._name
Bureaucrat& Bureaucrat::operator= (const Bureaucrat& original)
{
    std::cout << "Copy assignment operator called" << std::endl;

    if (this != &original)
    {
        _grade = original._grade;
    }
    return (*this);
}

                            //GETTERS
const std::string& Bureaucrat::getName() const
{
    return (_name);
}

int Bureaucrat::getGrade() const
{
    return (_grade);
}

                        //CF SUJET, FONCT ->NB : 1 = meilleur grade
                        //                     150 = pire grade

void    Bureaucrat::incrementGrade() //monter ds la hierarchie
{
    if (_grade == 1 || _grade <= 1)
        throw GradeTooHighException(); //condit. remplie -> genere l'except. + arret immediat de la fonct. actuelle
    
    _grade--;
}

void    Bureaucrat::decrementGrade() //retrograder ds la hierarchie
{
    if (_grade == 150 || _grade >= 150)
        throw GradeTooLowException();
    
    _grade++;
}

                    //EXCEPTIONS

const char* Bureaucrat::GradeTooHighException::what() const throw()
// return un const char* -> pcq signature du what() ds le std::exception(.hpp) -> la phrase d'erreur
//what() -> fonct heritee de std::exception -> pr personnaliser le mess a return & le lire
//const->ps de modif de l'obj
//throw () ->garantie qu'elle ne lance ps d'exception -> = what() ne throwera jms ->prevent. pr ps qu'1 fonct. d'err throw une erreur

{
    return ("Grade too high!"); // mess retourne par e.what()
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return ("Grade too low!"); // mess retourne par e.what()
}

                            //OPE <<, CF SUJET

std::ostream& operator<<(std::ostream& flux, const Bureaucrat& bureaucrat)
{
    flux << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade(); //syntaxe cf sujet
    return (flux);
}





void    Bureaucrat::executeForm(AForm const & form) const
{
    try
    {
        form.execute(*this);
        std::cout << _name << " executed " << form.getName() << std::endl;
        
    }
    catch(const std::exception& e)
    {
        std::cout << _name << " could not execute " << form.getName() << " because " << e.what() << std::endl;
    }
    
}

                        //CF SUJET EX01!!!!!!!!
void Bureaucrat::signForm(AForm& form) const
{
    try
    {
        form.beSigned(*this);
        //*this = le bureaucrat lui-même (moi)
        // on demande au form "peux-tu être signé par moi ?"
        // si beSigned throw -> on saute au catch
        // si beSigned ne throw ps -> le formulaire est signé, on continue
        
        std::cout << getName() << " signed " << form.getName() << std::endl;
    }
    catch (std::exception& exceptioncaught)
    {
        // beSigned a throwé -> le grade était insuffisant
        std::cout << getName() << " couldn't sign " << form.getName()
                  << " because " << exceptioncaught.what() << std::endl;
    }
}
