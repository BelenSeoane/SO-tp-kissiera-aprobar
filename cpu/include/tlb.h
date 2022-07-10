#ifndef TLB_H_
#define TLB_H_

#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

int buscar_entrada_en_tlb(int, int tlb[][3], int);
int esta_en_tlb(int, int tlb[][3], int);
int obtener_marco_asociado(int, int, int tlb[][3]);
void inicializar_tlb(int tlb[][3], int);
void agregar_direccion(int, int, int tlb[][3], int);
void printear(int tlb[][3], int);
bool esta_llena(int tlb[][3], int);
void reemplazo_fifo(int, int, int tlb[][3], int);
void reemplazo_lru(int, int, int tlb[][3], int);

#endif /* TLB_H_ */