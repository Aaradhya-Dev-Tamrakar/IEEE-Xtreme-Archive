#include <iostream>
#include <stack>

using namespace std;

int main() {
    int N, i, j, currMax, tempMax, index, count = 0;
    int* arr;
    
    // input
    cin >> N;
    arr = new int[N];
    for(i = 0; i < N; i++)
    {
        cin >> arr[i];
    }
    
    i = 0;
    while(i < N)
    {
        currMax = arr[i]; tempMax = arr[i]; index = i;
        for(j = i; j < N; j++)
        {
            if(arr[j] < currMax)
            {
                currMax = tempMax;
                index = j;
            }
            else if(arr[j] > tempMax)
            {
                tempMax = arr[j];
            }
        }
        i = index + 1;
        count++;
    }
    
    cout << count << endl;
    
    delete[] arr;
    return 0;
}