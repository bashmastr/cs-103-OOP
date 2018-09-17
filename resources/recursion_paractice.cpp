#include <iostream>
using namespace std;

//FACTORIAL FUNCTION THROUGH RECURSION 
int factorial(int n){
	if( n == 1){
		return 1;
	}
	return (n * factorial(n-1));
}

//TABLE THROUGH FACTORIAL
void table(int n){
	//STATIC VARIABLE FIXED AFTER RE CALL THE FUNCTION
	static 	int i = 0;
	if (i == 10){
		return ;
	}
	else{
		i++;
		cout<<n<<"*"<<i<<"="<<n*i<<endl;
		table(7);
	}
}


//EVEN NUMBERS BY RECORSION
int sumEven(int n){	
	int sum;
	static int res = 0;

	if( n <= 0){
		return 0;
	}
	else{
		n--;
		sum = sumEven(n);
		if(sum%2==0){
			res += sum;
		}
		if (n==49){
			n = res;
		}
		
		return n;			
	}
}


int main(){
	//cout<<factorial(3);
	//table(10);
	cout<<sumEven(50);
	return 0;
}