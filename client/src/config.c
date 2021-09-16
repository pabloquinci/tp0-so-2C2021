#include "client.h"

int configValida(t_config* fd_configuracion) {
	return (config_has_property(fd_configuracion, "CLAVE") &&
			config_has_property(fd_configuracion, "IP_SERVIDOR")&&
			config_has_property(fd_configuracion, "PUERTO_SERVIDOR"));
}

int cargarConfiguracion() {
	logger = log_create("LOGTp0", "TP0", true, LOG_LEVEL_INFO);
	configuracion = malloc(sizeof(tConfiguracion));

	if (fd_configuracion == NULL) {
		fd_configuracion = config_create("client.config");
	}

	if (fd_configuracion == NULL || !configValida(fd_configuracion)) {
		log_error(logger,"Archivo de configuración inválido.","ERROR");
		return -1;
	}
	configuracion->clave = config_get_string_value(fd_configuracion, "CLAVE");
	configuracion->ipServidor = config_get_string_value(fd_configuracion, "IP_SERVIDOR");
	configuracion->puertoServidor = config_get_string_value(fd_configuracion, "PUERTO_SERVIDOR");





	log_info(logger,
			"\nCLAVE: %s\n"
			"IP_SERVIDOR%s\n"
			"\nPUERTO_SERVIDOR%s\n",
			configuracion->clave,
			configuracion->ipServidor,
			configuracion->puertoServidor);
	return 0;
}

void limpiarConfiguracion() {
	free(configuracion);
	config_destroy(fd_configuracion);
	log_destroy(logger);

}
