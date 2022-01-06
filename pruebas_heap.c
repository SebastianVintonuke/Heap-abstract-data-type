// gcc -g -std=c99 -Wall -Wno-unused-function -Wconversion -Wno-sign-conversion -Werror -o pruebas_heap *.c
// valgrind --leak-check=full --track-origins=yes --show-reachable=yes ./pruebas_heap

#include "heap.h"
#include "testing.h"

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>

//* FUNCION RAND() PARA SIZE_T *//
size_t rand_uint64_slow(void) {
  size_t r = 0;
  for (int i=0; i<64; i++) {
    r = r*2 + rand()%2;
  }
  return r;
}

int max_int(const void *a, const void *b) {
    const int *x = a;
    const int *y = b;
    if (x == y) {
        return 0;
    } else {
        return x > y ? 1 : -1;
    }
}

static void prueba_heap_vacio(void) {
    printf("INICIO DE PRUEBAS HEAP VACIO\n");

    heap_t *heap = heap_crear(max_int);
    print_test("crear heap", heap != NULL);
    print_test("el heap esta vacio", heap_esta_vacio(heap));
    print_test("la cantidad es 0", heap_cantidad(heap) == 0);
    print_test("ver max es NULL", heap_ver_max(heap) == NULL);
    print_test("desencolar es NULL", heap_desencolar(heap) == NULL);
    heap_destruir(heap, NULL);
    print_test("el heap fue destruido", true);
}

static void prueba_heap(void) {
    printf("INICIO DE PRUEBAS DEL HEAP\n");
    
    heap_t *heap = heap_crear(max_int);
    print_test("crear heap", heap != NULL);
    
    /* Declaro las variables a utilizar */
    int n1 = 1;
    int n2 = 2;
    int n3 = 3;
    int n4 = 4;
    int *valor1 = &n1;
    int *valor2 = &n2;
    int *valor3 = &n3;
    int *valor4 = &n4;
    
    /* Pruebo encolar 1 */
    print_test("se encolo el elemento 1", heap_encolar(heap, valor1));
    
    /* Pruebo el elemento encolado */
    print_test("el heap no esta vacio", !heap_esta_vacio(heap));
    print_test("la cantidad es 0", heap_cantidad(heap) == 1);
    print_test("ver max es el elemento 1", heap_ver_max(heap) == valor1);
    
    /* Pruebo encolar 2 */
    print_test("se encolo el elemento 2", heap_encolar(heap, valor2));
    
    /* Pruebo el elemento encolado */
    print_test("el heap no esta vacio", !heap_esta_vacio(heap));
    print_test("la cantidad es 2", heap_cantidad(heap) == 2);
    print_test("ver max es el elemento 2", heap_ver_max(heap) == valor2);
    
    /* Pruebo encolar 4 */
    print_test("se encolo el elemento 4", heap_encolar(heap, valor4));
    
    /* Pruebo el elemento encolado */
    print_test("el heap no esta vacio", !heap_esta_vacio(heap));
    print_test("la cantidad es 2", heap_cantidad(heap) == 3);
    print_test("ver max es el elemento 4", heap_ver_max(heap) == valor4);
    
    /* Pruebo encolar 3 */
    print_test("se encolo el elemento 3", heap_encolar(heap, valor3));
    
    /* Pruebo el elemento encolado */
    print_test("el heap no esta vacio", !heap_esta_vacio(heap));
    print_test("la cantidad es 4", heap_cantidad(heap) == 4);
    print_test("ver max es el elemento 4", heap_ver_max(heap) == valor4);
    
    /* Pruebo desencolar 4 */
    print_test("desencolo el elemento 4", heap_desencolar(heap) == valor4);
    
    /* Pruebo el elemento desencolado */
    print_test("el heap no esta vacio", !heap_esta_vacio(heap));
    print_test("la cantidad es 3", heap_cantidad(heap) == 3);
    print_test("ver max es el elemento 3", heap_ver_max(heap) == valor3);
    
    /* Pruebo desencolar 3 */
    print_test("desencolo el elemento 3", heap_desencolar(heap) == valor3);
    
    /* Pruebo el elemento desencolado */
    print_test("el heap no esta vacio", !heap_esta_vacio(heap));
    print_test("la cantidad es 2", heap_cantidad(heap) == 2);
    print_test("ver max es el elemento 2", heap_ver_max(heap) == valor2);
    
    /* Pruebo encolar 4 */
    print_test("se encolo el elemento 4", heap_encolar(heap, valor4));
    
    /* Pruebo el elemento encolado */
    print_test("el heap no esta vacio", !heap_esta_vacio(heap));
    print_test("la cantidad es 2", heap_cantidad(heap) == 3);
    print_test("ver max es el elemento 4", heap_ver_max(heap) == valor4);
    
    /* Pruebo desencolar 4 */
    print_test("desencolo el elemento 4", heap_desencolar(heap) == valor4);
    
    /* Pruebo el elemento desencolado */
    print_test("el heap no esta vacio", !heap_esta_vacio(heap));
    print_test("la cantidad es 2", heap_cantidad(heap) == 2);
    print_test("ver max es el elemento 2", heap_ver_max(heap) == valor2);
    
    /* Pruebo desencolar 2 */
    print_test("desencolo el elemento 2", heap_desencolar(heap) == valor2);
    
    /* Pruebo el elemento desencolado */
    print_test("el heap no esta vacio", !heap_esta_vacio(heap));
    print_test("la cantidad es 1", heap_cantidad(heap) == 1);
    print_test("ver max es el elemento 1", heap_ver_max(heap) == valor1);
    
    /* Pruebo desencolar 1 */
    print_test("desencolo el elemento 1", heap_desencolar(heap) == valor1);
    
    /* Pruebo que el heap esta vacio */
    print_test("el heap esta vacio", heap_esta_vacio(heap));
    print_test("la cantidad es 0", heap_cantidad(heap) == 0);
    print_test("ver max es NULL", heap_ver_max(heap) == NULL);
    print_test("desencolar es NULL", heap_desencolar(heap) == NULL);
    
    /* Destruyo el heap */
    heap_destruir(heap, NULL);
    print_test("el heap fue destruido", true);
}

