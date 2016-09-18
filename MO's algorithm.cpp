#include <bits/stdc++.h>
using namespace std;

#define N 311111
#define A 1111111
#define BLOCK 555 // ~sqrt(N)

int cnt[A], arr[N], ans[N], answer = 0;

struct query
{
	int l;
	int r;
	int i;
}q[N];

bool cmp(node x, node y) {
	if(x.l/BLOCK != y.l/BLOCK) {
		// different blocks, so sort by block.
		return x.l/BLOCK < y.l/BLOCK;
	}
	// same block, so sort by R value
	return x.r < y.r;
}

void add(int position) {
	cnt[arr[position]]++;
	if(cnt[arr[position]] == 1) {
		answer++;
	}
}

void remove(int position) {
	cnt[arr[position]]--;
	if(cnt[arr[position]] == 0) {
		answer--;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	
	int m;
	cin>>m;
	for(int i=0;i<m;i++){
		cin>>q[i].l>>q[i].r;
		q[i].l--; q[i].r--;
		q[i].i = i;
	}

	sort(q, q + m, cmp);

	int currentL = 0, currentR = 0;
	for(int i=0;i<m;i++){
		int l,r;
		l = q[i].l;
		r = q[i].r;
		while(currentL<l){
			remove(currentL);
			currentL++;
		}
		while(currentL>l){
			add(currentL-1);
			currentL--;
		}
		while(currentR<r){
			add(currentR+1);
			currentR++;
		} 
		while(currentR>r){
			remove(currentR);
			currentR--;
		}
		ans[q[i].i] = answer;
	}
}