int servo = A0;                 
int vv = 0;
static boolean bb = false;
static boolean cc = false;
static int xx;
static int XX;

void setup()
{
  pinMode(servo, OUTPUT);     
  pinMode(2, INPUT_PULLUP);
 
}

void loop()
{
  vv = digitalRead(2);
  
  if(vv == HIGH){               
  s();
  }
  
  if(vv == LOW){
  cc = true;
  }
  
  if(cc == true){
  S();
  }
  
}

void s(){
  
  if(bb == false && xx <= 90){
  digitalWrite(servo, HIGH);   
  delay(1);                  
  digitalWrite(servo, LOW);         
  delay(1);
  xx = xx + 1;
  }
  
}

void S(){
  if(cc == true && XX <= 90){
  digitalWrite(servo, HIGH);   // sets the LED on
  delay(2);                  // waits for a second
  digitalWrite(servo, LOW);    // sets the LED off //           1 MAKES IT GO RIGHT AND 2 MAKES IT GO LEFT
  delay(2);
  XX = XX + 1;
  }
}

