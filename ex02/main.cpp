#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

// Petit helper pour aérer l'affichage entre chaque section de test
void printSection(const std::string& title)
{
    std::cout << "\n========== " << title << " ==========" << std::endl;
}

int main()
{
    std::srand(static_cast<unsigned int>(std::time(NULL))); // seed pour le rand() de RobotomyRequestForm

    // ------------------------------------------------------------------
    // SECTION 1 : Bureaucrat - Orthodox Canonical Form + exceptions grade
    // ------------------------------------------------------------------
    printSection("1. Bureaucrat : construction et limites de grade");

    Bureaucrat lowGrade("Bob", 150);   // pire grade possible, valide
    Bureaucrat highGrade("Alice", 1);  // meilleur grade possible, valide
    std::cout << lowGrade << std::endl;
    std::cout << highGrade << std::endl;

    try
    {
        Bureaucrat invalid("Ghost", 0); // grade < 1 -> doit throw
        (void)invalid;
    }
    catch (std::exception& e)
    {
        std::cout << "Exception attrapee (grade 0) : " << e.what() << std::endl;
    }

    try
    {
        Bureaucrat invalid("Ghost", 151); // grade > 150 -> doit throw
        (void)invalid;
    }
    catch (std::exception& e)
    {
        std::cout << "Exception attrapee (grade 151) : " << e.what() << std::endl;
    }

    // ------------------------------------------------------------------
    // SECTION 2 : increment/decrement grade
    // ------------------------------------------------------------------
    printSection("2. incrementGrade / decrementGrade");

    Bureaucrat middle("Charlie", 75);
    std::cout << "Avant : " << middle << std::endl;
    middle.incrementGrade();
    std::cout << "Apres incrementGrade : " << middle << std::endl;
    middle.decrementGrade();
    std::cout << "Apres decrementGrade : " << middle << std::endl;

    try
    {
        highGrade.incrementGrade(); // deja grade 1, ne peut pas monter davantage
    }
    catch (std::exception& e)
    {
        std::cout << "Exception attrapee (increment sur grade 1) : " << e.what() << std::endl;
    }

    try
    {
        lowGrade.decrementGrade(); // deja grade 150, ne peut pas descendre davantage
    }
    catch (std::exception& e)
    {
        std::cout << "Exception attrapee (decrement sur grade 150) : " << e.what() << std::endl;
    }

    // ------------------------------------------------------------------
    // SECTION 3 : AForm - creation et signature (beSigned)
    // ------------------------------------------------------------------
    printSection("3. Signature des formulaires");

    ShrubberyCreationForm shrubForm("home");
    std::cout << shrubForm << std::endl; // pas encore signe

    // Bureaucrat avec grade insuffisant pour signer (145 requis)
    Bureaucrat weakSigner("Weak", 150);
    try
    {
        shrubForm.beSigned(weakSigner);
    }
    catch (std::exception& e)
    {
        std::cout << "Signature refusee : " << e.what() << std::endl;
    }
    std::cout << "Etat apres tentative : " << shrubForm << std::endl;

    // Bureaucrat avec grade suffisant pour signer
    Bureaucrat strongSigner("Strong", 130);
    shrubForm.beSigned(strongSigner);
    std::cout << "Etat apres signature reussie : " << shrubForm << std::endl;

    // ------------------------------------------------------------------
    // SECTION 4 : Bureaucrat::executeForm - le coeur de l'exercice
    // ------------------------------------------------------------------
    printSection("4. executeForm : cas d'echec (formulaire non signe)");

    ShrubberyCreationForm unsignedForm("garden");
    Bureaucrat executor(strongSigner); // grade 130, suffisant pour executer (137 requis)
    // le grade 130 est en fait TROP BAS pour executer (il faut <=137, 130 est bon)
    // mais le formulaire n'est pas signe -> l'echec doit venir de la, pas du grade
    executor.executeForm(unsignedForm);

    printSection("5. executeForm : cas d'echec (grade insuffisant)");

    shrubForm.beSigned(strongSigner); // deja signe plus haut, on s'assure qu'il l'est
    Bureaucrat tooWeakToExecute("Intern", 150); // grade 150, largement insuffisant (137 requis)
    executor.executeForm(shrubForm); // on garde ce test pour comparaison
    tooWeakToExecute.executeForm(shrubForm);

    printSection("6. executeForm : cas de succes (ShrubberyCreationForm)");

    Bureaucrat gardener("Gardener", 100); // grade largement suffisant pour signer (145) et executer (137)
    ShrubberyCreationForm successShrub("office");
    gardener.executeForm(successShrub); // pas encore signe -> doit echouer
    successShrub.beSigned(gardener);
    gardener.executeForm(successShrub); // maintenant signe -> doit reussir + creer "office_shrubbery"

    // ------------------------------------------------------------------
    // SECTION 7 : RobotomyRequestForm - aspect aleatoire (50/50)
    // ------------------------------------------------------------------
    printSection("7. RobotomyRequestForm : succes/echec aleatoire");

    Bureaucrat robotomist("Robotomist", 40); // grade suffisant pour signer (72) et executer (45)
    RobotomyRequestForm robotForm("Bender");
    robotForm.beSigned(robotomist);
    robotomist.executeForm(robotForm); // premier essai
    robotomist.executeForm(robotForm); // second essai, pour voir les deux issues possibles

    // ------------------------------------------------------------------
    // SECTION 8 : PresidentialPardonForm
    // ------------------------------------------------------------------
    printSection("8. PresidentialPardonForm : cas de succes");

    Bureaucrat president("President", 1); // grade maximal, suffisant pour tout (25 et 5 requis)
    PresidentialPardonForm pardonForm("Zaphod's rival");
    pardonForm.beSigned(president);
    president.executeForm(pardonForm);

    // ------------------------------------------------------------------
    // SECTION 9 : AForm est abstraite -> ne compile pas si on essaie
    // ------------------------------------------------------------------
    printSection("9. AForm est une classe abstraite");
    std::cout << "AForm ne peut pas etre instanciee directement." << std::endl;
    std::cout << "La ligne suivante, si decommentee, provoque une erreur de compilation :" << std::endl;
    // AForm form("test", 10, 10); // decommenter pour verifier -> erreur de compilation attendue

    // ------------------------------------------------------------------
    // SECTION 10 : polymorphisme - un tableau de AForm* pointant vers
    // des formulaires concrets differents
    // ------------------------------------------------------------------
    printSection("10. Polymorphisme : executer plusieurs types via AForm*");

    ShrubberyCreationForm polyShrub("poly_target");
    RobotomyRequestForm polyRobot("poly_target");
    PresidentialPardonForm polyPardon("poly_target");

    AForm* forms[3] = { &polyShrub, &polyRobot, &polyPardon };
    Bureaucrat polyExecutor("PolyBoss", 1); // grade 1 = accepte tout

    for (int i = 0; i < 3; i++)
    {
        forms[i]->beSigned(polyExecutor);
        polyExecutor.executeForm(*forms[i]); // execute() est appelee de facon polymorphique
    }

    return 0;
}