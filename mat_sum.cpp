// what number of rows, column, A, B = A + B

#include <iostream>
using namespace std;

int main(){
	int m, n;
	cout<<"Enter the row, column (same for both): "<<endl;
	
	cin>>m>>n;
	int A[m][n]; int B[m][n]; int res[m][n];
	
	cout<<"Enter the values of A"<<endl;
	for(int i=0; i<m; i++){
		for(int j=0; j<n; j++){
			cin>>A[i][j];
		}
	}
	cout<<"Enter the values of B"<<endl;
	for(int i=0; i<m; i++){
		for(int j=0; j<n; j++){
			cin>>B[i][j];
		}
	}
	for(int i=0; i<m; i++){
		for(int j=0; j<n; j++){
			res[i][j] = A[i][j] + B[i][j];
		}
	}
	for(int i=0; i<m; i++){
		for(int j=0; j<n; j++){
			cout<<res[i][j]<<" ";
		}
		cout<<endl;
	}
	
}
	

