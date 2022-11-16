# Scale for project CPP Module 00

### Introduction

Veuillez respecter les règles suivantes:  
- Restez poli, courtois, respectueux et constructif pendant le processus  
d'évaluation. Le bien-être de la communauté repose là-dessus.
- Identifiez avec la personne (ou le groupe) évalué les éventuelles  
dysfonctionnements du travail. Prenez le temps d'en discuter et  
débatez des problèmes identifiés.
- Vous devez prendre en compte qu'il peut y avoir de legères différences  
d'interprétation entre les instructions du projet, son scope et ses  
fonctionnalités. Gardez un esprit ouvert et notez de la manière la plus  
honnête possible. La pédagogie n'est valide que si la peer-évaluation  
est faite sérieusement.

### Disclaimer

- Ne notez que ce qui est contenu dans le dossier git cloné de l'étudiant  
ou du groupe.

- Vérifiez que le dossier git de appartient bien à l'étudiant ou au groupe,  
que le projet correspond bien, et que "git clone" est utilisé sur un dossier vide.

- Vérifiez scrupuleusement qu'aucun alias n'a été utilisé pour vous tromper et assurez  
vous que vous corrigez bien le rendu officiel.

- Afin d'éviter toute surprise, vérifiez avec l'évalué les potentiels scripts  
utilisés pour faciliter l'évaluation.

- Si, en temps qu'évaluateur, vous n'avez pas fait le projet courant, vous devez  
lire le sujet en entier avant de commencer l'évaluation.

- Utilisez les flags disponibles pour signaler un rendu vide, un programme ne fonctionnant pas,  
une erreur de norme, un problème de triche... Dans ces situations, l'évaluation est terminée  
et la note est 0 (ou -42 en cas de triche). Cependant, à l'exception des cas de triche,  
vous êtes encouragés à continuer la discussion sur le travail rendu (même si pas terminé)  
pour identifier les problèmes qui ont causé cet échec et éviter de les reproduire dans le futur.

- Pendant toute la durée de l'évaluation, aucun segfault ou autre arrêt  
du programme (inattendu, prémature ou incontrôlé) ne sera toléré. Dans ces cas-là,  
la note finale est 0. Utilisez le flag approprié.  
Vous ne devriez jamais avoir à éditer un fichier mis à part un fichier de configuration,  
si celui-ci existe. Dans le cas ou vous souhaitez modifier un fichier, vous devez expliciter  
clairement les raisons de l'édition et entre en accord avec l'étudiant évalué avant de faire  
quoi que ce soit.

- Il vous revient également de vérifier l'absence de fuite mémoire. Toute mémoire allouée  
sur la heap doit être proprement libérée avant la fin de l'éxecution.  
Vous pouvez pour cela utiliser les différents outils présent sur l'ordinateur,  
tels que leaks, valgrind, ou encore e\_fence. En cas de fuite mémoire, cochez le flag approprié.

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

* * *

### Attachments

#### [subject.pdf](https://cdn.intra.42.fr/pdf/pdf/35337/fr.subject.pdf)

#### [Account.hpp](https://projects.intra.42.fr/uploads/document/document/6150/Account.hpp)

#### [19920104\_091532.log](https://projects.intra.42.fr/uploads/document/document/6151/19920104_091532.log)

#### [tests.cpp](https://projects.intra.42.fr/uploads/document/document/6152/tests.cpp)

### Ex00: Megaphone

Cet exercice est un échauffement pour découvrir les I/O en C++

#### Is it working ?

Cet exercice est juste un to\_upper avec un comportement spécifique quand lancé sans paramètre.  
Uniquement l'approche C++ (string/upper) est accepté.

`Yes` -  `No`

* * *

### Ex01: Mon super carnet de contacts

Cet exercice est une première approche pour écrire une classe simple et un programme interactif qui l'utilise. Si l'exercice ne fonctionne pas totalement, notez ce qui peut l'être.

#### Gestion d'erreur

Il y a un peu de gestion d'erreur a faire dans ce programme mais les comportements ne sont pas précisés dans le sujet.

`Rate it from 0 (failed) through 5 (excellent)`

* * *

#### La commande EXIT

Notez la commande `EXIT` par rapport à ce qui est demandé dans le sujet

`Yes` -  `No`

#### Visibilité

Les attributs de la classe Contact doivent être privées  
et la classe doit exposer les accesseurs correspondants.  
Vérifiez également que tout ce qui n'est utilisé que dans  
la classe est privé, et le reste public.  
Les débutants on tendance à tout mettre en public,  
c'est ce que vous devez vérifier ici.

`Rate it from 0 (failed) through 5 (excellent)`

* * *

#### La classe Contact et Phonebook

Le code doit inclure une classe Contact (ou autre nom).  
La classe doit contenir les attributs demandés.  
Le code doit contenir une classe Phonebook avec un tableau de  
contacts à l'intérieur.

`Yes` -  `No`

#### boucle de Read/Eval

Le programme doit proposer une boucle read/eval :  
Lecture d'input, analyse, et loop jusqu'à croiser une  
commande `EXIT`.  
La lecture devrait être en C++ ! (std::cin)

`Yes` -  `No`
#### La commande ADD

Notez la commande `ADD` comme demandé dans le sujet.

`Rate it from 0 (failed) through 5 (excellent)`

* * *

#### La commande SEARCH

Notez la commande `SEARCH` comme demandé dans le sujet. Une légère divergence dans le format attendu n'est pas importante.
Cette partie vise à utiliser les `iomanips` de C++ et c'est ce sur quoi vous devez vous concentrer.

`Rate it from 0 (failed) through 5 (excellent)`

* * *

* * *

### Ex02: Le boulot de vos rêves

Le but de cet exercice est de récupérer les informations cachées au milieu du bruit

#### Avez-vous sauvé le monde ?

Cet exercice est plutôt simple. Soit Account.cpp marche, ou il ne marche pas.  
La moindre différence mis à part le timestamp est un indice que quelque chose n'a  
pas marché.

`Yes` -  `No`