static void prueba_heap_arr(void) {
    printf("INICIO DE PRUEBAS DEL HEAP USANDO UN ARR\n");

    /* Declaro las variables a utilizar */
    int n1 = 1;
    int n2 = 2;
    int n3 = 3;
    int n4 = 4;
    int *valor1 = &n1;
    int *valor2 = &n2;
    int *valor3 = &n3;
    int *valor4 = &n4;
    
    void** valores = malloc(sizeof(int*) * 4);
    valores[0] = valor2;
    valores[1] = valor3;
    valores[2] = valor1;
    valores[3] = valor4;
    
    heap_t *heap = heap_crear_arr(valores, 4, max_int);
    print_test("crear heap con un arr", heap != NULL);
    
    /* Pruebo el arreglo */
    print_test("el heap no esta vacio", !heap_esta_vacio(heap));
    print_test("la cantidad es 4", heap_cantidad(heap) == 4);
    
    /* Pruebo desencolar 4 */
    print_test("desencolo el elemento 4", heap_desencolar(heap) == valor4);
    
    /* Pruebo el elemento desencolado */
    print_test("el heap no esta vacio", !heap_esta_vacio(heap));
    print_test("la cantidad es 3", heap_cantidad(heap) == 3);
    print_test("ver max es el elemento 3", heap_ver_max(heap) == valor3);
    
    /* Pruebo desencolar 3 */
    print_test("desencolo el elemento 3", heap_desencolar(heap) == valor3);
    
    /* Pruebo el elemento desencolado */
    print_test("el heap no esta vacio", !heap_esta_vacio(heap));
    print_test("la cantidad es 2", heap_cantidad(heap) == 2);
    print_test("ver max es el elemento 2", heap_ver_max(heap) == valor2);
    
    /* Pruebo encolar 4 */
    print_test("se encolo el elemento 4", heap_encolar(heap, valor4));
    
    /* Pruebo el elemento encolado */
    print_test("el heap no esta vacio", !heap_esta_vacio(heap));
    print_test("la cantidad es 2", heap_cantidad(heap) == 3);
    print_test("ver max es el elemento 4", heap_ver_max(heap) == valor4);
    
    /* Pruebo desencolar 4 */
    print_test("desencolo el elemento 4", heap_desencolar(heap) == valor4);
    
    /* Pruebo el elemento desencolado */
    print_test("el heap no esta vacio", !heap_esta_vacio(heap));
    print_test("la cantidad es 2", heap_cantidad(heap) == 2);
    print_test("ver max es el elemento 2", heap_ver_max(heap) == valor2);
    
    /* Pruebo desencolar 2 */
    print_test("desencolo el elemento 2", heap_desencolar(heap) == valor2);
    
    /* Pruebo el elemento desencolado */
    print_test("el heap no esta vacio", !heap_esta_vacio(heap));
    print_test("la cantidad es 1", heap_cantidad(heap) == 1);
    print_test("ver max es el elemento 1", heap_ver_max(heap) == valor1);
    
    /* Pruebo desencolar 1 */
    print_test("desencolo el elemento 1", heap_desencolar(heap) == valor1);
    
    /* Pruebo que el heap esta vacio */
    print_test("el heap esta vacio", heap_esta_vacio(heap));
    print_test("la cantidad es 0", heap_cantidad(heap) == 0);
    print_test("ver max es NULL", heap_ver_max(heap) == NULL);
    print_test("desencolar es NULL", heap_desencolar(heap) == NULL);
    
    /* Destruyo el heap */
    heap_destruir(heap, NULL);
    print_test("el heap fue destruido", true);
    
    free(valores);  
}

