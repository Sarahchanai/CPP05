#ifndef	RobotomyRequestForm_HPP
#define	RobotomyRequestForm_HPP

#include "AForm.hpp"
#include <string>
#include <cstdlib> //pr rand

// parodie bureaucratique -> but pedagogique
// -> faire pratiquer -> 1 classe concrete qui herite dAForm
// -> action a simuler (std::cout)
// 2e classe fille en re usnt le m^ squelette que la 1ere

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

				const std::string _target; //cf sujet


};








#endif