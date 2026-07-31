#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm(/*fais la meme chose que dans ShrubberyCreationForm.cpp*/){}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) : AForm(/*fais la meme chose que dans ShrubberyCreationForm.cpp*/) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& original) : AForm(/*fais la meme chose que dans ShrubberyCreationForm.cpp*/) {}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& original){
/*fais la meme chose que dans ShrubberyCreationForm.cpp*/
}

void execute (Bureaucrat const & executor) const
{
    /*cest la que ca va changer et faudra faire la fonction en particulier d'execution pour ce formulaire*/
}