//TP2: initialisation des n premiers éléments d'un tableau à 0
//Objectifs du TP: 
//      - Analyse d'un contrat ACSL: analyse de chaque ligne ACSL à mettre en bout de ligne sous forme de commentaire.
//      - codage de la fonction InitWithZero à partir de l'ACSL
//      - preuve

#define SIZE_MAX 1000

/*@
  @ requires R1: 0<n && n < SIZE_MAX; //in the pre_state, the entry n must be : strictly positive and inferior to the constant SIZE_MAX
  @ requires R2: \valid(t+(0..n-1));  //in the pre_state, the memory space at address t[0] to t[n-1] must be accessible
  @ ensures E1: \forall integer k; 0<=k<n ==> t[k]==0;//for all integer k between 0 and n, in the post_state, t[k] must equal 0
  @ assigns t[0..(n-1)]; //the function can modify the space at the adresses of t[0..(n-1)]
*/
void InitWithZero(int *t, int n) {
	int i;
	/*@
	  @ loop invariant I_RANGE_i: 0 <= i <= n; //before and after each iteration, i must be between 0 and n
	  @ loop invariant I_E1: \forall integer k; 0<=k<i ==> t[k]==0; //before and after each iteration, for all k between 0 and i, t[k] must be equal to 0
	  @ loop assigns i, t[0..(n-1)]; //in the loop, the function can access to and modify only these memory spaces(variable i, spaces 0 to n-1 of tableau t[])
	  @ loop variant n-i;// the expression n-i must be strictly positive and decrease at each iteration to ensure loop termination
	*/
	for(i=0;i<n;i++){
		t[i] = 0;
	}
}
