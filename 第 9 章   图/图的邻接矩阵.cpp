#include <iostream>
#include <vector>
using namespace std;

vector<int> Init(){
	vector<int> v1;
	int x,i=0;
	do{
		cout<<"请输入索引"<<i<<"对应的值";
		cin>>x;
//		a[i]=x;
		v1.push_back(x);
		i++;
	}
	while(x!=-1);
	v1.pop_back();
	int a[v1.size()][v1.size()];
	for(x=0;x<v1.size();x++){
		cout<<"索引"<<x<<"："<<v1[x]<<endl;	
		for(i=0;i<v1.size();i++){
			a[x][i]=v1[i];
		}
	}

	for(x=0;x<v1.size();x++){
		for(i=0;i<v1.size();i++){
			cout<<x;
			cout<<"请输入"<<a[x][x]<<"与"<<a[x][i]<<"的邻接关系";
			int flag;
			cin>>flag;
			a[x][i]=flag;
		}
	}
	return v1;
}
//void Print(vector<int>v1){
//	for(int i=0;i<v1.size();i++){
//		for(int j=0;j<)
//	}
//}
int main(){
	vector<int> v1;
	v1=Init();	
    return 0;
}
