/**
 *    \file caraterisationVitesseMoteur.ino
 *    \brief test des drivers, test des encodeurs
 *
 *    \author Arthur Duytschaever et Nicolas Sobczak
 *    \date Février 2017
 */
//_______________________________________________________________________________________________________
/* ======================================================================================================
 *      Include
 * ======================================================================================================
 */
#include <Arduino.h>
#include <SimpleTimer.h>           // http://arduino.cc/playground/Code/SimpleTimer


/* ======================================================================================================
 *      Variables globales
 * ======================================================================================================
 */
#define encoder0PinA_L 13   //encodeur gauche A
#define encoder0PinB_L 12   //encodeur gauche B
#define encoder0PinA_R 11   //encodeur droit A
#define encoder0PinB_R 10   //encodeur droit B

#define MotorR 6 // Attention sur Due PWM ou Pwm sont des keyword -> donc ne pas les utiliser pour des nom de variable
#define MotorL 3
#define IN1MotorR 52
#define IN2MotorR 53
#define IN1MotorL 22
#define IN2MotorL 23

unsigned int tick_codeuse_R = 0;   // Compteur de tick de la codeuse
unsigned int tick_codeuse_L = 0;   // Compteur de tick de la codeuse

unsigned long duration;


/* ======================================================================================================
 *      Fonctions
 * ======================================================================================================
 */

/**
 * \fn void setup()
 * \brief fonction setup d'arduino
 */
void setup()
{
        Serial.begin(115200);     // Initialisation port COM
        pinMode(MotorR,OUTPUT);
        pinMode(MotorL,OUTPUT);
        pinMode(IN1MotorR,OUTPUT);
        pinMode(IN2MotorR,OUTPUT);
        pinMode(IN1MotorL,OUTPUT);
        pinMode(IN2MotorL,OUTPUT);

        pinMode(encoder0PinA_L, INPUT);
        pinMode(encoder0PinB_L, INPUT);
        pinMode(encoder0PinA_R, INPUT);
        pinMode(encoder0PinB_R, INPUT);

        attachInterrupt(encoder0PinA_R, compteur_tick_R, CHANGE);    // Interruption sur tick de la codeuse (interruption 0 = pin2 arduino mega)
        //attachInterrupt(encoder0PinA_L, compteur_tick_L, CHANGE);    // Interruption sur tick de la codeuse (interruption 0 = pin2 arduino mega)

/*
        digitalWrite(IN1MotorL, LOW);
        digitalWrite(IN2MotorL, LOW);
        analogWrite(MotorL,255);
        digitalWrite(IN1MotorR, HIGH);
        digitalWrite(IN2MotorR, LOW);
        analogWrite(MotorR,255);
        delay(1000);              
        analogWrite(MotorR,0);
*/
//Moteur droit
        analogWrite(MotorL,255);
        analogWrite(MotorR,255);
        digitalWrite(IN1MotorR, HIGH);
        digitalWrite(IN2MotorR, LOW);
        digitalWrite(IN1MotorL, LOW);
        digitalWrite(IN2MotorL, LOW);
        analogWrite(MotorL,255);
        analogWrite(MotorR,0);
}


/**
 * \fn void loop()
 * \brief fonction loop d'arduino
 */
void loop()
{ 
        //testDriver();
        
        Serial.print("\t tick_codeuse_R : \t");
        Serial.println(tick_codeuse_R);

        Serial.print("\t duration : \t");
        Serial.println(duration);

        Serial.println("\n");
}


/**
 * \fn void compteur_tick_R()
 * \brief Interruption sur tick de la codeuse right
 */
void compteur_tick_R(){
        //Serial.println("Interruption");
        tick_codeuse_R++; // On incrémente le nombre de tick de la codeuse
        duration += pulseIn(encoder0PinA_R, HIGH); // in microsecond
        //Serial.println("Je compte les ticks");
}


/**
 * \fn void compteur_tick_L()
 * \brief Interruption sur tick de la codeuse left
 */
