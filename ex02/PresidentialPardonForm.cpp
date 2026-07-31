#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm(/*fais la meme chose que dans ShrubberyCreationForm.cpp*/){}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target) : AForm(/*fais la meme chose que dans ShrubberyCreationForm.cpp*/) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& original) : AForm(/*fais la meme chose que dans ShrubberyCreationForm.cpp*/) {}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& original){
/*fais la meme chose que dans ShrubberyCreationForm.cpp*/
}

void execute (PresidentialPardonForm const & executor) const
{
    /*cest la que ca va changer et faudra faire la fonction en particulier d'execution pour ce formulaire*/
}