static void prueba_heap_destruir(size_t tam) {
    printf("INICIO DE PRUEBAS DESTRUIR HEAP\n");
    
    heap_t *heap = heap_crear(max_int);
    print_test("crear heap", heap != NULL);
    
    bool ok = true;
    size_t* dato;
    for (size_t i = 0; i < tam; i++) {
        dato = malloc(sizeof(size_t));
        *dato = i;
        ok &= heap_encolar(heap, dato);
    }

    print_test("se pudieron encolar todos los elementos", ok);
    
    /* Destruyo el heap*/
    heap_destruir(heap, free);
    print_test("el heap lleno fue destruido", true);   
}

static void prueba_heap_volumen(size_t tam) {
    printf("INICIO PRUEBAS DE HEAP DE VOLUMEN\n");
    
    heap_t *heap = heap_crear(max_int);
    print_test("crear heap", heap != NULL);
    
    void** datos = malloc(sizeof(void*) * tam);
    void** datos_aux = malloc(sizeof(void*) * tam);
    
    size_t* dato;
    for (size_t i = 0; i < tam; i++) {
        dato = malloc(sizeof(size_t));
        *dato = i;
        datos[i] = dato;
        datos_aux[i] = dato;
    }
    
    void* aux;
    for (size_t i = 0; i < tam; i++) {
        size_t random = rand_uint64_slow() % tam;
        aux = datos[i];
        datos[i] = datos[random];
        datos[random] = aux;
    }
    
    bool ok = true;
    for (size_t i = 0; i < tam; i++) {
        ok &= heap_encolar(heap, datos[i]);
    }
    
    print_test("se pudieron encolar todos los elementos", ok);
    
    bool ok1 = true;
    bool ok2 = true;
    bool ok3 = true;
    bool ok4 = true;
    
    for (size_t i = 0; i < tam; i++) {
        if (heap_esta_vacio(heap)) {
            ok1 = false;
            break;
        } else if (heap_cantidad(heap) != tam - i) {
            ok2 = false;
            break;
        } else if (heap_ver_max(heap) != datos_aux[tam - i - 1]) {
            ok3 = false;
            break;
        } else if (heap_desencolar(heap) != datos_aux[tam - i - 1]) {
            ok4 = false;
            break;
        }
    }
    
    print_test("vacios correctos", ok1);
    print_test("cantidades correctas", ok2);
    print_test("ver max correctos", ok3);
    print_test("desencolar correctos", ok4);
    
    /* Destruyo el heap*/
    heap_destruir(heap, NULL);
    print_test("el heap fue destruido", true);
    
    printf("PRUEBAS CON ARR\n");
    /* Pruebo con arr */
    heap = heap_crear_arr(datos, tam, max_int);
    
    ok1 = true;
    ok2 = true;
    ok3 = true;
    ok4 = true;
    
    for (size_t i = 0; i < tam; i++) {
        if (heap_esta_vacio(heap)) {
            ok1 = false;
            break;
        } else if (heap_cantidad(heap) != tam - i) {
            ok2 = false;
            break;
        } else if (heap_ver_max(heap) != datos_aux[tam - i - 1]) {
            ok3 = false;
            break;
        } else if (heap_desencolar(heap) != datos_aux[tam - i - 1]) {
            ok4 = false;
            break;
        }
    }
    
    print_test("vacios correctos", ok1);
    print_test("cantidades correctas", ok2);
    print_test("ver max correctos", ok3);
    print_test("desencolar correctos", ok4);
    
    /* Destruyo el heap*/
    heap_destruir(heap, NULL);
    print_test("el heap fue destruido", true);
    
    for (size_t i = 0; i < tam; i++) {
        free(datos[i]);
    }
    free(datos);
    free(datos_aux);
}

