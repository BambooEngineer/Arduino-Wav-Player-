#include <SimpleSDAudio.h>

int Y0 = 6; // Arduino Pins connected to the Output Pins of the Demultiplexer IC 
int Y1 = 5; // THERE ARE 43 SOUND FILES THAT CAN BE ACCESSED WITH THE IC CHIP(Only 6 pins needed = 101011), but the arduino kept givin problems with the amount of possible CODES over 19 so I just kept it at exactly 19 
int Y2 = 7; 
int Y3 = 3;
int Y4 = 2; 
int Y7 = 8; 
            

int v0 = 0; // digitalRead() values 
int v1 = 0;
int v2 = 0;
int v3 = 0;
int v4 = 0;
int v7 = 0;
int V = 0; // Button value
int v = 0; 

int Enter = 10; // Button for storing binary digital pin values into strings(a,B,c,d,e,f)


boolean b = false; // Turns Code analysis off and on
int x = 0;
static int X; 

String a; 
String B; 
String c; 
String d;
String e;
String f;

int servo = A5; // Servo analog pin                
int vv = 0; // analog pin value
static boolean bb = false; // booleans for Servo activity
static boolean cc = false;
static int xx; // Ints for basically telling the Servo how far to the Right or Left to move
static int XX;




void setup() {            
  Serial.begin(9600); 
  pinMode(Y0, INPUT); // Demultiplexer digital Pins
  pinMode(Y1, INPUT);
  pinMode(Y2, INPUT);
  pinMode(Y3, INPUT);
  pinMode(Y4, INPUT);
  pinMode(Y7, INPUT);
  
  pinMode(Enter, INPUT_PULLUP); // Button 
  pinMode(servo, OUTPUT);    
//////////////////////////////////////////////////////////////////////////////////
SdPlay.setSDCSPin(4); // SD Card Chip Select Pin

if (!SdPlay.init(SSDA_MODE_FULLRATE | SSDA_MODE_MONO | SSDA_MODE_AUTOWORKER)) // Sets SD Modes

{ while(1); }
//////////////////////////////////////////////////////////////////////////////////
  
}

