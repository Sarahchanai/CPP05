#ifndef	PRESIDENTIALPARDONFORM_HPP
#define	PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"
#include <string>
#include <iostream>



class PresidentialPardonForm : public AForm
{
	public :

				PresidentialPardonForm ();
				~PresidentialPardonForm ();

				PresidentialPardonForm (const std::string& target);
				PresidentialPardonForm (const PresidentialPardonForm& original);
				PresidentialPardonForm& operator= (const PresidentialPardonForm& original);

				void execute (Bureaucrat const & executor) const; //redef fonction virtuelle

	private :

				const std::string _target; //cf sujet


};








#endif