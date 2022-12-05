/*



*/


#define A 2
#define B 3
#define C 4
#define D 5
#define E 6
#define F 7
#define G 8
#define DP 9

byte cont = 0;
int tempo = 1000;
char caractere = 'y';

const byte tabela_7seg[26][7] = 
{ //A B C D E F G
  { 1,1,1,1,1,1,0},	//0
  { 0,1,1,0,0,0,0}, //1
  { 1,1,0,1,1,0,1},	//2
  { 1,1,1,1,0,0,1}, //3 
  { 0,1,1,0,0,1,1},	//4
  { 1,0,1,1,0,1,1},	//5
  { 1,0,1,1,1,1,1}, //6
  { 1,1,1,0,0,0,0},	//7
  { 1,1,1,1,1,1,1}, //8
  { 1,1,1,1,0,1,1}, //9
  { 1,1,1,0,1,1,1}, //A
  { 1,1,1,1,1,1,1}, //B
  { 1,0,0,1,1,1,0}, //C
  { 1,1,1,1,1,1,0}, //D
  { 1,0,0,1,1,1,1}, //E
  { 1,0,0,0,1,1,1}, //F
  { 1,0,1,1,1,1,1}, //G
  { 0,1,1,0,1,1,1}, //H
  { 0,1,1,0,0,0,0}, //I
  { 0,1,1,1,1,0,0}, //J
  { 0,0,0,1,1,1,0}, //L
  { 1,1,1,1,1,1,0},	//O
  { 1,1,0,0,1,1,1},	//P
  { 1,0,1,1,0,1,1},	//S
  { 0,1,1,1,1,1,0},	//U
  { 1,1,0,1,1,0,1},	//Z
};

void converteValorDisplay(byte valor){
  byte pino = 2;
 
  for(byte x = 0;x<7;x++){
    digitalWrite(pino,tabela_7seg[valor][x]);
    //delay(1000);
    pino++;
  }
}

void setup()
{
  pinMode(A, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(C, OUTPUT);
  pinMode(D, OUTPUT);
  pinMode(E, OUTPUT);
  pinMode(F, OUTPUT);
  pinMode(G, OUTPUT);
  pinMode(DP, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  //dado
  
     if(Serial.available()) { 
        Serial.println("Lançar dado ? y");
        Serial.println("Mostrar numeros ? n");
        Serial.println("Mostrar letras ? l");
        caractere = Serial.read(); // Armazena caractere lido
        Serial.println(caractere);
          if ( caractere == 'y' ) {
          for(int i = 0; i < 8; i++){
                              converteValorDisplay(random(6));
                              delay(tempo);
                            }
                        //converteValorDisplay(cont);
                        caractere = 'n';
                    
          }else if ( caractere == '*' ){
            //numeros 
              for(cont = 0; cont<10; cont++){
                converteValorDisplay(cont);
                delay(tempo);
              }
             
          caractere = '*';
          }else if ( caractere == 'l' ){
             //letras
           for(cont =10; cont<26; cont++){
                converteValorDisplay(cont);
                delay(tempo);
              }
              
          caractere = '*';
          }
    }
    
}

