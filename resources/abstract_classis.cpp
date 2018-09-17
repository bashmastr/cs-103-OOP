#include <iostream>
using namespace std;

class base {
public:
        virtual void show() = 0;
};
class derv1 : public base{
public:
        void show(){
                cout<<"\n..derv1..\n";
        }
};
class derv2:public base{
public:
        void show(){
                cout<<"\n...derv2...\n";
        }
};
void f(base &a){
        a.show();
}

int main(){

        derv1 dv1;
        derv2 dv2;
        base *ptr;
        ptr = &dv1;
        ptr->show();

        ptr = &dv2;
        ptr->show();
        f(dv1);
        dv2.show();


        return 0;
}