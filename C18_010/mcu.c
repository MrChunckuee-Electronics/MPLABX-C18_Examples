/*******************************************************************************
 *
 *                         TMR0 COMO TEMPORIZADOR
 *
 *******************************************************************************
 * FileName:        mcu.c
 * Processor:       PIC18F4620
 * Complier:        C18 v3.47
 * Author:          Pedro Sánchez (MrChunckuee)
 * Blog:            http://mrchunckuee.blogspot.com/
 * Email:           mrchunckuee.psr@gmail.com
 * Description:
 *******************************************************************************
 * Rev.         Date            Comment
 *   v1.00      02/01/2015     Creación del firmware
 ******************************************************************************/

//Librerias utilizadas
#include <p18f4620.h>
#include <stdio.h>
#include <portb.h>
#include <stdlib.h>
#include <usart.h>
#include <string.h>
#include <delays.h>
#include <timers.h>
#include "all_interrupts.h"
#include "mcu.h"

void MCU_Init(void){
    OSCCONbits.IRCF=0b110;//Configura oscilador interno a 4MHz
    ADCON1=0xFF;//Entradas y salidas digitales
    LED_STATUS_TRIS=0;//Pin del LED como salida
    LED_STATUS=0;//Se inicializa en cero
}

void TMR0_Init(void){
    //Configuración del TMR0
    T0CON=0x83;
    TMR0H=0x0B;
    TMR0L=0xDC;
    INTCONbits.TMR0IF=0;
    INTCONbits.TMR0IE=1;
    INTCON2bits.TMR0IP=1;
    RCONbits.IPEN=1;
    INTCONbits.GIEH=1;
}


	
	
	