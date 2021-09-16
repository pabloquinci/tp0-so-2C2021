#ifndef CLIENT_H_
#define CLIENT_H_

#include<stdio.h>
#include<stdlib.h>
#include<commons/log.h>
#include<commons/string.h>
#include<commons/config.h>
#include<readline/readline.h>

#include "utils.h"

typedef struct{
	char* clave;
	char* ipServidor;
	char* puertoServidor;
}tConfiguracion;

t_log* iniciar_logger(void);
tConfiguracion * configuracion;
t_config * fd_configuracion;
t_log* logger;
t_config* iniciar_config(void);
void leer_consola(t_log*);
void paquete(int);
void terminar_programa(int, t_log*, t_config*);
#endif /* CLIENT_H_ */
