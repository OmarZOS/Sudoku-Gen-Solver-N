#include<iostream>
#include <stdlib.h>
#include <time.h>
#include<string.h>
#include<fstream>

// This code was based on the 3x3 grid generating script by Dr. Demigha Oualid

using namespace std;

#define MAX_N 30

int VarNbr(int i, int j, int k,int n) {
	return ((i-1)*n*n*n*n+(j-1)*n*n+k);
}



int main() {


	int n=0,i=0, j=0, k=0, c=0, l=0,N=0, Car1=0, Carr2=0,counter=0;
	string filename;
	cin>> n;
	cin >>filename;
	N=n*n;
	int** M;
	M=new int*[N];
	for(int b=0;b<N;b++){
		M[b]=new int[N];
		for(j=0;j<N;j++)
			M[i][j]=0;	//initialising them to avoid any segfault
	}

	cout<<"c This file describes a Sudoku model in DIMACS format\n";
	cout<<"c in order to work, replace mod with the number in the last line of the file then delete that line.\n";
	cout<<"p cnf "<<n*n*n*n*n*n<<" hil\n"; //hil here is the number of constraints, it will be changed later by the Baker.sh script..

	// Cellules
	//cout<<"c CELLS\n");
	for (i = 1; i <=n*n; i++) {
	//cout<<"c\n");
		for (j = 1; j <=n*n; j++) {
			for (k = 1; k <=n*n; k++) {
				cout<<VarNbr(i, j, k,n)<<" ";
			}
				counter++;
			cout<<"0\n";
		}
	}

	// Lignes
	for (i = 1; i <=n*n; i++) {
		//cout<<"c L%d\n", i);
		for (k = 1; k <=n*n; k++) {
			for (j = 1; j <=n*n; j++) {
				c = 1;
				while ((c <=n*n) && (c != j)) {
					cout<<"-"<<VarNbr(i, j, k,n)<<" -"<<VarNbr(i, c, k,n)<<" 0\n";
					c++;
					counter++;
				}
			}
		}
	}
	// Colonnes
	for (j = 1; j <=n*n; j++) {
		for (k = 1; k <=n*n; k++) {
			for (i = 1; i <=n*n; i++) {
				l = 1;
				while ((l <=n*n) && (l != i)) {
					cout<<"-"<<VarNbr(i, j, k,n)<<" -"<<VarNbr(l++, j, k,n)<<" 0\n";
				counter++;
			}
			}
		}
	 }
	// Squares
	for (Car1 = 1; Car1 <=n*n; Car1 += n) {
		for (i = Car1; i < Car1 + n; i++) {
			for (Carr2 = 1; Carr2 <=n*n; Carr2 += n) {
				for (j = Carr2; j < Carr2 + n; j++) {
					for (k = 1; k <=n*n; k++) {
						l = Car1; 
						while (l < Car1 + n) {
							c = Carr2;
							while (c < Carr2 + n) {
								if ((i != l) || (j != c)) {
									cout<<" -"<<VarNbr(i, j, k,n)<<" -"<<VarNbr(l, c, k,n)<< " 0\n";
									counter++;
									}
								c++;
							}
						l++;
						}
					}
				}
			}
		}
	}
	// Pre-definition
	
	
	ifstream file(filename);
	cout<<endl;
	i=1;j=1;
	while(file>>k){
		if(k != 0){
			cout <<VarNbr(i, j,  k,n)<<" 0\n";
			counter++;
		}
		if(++j>n*n)
		{
			j=1;
			i++;
		}
	}
	
	cout<<"n: "<<counter;
	// this one should replace "hil" at the beginning using sed command


	return 0;
}






