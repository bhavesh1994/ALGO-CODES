#include <bits/stdc++.h>
using namespace std;

vector<int> inverseArray(int n, int m) {
    vector<int> modInverse(n + 1,0);
    modInverse[1] = 1;
    for(int i = 2; i <= n; i++) {
        modInverse[i] = (-(m/i) * modInverse[m % i]) % m + m;
    }
    return modInverse;
}

int main() {
	ios_base::sync_with_stdio(0);
	int n;
	cin>>n;
	
}