#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"

                // C par defaut -> si ds main : ShrubberyCreationForm citron;
ShrubberyCreationForm::ShrubberyCreationForm() : 
    AForm ("ShrubberyCreationForm", 145, 137),
    _target("default")
{
    std::cout << "Default ShrubberyCreationForm Constructor called" << std::endl;
}

                //D
ShrubberyCreationForm::~ShrubberyCreationForm ()
{
    std::cout << "ShrubberyCreationForm's Destructor called" << std::endl;
}


                    //C w/ valeurs -> si ds main : ShrubberyCreationForm citron ("vert");
                    // NB : target recoit "vert" -> _target = vert
ShrubberyCreationForm::ShrubberyCreationForm (const std::string& target) :
    AForm ("ShrubberyCreationForm", 145, 137),
    _target(target)
{
    std::cout << "Values ShrubberCreationForm Constructor called" << std::endl;
}

                //C de copie
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& original)
    : AForm(original),
      _target(original._target)
{
    std::cout << "Copy Shrubbery constructor called" << std::endl;
}


                //Ope assign.
ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& original)
{
    if (this != &original)
        _target = original._target;//impossible pcq const
        // AForm::operator=(original); // a revoir 

    return *this;
}

//cf sujet
// verif que le form est sign + grade suffisant
// creer le newfile _target + "_shrubbery" (syntaxe cf sujet : Creates a newfile <target>_shrubbery)
// y ecrire des arbres ascii
void	ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
    checkRequirements(executor);

    std::ofstream newfile ( (_target + "_shrubbery") .c_str() );

    if (!newfile.is_open())
        throw std::runtime_error("ShrubberyCreationForm : could not create newfile");

	newfile << " __" << std::endl;
	newfile << " .' `." << std::endl;
	newfile << " / \\" << std::endl;
	newfile << " | LEMON |" << std::endl;
	newfile << " | |" << std::endl;
	newfile << " \\ /" << std::endl;
	newfile << " `.__.'" << std::endl;

    newfile.close();
	if (newfile.fail())
		throw std::runtime_error("ShrubberyCreationForm : failed 2 close newfile");

}    