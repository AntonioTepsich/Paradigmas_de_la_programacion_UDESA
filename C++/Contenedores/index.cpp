#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <stdexcept>

//---------Vectores----------
void uno_v();
void dos_v();
void tres_v();
void cuatro_v();

//---------Tuplas----------
void uno_t();
void dos_t();
void tres_t();
void cuatro_t();


int main(int argc, char const *argv[])
{
    //---------Vectores----------
    // uno_v();     //1
    // dos_v();     //2
    // tres_v();     //3
    // cuatro_v();     //4

    //---------Tuplas----------
    // uno_t();    //1
    // dos_t();    //2
    // tres_t();     //3
    cuatro_t();     //3

    return 0;
}

std::tuple<std::string,std::string> materia(std::string id){
    if(id == "l102"){
        return std::make_tuple("Paradigmas de Programación", "Patricio Moreno");
    } 
    throw std::invalid_argument("id");
}

void uno_t(){
    auto materia0=materia("l102");
    std::cout<<"Materia: "<<std::get<0>(materia0)<<std::endl; 
    std::cout<<"Profesor: "<<std::get<1>(materia0)<<std::endl; 
}

void dos_t(){
    
    // std::vector<std::tuple<std::string,int>> a;
    std::vector<std::tuple<std::string,int>> y;
    // a.push_back(std::make_tuple("EEG", 1)); 
    // a.push_back(std::make_tuple("ECG", 2)); 
    // a.push_back(std::make_tuple("EEG", 3)); 
    // a.push_back(std::make_tuple("EMG", 4));
    std::vector<std::tuple<std::string,int>>a = {{"EEG", 1}, {"ECG", 2}, {"EEG", 3}, {"EMG", 4}};
    std::string h="EEG";

    for (int i = 0; i < a.size(); i++){
        std::string c=std::get<0>(a[i]);
        int m=std::get<1>(a[i]);
        if(c==h){
            y.push_back(std::make_tuple(c,m));
        }
    }
    std::cout<<"Entrada"<<std::endl;
    for (int i = 0; i < a.size(); i++){
        std::cout<<std::get<0>(a[i])<<", ";
        std::cout<<std::get<1>(a[i])<<std::endl;
    }
    std::cout<<std::endl;
    std::cout<<"Salida con "<<h<<std::endl;
    for (int i = 0; i < y.size(); i++){
        std::cout<<std::get<0>(y[i])<<", ";
        std::cout<<std::get<1>(y[i])<<std::endl;
    }
    
    
}

void tres_t(){
    std::vector<std::tuple<std::string,std::string>> a;
    a.push_back(std::make_tuple("Abraham","Homero"));
    a.push_back(std::make_tuple("Homero","Bart"));
    a.push_back(std::make_tuple("Marge","Lisa"));

    size_t p,t;

    std::string b="Homero";
    std::string c="Bart";
    std::string q;

    for (size_t i = 0; i < a.size(); i++){
        std::string f=std::get<0>(a[i]);
        std::string g=std::get<1>(a[i]);
        if(f==b || g==b) {
            p=i;
            break;
        } 
    }
    for (size_t i = 0; i < a.size(); i++){
        std::string f=std::get<0>(a[i]);
        std::string g=std::get<1>(a[i]);
        if(f==c || g==c) {
            t=i;
            break;
        } 
    }

    (p<t)?q="True":q="False";

    std::cout<<b<<" es ancestro de "<<c<<"?"<<std::endl;
    std::cout<<q<<std::endl;

}

void cuatro_t(){
    std::vector<std::tuple<std::string,std::string,int>> a;
    std::vector<std::tuple<std::string>> b;
    a.push_back(std::make_tuple("Juan","Ilaria",200));
    a.push_back(std::make_tuple("Mauricio","Juan",100));
    a.push_back(std::make_tuple("Ilaria","Ignacio",100));
    

    for (size_t i = 0; i < a.size(); i++){
        int k=0;
        std::string f=std::get<0>(a[i]);
        int q=std::get<2>(a[i]);
        for (size_t j = 0; j < a.size(); j++){
            std::string g=std::get<1>(a[j]);
            int k=std::get<2>(a[j]);

            if(g==f){
                if(q>k){
                    b.push_back(f);
                }
            }
        }
    }
    for (int i = 0; i < b.size(); i++){
        std::cout<<std::get<0>(b[i])<<", ";
    }

    

}





std::vector<int> duplicar(std::vector<int> a){
    std::vector<int> b;
    for (int i = 0; i < a.size(); i++){
        b.push_back(a.at(i));
        b.push_back(a.at(i));
    }
    return b;
}

void uno_v(){
    std::vector<int> a={1,2,3,4},b;
    b=duplicar(a);

    std::cout << "entrada:";
    for (unsigned i=0; i<a.size(); i++)
        std::cout << ' ' << a.at(i);
    std::cout << '\n';
    std::cout << "salida:";
    for (unsigned i=0; i<b.size(); i++)
        std::cout << ' ' << b.at(i);
    std::cout << '\n';
}
bool es_primo(int numero){
    if (numero == 0 || numero == 1 || numero == 4) return false;
    for (int x = 2; x < numero / 2; x++) {
        if (numero % x == 0) return false;
    }
    // Si no se pudo dividir por ninguno de los de arriba, sí es primo
    return true;
}

void dos_v(){
    std::vector<int> a={1,2,3,4,5,6,7,8};
    std::cout << "entrada:";
    for (int i=0; i<a.size(); i++)
        std::cout << ' ' << a.at(i);
    std::cout << '\n';
    for (int i = 0; i < a.size(); i++){
        if (es_primo(a.at(i))==true){
            a.erase(a.begin()+i);
            i--;
        }
    }
    std::cout << "salida:";
    for (int i=0; i<a.size(); i++)
        std::cout << ' ' << a.at(i);
    std::cout << '\n';
    
}

std::vector<int> ordenar(std::vector<int> a){
    std::sort(a.begin(),a.end(),std::less_equal<int>());
    return a;
}

void tres_v(){
    std::vector<int> a={1,2,3,4,5},b={2,3,8};

    for (int i = 0; i < b.size(); i++){
        a.push_back(b.at(i));
    }
    std::cout << "entrada:";
    for (int i=0; i<a.size(); i++)
        std::cout << ' ' << a.at(i);
    std::cout << '\n';
    
    a=ordenar(a);

    std::cout << "salida:";
    for (int i=0; i<a.size(); i++)
        std::cout << ' ' << a.at(i);
    std::cout << '\n';

}

bool multiplos(std::vector<int> a,int b){
    int cont=0;

    for (int i = 0; i < a.size(); i++)
    {
        if(a.at(i)!=1 && a.at(i)%b==0){
            cont++;
        } 
        if(cont==3) return true;
    }
    return false;
}

void cuatro_v(){
    std::vector<int> a={1,2,3,4,5,6};
    int b=2;
    bool c=multiplos(a,b);

    if(c){
        std::cout<<"Verdadero"<<std::endl;
    }
    else{
        std::cout<<"Falso"<<std::endl;
    }
    

}