#include <iostream>

void dos(){
    int **n;
    n=new int*[4];

    for(size_t i=0;i<4;i++){
        n[i]=new int;
        (*n)[i]=i;
    }

    for(size_t i=0;i<4;i++){
        std::cout<<"elemento: "<<(*n)[i]<<std::endl;
        std::cout<<"espacio de memoria: "<<n[i]<<std::endl;
    }

    for (size_t i = 0; i < 4; i++)
    {
        std::cout<<"borrar "<< n[i]<<std::endl;
        delete n[i];
    }
    delete [] n;
    
}

void tres(){
    int ***M;
    M=new int**[5];
    for (size_t i = 0; i < 5; i++){
        M[i]=new int*[5];
    }

    for (size_t j = 0; j < 5; j++){
        for (size_t n = 0; n < 5; n++)
        {
            M[j][n] = new int;
        }
    }

    for (size_t i = 0; i < 5; i++){
        for (size_t j = 0; j < 5; j++){
            (*M)[i][j] = 1;
        }
    }

    for (size_t i = 0; i < 5; i++)
    {
        for (size_t j = 0; j < 5; j++)
        {
            std::cout<<(*M)[i][j]<<" - ";
        }
        std::cout<<std::endl;
    }

    for (size_t i = 0; i < 5; i++)
    {
        for (size_t j = 0; j < 5; j++)
        {
            std::cout<<"A"<<std::endl;
            delete M[i][j];
        }
        std::cout<<"AA"<<std::endl;
        delete M[i];
    }
    std::cout<<"AAA"<<std::endl;
    delete[] M;
}

#include <vector>

class Qsy{
    protected:
        int i;
    public:
        Qsy(int j){
            i=j;
        }
        int num(){
            return i;
        }
};

void cuatro(){
    Qsy *n1= new Qsy(1);
    Qsy *n2= new Qsy(2);
    Qsy *n3= new Qsy(3);
    Qsy *n4= new Qsy(4);

    std::vector<Qsy*> habLibre;
    habLibre.emplace_back(n2);
    habLibre.emplace_back(n4);
    habLibre.emplace_back(n3);
    habLibre.emplace_back(n1);

    Qsy *aux;
    for(const auto h:habLibre){
        for(size_t j=0; j<habLibre.size()-1;j++){
            if(habLibre.at(j)->num()<(habLibre.at(j+1)->num())){    
                aux=habLibre.at(j);
                habLibre.at(j)=habLibre.at(j+1);
                habLibre.at(j+1)=aux;
            }
        }
    }
    for(int i=0;i<habLibre.size();i++){
        std::cout<<habLibre.at(i)<<std::endl;
    }
    delete n1,n2,n3,n4,aux;
}

#include <iostream>

struct A {
    A() { std::cout << "A\n"; }
    virtual ~A() { std::cout << "~A\n"; }
};


struct B {
    B() { std::cout << "B\n"; }
    virtual ~B() { std::cout << "~B\n"; }
};


struct DA : public A {
    DA() { std::cout << "DA\n"; }
    ~DA() { std::cout << "~DA\n"; }
};

struct DDA : public DA {
    DDA() { std::cout << "DDA\n"; }
    ~DDA() { std::cout << "~DDA\n"; }
};


struct DB : public B {
    DB() { std::cout << "DB\n"; }
    ~DB() { std::cout << "~DB\n"; }
};


void cinco(void)
{
    A *a = new DDA();
    B *b = new DB();

    delete a;
    delete b;

    std::cout << "Me parece que faltÃ³ destruir algo...\n";

}



int main(){
    // tres();
    // cuatro();
    cinco();
    return 0;
}