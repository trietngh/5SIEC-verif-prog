Les TP donnent lieu à un examen. Ce qui est demandé figure en en-tête de chaque fichier C.
Cela consiste :
	- à développer (spécification formelle, code) à partir du contenu initial de chaque fichier C.
	- à fournir les explications demandées sous forme de commentaires dans le fichier C.

Le contrôle (examen) se fera sur la base :
	- Du contenu des fichiers C (incluant les explications en commentaires)
	- Des résultats de l'outil de preuve passé sur les fichiers C.

Chaque binôme devra donc fournir par email à jean.souyris@airbus.com :
	- les fichiers C
	- les fichiers résultats de preuve.

ORDRE DES TP:
	1- Confirmateur
	2- Init
	3- AreTabSame
	4- CopieTableau 
	5- Maxn
	6- InitMatrix

Le travail se fait sous Linux.

REALISATION DES TPs:

	1- ALLER dans le dossier TPs
	2- A faire en début de chaque séance de TP : ./frama-c_env
	3- A ne faire qu'une seule fois pour toutes les séances de TP : why3 config detect
	4- Lancer les preuves : ./proof.sh <nom de fichier>.c. Exemple : ./proof.sh init.c
