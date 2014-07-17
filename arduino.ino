#include <Process.h>
#include <Bridge.h>
#include <Console.h>


int led = 13;
int sensorPin = A0;
unsigned int sensorValue = 0;
// Broche 3 en sortie commande du relais n1
const int RELAIS = 3; //declaration broche 3 output

boolean etatRelais = 1; // Etat du relais (on / off)


void setup()   {
  Bridge.begin();   // Initialize the Bridge
  Console.begin();
  Serial.begin(9600);   //Ouvre le port série à 9600 bauds
  // Broche de sortie
  pinMode(RELAIS, OUTPUT); //Configure la broche RELAIS en sortie 
} //  Fin du setup


void loop(){ // Boucle principale
  Process p;
  p.runShellCommand("/usr/bin/curl http://mathemagie.net/projects/tu_chauffes/index.php");

  Serial.println("run curl command");
   
  while (p.running());
    while (p.available()) {
      int result = p.parseInt();
       Serial.println(result);
        if (result == 1)   digitalWrite(RELAIS,LOW);
        if (result == 0)   digitalWrite(RELAIS,HIGH);
        
    }
 
  delay (1000);

  //sensorValue = analogRead(sensorPin);

//  if(sensorValue<950){ 
    //digitalWrite(RELAIS,etatRelais);
  //  digitalWrite(RELAIS,HIGH);
  //}else{ 
    //digitalWrite(RELAIS,LOW);
 // }
  //Serial.println(etatRelais);
  //Serial.print(sensorValue, DEC);
  //Serial.println("");


}
