/*******************************************************************************
 *
 *                       LED INTERMITENTE
 *
 *******************************************************************************
 * FileName:        main.c
 * Processor:       PIC18F4620
 * Complier:        C18 v3.47
 * Author:          Pedro Sánchez (MrChunckuee)
 * Blog:            http://mrchunckuee.blogspot.com/
 * Email:           mrchunckuee.psr@gmail.com
 * Description:     Blinking a LED in RE0, MCLR on, INT OSC = 4MHz
 *******************************************************************************
 * Rev.         Date            Comment
 *   v1.00      15/12/2014     Creación del firmware
 ******************************************************************************/
#include <p18f4620.h>
#include <stdio.h>
#include <stdlib.h>
#include <delays.h>

#include "Config_FusesPIC.h"//Configuración de FUSES

#define LED_STATUS PORTEbits.RE0//Pin del LED

void main(void){
    OSCCONbits.IRCF = 0b110; //Configura oscilador interno a 4MHz
    ADCON1=0xFF; //Entradas y salidas digitales
    TRISE=0x00; //Puerto E como salida
    LATE=0; //Limpiamos el puerto E
    
    while (1){
        LED_STATUS=1;//Encendemos el LED
        Delay10KTCYx(100);//Retardo de 1 segundo
        LED_STATUS=0;//Apagamos el LED
        Delay10KTCYx(100);//Retardo de 1 segundo
    }  
}





