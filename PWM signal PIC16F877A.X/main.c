#include "16F877A.h"
#fuses HS, NOWDT, NOPROTECT, NOLVP
#use delay(clock=16MHz)

/*  Déclaration des régistres de nécessaire à la génération du PWM  */
#byte PR2 =	0x92
#byte CCPR1L =	0x15 
#byte CCP1CON =	0x17
#byte TRISC =	0x87
#byte T2CON =	0x12


void main (void){
   PR2 = 99;                //Permet de fixé la période du PWM avec l formule suivante | PWM Duty Cycle = (CCPR1L:CCP1CON<5:4>) •TOSC • (TMR2 Prescale Value) |
   TRISC = 0xfb;            //Configuration de RC2/CCP1 en sortie 
   T2CON = 0x05;            //Activation du TMR2 avec un Prescale de 4 (T2CON = 0b00000101)
   CCPR1L = 0b00011000;     //Registre contenant les 8 bits de poid fort des 10 bits de résolution (MSB) 
   CCP1CON = 0b00111100;    //Registre contenant les 2 bits de poid faible des 10 bits de résolution (LSB) qui corespondent au bit 5 et 4. Les bits 3 et 2 doivent toujours être a 1 pour que le PWM fonctionne
   while (1) {
       
    }

}

/*
 *	1) Ecrir un fonction qui nous permet de varier la duty cycle qui correspond a ? dans nos calcul sur papier
 * 	2) Résoudre le problème de résolution. Nous avons 10 bits donc une valeur entre 0 et 1023 mais calculant la résolution après avoir choisit la fréquence de PWM on a: soit une résolution > 10 bits, soit une résolution < 10 bits 
 *	   Que se passe t il réellement si la résolution est différent des 10 bits ?????
 */