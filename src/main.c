/** @file main.c 
 * @brief Implementação da máquina de estados
 *
 * É feita a configuração da máquina de estados em C, recorrendo\n
 * ao comando "switch", contido num ciclo "while". Há 5 "cases",\n 
 * correspondestes aos 5 estados definidos no config_macros.h. 
 *
 * O estado default é o S0, que corresponde ao display do produto\n
 * e do crédito total. Dependedo do botão pressionado, apartir\n
 * deste estado inicial, é possível ir para os outros estados:\n
 * S1, S2, S3 e S4. Depois da execução das respetivas tarefas \n
 * nestes estados, o sistema volta sempre ao estado inicial.
 *
 * 
 * 
 * @authors 
 *	Denys Zadorozhnyy\n
 * 	Vítor Correia\n
 * 	André Campos
 *
 * @date 16 May 2022
 * @note Alguns comentários adicionais de variáveis locais inicializadas\n
 * estão no próprio ficheiro.
 * @bug No known bugs
 */


#include <zephyr.h>
#include <device.h>
#include <devicetree.h>
#include <drivers/gpio.h>
#include <sys/printk.h>
#include <sys/__assert.h>
#include <string.h>
#include <stdio.h>
#include "config_macros.h"
#include "config_gpio.h"
#include "func_extras.h"

void main(void) 
{ 
  get_bind();			//configuracao de botoes
  

  int state = S0;		//estado inicial	
  double Vtotal = 0;		//credito total

  char produto1[] = "Beer: 1.5 EUR";
  char produto2[] = "Tuna Sandwich: 1.0 EUR";
  char produto3[] = "Coffee: 0.5 EUR";	//arrays com os nomes e precos dos produtos

  int *int_parts;  	//ponteiro para array recebido da funcao *split_credit()

  double vp1 = 1.5;	
  double vp2 = 1.0;
  double vp3 = 0.5;	//precos dos produtos

  int selProduct = 1;	//variavel de selecao de produto 


  while(1) 
  {
    k_msleep(100);     //funcao que serve de delay para facilitar a visualizacao      
    switch(state)
    {
      case S0:
        if (dcToggleFlag1==1 || dcToggleFlag2==1 || dcToggleFlag3==1 || dcToggleFlag4==1)
          state = S2;
        if (dcToggleFlag5==1 || dcToggleFlag6==1)
          state = S1;
        if (dcToggleFlag7==1)
          state = S3;
        if (dcToggleFlag8==1)
          state = S4; 
          
        if(selProduct == 1)
                printk("\n%s", produto1);
        if(selProduct == 2)
                printk("\n%s", produto2);
        if(selProduct == 3)
                printk("\n%s", produto3);
        
        int_parts = split_credit(Vtotal);
        printk("		Credit: %d.%d EUR\n", int_parts[0], int_parts[1]);
    
        break;
                              
      case S1:
        if(dcToggleFlag6==1 && selProduct == 1)
                selProduct = 2;
                
        else if(dcToggleFlag6==1 && selProduct == 2)
                selProduct = 3;

        else if(dcToggleFlag6==1 && selProduct == 3)
                selProduct = 1;

        else if(dcToggleFlag5==1 && selProduct == 1)
                selProduct = 3;

        else if(dcToggleFlag5==1 && selProduct == 2)
                selProduct = 1;

        else if(dcToggleFlag5==1 && selProduct == 3)
                selProduct = 2;
        
        dcToggleFlag6=0;
        dcToggleFlag5=0;
        state = S0;
        break;
                      
       case S2:
        if(dcToggleFlag1==1)
        {
          Vtotal += 0.1;
          dcToggleFlag1=0;
        }

        if(dcToggleFlag2==1)
        {
          Vtotal += 0.2;
          dcToggleFlag2=0;
        }

        if(dcToggleFlag3==1)
        {
          Vtotal += 0.5;
          dcToggleFlag3=0;
        }

        if(dcToggleFlag4==1)
        {
          Vtotal += 1;
          dcToggleFlag4=0;
        }

        state = S0;
        break;
                                      
        case S3:
          int_parts = split_credit(Vtotal);
          printk("\n%d.%d EUR return\n", int_parts[0], int_parts[1]);
          k_msleep(2000);
          Vtotal = 0;
          
          dcToggleFlag7=0;
          state = S0;
          break;
                                      
        case S4:
          if(selProduct == 1)
          {
            if( vp1 > Vtotal)
            {
              int_parts = split_credit(Vtotal);
              printk("Not enough credit, Product Beer cost 1.5 EUR, credit is %d.%d EUR\n", int_parts[0], int_parts[1]);
              k_msleep(2000);
            }
            else
            {
              Vtotal = Vtotal - vp1;
              int_parts = split_credit(Vtotal);
              printk("Product Beer dispensed, remaining credit is %d.%d EUR\n", int_parts[0], int_parts[1]);
              k_msleep(2000);
            }
          }

          if(selProduct == 2)
          {
            if( vp2 > Vtotal)
            {
              int_parts = split_credit(Vtotal);
              printk("Not enough credit, Product Tuna Sandwich cost 1.0 EUR, credit is %d.%d EUR\n", int_parts[0], int_parts[1]);
              k_msleep(2000);	
            }
            else
            {
              Vtotal = Vtotal - vp2;
              int_parts = split_credit(Vtotal);
              printk("Product Tuna Sandwich dispensed, remaining credit is %d.%d EUR\n", int_parts[0], int_parts[1]);
              k_msleep(2000);
            }
          }

          if(selProduct == 3)
          {
            if( vp3 > Vtotal)
            {
             int_parts = split_credit(Vtotal);
             printk("Not enough credit, Product Coffee cost 0.5 EUR, credit is %d.%d EUR\n", int_parts[0], int_parts[1]);
             k_msleep(2000);
            }
            else
            {
              Vtotal = Vtotal - vp3;
              int_parts = split_credit(Vtotal);
              printk("Product Coffee dispensed, remaining credit is %d.%d EUR\n", int_parts[0], int_parts[1]);
              k_msleep(2000);
            }
          }
           
          dcToggleFlag8=0;  
          state = S0;
          break;

    }		
  }
  return;
}
