#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("holiday1.in","r",stdin);
	freopen("holiday.out","w",stdout);
	int n,m,k,c,d;
	long long su[1005];
	long long b[1005];
	cin>>n>>m>>k;
	int a[100][100]={0};
	for(int i=2;i<=n;i++){
		cin>>b[i];
	}
	for(int i=1;i<=m;i++){
		cin>>c>>d;
		a[c][d]=1;
	}
	int h=1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int l=1;l<=n;l++){
				for(int x=1;x<=n;x++){
					if((a[1][i]==a[i][j]||a[i][1]==a[i][j]||a[1][i]==a[j][i]||a[i][1]==a[j][i])&&(a[i][j]==a[j][l]||a[j][i]==a[j][l]||a[i][j]==a[l][j]||a[j][i]==a[l][j])&&(a[j][l]==a[l][x]||a[l][j]==a[l][x]||a[j][l]==a[x][l]||a[l][j]==a[x][l])&&(a[l][x]==a[x][1]||a[x][l]==a[x][1]||a[l][x]==a[1][x]||a[x][l]==a[1][x])){
						su[h]=b[i]+b[j]+b[l]+b[x];
						h++;																																																																																																																																																																																																																																																																																																																																																																																																																																																																																			
					} 
				} 
			} 
		} 
	} 
	int cnm=0;
	for(int i=1;i<=h-1;i++){
		if(su[i]>cnm)
		cnm=su[i];	
		}
	cout<<cnm;//暴力都不会了，emo了
	//bye bye cpp; 
} 
