//Search() returns 1 if Val is in TAB, 0 otherwise

//FAIRE LES CHOSES DANS CET ORDRE :
//1) ECRIRE LE CONTRAT DE LA FONCTION. 
//2) CODER LA FONCTION
//3) ESSAYER DE PROUVER ; EXPLIQUER POURQUOI CELA PROUVE OU POURQUOI CELA NE PROUVE PAS
//4) AU CAS OU CELA NE PROUVERAIT PAS, COMPLETER PAR CE QU'IL FAUT
//5) ARRIVER A 100% DE PREUVE

//Penser à mettre un commentaire en bout de ligne ACSL (comme pour les TPs précédents)

#define SIZE 100
int Tab[SIZE];



/*@ assigns \nothing;
  @ behavior Found:
  @  assume ;
  @  ensures ;
  @ behavior NotFound:
  @  assumes ;
  @  ensures ;
  @ complete ;
  @ disjoint ;
*/
int Search(int Val);