static void Prueba_heap_sort(void) {
    printf("INICIO PRUEBAS DE HEAP_SORT\n");
    
    /* Declaro las variables a utilizar */
    int n1 = 1;
    int n2 = 2;
    int n3 = 3;
    int n4 = 4;
    int n5 = 5;
    int n6 = 6;
    int n7 = 7;
    int n8 = 8;
    int n9 = 9;
    int *valor1 = &n1;
    int *valor2 = &n2;
    int *valor3 = &n3;
    int *valor4 = &n4;
    int *valor5 = &n5;
    int *valor6 = &n6;
    int *valor7 = &n7;
    int *valor8 = &n8;
    int *valor9 = &n9;
    
    void* datos[] = {valor2, valor3, valor6, valor1, valor4, valor9, valor8, valor5, valor7, valor6};
    
    /* Ordeno */
    heap_sort(datos, 9, max_int);
    
    bool ok = true;
    for (int i = 0; i < 9; i++) {
        ok &= *(int*)datos[i] == i + 1;
    }
    
    print_test("el orden es correcto", ok);
}

static void Prueba_heap_sort_volumen(size_t tam) {
    printf("INICIO PRUEBAS DE HEAP_SORT DE VOLUMEN\n");
    
    void** datos = malloc(sizeof(void*) * tam);
    void** datos_aux = malloc(sizeof(void*) * tam);
    
    size_t* dato;
    for (size_t i = 0; i < tam; i++) {
        dato = malloc(sizeof(size_t));
        *dato = i;
        datos[i] = dato;
        datos_aux[i] = dato;
    }
    
    void* aux;
    for (size_t i = 0; i < tam; i++) {
        size_t random = rand_uint64_slow() % tam;
        aux = datos[i];
        datos[i] = datos[random];
        datos[random] = aux;
    }
    
    /* Ordeno */
    heap_sort(datos, tam, max_int);
    
    bool ok = true;
    for (size_t i = 0; i < tam; i++) {
        ok &= datos[i] == datos_aux[i];
    }
    
    print_test("el orden es correcto", ok);  
    
    for (size_t i = 0; i < tam; i++) {
        free(datos[i]);
    }
    free(datos);
    free(datos_aux);
}

void pruebas_heap_estudiante() {
    prueba_heap_vacio();
    prueba_heap();
    prueba_heap_arr();
    prueba_heap_destruir(500);
    prueba_heap_volumen(500);
    Prueba_heap_sort();
    Prueba_heap_sort_volumen(500);
}

#ifndef CORRECTOR

int main(void) {
    pruebas_heap_estudiante();
    return failure_count() > 0;
}

#endif
