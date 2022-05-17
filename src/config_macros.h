/** @file config_macros.h
 * @brief Definição das variáveis globais do programa. 
 *
 *  
 * 
 * @authors 
 *	Denys Zadorozhnyy\n
 * 	Vítor Correia\n
 * 	André Campos
 *
 * @date 16 May 2022
 * @bug No known bugs
 */


#ifndef _CONFIG_MACROS_H
#define _CONFIG_MACROS_H

#define S0 0 /*!< Estado de display */
#define S1 1 /*!< Estado de mudança de produto */
#define S2 2 /*!< Estado de inserseção de moeda */
#define S3 3 /*!< Estado de retorno de crédito */
#define S4 4 /*!< Estado de seleção de produto */

#define GPIO0_NID DT_NODELABEL(gpio0) 
#define BOARDBUT1 11 /*!< Pino ao qual o BUT1 está conectado */	
#define BOARDBUT2 12 /*!< Pino ao qual o BUT2 está conectado */
#define BOARDBUT3 24 /*!< Pino ao qual o BUT3 está conectado */
#define BOARDBUT4 25 /*!< Pino ao qual o BUT4 está conectado */
#define BOARDBUT5 0x3 /*!< Pino ao qual o BUT5 está conectado */
#define BOARDBUT6 0x4 /*!< Pino ao qual o BUT6 está conectado */
#define BOARDBUT7 0x1c /*!< Pino ao qual o BUT7 está conectado */
#define BOARDBUT8 0x1d /*!< Pino ao qual o BUT8 está conectado */
#endif
