#include <iostream>
using namespace std;

// Segmet tree for sum over a range of an array

int lazy[14];
int segtree[14];
int arr[7];
void build(int node, int start, int end){
	if(start == end){
		// Leaf node
		segtree[node] = arr[start];
	}
	else{

		int mid = (start + end) / 2; // find mid point of range

		build(2*node, start, mid); // recursive call to left child

		build(2*node + 1, mid+1, end); // recursive call to right child

		segtree[node] = segtree[2*node] + segtree[2*node + 1]; // merge step
	}
}

void update(int node, int start, int end, int l, int r, int val){
	if(lazy[node] != 0){
		segtree[node] += (end - start) * lazy[node];
		if(start != end){
			lazy[2*node] += lazy[node];
			lazy[2*node + 1] += lazy[node];
		}
		lazy[node] = 0;
	}

	if(start > r || end <l){
		return 0 ;
	}

	if(l<= start && end <= r){
		segtree[node] += (end - start + 1) * val; 
		if(start != end){
			lazy[2*node] += val;
			lazy[2*node + 1] += val;
		}
	}
	else{
		int mid = (start + end ) / 2;
		if (start <= idx && idx<= mid){
			update(2*node, start, mid, idx, val);
		}
		else{
			update(2*node + 1, mid + 1, end , idx, val);	
		}
		segtree[node] = segtree[2*node] + segtree[2*node + 1];
	}
}

int query(int node, int start, int end, int l, int r){
	
	if(lazy[node] != 0){
		segtree[node] += (end - start) * lazy[node];
		if(start != end){
			lazy[2*node] += lazy[node];
			lazy[2*node + 1] += lazy[node];
		}
		lazy[node] = 0;
	}

	if(start > r || end <l){
		return 0 ;
	}

	if(l<= start && end <= r){
		return segtree[node];
	}

	int mid = (start + end ) /2;
	int p1 = query(2*node, start,mid, l,r);
	int p2 = query(2*node + 1, mid + 1, end, l,r);
	return ( p1+ p2);
}

int main() {
	
	for (int i = 0; i < 7; ++i){
		arr[i] = i;
	}
	build(1,0,6);
	update(1,0,6,3,0);

	cout<<query(1,0,6,0,6)<<endl;
	return 0;
}