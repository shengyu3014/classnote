#include<bits/stdc++.h>
using namespace std;
int n;
int ans[15];
bool vis[50];
bool jvis[50];
bool hvis[50];
int sum;
void dfs(int idx){
	if(idx==n+1){
		sum++;
		if(sum<=3){
			for(int i=1;i<=n;i++){
				cout<<ans[i]<<" ";
			}
			cout<<endl;
		}
		return;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]&&!jvis[idx+i]&&!hvis[idx-i+n]){
			ans[idx]=i;
			vis[i]=1;
			jvis[idx+i]=1;
			hvis[idx-i+n]=1;
			dfs(idx+1);
			vis[i]=0;
			jvis[idx+i]=0;
			hvis[idx-i+n]=0;
		}
	}
}
int main(){
	sum=0;
	cin>>n;
	dfs(1);
	cout<<sum;
	return 0;
}

