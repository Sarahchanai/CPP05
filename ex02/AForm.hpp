#ifndef AFORM_HPP
#define AFORM_HPP

#include <string>
#include <iostream>

class Bureaucrat;


class AForm // classe mere polymorphique 
{
    public :

                AForm(); // C/ def
                virtual ~AForm(); //D

                AForm (const std::string& name, int gradetoSign, int gradeToExecute); //C w/ values -> liste init.
                AForm (const AForm& original); // C de copie
                AForm& operator= (const AForm& original); //Ope d'affect.


	                            //GETTERS, cf sujet
				const std::string&  getName() const;
				bool                getIsSigned() const;
    			int                 getGradeToSign() const;
    			int                 getGradeToExecute() const;


                                //FONCT., cf sujet
				void beSigned(const Bureaucrat& bureaucrat); // cf sujet, le bureaucrat a t-il le grade suffisant pr sign
				

						//EXCEPT°, cf sujet
				class	GradeTooHighException : public std::exception
    			{
    				public:
        					const char* what() const throw();
    			};

    			class	GradeTooLowException : public std::exception
    			{
    				public:
        				const char* what() const throw();
                };

				class	FormNotSignedException : public std::exception
				{
					public :
						const char* what() const throw();
				};


                //HELPER
                void	checkRequirements(const Bureaucrat& executor) const;
				// form signe ? le bureaucrat possede le grade requis ?
//AForm vérifie les règles communes, puis délègue l'action spécifique aux classes filles


                //FONC. VIRTUELLE, cf sujet 
                virtual void execute (Bureaucrat const & executor) const = 0;
// NB : virtual = 7 fonc. doit etre redef ds les classes filles, chacune l'implemente a sa facon 


    private :

                // cf sujet
                const std::string   _name;
                bool                _isSigned;          // false à la construction, cf sujet
    			const int           _gradeToSign;       // constant -> liste d'init° obligatoire
    			const int           _gradeToExecute;    // constant -> liste d'init° obligatoire

               

};


std::ostream& operator<<(std::ostream& flux, const AForm& form); //cf sujet 

#endif