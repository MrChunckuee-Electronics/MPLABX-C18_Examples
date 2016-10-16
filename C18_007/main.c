/*******************************************************************************
 *
 *                       LEDs SECUENCIALES
 *
 *******************************************************************************
 * FileName:        main.c
 * Processor:       PIC18F4620
 * Complier:        C18 v3.47
 * Author:          Pedro Sánchez (MrChunckuee)
 * Blog:            http://mrchunckuee.blogspot.com/
 * Email:           mrchunckuee.psr@gmail.com
 * Description:     Desplazamiento de LEDS en LATB, MCLR on, INT OSC = 4MHz
 *******************************************************************************
 * Rev.         Date            Comment
 *   v1.00      19/12/2014     Creación del firmware
 ******************************************************************************/

#include <p18f4620.h>
#include <stdio.h>
#include <stdlib.h>
#include <delays.h>

#include "Config_FusesPIC.h"//Configuración de FUSES

unsigned char LED_Number=0;
//Ejemplo 1:
unsigned char LED_LookupTable[8]={0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80};

//Ejemplo 2: si se usa este ejemplo comentar ejemplo 1 y 3, y descomentar este
//Cambiar if (LED_Number==8) por if (LED_Number==7)
//unsigned char LED_LookupTable[7]={0x81, 0x42, 0x24, 0x18, 0x24, 0x42, 0x81};

//Ejemplo 3: si se usa este ejemplo comentar ejemplo 1 y 2, y descomentar este
//Cambiar if (LED_Number==8) por if (LED_Number==15)
//unsigned char LED_LookupTable[15]={0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80, 0x40, 0x20, 0x10, 0x08, 0x04, 0x02, 0x01};

void main(void){
    OSCCONbits.IRCF=0b110;//Configura oscilador interno a 4MHz
    ADCON1=0xFF;//Entradas y salidas digitales
    TRISB=0x00;//Puerto B como salida
    LATB=0;//Se inicializán el puerto B en cero

    while(1){
        LATB=LED_LookupTable[LED_Number];//Muestro los datos en el puerto
        LED_Number++;
        if (LED_Number==8)
            LED_Number=0;
        Delay1KTCYx(100);//Retardo de 100 mS
    } 
}





