#include <cstdio>
#include <iostream>

using namespace std;

/* Función para leer enteros rápidamente usando getchar_unlocked()
int fastInput() {
    int num = 0;
    char c = getchar_unlocked();
    while (c < '0' || c > '9') {
        c = getchar_unlocked(); // Ignorar caracteres no numéricos
    }
    while (c >= '0' && c <= '9') {
        num = num * 10 + (c - '0');
        c = getchar_unlocked();
    }
    return num;
}*/

// Función para leer enteros rápidamente usando getchar_unlocked()
int fastInput() {
    int num = 0;
    char c = getchar_unlocked();
    
    // Leer hasta encontrar un carácter que no sea un dígito
    while (c >= '0' && c <= '9') {
        num = num * 10 + (c - '0');
        c = getchar_unlocked();
    }
    return num;
}

void fastOutput(int number) {
    if (number < 0) {
        putchar_unlocked('-'); // Imprimir el signo negativo
        number = -number; // Hacer el número positivo
    }

    // Convertir el número a una cadena y almacenar los dígitos
    char buffer[10]; // Asumimos un tamaño suficiente para un entero
    int index = 0;

    do {
        buffer[index++] = (number % 10) + '0'; // Convertir a carácter
        number /= 10;
    } while (number > 0);

    // Imprimir los dígitos en orden inverso
    while (index > 0) {
        putchar_unlocked(buffer[--index]); // Imprimir el carácter
    }
}

// Función para calcular el MCD de dos números
int gcd2(int a, int b) {
    return b ? gcd2(b, a % b) : a;
}

int main() {
    int N = fastInput(); // Leer el número de elementos
    int M = fastInput(); // Leer el número de operaciones
    
    int list[N];
    
    list[0] = fastInput(); // Leer el primer elemento
    int gcd = list[0];
    
    // Leer el resto de los elementos del arreglo
    for (int i = 1; i < N ; i++) {
        list[i] = fastInput();
        gcd = gcd2(gcd, list[i]);
    }
    
    int index, divisor;
    
    // Leer las operaciones y calcular el MCD después de cada operación
    for (int i = 0; i < M ; i++) {
        index = fastInput();   // Leer el índice
        divisor = fastInput(); // Leer el divisor
        
        list[index - 1] /= divisor; // Actualizar el valor en el arreglo
        
        gcd = gcd2(gcd, list[index - 1]); // Calcular el nuevo MCD
        
        fastOutput(gcd);
        putchar_unlocked('\n'); // Nueva línea
    }
    return 0;
}
