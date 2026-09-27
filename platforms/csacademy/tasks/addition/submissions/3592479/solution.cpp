#include <algorithm>
#include <iostream> 
#include <unistd.h>
#include <cstring>

using namespace std;

char buf[100 << 20];
int a, b;

int main() {
    //memset(buf, -1, sizeof(buf));
    scanf("%d %d", &a, &b);
    printf("%d\n", a + b);
    for (int i = 0; i < 1e8; i++) {
        if (i ^ 5) a += i;
    }
    //printf("%d %d %d\n", __GNUC__, __GNUC_MINOR__, __GNUC_PATCHLEVEL__);
    return a == 0;
}
