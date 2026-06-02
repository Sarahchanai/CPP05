#ifndef	ShrubberyCreationForm_HPP
#define	ShrubberyCreationForm_HPP

#include "AForm.hpp"
#include <string>
#include <iostream>



class ShrubberyCreationForm : public AForm
{
	public :

				ShrubberyCreationForm ();
				~ShrubberyCreationForm ();

				ShrubberyCreationForm (const std::string& target);
				ShrubberyCreationForm (const ShrubberyCreationForm& original);
				ShrubberyCreationForm& operator= (const ShrubberyCreationForm& original);

				void execute (Bureaucrat const & executor) const; // redef fonction virtuelle

	private :

				std::string _target; //cf sujet


};




#endif