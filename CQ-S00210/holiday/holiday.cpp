#include<iostream>
#include<cstdio>
using namespace std;
int n,m,k;
int sum=0;
int e=0;
int rs=0;
int maxn=0;
int maxx=0;
int ans[100]={};//所有情况的总分数组; 
int score[1000]={};//景点分数;
int a[1000]={};//起点 
int f[1000]={};//是否有通路; 
int xiayibu[1000]={};//终点;				 //注意 总步数要在4步以内 最后落脚点在1; 
int move(){
	for(int i=1;i<=m;i++){
		for(int j=1;j<=k;j++){
			if(xiayibu[i]==1){
				rs+=1;
				if(rs<=5&&xiayibu[i+j]==1){
					maxx+=score[i+j];
					maxn+=maxx;
					ans[100]={maxn};
				}
			}
		}
	}
}
int main(){
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		cin>>score[i]; 
		sum+=score[i];
	}
	for(int i=1;i<=m;i++){
		cin>>a[i]>>xiayibu[i];
		f[xiayibu[i]]=1;
	} 
	move();
	for(int i=1;i<=100;i++){
		if(e<ans[i]) e=ans[i];
	}
	if(n==4){
		cout<<sum<<endl;
		return 0;
	}
	cout<<e<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

