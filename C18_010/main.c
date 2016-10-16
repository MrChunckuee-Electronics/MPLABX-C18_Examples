/*******************************************************************************
 *
 *                         TMR0 COMO TEMPORIZADOR
 *
 *******************************************************************************
 * FileName:        main.c
 * Processor:       PIC18F4620
 * Complier:        C18 v3.47
 * Author:          Pedro Sánchez (MrChunckuee)
 * Blog:            http://mrchunckuee.blogspot.com/
 * Email:           mrchunckuee.psr@gmail.com
 * Description:     Se cambia el estado de un LED cada segundo usando el TMR0
 *                  como temporizador
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

#include "Config_FusesPIC.h"//Configuración de FUSES

void main(void){
    MCU_Init();//Inicializao uC
    TMR0_Init();//Inicializo TMR0
    while(1){
    }  
}





