/** @file func_extras.c 
 * @brief Separação da parte inteira e decimal do crédito
 *
 * Para ser possível dar print do valor do crédito com parte inteira\n 
 * e decimal, foi necessário separar esse valor em 2 partes inteiras.
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




#include "func_extras.h"

int *split_credit(double credit)
{
  static int array[2];
  int inteiro = 0;
  int decimal = 0;  

  inteiro = (int) credit;
  decimal = (credit - inteiro) * 10;

  array[0] = inteiro;
  array[1] = decimal;

  return array;
}
