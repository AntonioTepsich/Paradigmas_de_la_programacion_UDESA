#include <iostream>

/* pizza */
class Pizza {
  public:
    virtual ~Pizza() {}
    virtual std::string Precio() const = 0;
};

class PizzaMozzarella : public Pizza {
  public:
    static std::string name;
    std::string Precio() const override {
        return "Precio de la pizza de mozzarela";
    }
};
std::string PizzaMozzarella::name = "Muzza";

class PizzaFugazzetta : public Pizza {
  public:
    static std::string name;
    std::string Precio() const override {
        return "Precio de la fugazzetta";
    }
};
std::string PizzaFugazzetta::name = "Fugazzetta";


/* pizzero */
class Pizzero {
  public:
    virtual ~Pizzero(){};
    virtual Pizza* PrepararPizza() const = 0;
    std::string CocinarUnaPizza() const {
        // Crear una pizza
        Pizza* pizza = this->PrepararPizza();
        // Usarla (imprime, pero la usamos para algo (agregar a pedido, pero no hay pedido)
        std::string resultado = pizza->Precio();
        delete pizza;
        return resultado;
    }
};

class PizzeroMuzza : public Pizzero {
  public:
    Pizza* PrepararPizza() const override { return new PizzaMozzarella(); }
};

class PizzeroFuga : public Pizzero {
  public:
    Pizza* PrepararPizza() const override { return new PizzaFugazzetta(); }
};



void Pizzeria(const Pizzero& pizzero) {
    std::cout << "No sé que pizza es, pero es una pizza.\n"<< pizzero.CocinarUnaPizza() << std::endl;
}

int uno() {
    std::cout << "Sólo hacemos Muzza.\n";
    Pizzero* pizzero = new PizzeroMuzza();
    Pizzeria(*pizzero);
    std::cout << std::endl;
    delete pizzero;

    std::cout << "Sólo vendemos Fugazzetta.\n";
    pizzero = new PizzeroFuga();
    Pizzeria(*pizzero);
    delete pizzero;

    return 0;
}



class Shape{
    public:
        virtual void area()=0;
};

class Cuadrado1:public Shape{
    private:
        int base;
    public:
        Cuadrado1(){
            base=10;
        };
        void area() override{
            std::cout<<base*base<<std::endl;
        }
};
class Rect:public Shape{
    private:
        int base;
        int altura;
    public:
        Rect(){
            base=10;
            altura=20;
        };
        void area() override{
            std::cout<<base*altura<<std::endl;
        }
};

class Fabrica{
    public:
        Shape* getArea(int n){
            if(n==1){
                return new Cuadrado1();
            }
            else{
                return new Rect();
            }
        }
};



void dos(){
    Fabrica* fact= new Fabrica();
    Shape* c=fact->getArea(2);
    c->area();
    delete fact,c;
}

int main(int argc, char const *argv[])
{
    // uno();
    dos();
    return 0;
}
