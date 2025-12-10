//La fonction doit retourner 1 si les n premiers éléments des tableaux T1 et T2 sont égaux, ou 0 dans le cas contraire. 
//FAIRE LES CHOSES DANS CET ORDRE :
//1) ECRIRE LE CONTRAT DE LA FONCTION. Penser à mettre un commentaire en bout de chaque ligne d'ACSL (comme pour les TPs précédents)
//2) CODER LA FONCTION
//3) ESSAYER DE PROUVER ; EXPLIQUER POURQUOI CELA PROUVE OU POURQUOI CELA NE PROUVE PAS
//4) AU CAS OU CELA NE PROUVERAIT PAS, COMPLETER PAR CE QU'IL FAUT
//5) ARRIVER A 100% DE PREUVE

//Penser à mettre un commentaire en bout de ligne ACSL (comme pour les TPs précédents)

/*@ requires n>0;                                         //precondition, n must be superior to 0
  @ requires \valid(T1+(0..n-1));                         //the n first elements of the two tables are accessible
  @ requires \valid(T2+(0..n-1)); 
  @ assigns \nothing;                                     //the function does not modify any memory space
  @ behavior SAME:
  @   assumes \forall integer k; 0<=k<n ==> T1[k]==T2[k]; //first behavior, if the n first elements of each tab ar equal, then the function must return 1
  @   ensures \result == 1;
  @ behavior DIFF:
  @   assumes \exists integer k; 0<=k<n && T1[k]!=T2[k];  //second behavior, if two parallel elements in the n first elements of each tab are not equal, then the function must return 0
  @   ensures \result == 0;
  @ complete behaviors SAME, DIFF;                        //check if the two behaviors together are complete and without overlap
  @ disjoint behaviors SAME, DIFF;
*/
_Bool AreTabSame(int *T1, int *T2, int n) {
    int i = 0;
    _Bool result = 1;
    /*@
      @ loop invariant I_RANGE_i: 0 <= i <= n;                                                    //before and after each iteration, i must be between 0 and n
      @ loop invariant I_SAME: (\forall integer k; 0<=k<i ==> (T1[k] == T2[k])) ==> result == 1;  //for each postcondition for the function, we write an equivalent for the loop, here for behavior SAME
      @ loop invariant I_DIFF: (\exists integer k; 0<=k<i && (T1[k] != T2[k])) ==> result == 0;   //equivalent to behavior DIFF for the loop
      @ loop assigns i,result;                                                                    //in the loop, the function can modify only variable i and variable result
      @ loop variant n-i;                                                                         //the expression n-i must be strictly positive and decrease at each iteration to ensure loop termination
    */
    while (i < n && result) {
      if (T1[i] != T2[i]) {
        result = 0;
      }
      i++;
    }
    return result;
}

/*
EXPLICATION PREUVE :
  dans la fonction :
    on vérifie que tous les éléments des deux tableaux sont accessibles
    on vérifie que si tous les elements du tableaux sont les mêmes, le résultat est true
    on vérifie que
  dans la boucle :
CQFD
*/