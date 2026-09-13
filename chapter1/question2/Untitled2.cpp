#include <bits/stdc++.h> 

using namespace std; 
// ham xu ly xau ki tu 
int String_process( string line ) {
	string command; 
	int k; 
	stringstream ss( line ); 
	ss >> command >> k; // su dung stringstream de tach hai token co chua space 
	return k; 
} 
int main(){
	int n; cin >> n; // so phan tu trong mang 
	vector<int> v; 
	// nhap cac phan tu vao vector 
	for ( int i = 0; i < n ; i++) {
		int x; cin >> x; 
		v.push(x); 
	}
	sort(v.begin(), v.end()); // sort hàm 
	while(1){
		String s; 
		getline(s, cin ); 
		if ( s == "#") return; 
		else {
			int val = String_process(s); // gia tri can dem di tim theo yc de bai 
			int ckc = 0; 
			for ( int i = 0 ; i < n ; i++){
				if( v[i] == val ) {
					cout << v[i++]; 
					ckc = 1; 
					break; 
				}
			}
			if ( ckc = 0) cout << -1 << endl ;  
		} 
	} 
}


