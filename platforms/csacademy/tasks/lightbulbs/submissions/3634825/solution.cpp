#include <iostream>
#include <set>
#include <vector>
#include <queue>
#include <string>
#define boost() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);


using namespace std;


int main() {
    boost();
    string gray, binary;
    cin >> gray;
    binary = gray[0];
    for (int i = 0; i < gray.length() - 1; i++)
        binary += binary[i] == gray[i + 1] ? "0" : "1";

    cout << stoll(binary, nullptr, 2);
    return 0;
}