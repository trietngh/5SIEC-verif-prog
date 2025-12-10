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
  @ behavior NotFound:
  @   assumes \forall integer k; 0<=k<SIZE ==> Tab[k]!=Val; //first behavior, the value is not present in tab
  @   ensures \result == 0;                                 //the function must return 0
  @ behavior Found:
  @   assumes \exists integer k; 0<=k<SIZE && Tab[k]==Val;  //second behavior, the value is present in tab
  @   ensures \result == 1;                                 //the function must return 1
  @ complete behaviors NotFound, Found;                     //check if the two behaviors together are complete and without overlap
  @ disjoint behaviors NotFound, Found;                       
*/
int Search(int Val){
  int i = 0;
  int result = 0;

  /*@
    @ loop invariant I_RANGE_i: 0 <= i <= SIZE;                                                    //before and after each iteration, i must be between 0 and n
    @ loop invariant I_NOTFOUND: (\forall integer k; 0<=k<i ==> (Tab[k] != Val)) ==> result == 0;  //before and after each iteration, if for all k in [0,i), Tab[k] is not equal to Val then result == 0 (for NotFound Behaviour)
    @ loop invariant I_FOUND: (\exists integer k; 0<=k<i && (Tab[k] == Val)) ==> result == 1;      //before and after each iteration, if there exist an integer k in [0,i) such as Tab[k] equal Val then result == 1 (for Found Behaviour)
    @ loop assigns i,result;                                                                       //in the loop, the function can modify only variable i and variable result
    @ loop variant SIZE-i;                                                                         //the expression SIZE-i must be strictly positive and decrease at each iteration to ensure loop termination
  */
  while (i < SIZE){
      if (Tab[i] == Val){
        result = 1;
        return result;
      }
      i++;
  }
  return result;
}
