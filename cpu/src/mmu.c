#include "../include/mmu.h"

int traducir_direccion(int direccion_logica, int tlb[][3], int tamanio, int pid) {

    int numero_pagina = floor(direccion_logica / tamanio_pagina);
    int marco_tlb = buscar_entrada_en_tlb(numero_pagina, tlb, tamanio);

    if(marco_tlb != -1) { //tlb devuelve -1 si no la tiene
        int direccion_fisica = marco_tlb * tamanio_pagina + (direccion_logica - numero_pagina * tamanio_pagina);
        log_info(logger, "La direccion fisica final es %d", direccion_fisica);
        return direccion_fisica;
    } else {
        int direccion_fisica;
        int marco;
        
        calcular_dir_fisica(direccion_logica, pid, &direccion_fisica, &marco);
        eliminar_entrada(marco, tamanio, tlb);
        agregar_direccion(numero_pagina, marco, tlb, tamanio);

        return direccion_fisica;
    }
}

void calcular_dir_fisica(int direccion_logica, int pid, int *direccion_fisica, int *marco) {
    int numero_pagina = floor(direccion_logica / tamanio_pagina);
    int entrada_tabla_primer_nivel = floor(numero_pagina / cant_entradas_tabla);
    send_pedido_tabla_segundo_nivel(entrada_tabla_primer_nivel, pid);
    
    int direc_tabla_segundo_nivel;
    recv(conexion_memoria, &direc_tabla_segundo_nivel, sizeof(int), 0);
    log_info(logger, "Recibi direccion tabla segundo nivel: %d", direc_tabla_segundo_nivel);
    
    int entrada_tabla_segundo_nivel = numero_pagina % cant_entradas_tabla;
    send_pedido_marco(pid, direc_tabla_segundo_nivel, entrada_tabla_segundo_nivel);

    recv(conexion_memoria, marco, sizeof(int), 0);
    log_info(logger, "Recibi marco: %d", *marco);

    //Se podria enviar desde memoria ademas un int que avise si fue page fault o no
    //Haciendo eso nos podriamos ahorrar tener que verificar de limpiar la tlb siempre

    *direccion_fisica = *marco * tamanio_pagina + (direccion_logica - numero_pagina * tamanio_pagina);
    log_info(logger, "La direccion fisica final es %d", *direccion_fisica);
}