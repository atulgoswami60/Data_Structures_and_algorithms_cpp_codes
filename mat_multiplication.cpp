#include <iostream>
using namespace std;

int main(){
	int m, n;
	cout<<"Enter the row, column for A: "<<endl; cin>>m>>n;
	int x, y;
	cout<<"Enter the row, column for B: "<<endl; cin>>x>>y;
	
	int A[m][n]; int B[x][y]; int res[m][y];
	
	if(n != x){
		cout<<"Not possible, column of A should be same as rows of B !!"<<endl;
		return 0;
	}
	
	cout<<"Enter the values of A"<<endl;
	for(int i=0; i<m; i++){
		for(int j=0; j<n; j++){
			cin>>A[i][j];
		}
	}
	cout<<"Enter the values of B"<<endl;
	for(int i=0; i<x; i++){
		for(int j=0; j<y; j++){
			cin>>B[i][j];
		}
	}
	for(int i=0; i<m; i++){
		for(int j=0; j<y; j++){
			int local_sum = 0;
			for(int k=0; k<n; k++){
				local_sum += A[i][k]*B[k][j];
			}
			res[i][j] = local_sum;
			
		}
	
	}
	for(int i=0; i<m; i++){
		for(int j=0; j<y; j++){
			cout<<res[i][j]<<" ";
		}
		cout<<endl;
	}
	
	
	return 0;
}
