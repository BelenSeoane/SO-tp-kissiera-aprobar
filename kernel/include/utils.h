#ifndef UTILS_H_
#define UTILS_H_

#include <stdio.h>
#include <stdlib.h>
#include <commons/config.h>
#include <commons/log.h>
#include <string.h>
#include <sys/socket.h>
#include "../../shared/include/shared.h"
#include <commons/collections/list.h>
#include <pthread.h>
#include "pcb.h"
#include "pedidos.h"
#include "planificacion.h"
#include <semaphore.h>
#include <time.h>
#include <sys/timeb.h>

typedef struct {
	char* IP_MEMORIA;
	char* IP_CPU;
	char* IP_KERNEL;
	char* PUERTO_MEMORIA;
	char* PUERTO_CPU_DISPATCH;
	char* PUERTO_CPU_INTERRUPT;
	char* PUERTO_ESCUCHA;
	char* ALGORITMO_PLANIFICACION;
	int ESTIMACION_INICIAL;
	double ALFA;
	int GRADO_MULTIPROGRAMACION;
	int TIEMPO_MAXIMO_BLOQUEADO;
} Config;

typedef struct {
    int cliente_fd;
} args_thread;

t_log* logger;
Config config;
int kernel_server;

// Conexiones
int conexion_dispatch;
int conexion_interrupt;
int conexion_memoria;

// Hilo IO
pthread_t hilo_IO; 

// Hilos Planificadores
pthread_t hilo_new_ready; 
pthread_t hilo_ready_susp_ready;
pthread_t hilo_ready_exec;
pthread_t hilo_bloqueado_a_bloqueado_susp;
pthread_t hilo_bloqueado_susp_a_susp_ready;

// Hilos dispatch e interrupt
pthread_t hilo_atender_pedidos_dispatch;

// Semaforos para eventos de planificadores
sem_t sem_hilo_new_ready;
sem_t sem_hilo_ready_susp_ready;
sem_t sem_hilo_bloqueado_a_bloqueado_susp;
sem_t sem_hilo_bloqueado_susp_a_susp_ready;
sem_t sem_planificar_FIFO;
sem_t sem_planificar_SRT;
sem_t sem_hay_procesos_en_ready;
sem_t sem_hilo_exec_exit;
sem_t finalizar;
sem_t sem_ejecutar_IO;
sem_t IO_esta_disponible;
sem_t sem_grado_multiprogramacion;
sem_t sem_hilo_blocked_a_blocked_susp;
sem_t sem_priorizar;
sem_t sem_desalojar;

// Mutex - Estados del proceso
pthread_mutex_t mutexNew;
pthread_mutex_t mutexReady;
pthread_mutex_t mutexBlock;
pthread_mutex_t mutexExe;
pthread_mutex_t mutexExit;
pthread_mutex_t mutexSuspendedBlocked;
pthread_mutex_t mutexSuspendedReady;

pthread_mutex_t mutexProcesosQueSeVanASuspender;

// Mutex - Variables globales
pthread_mutex_t mutex_vg_ex;
pthread_mutex_t mutex_vg_io;

// Listas - Estados del proceso
t_list *cola_new;
t_list *cola_ready;
t_list *cola_blck;
t_list *cola_suspended_ready;
t_list *cola_suspended_blck;

t_list *procesos_que_se_van_a_suspender;

void cargarConfig(char*, Config*);
void inicializar_colas();
void inicializar_semaforos();
void inicializar_logger();
void inicializar_config();
void inicializar_servidor();
void inicializar_conexiones();
void destroy_recursos();
void inicializar_planificacion();
void* ejecutar_IO();
void print_colas();
void print_elementos_de_una_cola(t_list *);

#endif
