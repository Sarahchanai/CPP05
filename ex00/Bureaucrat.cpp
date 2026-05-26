#include "Bureaucrat.hpp"

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
    std::cout << "Bureaucrat's (value's) constructor called" << std::endl;

    if (grade < 1)
        throw GradeTooHighException();

    if (grade > 150)
        throw GradeTooLowException();
    
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


Bureaucrat::const std::string& getName() const
{
    
}




