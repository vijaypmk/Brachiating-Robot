int A,B,C,D,E,F,G; //motor pins
int X,Y;  //magnet pins
int M1=0,M2=0;//flag variables
int M,N,O;//delay

void setup()
{  
B=13;
D=12;
F=11;
C=10;
E=9;
G=8;
X=5;
Y=4;
  pinMode(A,INPUT);  
  digitalWrite(A,1);
  pinMode(B,OUTPUT);  //motor for arm 1 
  pinMode(C,OUTPUT);
  pinMode(D,OUTPUT);  //main motor at the middle (3)
  pinMode(E,OUTPUT);
  pinMode(F,OUTPUT);  //motor for arm 2
  pinMode(G,OUTPUT);
  pinMode(2,INPUT);
  attachInterrupt(0, magnet1, RISING);//ISR called when pin 2 goes from low to high
  pinMode(3, INPUT);
  attachInterrupt(1, magnet2, RISING);//ISR called when pin 3 goes from high to low
  pinMode(X,OUTPUT); //pin for electromagnet 1
  pinMode(Y,OUTPUT); //pin for electromagnet 2
  int M=1000;
  int N=100;
}

void magnet1()  //fixing arm 1 to be stationary
{
  digitalWrite(X,1);
  digitalWrite(B,0);
  digitalWrite(D,0);
  digitalWrite(F,0);
  M1=1;
}

void magnet2()  //fixing arm 2 to be stationary
{
  digitalWrite(Y,1);
  digitalWrite(B,0);
  digitalWrite(D,0);
  digitalWrite(F,0);
  M2=1;
}

void loop()
{
  if(M1==1)
  {
    delay(500);
    M1=0;
  }
  
  if(M2==0)
  {
    delay(500);
    M2=0;
  }
  
    digitalWrite(G,0);
    digitalWrite(C,0);
    digitalWrite(E,0);
    digitalWrite(B,1);
    delay(M);
    digitalWrite(D,1);
    delay(N);
    digitalWrite(F,1);
    delay(O);
  }
