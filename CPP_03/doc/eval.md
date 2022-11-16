# Scale for project CPP Module 03

### Introduction

Please comply with the following rules:

- Remain polite, courteous, respectful and constructive throughout the  
  evaluation process. The well-being of the community depends on it.

- Identify with the student or group whose work is evaluated the possible  
  dysfunctions in their project. Take the time to discuss and debate the  
  problems that may have been identified.

- You must consider that there might be some differences in how your peers  
  might have understood the project's instructions and the scope of its  
  functionalities. Always keep an open mind and grade them as honestly as  
  possible. The pedagogy is useful only and only if the peer-evaluation is  
  done seriously.

### Guidelines

- Only grade the work that was turned in the Git repository of the evaluated  
  student or group.

- Double-check that the Git repository belongs to the student(s). Ensure that  
  the project is the one expected. Also, check that 'git clone' is used in an  
  empty folder.

- Check carefully that no malicious aliases was used to fool you and make you  
  evaluate something that is not the content of the official repository.

- To avoid any surprises and if applicable, review together any scripts used  
  to facilitate the grading (scripts for testing or automation).

- If you have not completed the assignment you are going to evaluate, you have  
  to read the entire subject prior to starting the evaluation process.

- Use the available flags to report an empty repository, a non-functioning  
  program, a Norm error, cheating, and so forth.  
  In these cases, the evaluation process ends and the final grade is 0,  
  or -42 in case of cheating. However, except for cheating, student are  
  strongly encouraged to review together the work that was turned in, in order  
  to identify any mistakes that shouldn't be repeated in the future.

- You should never have to edit any file except the configuration file if it  
  exists. If you want to edit a file, take the time to explicit the reasons  
  with the evaluated student and make sure both of you are okay with this.

- You must also verify the absence of memory leaks. Any memory allocated on  
  the heap must be properly freed before the end of execution.  
  You are allowed to use any of the different tools available on the computer,  
  such as leaks, valgrind, or `e_fence`. In case of memory leaks, tick the  
  appropriate flag.

* * *

### Attachments

#### [subject.pdf](https://cdn.intra.42.fr/pdf/pdf/41486/fr.subject.pdf)

### Tests préliminaires

Si un cas de triche est suspecté, la notation et l'évaluation prennent fin immédiatement. Pour le signaler, sélectionnez le flag "Cheat". Faites attention à l'utiliser avec calme, précaution et discernement.

### Guidelines

Vous devez compiler avec clang++, with -Wall -Wextra -Werror  
Nous vous rapellons que ce projet est en C++98, et toute fonction/container des versions suivantes n'est pas attendue,  
et leur utilisation se soldera par un 0.

Ces points signifient que vous ne devez pas noter l'exercice demandé :
- Une fonction est implémentée dans un header (sauf pour les templates)
- Un Makefile compile sans les flags et/ou avec autre chose que clang++

Ces point signifient que vous devez tag le projet en "Fonction Interdite" :
- Utilisation d'une fonction "C" (\*alloc, \*printf, free)
- Utilisation d'une fonction interdite dans le projet
- Utilisation de "using namespace" ou de "friend"
- Utilisation d'une lib externe, ou des features des versions  
  postérieures a C++98

`Yes` -  `No`

* * *

### Ex00 : Eeeeet… ACTION !

Comme d'habitude, il doit y avoir assez de tests pour prouver que le programme fonctionne comme demandé. S'il n'y en a pas, ne notez pas cet exercice.

#### Classe et attributs

Il y a une classe ClapTrap.  
Elle possède tous les attributs privés suivants :  
- name  
- hit points  
- energy points  
- attack damage  
Ces attributs sont initialisés aux valeurs demandées.

`Yes` -  `No`

#### Fonctions membres

Les fonctions membres suivantes sont présentes et fonctionnent comme spécifié :  
- attack  
- takeDamage  
- beRepaired

