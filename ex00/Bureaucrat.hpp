#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <stdexcept> //librairie classe exception 


class Bureaucrat
{

    public :

                Bureaucrat (); //C
                ~Bureaucrat(); // D


                Bureaucrat (const std::string& name, int grade); // Constructeur w/ valeurs
                Bureaucrat (const Bureaucrat& original); //Constructeur de copie
                Bureaucrat& operator= (const Bureaucrat& original); //Opérateur d'assignation


                                //NB inversement 
                void    incrementGrade(); //cf sujet = grade 3 -> grade 2 
                void    decrementGrade(); //cf sujet = grade 2 -> grade 3

                                                    //GETTERS
                const std::string& getName() const; //cf sujet, NB : const à la fin -> ps de modif° d'obj
                int getGrade() const; //cf sujet 

                                                //CLASSES EXCEPTIONS (imbriquées) -> éviter erreur silencieuse 
                class GradeTooHighException : public std::exception //pcq hérite de la classe mère : exception 
                {
                    public:
                        const char* what() const throw(); //fonct° imposée par std::exception qui retourne le mess d'erreur
                    //const char* = retourne une phrase
                    //what() = imposé par std::exception
                    //const = cette fonc° ne modif ps l'obj
                    //throw() = prévient que la fonc° d'erreur crée elle-même une erreur

                };

                class GradeTooLowException : public std::exception
                {
                    public:
                        const char* what() const throw();
                };



// catch (std::exception & e) -> cf sujet imposee donc pr compatibilite w/ throw qui est en str on fait une classe pour que ca devienne un obj du type exception

    private :

                const std::string _name; // cf sujet
                int _grade; //cf sujet


};

std::ostream& operator<<(std::ostream& flux, const Bureaucrat& bureaucrat); //cf sujet 

#endif



//throw   // "je lance une erreur"
//try     // "j'essaie ce bloc, en sachant que ça peut foirer"
//catch   // "si ça foire, je gère ici"