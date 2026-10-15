#include<iostream>
#include<vector>
using namespace std;
void selectionSort(vector<int> &v1) {
	static int min=v1[0];
	for (int i=0;i<v1.size();i++)
		
		if (v1[i]<min)
			min=v1[i];

}
int main(){
	vector<int> v1={4,1,3,1,5,2};
} 