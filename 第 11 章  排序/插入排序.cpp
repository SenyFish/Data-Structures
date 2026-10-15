#include<iostream>
#include<vector>
using namespace std;
void insertionSort(vector<int> &v1){
		vector<int> sort;
		sort.push_back(v1[0]);
		for(int i=sort.size();i<v1.size()-sort.size();i++){
			for(int j=0;j<sort.size();j++){
				if(v1[i]<sort[j]){
					tmp=sort[j];
					sort[j]=v1[i];
					sort[j+1]=tmp;				
				}	
			}
		}		
}
int main(){
	vector<int> v1={4,1,3,1,5,2}
}