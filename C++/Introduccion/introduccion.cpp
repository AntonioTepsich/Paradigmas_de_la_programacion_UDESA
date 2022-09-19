#include <iostream>

void uno(){
    //--------a----------
    std::cout <<"She sells sea shells by the seashore"<< std::endl;

    //--------b----------
    std::cout<<"She ";
    std::cout<<"sells ";
    std::cout<<"sea ";
    std::cout<<"shells ";
    std::cout<<"by ";
    std::cout<<"the ";
    std::cout<<"seashore"<<std::endl;

    //--------c----------
    std::cout<<"|--------------------------------------|"<< std::endl;
    std::cout <<"| She sells sea shells by the seashore |"<< std::endl;
    std::cout<<"|--------------------------------------|"<<std::endl;

}

void dos(int a,int b,int c){
    int sum=(a+b+c)*2+c;
    std::cout<<sum<<std::endl;
}

void tres(){
    int a = 1, b = 2, c = 3;
    std::cout << a+b << " = a + b"<<std::endl;
    std::cout <<"c = " << c<<std::endl;
}

void cuatro(){
    //--------a----------
    int c5,c10,c25,c50,p1,p2,p5,p10;
    std::cout<<"5 centavos: ";
    std::cin>>c5;
    std::cout<<"10 centavos: ";
    std::cin>>c10;
    std::cout<<"25 centavos: ";
    std::cin>>c25;
    std::cout<<"50 centavos: ";
    std::cin>>c50;
    std::cout<<"1 peso: ";
    std::cin>>p1;
    std::cout<<"2 peso: ";
    std::cin>>p2;
    std::cout<<"5 peso: ";
    std::cin>>p5;
    std::cout<<"10 peso: ";
    std::cin>>p10;
    float sum=c5*0.05+c10*0.10+c25*0.25+c50*0.5+p1+p2*2+p5*5+p10*10;
    std::cout<<"Su monto total es de "<<sum<<std::endl;

    //--------b----------
    float cent=(sum-int(sum))*100,pesos=int(sum);
    if (pesos==1){
        std::cout<<"Su monto total es de "<<pesos<<" peso y "<<cent<<" centavos"<<std::endl;
    }
    else{
        std::cout<<"Su monto total es de "<<pesos<<" pesos y "<<cent<<" centavos"<<std::endl;
    }
}

int gcd(int m, int n){
    int r; 
    while (n != 0) { 
        r = m % n; 
        m = n; 
        n = r;
    } 
    return m; 
}

void mai(void){
    int x, y, how_many;
    std::cout << "\nPROGRAM GCD C++";
    std::cout << "\nEnter how many GCD computations? ";
    std::cin >> how_many;
    for (int i = 0; i < how_many; ++i) {
        std::cout << "\nEnter two integers: ";
        std::cin >> x >> y;
        std::cout << "\nGCD(" << x << ", " << y << ") = "<< gcd(x, y) << std::endl;
    }
}
void cinco(){
    mai();
}

void seis(){
    int x,i,f,min,max;
    std::cout<<"cuantos valores va a ingresar? --> ";
    std::cin>>x;
    std::cout<<"1-";
    std::cin>>f;
    min=f;
    max=f;
    for(i=2;i<=x;i++){
        std::cout<<i<<"-";
        std::cin>>f;
        if(max<f){
            max=f;
        }
        if(min>f){
            min=f;
        }
    }
    std::cout<<"maximo: "<<max<<std::endl;
    std::cout<<"minimo: "<<min<<std::endl;
}

void nueve(){
    char c = 'A';
    int i = 3, j = 1, m = 0;
    bool p = false, q = true;
    std::cout << c << " is integer value " << int(c) << " and !'A' is " << !c << std::endl;
    std::cout << "i = " << i << ", !i = " << !i << std::endl;
    std::cout << "!!i = " << !!i << ", !m = " << !m << std::endl;
    std::cout << "p = " << p << ", q = " << q << std::endl;
    std::cout << "!p = " << !p << ", !q = " << !q << std::endl;
    std::cout << "!(i + j) || m = " << (!(i + j) || m) << std::endl;
    std::cout << "q || (j / m) = " << (q || (j / m)) << std::endl;
    //std::cout << "(j / m) || q = " << ((j / m) || q) << std::endl;
}



int main(){

    // uno();
    // dos(1,2,3);
    // tres();
    // cuatro();
    // cinco();
    // seis();
    // siete(); //falta
    // ocho(); //falta
    // nueve();


    return 0;
}