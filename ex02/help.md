CONCRETEMENT : bureaucratie fictive btwn 2 entités qui interagissent :

1 bureaucrat = individu w/ 1 nom et 1 grade (1 = best grade, 150 = pire grade). + le grade est bas (proche de 1) + l'individu a de pv.

1 formulR (AForm) = doc administratif ayant bes1 de 2 choses pr être traité : 

                être signé par qlq1 d'assez gradé (_gradeToSign)
                être executé par qlq1 d'assez gradé (_gradeToExecute)

NB : signer et exécuter = 2 actions distinctes avec des seuils de grade différents

1 form peut très b1 être signé par qlq1 mais nécessiter qlq1 d'1 rang encore + élevé pr être reellement executé -> 2 étapes différentes

Si une de ces 2 condit. échoue, l'exec doit être refusée et une exception adaptée doit être levée pr préciser.

Dualité btwn signature ≠ execution


OBJECTIF EXO :

Créer une classe abstraite AForm qui sert de classe mère à plusieurs formulR


CARACTERISTIQUES COMMUNES DES FORMS :
- 1 nom
- 1 grade nécessR pr être signé
- 1 grade nécessR pr être exécuter
- un état : signé / non signé



Les 3 formulR héritent de AForm (exemple : ShruberryCReationForm = un AForm particulier) -> ils récupèrent les éléments comm1 de AForm tt en possédant leur propre version de execute()



PROCESS DE LA SIGNATURE D'1 FORM : boss.signForm(shrub);

Bureaucrat::signForm()
            ↓
AForm::beSigned()
            ↓
vérif du grade
            ↓
 _isSigned = true


PROCESS EXEC. D'1 FORM : boss.executeForm(shrub);
Bureaucrat::executeForm()
        ↓
AForm::execute()
        ↓
ShrubberyCreationForm::execute()
        ↓
checkRequirements() | +--> signé ? | +--> grade suffisant ?
        ↓
création du file



EXCEPTIONS VS IF :

avce if -> bes1 de vérif partout et tt le temps -> si oublie : erreur passe silencieusement inaperçue

NB : un constructeur n'a aucune valeur de retour





RAPPEL CONST :
const int _gradeToSign; -> ne peut ps etre modif apres sa construct.
int getGrade() const; -> la méthode ne modifie ps l'objet

RAPPEL RÉFÉRENCE :
accéder a l'objet original sans le copier 







