/*! @fn *split_credit(double credit)
* \brief É feito um cast para int do crédito total e guardado esse\n
* valor numa variável. De seguida, subtrai-se ao crédito total o \n
* valor da variável anteriormente guardado. Ambos os valores são \n
* guardados num array.
*    
* @param credit Crédito total disponível.
* @return Array de 2 posições que guarda os valores da parte inteira e decimal do número a "printar". 
*/

#ifndef _CONFIG_GPIO_H
#define _CONFIG_GPIO_H

#include <stdio.h>

int *split_credit(double credit); 

#endif



