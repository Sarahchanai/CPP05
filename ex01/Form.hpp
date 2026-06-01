#ifndef	FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"



class	Form
{
	public :

				Form(); // C par défaut
				~Form(); // D

				Form(const std::string& name, int gradeToSign, int gradeToExecute); // C w/ values, const donc liste init° oblgtr
    			Form(const Form& original); // C de copie
    			Form& operator=(const Form& original); //Opé d'affect°

					//GETTERS
				const std::string&  getName() const;
				bool                getIsSigned() const;
    			int                 getGradeToSign() const;
    			int                 getGradeToExecute() const;


				void beSigned(const Bureaucrat& bureaucrat); // cf sujet, le bureaucrat a t-il le grade suffisant pr sign
				
						//EXCEPT°, cf sujet
				class GradeTooHighException : public std::exception
    			{
    				public:
        					const char* what() const throw();
    			};

    			class GradeTooLowException : public std::exception
    			{
    				public:
        				const char* what() const throw();
    			};



	private :
				// cf sujet
				const std::string   _name;              // constant -> liste d'init° obligatoire
    			bool                _isSigned;          // false à la construction, cf sujet
    			const int           _gradeToSign;       // constant -> liste d'init° obligatoire
    			const int           _gradeToExecute;    // constant -> liste d'init° obligatoire


};

std::ostream& operator<<(std::ostream& flux, const Form& form);





#endif