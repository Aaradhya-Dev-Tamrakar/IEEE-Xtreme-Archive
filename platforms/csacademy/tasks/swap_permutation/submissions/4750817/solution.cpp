#include <stdio.h>
#include <stdlib.h>

inline long int read() {
    char c = getchar();
    long int num = 0;
    int sign = 1;
    while (c < '0' || c > '9') {
        if (c == '-') sign = -1;
        c = getchar();
    }
    while (c >= '0' && c <= '9') {
        num = num * 10 + c - '0';
        c = getchar();
    }
    return num * sign;
}


int N;
int M;
int K;

int main() {

    scanf("%d %d %d", &N, &M, &K);
    getchar();

    int a[M], b[M];
    int chainA[M];
    int chainB[M];
    
    int index;
    int indexB = M - 1;
    int firstA0 = 0;
    int currentFE = 1;  // Posición del primer elemento
    int currentKE = K;   // Posición del elemento K

    for (index = 0; index < M; index++) {
        a[index] = read();
        b[index] = read();
    }
    

    for (index = 0; index < M; index++) {
        
        chainA[index] = currentFE;
        
        if (a[index] == currentFE) {
            currentFE = b[index];
        } else if (b[index] == currentFE) {
            currentFE = a[index];
        }

        chainB[indexB] = currentKE;
        
        
        if (a[indexB] == currentKE) {
            currentKE = b[indexB];
        } else if (b[indexB] == currentKE) {
            currentKE = a[indexB];
        }
        
        indexB --;
        
    }
    
    for (index = 0; index < M; index++) {
        if (chainA[index] == chainB[index]) {
            printf("%d \n", index + 1);
            return 0;
        }else if(firstA0 == 0){
            firstA0 = index + 1;
        }
    }
    printf("%d \n", firstA0);
}
