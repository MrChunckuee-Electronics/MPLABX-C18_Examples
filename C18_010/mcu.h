/*
 * File:   mcu.h
 * Author: MrChunckuee
 * Created on 2 de enero de 2015, 07:44 PM
 */

#ifndef MCU_H
#define MCU_H

//Etiquetas de Entradas-Salidas
#define LED_STATUS          PORTEbits.RE0
#define LED_STATUS_TRIS     TRISEbits.RE0

//Funciones utilizadas
void MCU_Init(void);
void TMR0_Init(void);

#endif