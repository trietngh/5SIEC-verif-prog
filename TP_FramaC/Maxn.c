//La fonction doit retourner la plus grande valeur du tableau T, pour ls indices entre 0 et n-1.

//FAIRE LES CHOSES DANS CET ORDRE :
//1) ECRIRE LE CONTRAT DE LA FONCTION
//2) CODER LA FONCTION
//3) ESSAYER DE PROUVER ; EXPLIQUER POURQUOI CELA PROUVE OU POURQUOI CELA NE PROUVE PAS
//4) AU CAS OU CELA NE PROUVERAIT PAS, COMPLETER PAR CE QU'IL FAUT
//5) ARRIVER A 100% DE PREUVE

//Penser à mettre un commentaire en bout de ligne ACSL (comme pour les TPs précédents)

/*@ requires n>0;                                           //n must be strictly positive
  @ requires \valid(T+(0..n-1));                            //T[0] to T[n-1] must be accessible
  @ assigns \nothing;                                       //The function don't modify anything outside
  @ ensures \forall integer k; 0<=k<n ==> T[k] <= \result;  //The result must be greater or equal to all elements of T from T[0] to T[n-1]
  @ ensures \exists integer k; 0<=k<n && (T[k] == \result); //There exist at least one element of T between 0 and n-1 equal to the result
*/
int Maxn(int *T, int n){
  int i = 1;
  int max = T[0];
  /*@
    @ loop invariant I_RANGE_i: 0 <= i <= n;                                   //before and after each iteration, i must be between 0 and n
    @ loop invariant I_MAX: \forall integer k; 0<=k<i ==> (T[k] <= max);       //before and after each iteration, for all k between 0 and i, T[k] must be inferior or equal to max
    @ loop invariant I_MAX_EXIST: \exists integer k; 0<=k<i && (T[k] == max);  //before and after each iteration, there exist an integer k between 0 and i such as T[k] equal max
    @ loop assigns i,max;                                                      // in the loop, the function can access to and modify only these memory spaces(variable i, n first spaces of T2)
    @ loop variant n-i;                                                        // the expression n-i must be strictly positive and decrease at each iteration to ensure loop termination
  */
  while (i < n){
    if (T[i] > max){
      max = T[i];
    }
    i++;
  }
  return max;
}

/*
EXPLICATION PREUVE :
  contrat fonction :
    on verifie que le resultat correspond à une case du tableau et que toutes les cases sont inf ou égales au résultat
  contrat boucle :
    au sein de la boucle, on revérifie qu'avant ou après tt itérations, le résultat est égal à la valeure d'un élément évalué et
    que tous les éléments évalués sont inf ou égale au résultat
CQFD
*/