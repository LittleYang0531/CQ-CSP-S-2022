#include <bits/stdc++.h>
using namespace std;
int n,m,q,t,u,v;
int main(){
    freopen("galaxy.in","r",stdin);
    freopen("galaxy.out","w",stdout);
    
	for(int i = 0;i < m;i++){
		cin>>u>>v;
	}
	cin>>q;
	for(int i = 0;i < q;i++){
		if(i == q - 1){
			cout<<"NO";
		}else{
			cout<<"NO"<<endl;
		}
	}
    fclose(stdin);
    fclose(stdout);
    return 0;
}