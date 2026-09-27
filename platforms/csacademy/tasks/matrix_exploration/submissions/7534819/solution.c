#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#include <stdio.h>
#include <stdlib.h>

#define INDEX(x, y, M) ((x) * (M) + (y))

// Búfer gigante para cargar TODA la entrada de golpe a la memoria RAM (Aproximadamente 3 MB)
#define BUFFER_SIZE 3500000
char input_buffer[BUFFER_SIZE];
int buffer_ptr = 0;

// Función en línea para leer enteros directamente desde nuestro bloque de memoria RAM
static inline int leer_entero_rapido() {
    int numero = 0;
    while (input_buffer[buffer_ptr] < '0' || input_buffer[buffer_ptr] > '9') {
        buffer_ptr++;
    }
    while (input_buffer[buffer_ptr] >= '0' && input_buffer[buffer_ptr] <= '9') {
        numero = numero * 10 + (input_buffer[buffer_ptr] - '0');
        buffer_ptr++;
    }
    return numero;
}

int main() {
    // LEER TODO EL ARCHIVO DE GOLPE: Reducimos las peticiones al sistema operativo a UNA sola
    int bytes_leidos = fread(input_buffer, 1, BUFFER_SIZE, stdin);
    
    int N = leer_entero_rapido();
    int M = leer_entero_rapido();
    int K = leer_entero_rapido();
    
    int total_casillas = N * M;
    
    // Matriz plana y colas paralelas optimizadas
    short matriz[total_casillas];
    short cola_x[total_casillas];
    short cola_y[total_casillas];

    // Procesar el mapa directamente desde el búfer de memoria
    for (int i = 0; i < N; i++) {
        int fila_offset = i * M;
        // Saltarse los caracteres que no sean el mapa (espacios o saltos de línea)
        while (input_buffer[buffer_ptr] != '.' && input_buffer[buffer_ptr] != '#') {
            buffer_ptr++;
        }
        for (int j = 0; j < M; j++) {
            if (input_buffer[buffer_ptr] == '.') {
                matriz[fila_offset + j] = -2;
            } else {
                matriz[fila_offset + j] = -1;
            }
            buffer_ptr++;
        }
    }

    // Leer puntos especiales directamente de la memoria
    for (int i = 0; i < K; i++) {
        int x_val = leer_entero_rapido() - 1;
        int y_val = leer_entero_rapido() - 1;
        cola_x[i] = x_val;
        cola_y[i] = y_val;
        matriz[INDEX(x_val, y_val, M)] = 0;
    }

    int frente = 0, fin = K;

    // Bucle principal BFS optimizado con aritmética lineal plana
    while (frente < fin) {
        int x = cola_x[frente];
        int y = cola_y[frente];
        frente++;
        
        int idx_actual = INDEX(x, y, M);
        short val = matriz[idx_actual];
        short sgte_val = val + 1;
        
        // Norte
        if (x > 0) {
            int idx = idx_actual - M;
            if (matriz[idx] == -2) {
                matriz[idx] = sgte_val;
                cola_x[fin] = x - 1; cola_y[fin] = y; fin++;
            }
        }
        // Oeste
        if (y > 0) {
            int idx = idx_actual - 1;
            if (matriz[idx] == -2) {
                matriz[idx] = sgte_val;
                cola_x[fin] = x; cola_y[fin] = y - 1; fin++;
            }
        }
        // Sur
        if (x < N - 1) {
            int idx = idx_actual + M;
            if (matriz[idx] == -2) {
                matriz[idx] = sgte_val;
                cola_x[fin] = x + 1; cola_y[fin] = y; fin++;
            }
        }
        // Este
        if (y < M - 1) {
            int idx = idx_actual + 1;
            if (matriz[idx] == -2) {
                matriz[idx] = sgte_val;
                cola_x[fin] = x; cola_y[fin] = y + 1; fin++;
            }
        }
    }

    int val_total = 0;
    for (int i = 0; i < total_casillas; i++) {
        if (matriz[i] > 0) {
            val_total += matriz[i];
        }
    }

    printf("%d\n", val_total);
    return 0;
}
