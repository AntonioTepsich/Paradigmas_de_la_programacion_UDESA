#include <iostream>
#include <vector>

class Habitacion{
    protected:
        float precioBase_,adXCama_;
        int cantCamas_;
        bool mascotas_,fumar_,libre_;

    float getPrecioBase(){
        return precioBase_;
    }
    float getAdd(){
        return adXCama_;
    }

    float getPrecio() {
        float x=precioBase_+(adXCama_*cantCamas_);
        return x;
    }
    int getCapacidad() const {
        return cantCamas_;
    }
    bool getEstado() const {
        return libre_;
    }

    void ocuparHab(){
        libre_=false;
        std::cout<<"Ahora esta ocupado"<<std::endl;
    }

    friend class Reserva;
    friend class Hotel;
};

class Suite: public Habitacion{
    public:
        Suite(float precioBase,float adXCama,int cantCamas){
            precioBase_=precioBase;
            adXCama_=adXCama;
            cantCamas_=cantCamas;
            mascotas_=false;
            fumar_=false;
            libre_=true;
        }
};
class Premium: public Habitacion{
    public:
        Premium(float precioBase,float adXCama,int cantCamas){
            precioBase_=precioBase;
            adXCama_=adXCama;
            cantCamas_=cantCamas;
            mascotas_=true;
            fumar_=false;
            libre_=true;
        }
};
class Mega: public Habitacion{
    public:
        Mega(float precioBase,float adXCama,int cantCamas){
            precioBase_=precioBase;
            adXCama_=adXCama;
            cantCamas_=cantCamas;
            mascotas_=false;
            fumar_=true;
            libre_=true;
        }
};


class Reserva{
    private:
        std::string cod_;
        std::vector<Habitacion*> habs_;
    
    public:
        Reserva(std::string cod, std::vector<Habitacion*> habs): cod_(cod),habs_(habs){}
        virtual ~Reserva(){}

        std::string getCod(){
            return cod_;
        }

        float getPrecioReserva(){
            float precio=0;
            for(const auto h:habs_){
                precio+=h->getPrecio();
            }
            return precio;
        }
};

class Hotel{
    private:
        std::vector<Habitacion*> habTotal_;
        std::vector<Reserva*> resTotal_;

    public:
        Hotel(std::vector<Habitacion *>habTotal){
            habTotal_=habTotal;
        }
        ~Hotel(){
            for(auto h:habTotal_){
                delete []h;
            }
            for(auto r:resTotal_){
                delete []r;
            }
        }

        std::vector<Habitacion*> habsLibres(int capMin){
            std::vector<Habitacion*> habLibre;
            for(const auto h:habTotal_){
                if((h->getEstado()==true) && (h->getCapacidad()>=capMin)){
                    habLibre.emplace_back(h);
                }
            }
            // std::cout<<habLibre.at(0)->getPrecio()<<std::endl;
            Habitacion* aux;
            for(size_t i=0;i<habLibre.size()-1;i++){
                for (size_t j=0;j<habLibre.size()-1;j++){
                    if(habLibre.at(j)->getPrecio()<(habLibre.at(j+1)->getPrecio())){
                        aux=habLibre.at(j);
                        habLibre.at(j)=habLibre.at(j+1);
                        habLibre.at(j+1)=aux;
                    }
                }
            }
            return habLibre;
            delete aux;
        }
        void print(std::vector<Habitacion*> a){
            for(const auto s:a){
                std::cout<<s->getPrecio()<<std::endl;
            }
        }

        void reservar(std::string cod,std::vector<Habitacion*> habs){
            Reserva *r= new Reserva(cod,habs);
            resTotal_.emplace_back(r);
            for(auto h:habs){
                h->ocuparHab();
            }
        }
        
};

void uno(){
    Habitacion *a1= new Suite(100,5,5); 
    Habitacion *a2= new Premium(200,10,5); 
    Habitacion *a3= new Mega(300,15,5); 

    std::vector<Habitacion *>a={a1,a2,a3};

    Hotel *h= new Hotel(a);
    h->print(h->habsLibres(5));
    
    for(auto s:a){
        delete s;
    }
    delete a1,a2,a3,a,h;


}

struct A
{
    std::string n_;
    A(std::string n){
        n_=n;
        std::cout<<"A("+n_+")\n";
    }
    ~A(){
        std::cout<<"~A("+n_+")\n";
    }

    A(const A&a){
        n_="copy of "+a.n_;
        std::cout<<"A("+n_+")\n";
    }
    const A& operator=(const A&a){
        n_="eq to "+a.n_;
        std::cout<<"A("+n_+")\n";
        return *this;
    }
};

void PrintName(A a){
    std::cout<<a.n_<<std::endl;
}


void dos(){
    A *a=new A("class A");
    PrintName(*a);
    delete a;
}

int main(){
    uno();
    // dos();
    return 0;
}
