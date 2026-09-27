#include <iostream>
#include <vector>

using namespace std;
int mcd(int a, int b){
    if(b==0){
        return a;
    }else{
        return mcd(b,a%b);
    }
}

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> array(N);
    for(int i=0; i<N; i++){
        cin >> array[i];
    }
    //Mcd inicio
    int mcd_actual=array[0];
    for(int i=1; i<N; i++){
        mcd_actual=mcd(mcd_actual,array[i]);
    }
    for(int i=0; i<M; i++){
        //lee operaciones
        int pos,div;
        scanf("%d %d", &pos, &div);
        //hace operacion
        array[pos-1]=array[pos-1]/div;
        //divide las operaciones
        mcd_actual=mcd(mcd_actual,array[pos-1]);
        printf("%d\n",mcd_actual);
    }
    return 0;
}