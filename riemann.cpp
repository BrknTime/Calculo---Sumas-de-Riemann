#include <iostream>
#include <cmath>
using namespace std;

class Sumas 
{
    private:
        int a, b;
        float intervalo;
    public:
        Sumas(int a, int b, float intervalo) 
        {
            this->a = a;
            this->b = b;
            this->intervalo = intervalo;
        }

    float calcularIntegralDerecho() 
    {
        float suma = 0.0;
        int n = (b - a) / intervalo; // Número de subintervalos
        float delta_x = (b - a) / static_cast<float>(n); // Ancho de cada subintervalo

        for (int i = 1; i <= n; i++) {
            float x_i = a + i * delta_x; // Punto x_i en el subintervalo
            float f_x_i = funcion(x_i); // Valor de la función en el punto x_i
            suma += f_x_i * delta_x; // Sumar el área del rectángulo en el subintervalo
        }

        return suma;
    }

    float calcularIntegralIzquierdo() {
        float suma = 0.0;
        int n = (b - a) / intervalo; // Número de subintervalos
        float delta_x = (b - a) / static_cast<float>(n); // Ancho de cada subintervalo

        for (int i = 0; i < n; i++) {
            float x_i = a + i * delta_x; // Punto x_i en el subintervalo
            float f_x_i = funcion(x_i); // Valor de la función en el punto x_i
            suma += f_x_i * delta_x; // Sumar el área del rectángulo en el subintervalo
        }

        return suma;
    }

    float calcularIntegralMedio() {
        float suma = 0.0;
        int n = (b - a) / intervalo; // Número de subintervalos
        float delta_x = (b - a) / static_cast<float>(n); // Ancho de cada subintervalo

        for (int i = 0; i < n; i++) {
            float x_i = a + (i + 0.5) * delta_x; // Punto x_i en el subintervalo (punto medio)
            float f_x_i = funcion(x_i); // Valor de la función en el punto x_i
            suma += f_x_i * delta_x; // Sumar el área del rectángulo en el subintervalo
        }

        return suma;
    }

    float funcion(float x) {
        // Define la función f(x) aquí
        // Por ejemplo, para una función cuadrática: return x * x;
        return x * x; // Retorna el valor de la función en el punto x
    }
};

int main() 
{
    int a = 2; // Límite inferior del intervalo
    int b = 7; // Límite superior del intervalo
    float intervalo = (b - a) / 5.0; // Tamaño del intervalo (5 intervalos en este caso)

    Sumas sumaRiemann(a, b, intervalo);
    float resultadoDerecho = sumaRiemann.calcularIntegralDerecho();
    float resultadoIzquierdo = sumaRiemann.calcularIntegralIzquierdo();
    float resultadoMedio = sumaRiemann.calcularIntegralMedio();

    cout<<"Resultado utilizando la suma de Riemann (lado derecho): "<<resultadoDerecho <<endl;
    cout<<"Resultado utilizando la suma de Riemann (lado izquierdo): "<<resultadoIzquierdo<<endl;
    cout<<"Resultado utilizando la suma de Riemann (punto medio): "<<resultadoMedio<<endl;

return 0;
}