`Yes` -  `No`

* * *

### Ex01 : Serena, mon amour !

Comme d'habitude, il doit y avoir assez de tests pour prouver que le programme fonctionne comme demandé. S'il n'y en a pas, ne notez pas cet exercice.

#### Classe et attributs

Il y a une classe ScavTrap.  
Le ScavTrap hérite publiquement de la classe ClapTrap.  
Elle ne redéclare pas les attributs.  
Les attributs de la classe ClapTrap sont désormais protégés et non plus  
privés.  
Les attributs sont initialisés aux valeurs demandées.

`Yes` -  `No`

#### Fonctions membres

Les fonctions membres suivantes sont présentes et fonctionnelles :  
- attack  
- takeDamage (héritée)  
- beRepaired (héritée)  

Les messages du constructeur, du destructeur, et de la fonction `attack()`  
doivent être différents de ceux du ClapTrap.

`Yes` -  `No`

#### Construction et destruction

Le ScavTrap doit avoir un constructeur et un destructeur avec des  
messages spécifiques.  

Leur bonne implémentation doit être démontrée par un chaînage des appels  
dans l'ordre attendu : si vous créez un ScavTrap, le message du constructeur  
du ClapTrap doit être affiché en premier, suivi de celui du ScavTrap.  
À l'inverse, si vous supprimez un ScavTrap, le message du destructeur du  
ScavTrap doit être affiché en premier, suivi de celui du ClapTrap.

`Yes` -  `No`

#### Caractéristique spéciale

Le ScavTrap possède une fonction `guardGate()` qui affiche un message sur  
la sortie standard.  
Le ScavTrap a également une fonction `attack()` qui affiche un message  
différent de celui du ClapTrap sur la sortie standard.

`Yes` -  `No`

* * *

### Ex02 : Travail à la chaîne

Comme d'habitude, il doit y avoir assez de tests pour prouver que le programme fonctionne comme demandé. S'il n'y en a pas, ne notez pas cet exercice.

#### Classe et attributs

Il existe une classe FragTrap qui hérite publiquement de ClapTrap.  
Les attributs ne doivent pas être redéclarés sans raison.

`Yes` -  `No`

#### Construction et destruction

Le FragTrap doit avoir un constructeur et un destructeur avec des  
messages spécifiques. 

Leur bonne implémentation doit être démontrée par un chaînage des appels  
dans l'ordre attendu : si vous créez un FragTrap, le message du constructeur  
du ClapTrap doit être affiché en premier, suivi de celui du FragTrap.  
À l'inverse, si vous supprimez un FragTrap, le message du destructeur du  
FragTrap doit être affiché en premier, suivi de celui du ClapTrap.

`Yes` -  `No`

#### Caractéristique spéciale

Le FragTrap possède une fonction `highFivesGuys()` qui affiche un message  
sur la sortie standard.  

Le FragTrap a également une fonction `attack()` qui affiche un message  
différent de celui du ClapTrap sur la sortie standard.

`Yes` -  `No`

* * *

### Ex03 : Ok, ça devient bizarre

Comme d'habitude, il doit y avoir assez de tests pour prouver que le programme fonctionne comme demandé. S'il n'y en a pas, ne notez pas cet exercice.

#### L'ultime étrangeté du C++

Il y a une classe DiamondTrap.  
Elle hérite à la fois du FragTrap et du ScavTrap.  
Elle définit les attributs avec les valeurs demandées.  
Elle utilise l'héritage virtuel pour éviter les pièges de l'héritage en  
diamant.

`Yes` -  `No`

#### Choisissez judicieusement...

La classe DiamondTrap utilise la fonction `attack()` du Scavtrap.  
Elle possède les fonctions spéciales de ses deux parents.  
La DiamondTrap possède un membre `privé std::string name`.  
La fonction `whoAmI()` a accès à la fois à name et à `clapTrap::name`.

`Yes` -  `No`
