#include <iostream>
#include <vector>
using namespace std;
void bubbleSort(vector<int> &v1) {
    int tmp=0,n=v1.size()-1;
    for(int j=0;j<n;j++){
	    for (int i=0;i<n-j;i++) { //思考为什么i<n-j
	        if (v1[i]>v1[i+1]) {
	            tmp = v1[i];
	            v1[i] = v1[i + 1];
	            v1[i + 1] = tmp;
	        }
	    }
	}

}
int main() {
    vector<int> v1={908, 213, 33, 12, 34, 32};
    bubbleSort(v1);
    for (int i=0;i<v1.size();i++)
        cout<<v1[i]<<" ";
}