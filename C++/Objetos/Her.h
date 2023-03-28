#include <iostream>

void uno_h(){
    class Persona{
        private:
            std::string nombre;
            std::string apellido;
        public:
            Persona(std::string nombre,std::string apellido){
                this->apellido=apellido;
                this->nombre=nombre;
            }
            void mostrar(){
                std::cout<<"Nombre completo: "<<apellido<<" "<<nombre<<"."<<std::endl;
            }
            
    };

    class Estudiante : public Persona{
        private:
            std::string carrera;
            int ingreso;
        public:
            Estudiante(std::string nombre,std::string apellido,std::string carrera,int ingreso) : Persona(nombre,apellido) {
                this->carrera=carrera;
                this->ingreso=ingreso;
            }
    };

    class Profesor : public Persona{
        private:
            std::string departamento;
            std::string materia;
            
        public:
            Profesor(std::string nombre,std::string apellido,std::string departamento,std::string materia) : Persona(nombre,apellido) {
                this->departamento=departamento;
                this->materia=materia;
            }
    };

    Estudiante e1("Antonio","Tepsich","Ing. en IA",2022);
    Profesor p1("Tobias","Rousseaux","Ingenieria","Sistemas");

    e1.mostrar();
    p1.mostrar();
}

void dos_h(){
    class Pieza{
        std::string nombre;
        std::string posicion;
        bool enJuego;

        public:
            Pieza(std::string nombre){
                this->nombre=nombre;
            }

    };

    class Peon: public Pieza{
        public:
            std::string mover(){

            }
    };
}
