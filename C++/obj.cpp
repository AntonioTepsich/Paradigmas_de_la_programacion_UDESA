#include <iostream>

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

int main(){
    Employee empleado1= Employee("Antonio", 22);
    Employee empleado2= Employee("Juana", 13);
    Developer d = Developer("Salina",34,"C++");
    Teacher t = Teacher("Maria", 20,"Math");

    Employee *e1= &d;
    Employee *e2= &t;

    e1->Work();
    e2->Work();

    delete e1,e2;
}