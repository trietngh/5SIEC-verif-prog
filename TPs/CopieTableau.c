//La fonction doit copier les n premiers éléments du tableau T1 dans le tableau T2 
//FAIRE LES CHOSES DANS CET ORDRE :
//1) ECRIRE LE CONTRAT DE LA FONCTION. Penser à mettre un commentaire en bout de chaque ligne d'ACSL (comme pour les TPs précédents)
//2) CODER LA FONCTION
//3) ESSAYER DE PROUVER ; EXPLIQUER POURQUOI CELA PROUVE OU POURQUOI CELA NE PROUVE PAS
//4) AU CAS OU CELA NE PROUVERAIT PAS, COMPLETER PAR CE QU'IL FAUT
//5) ARRIVER A 100% DE PREUVE

//Penser à mettre un commentaire en bout de ligne ACSL (comme pour les TPs précédents)

/*@ requires n>0;                                                       //precondition: n must be strictly positive
  @ requires \valid(T1+(0..n-1)) && \valid(T2+(0..n-1));                //the n first elements of the two tables are accessible
  @ ensures \forall integer k; 0<= k < n ==> T2[k] == T1[k];            //postcondition: for all integer k between 0 and n, T2[k] must equal T1[k]
  @ assigns T2[0..(n-1)];                                               //the function can modify the space at the adresses of T2[0..(n-1)]      
*/
void CopieTab(int *T1, int *T2, int n) {
  /*@
    @ loop invariant I_RANGE_i: 0 <= i <= n;                                   //before and after each iteration, i must be between 0 and n
    @ loop invariant I_CHECK: \forall integer k; 0<=k<i ==> (T1[k] == T2[k]);  //before and after each iteration, for all k in [0,i), T2[k] must be equal to T1[k]
    @ loop assigns i,T2[0..(n-1)];                                             //in the loop, the function can only modify variable i and n first spaces of T2
    @ loop variant n-i;                                                        //the expression n-i must be strictly positive and decrease at each iteration to ensure loop termination
  */
  for (int i=0;i<n;i++) {
    T2[i]=T1[i];
  }
}

/*
EXPLICATION:
Dans le contrat de la fonction, on voudrais que pour tout k entre 0 et n-1, T2[k] = T1[k].
Or Frama-C n'est pas capable de prouver cela directement en raison de la boucle.
On écrit donc un invariant dans le contrat de boucle qui assure que :
- Avant et après chaque itération, pour k dans [0,i), T1[k]=T2[k] càd tous les éléments déjà passé est copié correctement.
Donc cela prouve que l'on écrit dans chaque case de 0 à n-1 de T2[] les élements de 0 à n-1 de T1[].
CQFD
*/