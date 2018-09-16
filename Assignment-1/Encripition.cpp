#include <iostream>
#include <string>
using namespace std;


string KeyTable(){


	cout<<"Enter your Key ; ";
	//All letters convert into upper case
    string text,capital,small ;
    int len,i,j;
    getline(cin, text);
    capital = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    small = "abcdefghijklmnopqrstuvwxyz";

    for(int i = 0; i <= text.size() ; i++){
    	for(int j = 0; j <= capital.size() ; j++){
    		if (text[i] == small[j]){
    			text[i] = capital[j];
    		}	
    	}
    }

    //remove extra letters

    i = 0;
    len = text.size();
    
    while(i < len){
    	if (int(text[i] < 65) || int(text[i]) > 90 ){
    		text.erase(i,1);
    	
    		len = len - 1;
    	}
    	else {
    		i = i + 1;
    	}
    }
    text = text + capital;
    
    //remove repetition and J converts into I

    for(i = 0 ; i < text.size(); i++){
    	for(j = 0 ; j < text.size(); j++){
    		if(i != j){
    			if(text[i] == text[j]){
    				text.erase(j,1);
    			}
    		}
    		if(text[i] == 'J'){
    			text[i] = 'I';
    		}
    	}
    }
    //return the value for use in another function
	return  text;
}

string Message(){

	string capital,small,last,message;
	int i,j,len;
	cout<<"Enter your message : ";
	getline(cin , message);

    // convert into capital letters
	capital = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    small = "abcdefghijklmnopqrstuvwxyz";
    for(i = 0 ; i <= message.size() ; i++){
    	for( j = 0 ; j <= capital.size() ; j++){
    		if(message[i] == small[j]){
    			message[i] = capital[j];
    		}
    	}
    }

    //remove extra spaces and wide spces(!%4%*)
    i = 0;
    len = message.size();
    while( i < len ){
    	if ( int(message[i] < 65) || int( message[i] > 90)){
    		message.erase(i,1);
    		len = len - 1;
    	}
    	else {
    		i = i + 1;
    	}
    }

    //add X between same pairs and aslo maintain size of message even by use 'X'
    //  at the end.
    if ( message.length() % 2 != 0){
    	message = message + 'X';
    	last = "add X in the end";
    }
    j = 1;
    for( i = 0; i < message.size(); i = i + 2 ){
    	if(message[i] == message[j]){
    		message.insert(j,"X");
    		if( last == "add X in the end"){
    			message.erase(message.length()-1 , 1);
    		}	
    	}
    j = j + 2;
    }
    if(message.size() % 2 != 0){
        message = message + 'X';
    }

    //return message to use the function valuse for another fun;
	return message;
}


string Encript(){

	string table,message;
	message = Message();
	cout<<endl;
	int i, j,k;
	table = KeyTable();

	char array[5][5] ;
    k = 0;

    //initialize the array
    for(i = 0 ; i < 5; i++){
    	for(j = 0 ; j < 5 ; j++){
    		array[i][j] = table[k];
    		k = k + 1;
    		cout<<array[i][j]<<"   ";
    	}
    	cout<<endl;
    }

    	int row1,col1,row2,col2,c,z,r;
    	j = 1;
    	for(i = 0 ; i < message.size() ; i = i + 2){
    		
    		for( k = 0 ; k < 5 ; k ++ ){
    			for( z = 0 ; z < 5 ; z++){
    				if (message[i]  == array[k][z]){
    					row1 = k;
    					col1 = z;
    					break;
    				}

    			}
    		}
    		for( r = 0 ; r < 5 ; r++){
    			for ( c = 0 ; c < 5 ; c++){
    				if (message[j] == array[r][c]){
    					row2 = r;
    					col2 = c;
    					break;
    				}
    			}
    		}
			//Encypition conditions
            
    		
            if(row1 == row2){
                if(col1 == 4){
                    message[i] = array[row1][0];
                    message[j] = array[row1][col2+1];
                }
                if (col2 == 4) {
                    message[j] = array[row2][0];
                    message[i] = array[row1][col1+1];
                }
                else{
                    message[i] = array[row1][col1+1];
                    message[j] = array[row1][col2+1];
                }
            }
            else{
                message[i] = array[row2][col1];
                message[j] = array[row1][col2];
            }
    		j = j + 2;
        }
    	cout<<endl;
    	cout<<message;
}


int main(){
	Encript();
	return 0;
}