#include<bits/stdc++.h>
using namespace std;
int n,m,q;
signed main(){
	freopen("transmit.in","r",stdin);
	freopen("transmit.out","w",stdout);
	srand(time(NULL));
	cin >>n>>m>>q;
	while(q--){
		cout <<rand()%(n*m)<<endl;
	}
}
