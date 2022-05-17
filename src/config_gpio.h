/*! \fn but1press_cbfunction(const struct device *dev, struct gpio_callback *cb, uint32_t pins)
    \brief Quando o botão 1 é pressionado, esta função iguala a variável #dcToggleFlag1 a 1.
    
    \param *dev Ponteiro para estrutura do tipo device; inicializado na função get_bind() 
    \param *cb  Ponteiro para estrutura do tipo gpio_callback
    \param pins Valor associado ao pino do botão pressionado
*/

/*! \fn but2press_cbfunction(const struct device *dev, struct gpio_callback *cb, uint32_t pins)
    \brief Quando o botão 2 é pressionado, esta função iguala a variável #dcToggleFlag2 a 1.
    
    \param *dev Ponteiro para estrutura do tipo device; inicializado na função get_bind()
    \param *cb  Ponteiro para estrutura do tipo gpio_callback
    \param pins Valor associado ao pino do botão pressionado
*/

/*! \fn but3press_cbfunction(const struct device *dev, struct gpio_callback *cb, uint32_t pins)
    \brief Quando o botão 3 é pressionado, esta função iguala a variável #dcToggleFlag3 a 1.
    
    \param *dev Ponteiro para estrutura do tipo device; inicializado na função get_bind()
    \param *cb  Ponteiro para estrutura do tipo gpio_callback
    \param pins Valor associado ao pino do botão pressionado
*/

/*! \fn but4press_cbfunction(const struct device *dev, struct gpio_callback *cb, uint32_t pins)
    \brief Quando o botão 4 é pressionado, esta função iguala a variável #dcToggleFlag4 a 1.
    
    \param *dev Ponteiro para estrutura do tipo device; inicializado na função get_bind()
    \param *cb  Ponteiro para estrutura do tipo gpio_callback
    \param pins Valor associado ao pino do botão pressionado
*/

/*! \fn but5press_cbfunction(const struct device *dev, struct gpio_callback *cb, uint32_t pins)
    \brief Quando o botão 5 é pressionado, esta função iguala a variável #dcToggleFlag5 a 1.
    
    \param *dev Ponteiro para estrutura do tipo device; inicializado na função get_bind()
    \param *cb  Ponteiro para estrutura do tipo gpio_callback
    \param pins Valor associado ao pino do botão pressionado
*/

/*! \fn but6press_cbfunction(const struct device *dev, struct gpio_callback *cb, uint32_t pins)
    \brief Quando o botão 6 é pressionado, esta função iguala a variável #dcToggleFlag6 a 1.
    
    \param *dev Ponteiro para estrutura do tipo device; inicializado na função get_bind()
    \param *cb  Ponteiro para estrutura do tipo gpio_callback
    \param pins Valor associado ao pino do botão pressionado
*/

/*! \fn but7press_cbfunction(const struct device *dev, struct gpio_callback *cb, uint32_t pins)
    \brief Quando o botão 7 é pressionado, esta função iguala a variável #dcToggleFlag7 a 1.
    
    \param *dev Ponteiro para estrutura do tipo device; inicializado na função get_bind()
    \param *cb  Ponteiro para estrutura do tipo gpio_callback
    \param pins Valor associado ao pino do botão pressionado
*/

/*! \fn but8press_cbfunction(const struct device *dev, struct gpio_callback *cb, uint32_t pins)
    \brief Quando o botão 8 é pressionado, esta função iguala a variável #dcToggleFlag8 a 1.
    
    \param *dev Ponteiro para estrutura do tipo device; inicializado na função get_bind()
    \param *cb  Ponteiro para estrutura do tipo gpio_callback
    \param pins Valor associado ao pino do botão pressionado
*/

/*! \fn get_bind(void)
    \brief Configura as interrupções que vão ser geradas quando um botão é pressionado.\n
    São assocociadas funções específicas a essas interrupões.
    
    Cada botão é associado a um pino específico da placa, tornando possível a deteção de\n
    eventos por estes gerados (Clicar num botão). É feita, assim, a configuração das \n
    interrupções geradas pelo clique dos botões.
    
    Se alguma interrupação não for corretamente configurada, o programa apresenta uma\n
    mensagem de erro.     
*/

#ifndef _CONFIG_GPIO_H
#define _CONFIG_GPIO_H

#include <zephyr.h>
#include <device.h>
#include <devicetree.h>
#include <drivers/gpio.h>
#include <sys/printk.h>
#include <sys/__assert.h>
#include <string.h>
#include <stdio.h>
#include "config_macros.h"

extern volatile int dcToggleFlag1; /*!< Flag para sinalizar que o Botão 1 foi pressionado*/
extern volatile int dcToggleFlag2; /*!< Flag para sinalizar que o Botão 2 foi pressionado*/
extern volatile int dcToggleFlag3; /*!< Flag para sinalizar que o Botão 3 foi pressionado*/
extern volatile int dcToggleFlag4; /*!< Flag para sinalizar que o Botão 4 foi pressionado*/
extern volatile int dcToggleFlag5; /*!< Flag para sinalizar que o Botão 5 foi pressionado*/
extern volatile int dcToggleFlag6; /*!< Flag para sinalizar que o Botão 6 foi pressionado*/
extern volatile int dcToggleFlag7; /*!< Flag para sinalizar que o Botão 7 foi pressionado*/
extern volatile int dcToggleFlag8; /*!< Flag para sinalizar que o Botão 8 foi pressionado*/

void but1press_cbfunction(const struct device *dev, struct gpio_callback *cb, uint32_t pins);
void but2press_cbfunction(const struct device *dev, struct gpio_callback *cb, uint32_t pins);
void but3press_cbfunction(const struct device *dev, struct gpio_callback *cb, uint32_t pins);
void but4press_cbfunction(const struct device *dev, struct gpio_callback *cb, uint32_t pins);
void but5press_cbfunction(const struct device *dev, struct gpio_callback *cb, uint32_t pins);
void but6press_cbfunction(const struct device *dev, struct gpio_callback *cb, uint32_t pins);
void but7press_cbfunction(const struct device *dev, struct gpio_callback *cb, uint32_t pins);
void but8press_cbfunction(const struct device *dev, struct gpio_callback *cb, uint32_t pins);

void get_bind(void);

#endif
