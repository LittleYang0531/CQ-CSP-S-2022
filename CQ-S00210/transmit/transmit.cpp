#include<iostream>
#include<cstdio>
using namespace std;
int n,q,k;
int rs=0;//表示可以走的步数范围内 
int sum=0;
int v[1000]={}; 
int x[100][100]={};//之间的连接
int y[100][100]={};//需要处理的东西; 
int f[1000]={};//标记是否可以通行; 
int contact(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			
		}
	}
}
int main(){
	freopen("transmit.in","r",stdin);
	freopen("transmit.out","w",stdout);
	cin>>n>>q>>k;
	for(int i=1;i<=n;i++){
		cin>>v[i];//第 i 台主机处理信息需要 vi 单位的时间
	}
	for(int i=1;i<n;i++){
		for(int j=1;j<n;j++){
			cin>>x[i][j];
		}
	}
	for(int i=1;i<=q;i++){
		for(int j=1;j<=q;j++){
			cin>>y[i][j];//处理; 
		}
	}
	for(int i=1;i<n;i++){
		for (int j=1;j<n;j++){
			for(int h=1;h<=q;h++){
				for(int k=1;k<=q;k++){
					if(x[i][j]==y[h][k]||x[i][j]==y[k][h]) sum=v[i]+v[j];
				}
			}
		} 
	}
	cout<<sum<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

