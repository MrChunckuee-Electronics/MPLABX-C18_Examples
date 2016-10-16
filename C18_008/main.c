/*******************************************************************************
 *
 *              ENCENDER Y APAGAR UN LED CON UN PULSADOR
 *
 *******************************************************************************
 * FileName:        main.c
 * Processor:       PIC18F4620
 * Complier:        C18 v3.47
 * Author:          Pedro Sánchez (MrChunckuee)
 * Blog:            http://mrchunckuee.blogspot.com/
 * Email:           mrchunckuee.psr@gmail.com
 * Description:     Toggle LED_STATUS with BUTTON, MCLR on, INT OSC = 4MHz
 *******************************************************************************
 * Rev.         Date            Comment
 *   v1.00      20/12/2014     Creación del firmware
 ******************************************************************************/

#include <p18f4620.h>
#include <stdio.h>
#include <stdlib.h>
#include <delays.h>

#include "Config_FusesPIC.h"//Configuración de FUSES

#define BUTTON          PORTEbits.RE0
#define BUTTON_TRIS     TRISEbits.RE0

#define LED_STATUS      PORTEbits.RE1
#define LED_STATUS_TRIS TRISEbits.RE1

void main(void){
    OSCCONbits.IRCF=0b110;//Configura oscilador interno a 4MHz
    ADCON1=0xFF;//Entradas y salidas digitales

    //Configuración de Entradas/Salida
    BUTTON_TRIS=1;//Pin del boton como entrada
    LED_STATUS_TRIS=0;//Pin del LED como salida

    //Se inicializán los puertos en cero
    BUTTON=0;
    LED_STATUS=0;
    
    while(1){
        if (BUTTON==1){//Si presiono el boton
            Delay1KTCYx(50);//Retardo de 50 mS
            LED_STATUS^=1;// Cambio de estado el LED
        }
    } 
}





