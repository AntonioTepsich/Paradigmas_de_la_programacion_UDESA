#include <iostream>
#include <vector>

class Habitacion{
    protected:
        float precioBase_,adXCama_;
        int cantCamas_;
        bool mascotas_,fumar_,libre_;
    Habitacion();
    ~Habitacion();

    float getPrecio() {
        float x=precioBase_+adXCama_*cantCamas_;
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
        ~Suite();
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
        ~Premium();
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
        ~Mega();
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

        std::vector<Habitacion*> habsLibres(int capMin){
            std::vector<Habitacion*> habLibre;
            for(const auto h:habTotal_){
                if((h->getEstado()==true) && (h->getCapacidad()>=capMin)){
                    habLibre.emplace_back(h);
                }
            }
            Habitacion* aux;
            for(const auto i:habLibre){
                for (size_t j=0;j<habLibre.size()-1;j++){
                    if(habLibre.at(j)->getPrecio()<(habLibre.at(j+1)->getPrecio())){
                        aux=habLibre.at(j);
                        habLibre.at(j)=habLibre.at(j+1);
                        habLibre.at(j+1)=aux;
                    }
                }
            }

            return habLibre;
        }
};

