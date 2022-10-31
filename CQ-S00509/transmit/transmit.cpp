#include <bits/stdc++.h>
using namespace std;

int v[200005];
int a[200005][100];

int main(){
    freopen("transmit.in","r",stdin);
    freopen("transmit.out","w",stdout);
    int n,Q,k,x,y,w = 0;
    cin>>n>>Q>>k;
    for (int i = 0;i < n;i++){
    	cin>>v[i];
	}
	for(int i = 0;i < n - 1;i++){
		cin>>x>>y;
		for(int j = 0;j < 100;j++){
			if(a[x][j] == 0){
				a[x][j] = y;
				goto label2;
			}
		}
		label2:
			w--;
	}
	while(Q--){
		cin>>x>>y;
		for(int i = 0;i < 100;i++){
			if(a[x][i] == y){
				cout<<v[x - 1] + v[y - 1]<<endl;
				goto label;
			}
		}
		
		cout<<v[x - 1] + v[y - 1] + v[0]<<endl;
		
		label:
			w--;
	}
    fclose(stdin);
    fclose(stdout);
    return 0;
}