void compteur_tick_L(){
        //Serial.println("Interruption");
        tick_codeuse_L++; // On incrémente le nombre de tick de la codeuse
        //Serial.println("Je compte les ticks");

        /*Calcul du nombre de ticks dans un certain temps (pulseIn)*/
        //Peut poser pb parce qu'on est dans une interruption et on veut mesurer la durée de l'interruption
        //duration += pulseIn(encoder0PinA_L, HIGH); // in microsecond
        // duration = duration/2500 // durée / 2500tick = nb de tours/microsecond
}


/**
 * \fn void testDriver()
 * \brief fonction qui teste qui les drivers fonctionnent correctement
 */
void testDriver(){
        //Moteur gauche
        analogWrite(MotorL,255);
        analogWrite(MotorR,255);
        Serial.print("On moteuL gauche \t 1");
        digitalWrite(IN1MotorR, LOW);
        digitalWrite(IN2MotorR, LOW);
        digitalWrite(IN1MotorL, HIGH);
        digitalWrite(IN2MotorL, LOW);
        Serial.print("\t 2");
        analogWrite(MotorL,100);
        analogWrite(MotorR,255);
        Serial.print("\t 3");
        delay(3000);
        Serial.println("\t 4");


        //Moteur droit
        analogWrite(MotorL,255);
        analogWrite(MotorR,255);
        Serial.print("On moteuL droit \t 1");
        digitalWrite(IN1MotorR, HIGH);
        digitalWrite(IN2MotorR, LOW);
        digitalWrite(IN1MotorL, LOW);
        digitalWrite(IN2MotorL, LOW);
        Serial.print("\t 2");
        analogWrite(MotorL,255);
        analogWrite(MotorR,100);
        Serial.print("\t 3");
        delay(3000);
        Serial.println("\t 4");


        //2 moteurs
        analogWrite(MotorL,255);
        analogWrite(MotorR,255);
        Serial.print("On 2 moteurs \t 1");
        digitalWrite(IN1MotorR, HIGH);
        digitalWrite(IN2MotorR, LOW);
        digitalWrite(IN1MotorL, HIGH);
        digitalWrite(IN2MotorL, LOW);
        Serial.print("\t 2");
        analogWrite(MotorL,100);
        analogWrite(MotorR,100);
        Serial.print("\t 3");
        delay(3000);
        Serial.println("\t 4");

        //Moteur droit
        analogWrite(MotorL,255);
        analogWrite(MotorR,255);
        Serial.print("On moteuL droit \t 1");
        digitalWrite(IN1MotorR, HIGH);
        digitalWrite(IN2MotorR, LOW);
        digitalWrite(IN1MotorL, LOW);
        digitalWrite(IN2MotorL, LOW);
        Serial.print("\t 2");
        analogWrite(MotorL,255);
        analogWrite(MotorR,100);
        Serial.print("\t 3");
        delay(3000);
        Serial.println("\t 4");

        //Moteur gauche
        analogWrite(MotorL,255);
        analogWrite(MotorR,255);
        Serial.print("On moteuL gauche \t 1");
        digitalWrite(IN1MotorR, LOW);
        digitalWrite(IN2MotorR, LOW);
        digitalWrite(IN1MotorL, HIGH);
        digitalWrite(IN2MotorL, LOW);
        Serial.print("\t 2");
        analogWrite(MotorL,100);
        analogWrite(MotorR,255);
        Serial.print("\t 3");
        delay(3000);
        Serial.println("\t 4");


        //2 moteurs
        analogWrite(MotorL,255);
        analogWrite(MotorR,255);
        Serial.print("On 2 moteurs \t 1");
        digitalWrite(IN1MotorR, HIGH);
        digitalWrite(IN2MotorR, LOW);
        digitalWrite(IN1MotorL, HIGH);
        digitalWrite(IN2MotorL, LOW);
        Serial.print("\t 2");
        analogWrite(MotorL,100);
        analogWrite(MotorR,100);
        Serial.print("\t 3");
        delay(3000);
        Serial.println("\t 4");
}