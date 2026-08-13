#ifndef	SHRUBBERYCREATIONFORM_HPP
#define	SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <string>
#include <iostream>
#include <fstream>



class ShrubberyCreationForm : public AForm
{
	public :

				ShrubberyCreationForm ();
				~ShrubberyCreationForm ();

				ShrubberyCreationForm (const std::string& target);
				ShrubberyCreationForm (const ShrubberyCreationForm& original);
				ShrubberyCreationForm& operator= (const ShrubberyCreationForm& original);

				void execute (Bureaucrat const & executor) const; // redef fonction virtuelle, cf sujet (syntaxe)

	private :

				const std::string _target; //cf sujet


};




#endif