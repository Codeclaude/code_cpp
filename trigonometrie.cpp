#include <iostream>
#include <cmath>

double pop(double a,double b){
    int i=1;
    double resultat = 1;
    while(i<=b){
        resultat *= a;
        i++;
    }
return resultat;
}


long facto(int n){
long resultat = 1;
int i;
for(i=2;i<=n;i++){
    resultat *= i;
}
return resultat;
}

double cosinus(double angle) {
    double cos = 0;
    for (int n = 0; n < 10; n++) {
        double terme = pop(-1, n) * pop(angle, 2 * n) / facto(2 * n);
        cos+= terme;
    }
    return cos;
}

double sinus(double angle) {
    double sin = 0;
    for (int n = 0; n < 10; n++) {
        double terme = pop(-1, n) * pop(angle, 2 * n + 1) / facto(2 * n + 1);
        sin += terme;
    }
    return sin;
}

double tangente(double angle) {
    double sin= sinus(angle);
    double cos = cosinus(angle);
int angledeg = angle*180/3.141592653;
    for(int k=0;k<=100;k++){
        if(angledeg == 90+k*180 || cos==0){
            return NAN;
        }
    }
    return sin / cos;
}

int main() {
    double angledeg;

    std::cout << "entrer l angle en degres: ";
    std::cin >> angledeg;

    double anglerad = angledeg * 3.141592653 / 180;

    std::cout << "le cosinus approximatif est: " << cosinus(anglerad)<< std::endl;
    std::cout << "le sinus approximatif est: " << sinus(anglerad) << std::endl;
    std::cout << "la tangente approximative est: " << tangente(anglerad) << std::endl;
    return 0;
}
