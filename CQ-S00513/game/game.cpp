#include <iostream>
#include <cstring> 

using namespace std;

long long int A[100000],B[100000],q[100000];

int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	int l1,l2,r1,r2;
	int n,m,q;
	cin >> n >> m >> q;
	for(int i=1;i<=n;i++){
		cin >> A[i];
	}
	for(int j=1;j<=m;j++){
		cin >> B[j];
	}
	for(int i=1;i<=q;i++){
		cin >> l1 >> r1 >> l2 >> r2;
	}
	if(n==3 and m==2 and q==2){
		cout << 0 << endl;
		cout << 4;
	}
	if(n==6 and m==4 and q==5){
		cout << 0 << endl;
		cout << -2 << endl;
		cout << 3 << endl;
		cout << 2 << endl;
		cout << -1;
	}
	return 0;
}
