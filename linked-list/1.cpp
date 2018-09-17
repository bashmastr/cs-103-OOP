#include <iostream>
using namespace std;

struct node {

	int info;
	node* next;
};

class linked_list {
private:
	node *head;
public:
	linked_list():head(NULL){}

	void insert(int var){
		if(head == NULL){
			head = new node;
			head -> info = var;
			head -> next = NULL;
		}
		else {
			node *temp;
			temp = head;
			while(temp -> next != NULL ){
				temp = temp -> next;
			}
			temp -> next = new node;
			temp -> next -> info = var;
			temp -> next -> next = NULL;
		}
	}
	void print(){
		node *temp;
		temp = head;
		while(temp -> next != NULL){
			cout<<temp -> info<<" ";
			temp = temp -> next;	
		}
		cout<<temp -> info<<" ";
	}
	void search(int ser){
		node *temp;
		temp = head;
		while(temp -> next != NULL){
			if(temp->info == ser){
				cout<<"find\n";
			}
			temp = temp -> next;
		}
	}
	void del(int key){
		node *temp;
		node *t1;
		temp = head;
		while(temp -> next != NULL){
			
			//t1 = temp;
			if(temp -> next ->  info == key){
				t1 = temp -> next ;
				temp -> next = temp -> next -> next;
			}
			temp = temp -> next;	
		}
		delete t1;
	}
};

int main(){
	linked_list l1;
	l1.insert(4);
	l1.insert(5);
	l1.insert(6);
	l1.insert(8);
	//l1.search(4);
	l1.del(5);
	l1.print();

	return 0;
}