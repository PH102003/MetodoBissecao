#include <iostream>
#include <cmath>

using namespace std;

double f(double x) {
    return x + cos(x); // função pra encontrar a raiz
}

double Bisection(double a, double b, double toler) {
    if (f(a) * f(b) >= 0) {
        cout << "A funcao nao atende aos requisitos do metodo da bissecao" << endl;
        return -1.0; // valor inválido
    }

    while ((b - a) / 2 > toler) {
        double c = (a + b) / 2;
        //ponto médio entre "a" e "b"
        if (f(c) == 0) {
            return c; // raiz exata
        }
        if (f(a) * f(c) < 0) {
            b = c; //atualiza o limite superior
        } else {
            a = c; //atualiza o limite inferior
        }
    }

    return (a + b) / 2; //  aproximação da raiz
}

int main() {
    double a = -5.0;
    double b = 4.0;
    double toler = 0.0001;

    double raiz = Bisection(a, b, toler);
    if (raiz != -1.0) {
        cout << "Aproximacao da raiz: " << raiz << endl;
    }

    return 0;
}
