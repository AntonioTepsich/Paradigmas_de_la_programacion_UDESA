#include <iostream>
#include <math.h>
#include <vector>
#include "Herencia.h"

void uno_c();
void dos_c();
void tres_c();
void cuatro_c();
void cinco_c();
void seis_c();
void siete_c();
void ocho_c();
void nueve_c();
void diez_c();   //revisar el ejercicio
void once_c();   //Falta hacer bien


int main(int argc, char const *argv[])
{
    //-------Clases-----------
    // uno_c();
    // dos_c();
    // tres_c();
    // cuatro_c();
    // cinco_c();
    // seis_c();
    // siete_c();
    // ocho_c();
    // nueve_c();
    // diez_c();
    // once_c();

    //-------Herencia-----------
    uno_h();
    // dos_h();
    // tres_h();
    // cuatro_h();
    // cinco_h();
    // seis_h();
    // siete_h();
    // ocho_h();
    // nueve_h();
    

    return 0;
}


void uno_c(){
    /*
    La principal diferencia es que la accesibilidad 
    de las estructuras viene por determinado en publica, 
    mientras que las clases son privadas
    */
}

void dos_c(){
    struct as {
        int i, j, k;
    }; //i,j,k son variables publicas

    class a {
        int i, j, k;

        public:
            a(int i,int j, int k){
                this->i=i;
                this->j=j;
                this->k=k;
            }
    }; //i,j,k son variables privadas.
    //No es util ya que al ser privadas no hay forma de acceder a ellas.


}

void tres_c(){
    class MiClase{

        public:
            std::string a="Hola Mundo";
            void saludar(){
                std::cout<<a<<std::endl;
            }
    };
    MiClase as;
    as.saludar();
}

void cuatro_c(){
    class Point{
        int x,y,z;
        public:
            Point(int x,int y, int z){
                this->x=x;
                this->y=y;
                this->z=z;
            }

            void getX(){
                std::cout<<x<<std::endl;
            }
            void getY(){
                std::cout<<y<<std::endl;
            }
            void getZ(){
                std::cout<<z<<std::endl;
            }
    };

    Point coordenadas(1,2,3);

    coordenadas.getX();

}

void cinco_c(){
    class MiClase{
        int x;
        public:

            void setx(int x){
                this->x=x;
            }

            void getx(){
                std::cout<<x<<std::endl;
            }           
    };

    MiClase a;
    a.setx(2);
    a.getx();
    a.setx(5);
    a.getx();
}


void seis_c(){
    class MiClase{
        public:
            MiClase(){
                std::cout<<"Hola Mundo"<<std::endl;
            }
            ~MiClase(){
                std::cout<<"Adios Mundo"<<std::endl;
            }
    };


    std::cout<<"----Estatico----"<<std::endl;
    MiClase as;
    std::cout<<"----Dinamico----"<<std::endl;
    MiClase *a=new MiClase();
    delete a;
}

void siete_c(){
    class Vector{
        int xf,yf;
        public:
            Vector(){
                xf=0;
                yf=0;
            }
            Vector(int xf,int yf){
                this->xf=xf;
                this->yf=yf;
            }

            void imprimir(){
                std::cout<<"X: "<<xf<<"\nY: "<<yf<<std::endl;
            }

            void norma(){
                std::cout<<sqrt((pow(xf,2)+pow(yf,2)))<<std::endl;
            }

            void cuadrante(){
                std::string s,h;
                (xf<0) ? s="Negatico" : s="Positivo"; 
                (yf<0) ? h="Negatico" : h="Positivo";  

                std::cout<<"X esta en el cuadrante: "<<s<<std::endl;
                std::cout<<"Y esta en el cuadrante: "<<h<<std::endl;
            }
    };

    Vector v1,v2(-4,3);
    std::cout<<"---v1---"<<std::endl;
    v1.imprimir();
    v1.norma();
    v1.cuadrante();
    std::cout<<"\n---v2---"<<std::endl;
    v2.imprimir();
    v2.norma();
    v2.cuadrante();
}

void ocho_c(){
    class Vector{
        int xf,yf;
        public:
            Vector(){
                xf=0;
                yf=0;
            }
            Vector(int xf,int yf){
                this->xf=xf;
                this->yf=yf;
            }

            Vector(Vector& a){
                xf=a.xf;
                yf=a.yf;
            }

            void set(int a){
                xf=a;
            }

            void imprimir(){
                std::cout<<"X: "<<xf<<"\nY: "<<yf<<std::endl;
            }

            void norma(){
                std::cout<<sqrt((pow(xf,2)+pow(yf,2)))<<std::endl;
            }

            void cuadrante(){
                std::string s,h;
                (xf<0) ? s="Negatico" : s="Positivo"; 
                (yf<0) ? h="Negatico" : h="Positivo";  

                std::cout<<"X esta en el cuadrante: "<<s<<std::endl;
                std::cout<<"Y esta en el cuadrante: "<<h<<std::endl;
            }
    };

    Vector v1,v2(-4,3);
    Vector v(v2);
    std::cout<<"---v1---"<<std::endl;
    v1.imprimir();
    v1.norma();
    v1.cuadrante();
    std::cout<<"\n---v2---"<<std::endl;
    v2.imprimir();
    v2.norma();
    v2.cuadrante();
    std::cout<<"\n---v3---"<<std::endl;
    v2.imprimir();
    v2.norma();
    v2.cuadrante();
}

void nueve_c(){
    class Point{
        private:
            int x;
            int y;

        public:
            Point(int x,int y){
                this->x=x;
                this->y=y;
            }
            Point(Point&& p1){
                x=std::move(p1.x);
                y=std::move(p1.y);
            }
            int getX(){
                return x;
            }
            int getY(){
                return y;
            }
    };

    Point a(0,2);
    std::cout<<"P1 = ("<<a.getX()<<", "<<a.getY()<<")"<<std::endl;
    Point a2(std::move(a));
    std::cout<<"P2 = ("<<a2.getX()<<", "<<a2.getY()<<")"<<std::endl;
}

void diez_c(){
    class Vector{
        int xf,yf;
        public:
            Vector(){
                xf=0;
                yf=0;
            }
            Vector(int xf,int yf){
                this->xf=xf;
                this->yf=yf;
            }

            void imprimir(){
                std::cout<<"X: "<<xf<<"\nY: "<<yf<<std::endl;
            }

            void norma(){
                std::cout<<sqrt((pow(xf,2)+pow(yf,2)))<<std::endl;
            }

            void cuadrante(){
                std::string s,h;
                (xf<0) ? s="Negatico" : s="Positivo"; 
                (yf<0) ? h="Negatico" : h="Positivo";  

                std::cout<<"X esta en el cuadrante: "<<s<<std::endl;
                std::cout<<"Y esta en el cuadrante: "<<h<<std::endl;
            }

            std::vector<int,int> v1{3, 2},v2{1, 5};
            // std::vector<int,int> v3 = v1 - v2;
    };
}

