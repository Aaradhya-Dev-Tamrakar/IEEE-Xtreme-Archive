#include <stdio.h>
#include <stdlib.h>

#define max(X,Y) ((X)>(Y))? (X):(Y)

int partition(int * , int );

int main(void){
    int N;
    scanf("%d", &N);
    int *list=malloc((N+1) * sizeof(int)), i;
    for (i=0;i<N;i++) scanf("%d", &list[i]);
    list[N]=0;
    printf("%d", partition(list, 0));
    free(list);
}

int partition(int *list, int prev){
    int index=0, iter=0, broke=0, pivot=0;

    while(list[index]) {
        pivot=max(pivot, list[index]);
        for (iter=index;list[iter];iter++) {
            if(pivot>list[iter] && iter-index>=1){
                broke=1;
                break;
            }
        }
        index++;
        if(broke) broke = 0;
        else return partition(&list[index], prev+1);
    }
    return prev;
}