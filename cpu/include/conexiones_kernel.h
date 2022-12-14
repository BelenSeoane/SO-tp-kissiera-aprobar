#ifndef CONEXIONES_KERNEL_H
#define CONEXIONES_KERNEL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <commons/log.h>
#include <commons/string.h>
#include <commons/config.h>
#include "utils.h"
#include "dispatch.h"
#include "interrupt.h"
#include <pthread.h>
#include "mmu.h"

void recv_proceso(Proceso_CPU*);
void serializar_proceso_bloqueado(Proceso_CPU*, int, void*);
void serializar_proceso_finalizado(Proceso_CPU*, void*);
void serializar_proceso_desalojado(Proceso_CPU*, void*);
void send_proceso_bloqueado(Proceso_CPU*, int);
void send_proceso_finalizado(Proceso_CPU*);
void send_proceso_desalojado(Proceso_CPU*);

#endif /* CONEXIONES_KERNEL_H_ */