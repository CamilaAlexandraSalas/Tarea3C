#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Punto {
    int x;  //x =la parte horizontal
    int y;  //y =la parte vertical
};

// para que sean aleatorios primero se crea el punto
struct Punto crearPuntoAleatorio() {
    struct Punto p;  
    
    // con rand devulve numeros altorios (pruebo con n´umero chientonces duelve hasta 49)
    p.x = rand() % 50;
    p.y = rand() % 50;
    
    return p;  // (regresa los dos valores como (x,y))
}

int main() {
    srand(time(0));
    
    // ejmeplo d e 3 puntos aleatorios
    struct Punto punto1 = crearPuntoAleatorio();
    struct Punto punto2 = crearPuntoAleatorio();
    struct Punto punto3 = crearPuntoAleatorio();
    
    // salida de los puntos
    printf("Punto 1: (%d, %d)\n", punto1.x, punto1.y);
    printf("Punto 2: (%d, %d)\n", punto2.x, punto2.y);
    printf("Punto 3: (%d, %d)\n", punto3.x, punto3.y);
    
    return 0;
}