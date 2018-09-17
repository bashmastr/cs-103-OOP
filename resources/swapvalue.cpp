#include <iostream>
using namespace std;



int main(){
	
	int x = 8;
	int y = 5;
	
// swap by multiplication without using third variable	
	
	x = x+y;
	y= x - y;
	x = x - y;
	cout<< x<<endl;
	cout<<y<<endl;
	
	return 0;
// swap by multiplication without using third variable	
	x = x*y;
	y = x / y;
	x = x / y;
	cout<< x<<endl<<y<<endl;
	
	return 0;
}

