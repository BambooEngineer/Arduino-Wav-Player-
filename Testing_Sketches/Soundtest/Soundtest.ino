
int Y0 = 6; // OUTPUTS FROM DEMULTIPLEXER
int Y1 = 5; // THERE ARE 43 SOUND FILES THAT CAN BE ACCESSED WITH THE IC CHIP(Only 6 pins needed = 101011), PT FILES ARE ACCESSED THROUGH NES Controller 
int Y2 = 7; 
int Y3 = 3;
int Y4 = 2; 
int Y7 = 8; // @Then NES controller function & PT headphone function (Headphone Male end's GND also goes to arduino analog pin to show headphones are plugged in by having the headphones GND go to an arduino analog pin)
            // @Then Casing can be done during weekend 

int v0 = 0; // DIGITALREAD VALUES
int v1 = 0;
int v2 = 0;
int v3 = 0;
int v4 = 0;
int v7 = 0;
int V = 0;

int Enter = 10; // SAVING BINARY CODE INTO ARRAY BUTTON


boolean b = false;
int x = 0;
String a;
String B; 
String c; 
String d;
String e;
String f;
void setup()
{ 

  

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
  V = analogRead(A1);
  Serial.println(V);
}
