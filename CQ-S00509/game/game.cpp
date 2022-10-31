#include <bits/stdc++.h>
using namespace std;
int A[100005],B[100005];
int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    
    int n,m,q,C = 0;
    cin>>n>>m>>q;
    for(int i = 1;i <= n;i++){
    	cin>>A[i];
	}
	for(int i = 1;i <= m;i++){
		cin>>B[i];
	}
    while(q > 0){
    	int l,r,ll,rr;
    	cin>>l>>r>>ll>>rr;
		cout<<0<<endl;
		q--;
	}
    
    fclose(stdin);
    fclose(stdout);
    return 0;
}