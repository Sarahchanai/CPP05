#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP


#include <iostream>
#include <stdexcept>


class Bureaucrat
{

    public :

                Bureaucrat (); //C
                ~Bureaucrat(); // D


                Bureaucrat (const std::string& name, int grade); // Constructeur w/ valeurs
                Bureaucrat (const Bureaucrat& original); //Constructeur de copie
                Bureaucrat& operator= (const Bureaucrat& original);



                void    incrementGrade(); //cf sujet
                void    decrementGrade(); //cf sujet

                const std::string& getName() const; //cf sujet
                int getGrade() const; //cf sujet

                //implementation des classes pour les exceptions

// The thrown exceptions must be catchable using try and catch blocks:
// try
// {
// /* do some stuff with bureaucrats */
// }
// catch (std::exception & e)
// {
// /* handle exception */
// }

// catch (std::exception & e) -> cf sujet imposee donc pr compatibilite w/ throw qui est en str on fat une class pour que ca dveienne un obj du type exception

    private :

                int _grade; //cf sujet
                const std::string _name; // cf sujet







};

















#endif