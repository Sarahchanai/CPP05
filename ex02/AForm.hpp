#ifndef AFORM_HPP
#define AFORM_HPP

#include <string>
#include <iostream>

class Bureaucrat;


class AForm
{
    public :

                AForm(); // C/ def
                ~AForm(); //D

                AForm (const std::string& name, int gradetoSign, int gradeToExecute); //C w/ values -> liste init.
                AForm (const AForm& original); // C de copie
                AForm& operator= (const AForm& original); //Ope d'affect.







    private :


                const std::string   _name





};














std::ostream& operator<<(std::ostream& flux, const AForm& form); //cf sujet 

#endif