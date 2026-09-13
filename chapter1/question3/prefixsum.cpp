#include < bits/stdc++.h> 

using namespace std; 

int main(){
	int n; cin >> n ;
	vector<int> v; 
	for( int i = 0; i < n ; i++){
		int tmp; cin >> tmp; 
		v.push_back(tmp); 
	}
	int k; cin >> k; 
	
	while ( k > 0 ){
		int i,j; 
		cin >> i >> j; 
		int res = 0; 	
		for ( int m = i; i < j ; i ++){
			res += v[i]; 
		}
		return res; 
		k --;
	}
}
