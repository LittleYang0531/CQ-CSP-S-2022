#include<iostream>
using namespace std;
const int N=1000;
int n,m,q;
int u,v,cnt;
int t;
bool a[N][N],ans[500000],flag;
int main(){
	freopen("galaxy.in","r",stdin);
	freopen("galaxy.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<m;i++){
		cin>>u>>v;
		a[u-1][v-1]=true;
//		live[u]=true;
//		live[v]=true;
	}
	cin>>q;
//	for(int j=0;j<n;j++){
//			for(int k=0;k<n;k++){
//				cout<<a[j][k]<<' ';
//			}
//			cout<<endl;
//		}
	for(int i=0;i<q;i++){
		cin>>t;
		if(t==1){
			cin>>u>>v;
			a[u-1][v-1]=false;
		}
		else if(t==2){
			cin>>u;
			for(int j=0;j<n;j++){
				if(j==u-1) continue;
				a[j][u-1]=false;
			}
		}
		else if(t==3){
			cin>>u>>v;
			a[u-1][v-1]=true;
		}
		else if(t==4){
			cin>>u;
			for(int j=0;j<n;j++){
				if(j==u-1) continue;
				a[j][u-1]=true;
			}
		}
		flag=true;
		for(int j=0;j<n;j++){
			cnt=0;
			for(int k=0;k<n;k++){
				if(a[j][k]) cnt++;
			}
//			cout<<cnt<<endl;
			if(cnt!=1) {
				flag=false;
				break;
			}
			else{
				flag=false;
				for(int k=0;k<n;k++){
					if(a[j][k]){
						flag=true;
						break;
					}
				}
			}
		}
		ans[i]=flag;
//		for(int j=0;j<n;j++){
//			for(int k=0;k<n;k++){
//				cout<<a[j][k]<<' ';
//			}
//			cout<<endl;
//		}
	}
	for(int i=0;i<q;i++){
		if(ans[i]) cout<<"YES";
		else cout<<"NO";
		cout<<endl;
	}
	return 0;
}

