/*******************************************************************************
 *
 *              LIBRERIA PARA LAS INTERRUPCIONES EN C18
 *
 *******************************************************************************
 * FileName:        all_interrupts.c
 * Processor:       None
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

/**************************************************************/
/**************************************************************/
/****************VECTORES DE INTERRUPCION**********************/
/**************************************************************/
/**************************************************************/

//Vector de interrupcion de baja prioridad
#pragma code low_vector=0x18
void interrupt_at_low_vector(void)
{
  _asm GOTO low_isr _endasm
}
#pragma code /* Regresa al lugar de donde dio el salto */
#pragma interruptlow low_isr
void low_isr (void)
{
    //En esta secccion se coloca las lineas de codigo
    //con grado de baja prioridad
}



//Vector de interrupcion de alta prioridad
#pragma code high_vector=0x08
void interrupt_at_high_vector(void)
{
  _asm GOTO high_isr _endasm
}
#pragma code /* Regresa al lugar de donde dio el salto */
#pragma interrupt high_isr
void high_isr (void)
{
    if(INTCONbits.TMR0IF){
        LED_STATUS^=1;
        TMR0H=0x0B;
        TMR0L=0xDC;
        INTCONbits.TMR0IF=0;
    }
}