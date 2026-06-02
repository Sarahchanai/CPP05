#ifndef	RobotomyRequestForm_HPP
#define	RobotomyRequestForm_HPP

#include "AForm.hpp"
#include <string>
#include <fstream> //librairie gest. de file



class RobotomyRequestForm : public AForm
{
	public :

				RobotomyRequestForm ();
				~RobotomyRequestForm ();

				RobotomyRequestForm (const std::string& target);
				RobotomyRequestForm (const RobotomyRequestForm& original);
				RobotomyRequestForm& operator= (const RobotomyRequestForm& original);

				void execute (Bureaucrat const & executor) const; // redef fonction virtuelle

	private :

				std::string _target; //cf sujet


};








#endif