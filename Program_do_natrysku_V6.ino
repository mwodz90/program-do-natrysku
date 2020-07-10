


unsigned long aktualnyCzas = 0;
unsigned long zapamietanyCzas1 = 0;
unsigned long roznicaCzasu1 = 0;
unsigned long zapamietanyCzas2 = 0;
unsigned long roznicaCzasu2 = 0;
unsigned long zapamietanyCzas3 = 0;
unsigned long roznicaCzasu3 = 0;
unsigned long zapamietanyCzas4 = 0;
unsigned long roznicaCzasu4 = 0;
unsigned long takt = 5250;           //czas otwarcia elektrozaworu
int stan1 = HIGH; 
int stan2 = HIGH;
int stan3 = HIGH;
int stan4 = HIGH;



void setup() {
  Serial.begin(9600);

pinMode (0, INPUT_PULLUP);     //wejście z czujnika 1
pinMode (1, INPUT_PULLUP);     //wejście z czujnika 2
pinMode (2, INPUT_PULLUP);     //wejście z czujnika 3
pinMode (3, INPUT_PULLUP);     //wejście z czujnika 4


pinMode (9, OUTPUT);     //wyjście na zawór 1
pinMode (10, OUTPUT);    //wyjście na zawór 2
pinMode (11, OUTPUT);    //wyjście na zawór 3
pinMode (12, OUTPUT);    //wyjście na zawór 4

digitalWrite (9, HIGH);  // zawor zamkniety podzas uruchomienia
digitalWrite (10, HIGH);   // zawor zamkniety podzas uruchomienia
digitalWrite (11, HIGH);  // zawor zamkniety podzas uruchomienia
digitalWrite (12, HIGH);   // zawor zamkniety podzas uruchomienia
attachInterrupt(digitalPinToInterrupt(0), czujnik1, FALLING);   // wykrycie obiektu przez czujnik 1
attachInterrupt(digitalPinToInterrupt(1), czujnik2, FALLING);   // wykrycie obiektu przez czujnik 2
attachInterrupt(digitalPinToInterrupt(2), czujnik3, FALLING);   // wykrycie obiektu przez czujnik 3
attachInterrupt(digitalPinToInterrupt(3), czujnik4, FALLING);   // wykrycie obiektu przez czujnik 4

}

void loop() {
  
aktualnyCzas = millis(); // pobieranie aktualnego czasu od startu


roznicaCzasu1 = aktualnyCzas - zapamietanyCzas1; 
roznicaCzasu2 = aktualnyCzas - zapamietanyCzas2;
roznicaCzasu3 = aktualnyCzas - zapamietanyCzas3;
roznicaCzasu4 = aktualnyCzas - zapamietanyCzas4;

if (stan1 == LOW && roznicaCzasu1 <= takt){
   digitalWrite (9, stan1);
 
  }
  else if (stan1 == LOW && roznicaCzasu1 > takt) {
    stan1 = HIGH;
    digitalWrite (9, stan1);
   
  }
  else {
    stan1 = HIGH;
    digitalWrite (9, stan1);
    zapamietanyCzas1 = aktualnyCzas;
  }

  if (stan2 == LOW && roznicaCzasu2 <= takt){
   digitalWrite (10, stan2);
   
  }
  else if (stan2 == LOW && roznicaCzasu2 > takt) {
    stan2 = HIGH;
    digitalWrite (10, stan2);
    
  }
  else {
    stan2 = HIGH;
    digitalWrite (10, stan2);
    zapamietanyCzas2 = aktualnyCzas;
  }
    if (stan3 == LOW && roznicaCzasu3 <= takt){
   digitalWrite (11, stan3);
   
  }
  else if (stan3 == LOW && roznicaCzasu3 > takt) {
    stan3 = HIGH;
    digitalWrite (11, stan3);
    
  }
  else {
    stan3 = HIGH;
    digitalWrite (11, stan3);
    zapamietanyCzas3 = aktualnyCzas;
  }
      if (stan4 == LOW && roznicaCzasu4 <= takt){
   digitalWrite (12, stan4);
  
  }
  else if (stan4 == LOW && roznicaCzasu4 > takt) {
    stan4 = HIGH;
    digitalWrite (12, stan4);
    
  }
  else {
    stan4 = HIGH;
    digitalWrite (12, stan4);
    zapamietanyCzas4 = aktualnyCzas;
  }
}

void czujnik1(){          // funkcja zmiany stanu dla czujnika 1
  stan1 = LOW;
}                     

void czujnik2(){          // funkcja zmiany stanu dla czujnika 2
  stan2 = LOW;
}

void czujnik3(){          // funkcja zmiany stanu dla czujnika 3
  stan3 = LOW;
}

void czujnik4(){          // funkcja zmiany stanu dla czujnika 4
  stan4 = LOW;
}



