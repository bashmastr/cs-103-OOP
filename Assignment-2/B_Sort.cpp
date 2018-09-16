#include <iostream>
using namespace std;

int threeDArray(){
	int i,j,x,y,k,z;
	int a;
int test[2][2][5]; /*= { 
                    { {3, 4, 2, 3}, {0, -3, 9, 11}, {23, 12, 23, 2} },
                     { {13, 4, 56, 3}, {5, 9, 3, 5}, {3, 1, 4, 9} }
                 };*/

//initialize the arrays by user values at run time.
	cout<<"Enter the values : "<<endl;
    for (i = 0 ; i < 2 ; i++ ){
		for(j = 0 ; j < 2 ; j++){
			for(k = 0 ; k < 5; k++){
				cin>>test[i][j][k];
			}
		}
	}

//sortng the array
	for (i = 0 ; i < 2 ; i++ ){
		for(j = 0 ; j < 2 ; j++){
			for(k = 0 ; k < 5; k++){

				for(z = 0 ; z < 2 ; z++){
					for(x = 0 ; x < 2 ; x++){
						for(y = 0 ; y < 5 ; y++){
							if(test[i][j][k] > test[z][x][y]){
								a = test[i][j][k];
								test[i][j][k] = test[z][x][y];
								test[z][x][y] = a;

							}
						} 
					}					
				}
			}
		}
	}

//print out the sorting elements in arrays
	for (i = 0 ; i < 2 ; i++ ){
		for(j = 0 ; j < 2 ; j++){
			for(k = 0 ; k < 5; k++){
				cout<<test[i][j][k]<<"  ";

			}			
		}
	}
	return 0;
}

int main(){
	threeDArray();
	return 0;
}