//TP1: Réalisation d'un confirmateur
//Objectifs du TP: 
//	- Analyse d'un contrat ACSL: analyse de chaque ligne ACSL à mettre en bout de ligne sous forme de commentaire
//	- codage de la fonction confirmateur à partir de l'ACSL
//	- preuve

//Entrée:
_Bool E;

//Sortie:
_Bool S;

//Compteur (état interne) = nombre de ticks d'une horloge temps-réel
static unsigned int Cpt;

//Temps de confirmation (configuration) en nombre de de ticks de la même horloge temps-réel
extern unsigned int ConfTime;


/*@
  @ requires ConfTime >= 1;                 //precondition: ConfTime must be at least 1 at function entry
  @ assigns S, Cpt;                         //function can only modify these folowing memory spaces ( Global variables Cpt, S)
  @ behavior OutputSetTo1:                  //first behavior: case when output S is equal to 1  
  @   assumes E == 1 && Cpt >= ConfTime;    //in the Pre_State, if E equal 1 and Cpt superior or equal to ConfTim
  @   ensures Output: S == 1;               //then, in the Post_State, The function must return S eaqual to 1
  @   ensures Cpt == \old(Cpt) + 1;         //then, in the Post_State, the Cpt must be actualise (+1)
  @   assigns S, Cpt;                       //redondant to the whole function assigns, to be changed?
  @ behavior OutPutSetTo0Input0:            //second behavior: case when input E is equal to 0 and output S is equal to 0
  @   assumes E == 0;                       //behaviour's entry condition: if E is equal to 0
  @   ensures S == 0;                       //then, the function must return S equal to 0 
  @   ensures Cpt == 0;                     //also, the function must reset Cpt to 0
  @   assigns S, Cpt;                       //same as above, the assigns for this behavior is redondant to the whole function assigns
  @ behavior OutPutSetToInput1NotConfirmed: //third behavior: case when input E is equal to 1 but confirmation time not yet reached
  @  assumes E == 1 && Cpt < ConfTime;      //behaviour's entry condition: if E equal 1 and Cpt inferior to ConfTime
  @  ensures S == 0;                        //then, the function must return S equal to 0  
  @  ensures Cpt == \old(Cpt) + 1;          //then also, the Cpt must be actualise (+1) 
  @  assigns S, Cpt;                        //redundant
  @
  @ complete behaviors OutputSetTo1, OutPutSetTo0Input0, OutPutSetToInput1NotConfirmed; //verify that the OR of the three behaviour together is TRUE, the behaviours cover the all possibilities
  @ disjoint behaviors OutputSetTo1, OutPutSetTo0Input0; //verify that the behaviours don't have conflicts between them
  @ disjoint behaviors OutPutSetTo0Input0, OutPutSetToInput1NotConfirmed;
  @ disjoint behaviors OutputSetTo1, OutPutSetToInput1NotConfirmed; //do this for each pair of behaviours
*/

void Conf(void) {
  if (E==1 && Cpt>=ConfTime){
    S = 1;
    Cpt++;
  } else if (E==1 && Cpt<ConfTime){
    S = 0;
    Cpt++;
  }
  else {
    S = 0;
    Cpt = 0;
  }
}
