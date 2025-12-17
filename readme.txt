

2)
  - Lancer l'analyse de valeur avec l'interface graphique :

  - Dans la fonction main(), analyser le fonctionnement de l'outil pour traiter les malloc :

    le malloc pourrait rendre une valeur nulle mais cela n'est jamais vérifier -> risque!

  - Dans la fonction main(), tous les blocs sont-ils couverts ? Pourquoi ? :
    
    StartVM -> contient un while(1) sans break -> on ne sort jamais de la loop!
    donc le return de la fonction main() n'est jamais atteint, tous les blocs ne sont donc pas couvert.

3) Fonction CallBackGetProgramByte, prendre connaissance et analyser les warnings relatifs à cette fonction :
    ligne 98,framaC émet le warning : /*@ assert Eva: index_bound: address < 72; */
    ->selon framaC,le code ne vérifie pas si la valeure mise en entrée de la fonction est plus graand que la taille du tableau
    or, la fonction le fait avec la ligne 96 : 	if( address > sizeof(program) ) return ERROR_PROGRAM_FETCH;

4) Faire fix ou modifs de code pour faire disparaître les warnings relatifs aux malloc()
  - soit en traitant dans le code le cas ou malloc retourne NULL
  - soit en paramétrant le comportement de malloc de l'outil pour qu'il ne renvoit jamais NULL (option -eva-no-alloc-returns-null)

    on modifie le code pour que le cas "malloc return NULL" soit traité,->la fonction s'arrete quand malloc renvoie NULL

    if((pStringFifo = malloc( STRINGFIFOSIZE ))==NULL) {
		return;
	}
	if((pCallStack  = malloc( CALLSTACKDEPTH*4 ))==NULL) {
		return;
	}
	if((pVarArray   = malloc( MAXVARS*4 ))==NULL) {
		return;
	}

    On relance FramaC et on a une érreure en moins! 69->68

5)Essayer d'autres niveaux de slevel. Jusqu'à 10000. Expliquer les différences (temps d'analyse, nb de warnings ...).

frama-c -lib-entry -absolute-valid-range  0-0xFFFFFFFF  -metrics-value-cover -eva -p
p-annot -cpp-command "gcc -C -E -DLINUX -LRobotSeeVM_v0001" RobotSeeVM_v0001/*.c -slevel 1000

[metrics] Statements analyzed by Eva
  --------------------------
  441 stmts in analyzed functions, 428 stmts analyzed (97.1%)

  match = re.search(r"stmts analyzed (\s+\(([\d.]+)%\)", result.stdout)