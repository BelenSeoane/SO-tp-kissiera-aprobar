#ifndef MANEJO_MEMORIA_H
#define MANEJO_MEMORIA_H

#include <stdio.h>
#include <stdlib.h>
#include "../../shared/include/shared.h"
#include <commons/bitarray.h>
#include "utils.h"
#include <math.h>

uint32_t asignar_memoria_y_estructuras(int, int);
void verificar_memoria();
void finalizar_estructuras_del_proceso_y_avisar_a_kernel(int,int);
void solicitar_pagina_a_swap(int, int, int);
int cargar_pagina_en_memoria(int);
void actualizar_tabla_de_paginas(int, int, int, int);
void generar_lista_de_paginas_cargadas(int);
void actualizar_bit_presencia(int);
void actualizar_bit_modificado(int, int);
int buscar_index_puntero_para_aplicar_algoritmo();
int aplicar_algoritmo_de_sustitucion_clock();
int aplicar_algoritmo_de_sustitucion_clock_modificado();
void eliminar_archivo_swap(int);
void solicitar_swap_out_a_swap(int, int, int);
void buscar_numero_de_pagina(int, int, pagina_victima*);
bool escribir_paginas_modificadas(int);
void mostrar_bitmap();
void actualizar_bit_uso(int, int);


#endif