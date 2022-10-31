#include<bits/stdc++.h>
using namespace std;
int a[1000000];
int b[1000000];
int score[100000];
int n,m,q;
int l1,r1,l2,r2;
int ans;
int length,mid;
//计算每轮得分
int i=1; 
int tjy(int h){
		cin>>l1>>r1>>l2>>r2;
    	for(int i=l1;i<=r1;i++){
    		for(int j=l2;j<=r2;j++){
    			score[i]=a[i]*b[j];
    			++i;
			}
		}
		
	length=(r1-l1)*(r2-l2);
	mid=length/2;
	sort(score,score+length);
	ans=score[mid+1];
	return ans;
}
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	cin>>n>>m>>q;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=m;i++) cin>>b[i];
	
	for(int i=1;i<=q;i++){
		cout<<tjy(i)<<endl;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
