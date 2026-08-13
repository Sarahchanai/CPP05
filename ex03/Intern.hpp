#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include <string>
#include <iostream>

class	Intern // cf sujet
{
	public :
				Intern();
				~Intern();
				Intern (const Intern& original);
				Intern& operator= (const Intern& original);

				AForm* makeForm (const std::string& formName, const std::string& target) const; //cf sujet



	private :

				AForm* createShrubbery(const std::string& target) const;
				AForm* createRobotomy(const std::string& target) const;
				AForm* createPresidential(const std::string& target) const;




};

#endif