#include<iostream>
#include<fstream>

using namespace std;


void color(int i){
	
	
	switch(i%10){

case 4 :		cout<<"\033[1;35m";		//black
				break;
case 1 :		cout<<"\033[1;31m";		//red
				break;		
case 2 :		cout<<"\033[1;32m";
				break;	
case 3 :		cout<<"\033[1;33m";
				break;
case 9 :		cout<<"\033[1;34m";
				break;
case 5 :		cout<<"\033[1;36m";
				break;								
case 0 :		cout<<"\033[1;34m";
				break;
case 7 :		cout<<"\033[1;37m";
				break;
case 8 :		cout<<"\033[1;38m";
				break;				
case 6 :		cout<<"\033[1;39m";
				break;				
				
									
	}


}


int main()
{
	string s,line;
	int n;
	int lign=0;
	cin>>n;
	int i=1,j=1,sol,col=0;
	ifstream file("soly");
	cout<<endl;
	
	int scale=0,ord=1;
	while(n*n/ord>=1){//getting the scale..
		ord*=10;
		scale++;
	}
	
	
	while(file>>sol){
		if(j==1&&i==1){
			cout<<"             ";
			col=lign/n;
			color(col);
			lign++;
		}
			
		if(sol>0){
		if(((col-(lign-1)/n)%n)==0){
				color((col/n+(lign-1)/n)%n);
			
			}
		ord=1;
		for(int g=0;g<scale;g++) 	//solution pour le décalage dans l'affichage..
		{
			if(j/ord<1)
				cout<<"0";			//write a 0 to align all numbers 
			ord*=10;
		}
		
		
		cout<<j<<"  ";
			col++;
		}
		j++;
		
		if(j>n*n){
			i++;
			j=1;
			if(i>n*n){
				cout<<"\n\n";
				i=1;
			}
		}
	}
	
	return 0;
}




