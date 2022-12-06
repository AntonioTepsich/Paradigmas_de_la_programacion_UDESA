#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

class AbstractEmployee {
    virtual void askForPromotion()=0;
};

class Employee : AbstractEmployee {
    private:
        int Age;
    protected:
        string Name;

    public:
        Employee(string Name_,int Age_):Name(Name_),Age(Age_){}

        string getName(){
            return Name;
        }
        int getAge(){
            return Age;
        }

        void Introduce(){
            cout<<"Hola soy "<<Name<<" y tengo "<<Age<<" Anos"<<endl;
        }

        void askForPromotion(){
            if(Age>20){
                cout<<Name<<" promocion aceptada"<<endl;
            }
            else{
                cout<<Name<<" promocion denegada"<<endl;
            }
        }

        virtual void Work(){
            cout<<Name<<" esta chequeando mensajes"<<endl;
        }
};

class Developer: public Employee{
    public:
        string FavProgLang;
        Developer(string Name_,int Age_,string FavProgLang_):Employee(Name_,Age_), FavProgLang(FavProgLang_){}
        void FixBug(){
            cout<<getName()<<" arregla el problema usando "<<FavProgLang<<endl;
            cout<<Name<<" arregla el problema usando "<<FavProgLang<<endl;
        }
        void Work(){
            cout<<Name<<" esta codeando con "<<FavProgLang<<endl;
        }

};

class Teacher: public Employee{
    private:
        string Subject;
    public:
        Teacher(string Name_,int Age_,string Subject_):Employee(Name_,Age_), Subject(Subject_){}
        void PrepareLesson(){
            cout<<Name<<" is preparing "<< Subject<<endl;
        }
        void Work(){
            cout<<Name<<" esta ensenando "<<Subject<<endl;
        }
};

class Point{
    private:
        int x;
        int y;
        int d;

    public:
        Point(){
            x=0;
            y=0;
            d=0;   //N=0 O=1 S=2 E=3
        }
        void setX(int x_){
            x=x_;
        }
        void setY(int y_){
            y=y_;
        }
        void setD(int d_){
            d=d_;
        }
        int getX(){
            return x;
        }
        int getY(){
            return y;
        }
        int getD(){
            return d;
        }
};

class Mars{
    protected:
        Point position;
    public:
        Mars(Point pos){
            position=pos;
        }
        void mover(char* sec){
            for(size_t i=0;i<strlen(sec);i++){
                if(sec[i]=='f'){
                    switch (position.getD()){
                    case 0:
                    case 2:
                        position.setY(position.getY()+1);
                        break;
                    case 1:
                    case 3:
                        position.setX(position.getX()+1);
                        break;
                    default:
                        break;
                    }
                }
                else if(sec[i]=='b'){
                    switch (position.getD()){
                    case 0:
                    case 2:
                        position.setY(position.getY()-1);
                        break;
                    case 1:
                    case 3:
                        position.setX(position.getX()-1);
                        break;
                    default:
                        break;
                    }
                }
                else if(sec[i]=='i'){
                    position.setD(position.getD()-1);
                    if(position.getD()<0){
                        position.setD(3);
                    }
                }
                else if(sec[i]=='r'){
                    position.setD(position.getD()+1);
                    if(position.getD()>3){
                        position.setD(0);
                    }
                }
            }
        }
        void printPos(){
            std::cout<<"x: "<<position.getX()<<std::endl;
            std::cout<<"y: "<<position.getY()<<std::endl;
        }
};

int uno(){
    Point xy = Point();
    char * se={"ffifbrbb"};
    Mars m= Mars(xy);
    m.mover(se);
    m.printPos();

    return 0;
}


class Cuenta{
    private:
        char* cod;
        int balance;
        vector<int> historial;
    public:
        Cuenta(char* cod_,int n){
            cod=cod_;
            balance=n;
            historial.emplace_back(n);
        }
        bool hasRegistered(){
            if(historial.size()>1){
                return true;
            }
            else{
                return false;
            }
        }
        void transaction(){
            for(size_t i=0;i<historial.size();i++){
                cout<<historial.at(i)<<" - ";
            }
            cout<<endl;
        }
        void agregar(int n){
            balance+=n;
            historial.emplace_back(n);
        }
        char* getCod(){
            return cod;
        }
        int getBalance(){
            return balance;
        }
};

class Portfolio{
    private:
        std::vector<Cuenta *> potf;
        
    public:
        Portfolio(vector<Cuenta*> port){
            potf=port;
        }
        int balance(){
            int bal=0;
            for(size_t i=0; i<potf.size();i++){
                bal+=potf.at(i)->getBalance();
            }
            return bal;
        }
        void agregarCu(Cuenta* s){
            int c=1;
            for(size_t i=0; i<potf.size();i++){
                if(s->getCod()==potf.at(i)->getCod()){
                    c=0;
                }
            }
            if(c!=0){
                potf.emplace_back(s);
            }
        }
};

class SF{
    private:
        vector<Portfolio*> portfs;
        vector<Cuenta*>cues;
    public:
        SF(vector<Portfolio*> ps,vector<Cuenta*>cs){
            portfs=ps;
            cues=cs;
        }
        int balance(){
            int sum=0;
            for(size_t i=0; i<portfs.size();i++){
                sum+=portfs.at(i)->balance();
            }
            for(size_t i=0; i<cues.size();i++){
                sum+=cues.at(i)->getBalance();
            }
            return sum;
        }
};




int main(){
    // uno();


    return 0;
}