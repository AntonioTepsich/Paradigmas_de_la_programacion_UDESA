#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>


void uno(){
    //---------a----------
    typedef struct {
        char desc[31];
        int inventario;
        float precio;
        int stock;
        int lugar;
    }inventarios_t;

    //---------b----------
    typedef struct {
        char pais[41];
        char provincia[31];
        char ciudad[21];
        char direccion[31];
        char cp[11];
    }direccionfisica_t;

    //---------c----------
    typedef struct{
        char *nombre;
        char *apellido;
        direccionfisica_t *direccionfisica;
        
    }direccionpersona_t;

    //---------d----------
    typedef struct{
        int consumo;
        int km;
        float costoComb;
        float gastoRec;
        time_t time;
        bool lleno;
        char *comentario;

    }registro_t;
}

//---------a----------
typedef struct{
    float x;
    float y;
}punto_t;

float distancia1(const punto_t *p1,const punto_t *p2){
    return sqrt(pow(p1->x-p2->x,2)+pow(p1->y-p2->y,2));
}

float distancia2(const punto_t *p1,const punto_t *p2){
    if(NULL!=p1 && NULL!=p2){
        return sqrt(pow(p1->x-p2->x,2)+pow(p1->y-p2->y,2));
    }
    else{
        return EXIT_FAILURE;
    }
}
void dos(){
    //---------b----------
    punto_t p1={2,2};
    punto_t p2={5,5};

    //---------c----------
    printf("La distancia es: %f\n",distancia1(&p1,&p2));

    //---------d----------
    printf("La distancia es: %f\n",distancia2(&p1,&p2));
    
}

    //---------a----------
typedef struct{
    char msg[144];
    unsigned int msg_id;
    char *ts;
    char *nombre;
}mensaje_t;
void imprimir(mensaje_t *m){
    printf("%s\n%s. %s\n",m->ts,m->msg,m->nombre);
}
void tres(){
    //---------b----------
    time_t t;
    struct tm *tm;
    char fechayhora[100];

    t=time(NULL);
    tm=localtime(&t);
    strftime(fechayhora, 100, "%Y-%m-%d  %H:%M:%S", tm);
    mensaje_t p1={"hola como estas?",0,fechayhora,"Juan"};
    mensaje_t p2={"Bien y vos?",0,fechayhora,"Pepe"};
    imprimir(&p1);
}

    //---------a----------
typedef struct{
    int i;
    char *msg;
}opciones_t;

void cuatro(){
    //---------b----------
    opciones_t op1,op2,op3;
    op1.i=1;
    op1.msg="play";
    op2.i=2;
    op2.msg="pausa";
    op3.i=3;
    op3.msg="stop";

    printf("0-%s\n1-%s\n2-%s\n\n",op1.msg,op2.msg,op3.msg);

    //---------c----------
    opciones_t menu[5];
    menu[0]=op1;
    menu[1]=op2;
    menu[2]=op3;
    int j;
    printf("ingrese su opcion(0-2): ");
    scanf("%i",&j);
    printf("\n");
    printf("%s\n",menu[j].msg);
}

void cinco(){
    struct header {
        int secuencia;
        time_t stamp;
        char * frame;
    };

    struct pose {
        struct {
            double x, y, z;
        } posicion;
        struct {
            double qx, qy, qz, qw;
        } orientacion;
    };

    struct pose_stamped {
        struct header encabezado;
        struct pose pose;
    } robot_pose;
    
    /*
    robot_pose.encabezado.secuencia
    robot_pose.encabezado.stamp
    robot_pose.encabezado->frame

    robot_pose.pose.posicion.x
    robot_pose.pose.posicion.y
    robot_pose.pose.posicion.z

    robot_pose.pose.orientacion.qx
    robot_pose.pose.orientacion.qy
    robot_pose.pose.orientacion.qz
    robot_pose.pose.orientacion.qw
    */
}
void seis(){
    struct header {
        int secuencia;
        time_t stamp;
        char * frame;
    } header;

    struct punto {
        double x, y, z;
    } point;

    struct cuaternion {
        double qx, qy, qz, qw;
    } quaternion;

    struct pose {
        struct punto * posicion;
        struct cuaternion * orientacion;
    } pose;

    struct pose_stamped {
        struct header * encabezado;
        struct pose * pose;
    } robot_pose, * robot_pose_ptr;

    /*
    
    */

}

int main(){
    //dos();
    //tres();  
    //cuatro();
    //cinco();
    //seis(); //falta
    return EXIT_SUCCESS;
}