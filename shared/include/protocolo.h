#ifndef PROTOCOLO_H
#define PROTOCOLO_H

typedef enum {
	ENVIAR_INSTRUCCIONES,
	READ_M,
	WRITE_M, //les agrego _M (de memoria) para que no interfieran con los codigos de instruccion
	INIT_PROCESO,
	EXEC_PROCESO, //se manda proceso a cpu
	BLOCK_PROCESO,
	DESALOJO_PROCESO,
	EXIT_PROCESO,
	EXIT_PROCESO_M,
	INTERRUPCION,
	HANDSHAKE_MEMORIA,
	ENVIAR_TABLA_PRIMER_NIVEL,
	ENVIAR_TABLA_SEGUNDO_NIVEL,
	SWAP_IN,
	SWAP_OUT
}accion;

#endif