void loop() {
  s(); // Default Servo position function
  V = digitalRead(Enter); 
  String CODE; // Storage for all of the Demultiplexer Variables making one Binary formatted String
  
  if(cc == true){     // If a certain CODE is analyzed
  S(); // Moves Servo
  }
  
  if(X == 1){ // Enables PT files to play which disables the programming of another CODE intill the files are done playing
    PT();
  }

  if(V == LOW){
   ++x; // Increments x
   delay(1500); // Debounces so x isnt incremented more then once per button press
  }
  
  if(x == 1){
    Serial.println("Started"); // Starts the programming of CODE
    
  }
  if(x == 2){
      v0 = digitalRead(Y0); // Senses the Demultiplexer pin to see if its a 1 or a 0, then stores that value as the first LETTER in the CODE STRING, this pattern continues intill the 5th letter is stored 
      Serial.println(v0);
      a = String(v0);
      Serial.println("Program 0");
      
      
    }
  if(x == 3){
      v1 = digitalRead(Y1); 
      Serial.println(v1);
      B = String(v1);
      Serial.println("Program 1");
      
      
     
    }
    if(x == 4){
      v2 = digitalRead(Y2); 
      Serial.println(v2);
      c = String(v2);
      Serial.println("Program 2");
      
      
      
    }
    if(x == 5){
      v3 = digitalRead(Y3); 
      Serial.println(v3);
      d = String(v3);
      Serial.println("Program 3");
      
      
    }
    if(x == 6){
      v4 = digitalRead(Y4); 
      Serial.println(v4);
      e = String(v4);
      Serial.println("Program 4");
      
      
    }
    if(x == 7){
      v7 = digitalRead(Y7); // After the last letter is Stored b becomes true while x stays equal to 7 
      Serial.println(v7);
      f = String(v7);
      Serial.println("Program 7");
      b = true; 
    }
  if(b){  // CODE is then analyzed and plays a WAV file based on if a corresponding CODE exists 
    CODE = String(a+B+c+d+e+f);
    Serial.println(CODE);  
    delay(1000);  // If the programming button is pushed after CODE is analyzed, it RESETS b to false and x to 0 for another CODE to be created
    if(V == LOW){
      b = false;
      x = 0;
      }
    } 
  
    
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////Binary Numbers with funny WAV files from the SD card
    if(CODE == "111110"){ // If this is the Code
      if(!SdPlay.setFile("Alex.wav")) // Then Play this  
      { while(1); }
      SdPlay.play(); 
      while(!SdPlay.isStopped() && b == true) 
      { ; }
      
    }
    if(CODE == "110000"){ 
      if(!SdPlay.setFile("Dragon.wav")) 
      { while(1); }
      SdPlay.play(); // Play File
      while(!SdPlay.isStopped() && b == true) 
      { ; }
    }
    if(CODE == "001000"){ 
      if(!SdPlay.setFile("music.wav")) 
      { while(1); }
      SdPlay.play(); // Play File
      while(!SdPlay.isStopped() && b == true) 
      { ; }
    }
    if(CODE == "011000"){
      if(!SdPlay.setFile("levar.wav")) 
      { while(1); }
      SdPlay.play(); // Play File
      while(!SdPlay.isStopped() && b == true) 
      { ; }
    }
    if(CODE == "111000"){ 
      if(!SdPlay.setFile("long.wav"))
      { while(1); }
      SdPlay.play(); // Play File
      while(!SdPlay.isStopped() && b == true) 
      { ; }
    }
    if(CODE == "100100"){ 
      if(!SdPlay.setFile("full.wav")) 
      { while(1); }
      SdPlay.play(); // Play File
      while(!SdPlay.isStopped() && b == true) 
      { ; }
    }
    if(CODE == "110100"){ 
      if(!SdPlay.setFile("JPP.wav"))
      { while(1); }
      SdPlay.play(); // Play File
      while(!SdPlay.isStopped() && b == true)
      { ; }
    }
    if(CODE == "001100"){ 
      if(!SdPlay.setFile("JPPP.wav")) 
      { while(1); }
      SdPlay.play(); // Play File
      while(!SdPlay.isStopped() && b == true) 
      { ; }
    }
     if(CODE == "111100"){ 
      if(!SdPlay.setFile("Billo.wav")) 
      { while(1); }
      SdPlay.play(); // Play File
      while(!SdPlay.isStopped() && b == true) 
      { ; }
    }
     if(CODE == "100010"){ 
      if(!SdPlay.setFile("Beings.wav")) 
      { while(1); }
      SdPlay.play(); // Play File
      while(!SdPlay.isStopped() && b == true) 
      { ; }
    }
     if(CODE == "010010"){ 
      if(!SdPlay.setFile("Adebisi.wav")) 
      { while(1); }
      SdPlay.play(); // Play File
      while(!SdPlay.isStopped() && b == true) 
      { ; }
    }
    
    if(CODE == "001010"){ 
      if(!SdPlay.setFile("levvarr.wav")) 
      { while(1); }
      SdPlay.play(); // Play File
      while(!SdPlay.isStopped() && b == true) 
      { ; }
    }
    if(CODE == "101010"){ 
      if(!SdPlay.setFile("Nick.wav")) 
      { while(1); }
      SdPlay.play(); // Play File
      while(!SdPlay.isStopped() && b == true) 
      { ; }
    }
    if(CODE == "111010"){ 
      if(!SdPlay.setFile("cell.wav")) 
      { while(1); }
      SdPlay.play(); // Play File
      while(!SdPlay.isStopped() && b == true) 
      { ; }
    }
     if(CODE == "100101"){ 
      if(!SdPlay.setFile("Tom.wav"))
      { while(1); }
      SdPlay.play(); // Play File
      while(!SdPlay.isStopped() && b == true) 
      { ; }
    }
    if(CODE == "001101"){ 
      if(!SdPlay.setFile("Wolf.wav")) 
      { while(1); }
      SdPlay.play(); // Play File
      while(!SdPlay.isStopped() && b == true) 
      { ; }
    }
    if(CODE == "101101"){ 
      if(!SdPlay.setFile("Nature.wav")) 
      { while(1); }
      SdPlay.play(); // Play File
      while(!SdPlay.isStopped() && b == true) 
      { ; }
    }
    if(CODE == "011101"){ 
      if(!SdPlay.setFile("Song.wav")) 
      { while(1); }
      SdPlay.play(); // Play File
      while(!SdPlay.isStopped() && b == true) 
      { ; }
    }
    if(CODE == "111101"){ 
      if(!SdPlay.setFile("Rikeit.wav")) 
      { while(1); }
      SdPlay.play(); // Play File
      while(!SdPlay.isStopped() && b == true) 
      { ; }
      delay(15000);
      cc = true;
      X = 1;
    }
    
    


}

void PT(){ // Plays Secret WAV files Seperate from the rest 
    
    SdPlay.setFile("You.wav"); 
    SdPlay.play();
    delay(15000);
    SdPlay.setFile("m.wav"); 
    SdPlay.play();
    delay(20000);
    X = 0;
    
    
}

void s(){ // Makes Servo reset to the RIGHT
  
  if(bb == false && xx <= 90){
  digitalWrite(servo, HIGH);   
  delay(1);                  
  digitalWrite(servo, LOW);         
  delay(1);
  xx = xx + 1;
  }
  
}

void S(){ // Makes Servo move to the Left
  if(cc == true && XX <= 90){
  digitalWrite(servo, HIGH);   
  delay(2);                  
  digitalWrite(servo, LOW);    
  delay(2);
  XX = XX + 1;
  }
}




