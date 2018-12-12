#include <SimpleSDAudio.h>

int Y0 = 6; 
int Y1 = 5; 
int Y2 = 7; 
int Y3 = 3;
int Y4 = 2; 
int Y7 = 8; 

int v0 = 0; 
int v1 = 0;
int v2 = 0;
int v3 = 0;
int v4 = 0;
int v7 = 0;
int V = 0;

int Enter = 10; 

int Demulti[8]; 
boolean b = false;
int x = 0;

void setup() {
  pinMode(Y0, INPUT);
  pinMode(Y1, INPUT);
  pinMode(Y2, INPUT);
  pinMode(Y3, INPUT);
  pinMode(Y4, INPUT);
  pinMode(Y7, INPUT);
  pinMode(Enter, INPUT_PULLUP);
  
  
  Serial.begin(9600); 
}

void loop() {
  
  
  v0 = digitalRead(Y0); 
  v1 = digitalRead(Y1);
  v2 = digitalRead(Y2);
  v3 = digitalRead(Y3);
  v4 = digitalRead(Y4);
  v7 = digitalRead(Y7); 
  V = digitalRead(Enter);

 
    static String bin;
    
    
    Demulti[0] = v0; 
    
    
    Demulti[1] = v1;
    
    Demulti[2] = v2;
    
    Demulti[3] = v3;
    
    Demulti[4] = v4;
    
    Demulti[5] = v7;
    bin = String(String(Demulti[0]) + String(Demulti[1])+ String(Demulti[2]) + String(Demulti[3]) + String(Demulti[4]) + String(Demulti[5]));
    Serial.println(bin);
    
    
  
 
  
  
  
  
  

}
