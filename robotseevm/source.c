

typedef struct {
  int a;
  int b;
  char tab1[10];
  char padd1[2];
} T_STR1;



/*@ ensures \result==-1 || \result==0 ;
  @ behavior b_ok:
  @   assumes 0<=msg.a<10 && -10<=msg.b<=0 && msg.a!=msg.b;
  @   ensures \result == 0 ;
  @ behavior b_ko:
  @   assumes !(0<=msg.a<10) || !(-10<=msg.b<=0) || msg.a==msg.b;
  @   ensures \result == -1 ;
  @*/
int f_filter1(T_STR1 msg)
{
  if (msg.a<0) return -1 ;
  if (msg.a>=10) return -1 ;
  if (msg.b<-10) return -1 ;
  if (msg.b>0) return -1 ;
  if (msg.a == msg.b) return -1 ;

  return 0;
}


/*@ ensures \result==-1 || \result==0 ;
  @ ensures !(0<=msg.a<10)   ==> \result == -1;
  @ ensures !(-10<=msg.b<=0) ==> \result == -1;
  @ ensures (msg.a==msg.b)   ==> \result == -1;
  @*/
int f_filter2(T_STR1 msg)
{
  if (msg.a<0) return -1 ;
  if (msg.a>=10) return -1 ;
  if (msg.b<-10) return -1 ;
  if (msg.b>0) return -1 ;
  if (msg.a == msg.b) return -1 ;

  return 0;
}



int f_filter4(T_STR1 msg)
{
  if (msg.a<0) return -1 ;
  if (msg.a>=10) return -1 ;
  if (msg.b<-10) return -1 ;
  if (msg.b>0) return -1 ;
  if (msg.a == msg.b)
    {
      return -1 ;
    }

  //@ assert 0<=msg.a<10;
  //@ assert -10<=msg.b<=0;
  //@ assert msg.a!=msg.b;
  //@ assert 0<=msg.a<8;

  return 0;
}



int v;
T_STR1 msg1;
void main(void)
{

  switch(v)
    {
    case 1:
      f_filter1(msg1);
      break;
      
    case 2:
      f_filter2(msg1);
      break;
    case 3:
      f_filter4(msg1);
      break;
      
    }
}
