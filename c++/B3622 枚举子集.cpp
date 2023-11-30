#include<bits/stdc++.h>
using namespace std;
int n;
string pl[15];

void dfs(int idx){
	if(idx==n+1){
		for(int i=1;i<=n;i++){
			cout<<pl[i];
		}
		cout<<endl;
		return; 
	}
	pl[idx]='N';
	dfs(idx+1);
	pl[idx]='Y';
	dfs(idx+1);
} 
  
int main(){
	cin>>n;
	dfs(1);
	return 0;
}

