#include <iostream>
#include <vector>


class Producto{
    private:
        std::string producto;
        int stockMinimo;
        int cantidad;
        int vendidos=0;
    public:
        Producto(std::string producto,int cantidad,int stockMinimo){
            this->cantidad=cantidad;
            this->producto=producto;
            this->stockMinimo=stockMinimo;
        }

        void venta(){
            if(cantidad!=0){
                if(stockMinimo>=cantidad){
                    std::cout<<"Stock minimo."<<std::endl;
                }
                vendidos++;
                cantidad--;
            }
            else{
                std::cout<<"No queda en stock "<<producto<<std::endl;
            }
        }
        void mostrar(){
            std::cout<<"Producto: "<<producto<<"\nStock actual: "<<cantidad<<"\nVendidos"<<vendidos<<std::endl;
        }

        void  compra(int extra){
            cantidad+=extra;
        }

        void cambiar(Producto&& p){
            producto=std::move(p.producto);
        }
};


class Stock{
    private:
        std::vector<Producto> elementos;
    public:
        Stock();

        void mostrar(){
            for(size_t i;i<elementos.size();i++){
                std::cout<<elementos.at(i);
            }
            std::cout<<std::endl;
        }
};