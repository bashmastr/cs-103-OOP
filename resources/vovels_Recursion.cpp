#include <iostream>
#include <string>
using namespace std;

//COUNT VOWELS THROUGH RECURSION
int word(string var, int index){
	int c = 0;
	if(index == 0 ){
		if(var[index]  == 'a' || var[index]  == 'e' || var[index]  == 'o'
						||	var[index]  == 'i' ||var[index]  == 'u' ){
		return 1;
	}
	else{
		return 0;
	}
	}
	if(var[index]  == 'a' || var[index]  == 'e' || var[index]  == 'o'
						||	var[index]  == 'i' ||var[index]  == 'u' ){
		c++;
	}
	return c + word(var , index-1);
}



int main(){
	cout<<word("to good",6);
	return 0;
	  }