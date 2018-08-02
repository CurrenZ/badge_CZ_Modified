// Tone frequencies
#include "pitches.h"

// ATtiny85 pin 3 as PWM for the buzzer
#define melodyPin 3
// ATtiny85 pin 4 as switch button pin
#define switchPin 4



//Oh Canada melody
int melody[] = {
NOTE_A4,NOTE_C5,NOTE_C5,NOTE_F4,NOTE_G4,NOTE_A4,NOTE_AS4,NOTE_C5,NOTE_D5, 
NOTE_G4,0,NOTE_A4,NOTE_G4,NOTE_B4,NOTE_C5,NOTE_D5,
NOTE_E5,NOTE_E5,NOTE_D5,NOTE_D5,NOTE_C5,NOTE_G4,NOTE_A4,NOTE_AS4,NOTE_A4,NOTE_G4,NOTE_A4,NOTE_AS4,
NOTE_C5,NOTE_AS4,NOTE_A4,NOTE_AS4,NOTE_C5,NOTE_D5,NOTE_C5,NOTE_AS4,NOTE_A4,NOTE_G4,NOTE_G4,NOTE_A4,
NOTE_AS4,NOTE_A4, NOTE_G4,NOTE_A4,NOTE_AS4,NOTE_C5,NOTE_AS4,NOTE_A4,NOTE_A4,NOTE_G4,NOTE_C5,NOTE_C5,NOTE_B4,NOTE_A4,NOTE_B4,NOTE_C5, 
NOTE_A4,NOTE_C5,NOTE_C5,NOTE_F4,NOTE_AS4,NOTE_D5,NOTE_D5,NOTE_G4, 
NOTE_C5,NOTE_CS5, NOTE_CS5, NOTE_D5, NOTE_AS4, NOTE_A4, NOTE_G4, NOTE_F4, NOTE_G4, NOTE_A4,
NOTE_C5,NOTE_F5,NOTE_F5,NOTE_D5,NOTE_AS4,NOTE_A4,NOTE_G4,NOTE_C5,NOTE_E4,NOTE_F4 
};

//Oh Canada them tempo
int tempo[] = {
2,2.67,8,1.33,4,4,4,4,4, 
1.33,4,2,2.67,8,1.33,4,
4,4,4,4,1.33,5.33,16,2.67,8,4,5.33,16, 
2.67,8,4,5.33,16,4,4,4,4,1.33,5.33,16, 
2.67,8,4,5.33,16,2.67,8,4,4,4.4,8,8,8,8,1, 
2,2.67,8,1,2,2.67,8,1, 
2,2.67,8,4,4,4,4,2,2,1,
2,2.67,8,4,4,4,4,2,2,1
};



 

void setup(void)
{
  pinMode(melodyPin, OUTPUT); 
  pinMode(0, INPUT);
  pinMode(1, INPUT);
  pinMode(2, INPUT);
  pinMode(switchPin, INPUT);

}

void loop()
{
  sing();
}

// Play melody
void sing(){      
     int size = sizeof(melody) / sizeof(int);
     for (int thisNote = 0; thisNote < size; thisNote++) {
       int noteDuration = 1000/tempo[thisNote];
       buzz(melodyPin, melody[thisNote],noteDuration);
       // to distinguish the notes, set a minimum time between them.
       // the note's duration + 30% seems to work well:
       int pauseBetweenNotes = noteDuration * 1;
       delay(pauseBetweenNotes);
       // stop the tone playing:
       buzz(melodyPin, 0,noteDuration);
    }
    
}

void buzz(int targetPin, long frequency, long length) {
  long delayValue = 1000000/frequency/2; // calculate the delay value between transitions
  long numCycles = frequency * length/ 1000; // calculate the number of cycles for proper timing
  for (long i=0; i < numCycles; i++){ // for the calculated length of time...
    digitalWrite(targetPin,HIGH); // write the buzzer pin high to push out the diaphram
    delayMicroseconds(delayValue); // wait for the calculated delay value
    digitalWrite(targetPin,LOW); // write the buzzer pin low to pull back the diaphram
    delayMicroseconds(delayValue); // wait again or the calculated delay value
  } 
  led(random(1,7));
  
}


void led(int number) {
  if(number==1){
    pinMode(2, INPUT);
    pinMode(0, OUTPUT);
    pinMode(1, OUTPUT);
    digitalWrite(1, LOW); 
    digitalWrite(0, HIGH); // LED 1
  }
  else if(number==2){
    pinMode(2, INPUT);
    pinMode(0, OUTPUT);
    pinMode(1, OUTPUT);
    digitalWrite(0, LOW); 
    digitalWrite(1, HIGH); // LED 2
  }
  else if(number==3){
    pinMode(0, INPUT);
    pinMode(1, OUTPUT);
    pinMode(2, OUTPUT);
    digitalWrite(1, LOW); 
    digitalWrite(2, HIGH);    
  }
   else if(number==4){
    pinMode(2, OUTPUT);
    pinMode(1, INPUT);
    pinMode(0, OUTPUT);
    digitalWrite(2, LOW); 
    digitalWrite(0, HIGH);   
  }
  else if(number==5){
    pinMode(2, OUTPUT);
    pinMode(1, INPUT);
    pinMode(0, OUTPUT);
    digitalWrite(0, LOW); 
    digitalWrite(2, HIGH); 
  }
  else if(number==6){
    pinMode(0, INPUT);
    pinMode(1, OUTPUT);
    pinMode(2, OUTPUT);
    digitalWrite(2, LOW); 
    digitalWrite(1, HIGH);     
  }
  else{
    
  }
}

