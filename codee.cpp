#define BLUETOOTH_RX_PIN 0
#define BLUETOOTH_TX_PIN 1


const int wetSensorPin = A0;


void Motoron(){
    digitalWrite(2,HIGH);
    digitalWrite(3,LOW);
 }

void MotorOff(){
    digitalWrite(2,LOW);
    digitalWrite(3,LOW);
    digitalWrite(6,LOW);
    digitalWrite(7,LOW);
 }

  pinMode(BLUETOOTH_RX_PIN, INPUT);
  pinMode(BLUETOOTH_TX_PIN, OUTPUT);
  pinMode(12,OUTPUT);

  Serial.begin(9600); 

  void loop()
  {

    int a=analogRead(wetSensorPin);
    Serial.println(a);

   if(a<500){
      digitalWrite(12,HIGH);
    }  
   else{
	    digitalWrite(12,LOW);
    }    
    
   if (Serial.available())
   {
      	char data;

      	data=Serial.read();
      	Serial.println(data);

      	if(data=='O')
      	{
      		Motoron(); 
      	}
      	else{
          	if(data=='X')
          	{
        		  MotorOff();
     		    }
   	    }               
    }
  
