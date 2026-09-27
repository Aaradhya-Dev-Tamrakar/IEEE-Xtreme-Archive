#include <iostream>
using namespace std;

int n;
int a[5010];
int m[5010];
int v[5010];

int main () {

	cin >> n;
	
	int mini = -1, maxi = 0;
	for (int i = 0; i < n; i ++) {
		cin >> a[i];
		if (mini == -1 || a[i] < mini) {
			mini = a[i];
		}
		if (a[i] > maxi) {
			maxi = a[i];
		}
	}

	for (int i = 0; i < n; i ++) {
		if (i > 0) {
			m[i] = m[i-1];
			v[i] = v[i-1];
		}
		if (a[i] == mini) m[i] ++;
		if (a[i] == maxi) v[i] ++;
		
		//cout << m[i] << " " << v[i] << "\n";
	}
	
	int siz = -1;
	for (int i = 0; i < n; i ++) {
		for (int j = i; j < n; j ++) {
			int kolm = m[j];
			int kolv = v[j];
			if (i > 0) {
				kolm -= m[i-1];
				kolv -= v[i-1];
			}
			
			if (kolm > 0 && kolv > 0 && (siz == -1 || j - i + 1 < siz)) {
				siz = j - i + 1;
			}
		}
	}
	
	cout << siz;

	return 0;
}
