#include <bits/stdc++.h>
using namespace std;

int sc[2][2509];
int ro[10005][2];
vector<int> ch;
int n,m,k,score,lastn = 0,lastx = 1,test;
bool flag = false;
  	                 
int main(){
			                 
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);						     
    int ss;
    cin>>n>>m>>k;
    sc[0][1] = 0;
    sc[1][1] = 1;
    
	for (int i = 0;i < n - 1;i++){
		cin>>sc[0][i + 2];
    	sc[1][i + 2] = i + 2;
	}
    
    for(int i = 0;i < m;i++){
    	cin>>ro[i][0]>>ro[i][1];
	}
    
    for(int i = 2;i <= n + 1;i++){
    	for(int j = 2;j <= n;j++){
    		if(sc[0][j] < sc[0][j + 1]){
    			swap(sc[0][j],sc[0][j + 1]);
    			swap(sc[1][j],sc[1][j + 1]);
			}
		}
	}
   
    cout<<sc[0][2]+sc[0][3]+sc[0][4]+sc[0][5]<<endl;
    
    fclose(stdin);
    fclose(stdout);
    return 0;
}         
          


          