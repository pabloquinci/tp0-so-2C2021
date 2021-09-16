#include "client.h"

int main(void)
{
	/*---------------------------------------------------PARTE 2-------------------------------------------------------------*/
	int conexion;
	char* ip;
	char* puerto;
	char* valor;

	//t_log* logger;
	t_config* config;

	//logger = iniciar_logger();

	// Usando el logger creado previamente
	// Escribi: "Hola! Soy un log"

	//config = iniciar_config();
	cargarConfiguracion();
	// Usando el config creado previamente
	// Lee las variables de IP, Puerto y Valor

	//Loggear valor de config

	//leer_consola(logger);


	/*---------------------------------------------------PARTE 3-------------------------------------------------------------*/

	// Antes de continuar, tenemos que asegurarnos que el servidor esté corriendo porque lo necesitaremos para lo que sigue.

	// Creamos una conexión hacia el servidor
	ip=malloc(strlen(configuracion->ipServidor)+1);
	puerto=malloc(strlen(configuracion->puertoServidor)+1);

	memcpy(ip,configuracion->ipServidor,strlen(configuracion->ipServidor));
	ip[strlen(configuracion->ipServidor)]='\0';
	memcpy(puerto,configuracion->puertoServidor,strlen(configuracion->puertoServidor));
	puerto[strlen(configuracion->puertoServidor)]='\0';

	conexion = crear_conexion(ip, puerto);

	//enviar CLAVE al servirdor

	enviar_mensaje(configuracion->clave,conexion);

	paquete(conexion);

	t_paquete* paquete=malloc(sizeof(t_paquete));
	leer_consola_y_armar_paquete(paquete,conexion);

//	while(leer_consola(logger)){
//
//	}

	terminar_programa(conexion, logger, config);

	/*---------------------------------------------------PARTE 5-------------------------------------------------------------*/
	// Proximamente
}

t_log* iniciar_logger(void)
{
	t_log* nuevo_logger;

	return nuevo_logger;
}

t_config* iniciar_config(void)
{
	t_config* nuevo_config;

	return nuevo_config;
}

void leer_consola(t_log* logger)
{
	char* leido;



	//El primero te lo dejo de yapa
    for(;;) {
		leido = readline(">");
		if(strcmp(leido,"0")!=0){
			log_info(logger, leido);
		}else break;
	}

	// Acá la idea es que imprimas por el log lo que recibis de la consola.

	free(leido);

}

void leer_consola_y_armar_paquete(t_paquete* paquete, int socket_cliente) {
	char* leido=string_new();
	int offsetLeido=0;
	char* cadena=string_new();


	paquete = crear_paquete();

	paquete->buffer->stream=malloc(200);

	//El primero te lo dejo de yapa
	for (;;) {
		leido = readline(">");
		if (strcmp(leido, "0") != 0) {
			log_info(logger, leido);
			agregar_a_paquete(paquete,(void*)cadena,strlen(cadena)+1);
			offsetLeido+=strlen(leido);
		} else
			break;
	}
	cadena[offsetLeido]='\0';

	enviar_paquete(paquete, socket_cliente);

	// Acá la idea es que imprimas por el log lo que recibis de la consola.

	free(leido);
}

void paquete(int conexion)
{
	//Ahora toca lo divertido!

	char* leido;
	t_paquete* paquete;


}

void terminar_programa(int conexion, t_log* logger, t_config* config)
{
	//Y por ultimo, para cerrar, hay que liberar lo que utilizamos (conexion, log y config) con las funciones de las commons y del TP mencionadas en el enunciado
	limpiarConfiguracion();
	//free(leido);

}
