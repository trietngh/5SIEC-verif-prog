//Initialisation des n premiers éléments d'une matrice à 0
//Objectifs du TP: 
//      - Analyse d'un contrat ACSL: analyse de chaque ligne ACSL à mettre en bout de ligne sous forme de commentaire.
//      - codage de la fonction InitWithZero à partir de l'ACSL
//      - preuve

/*@
  @ requires R1: n > 0 && m > 0 ;                                       //requires that input n and m are strictly positive      
  @ requires R2: \valid(mat+(0..n-1));                                  //requires the list of n pointers to each row of the matrix are accessible
  @ requires R3: \forall integer i; 0<=i<n ==> \valid(mat[i]+(0..m-1)); //requires that m elements of each row of the matrix are accessible
  @ assigns  A1: mat[0..n-1][0..m-1];
  @ ensures \forall integer i,j; (0<=i<n && 0<=j<m) ==> (mat[i][j] == 0);
*/
void InitMatWithZero(int **mat, int n, int m) {
  /*@
    @ loop invariant N_RANGE_i: 0 <= i <= n;                                                 //before and after each iteration, i must be between 0 and n
    @ loop invariant N_CHECK: \forall integer k,l; (0<=k<i && 0<=l<m) ==> (mat[k][l] == 0);  //before and after each iteration, for all k in [0,i), and l between 0 and m, mat[k][l] must be zero 
    @ loop assigns N_ASSIGN: i, mat[0..n-1][0..m-1];                                         //in the loop, the function can access to and modify only variable i, and the whole matrix mat (a list of n pointers to each row of m elements to be precised)
    @ loop variant n-i;                                                                      //the expression n-i must be strictly positive and decrease at each iteration to ensure loop termination
  */
  for (int i = 0; i < n; i++){
    /*@
      @ loop invariant M_RANGE_i: 0 <= j <= m;                                                                            //before and after each iteration, j must be between 0 and m
      @ loop invariant M_CHECK: \forall integer l; 0<=l<j ==> (mat[i][l] == 0);                                           //before and after each iteration, for all l in [0,j), mat[i][l] must be equal to 0 -> verify that the elements are put to 0 
      @ loop invariant M_LIGNE_COMPLETE: \forall integer k; 0<=k<i ==> (\forall integer l; 0<=l<m ==> (mat[k][l] == 0));  //before and after each iteration, far all k in [0,i) and l in [0,m), mat[k][l] must be equal to 0 -> verify that the lignes before are completly put to 0
      @ loop assigns M_ASSIGN: j, mat[i][0..m-1];                                                                         //in the loop, the function can access to and modify only variable i and m elements of the current row mat[i]
      @ loop variant m-j;                                                                                                 //the expression m-j must be strictly positive and decrease at each iteration to ensure loop termination
    */
    for (int j = 0; j < m; j++){
      mat[i][j] = 0;
    }
  }
  return;
}