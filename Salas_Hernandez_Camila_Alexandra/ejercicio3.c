#include <stdio.h>
#include <stdlib.h>  
#include <time.h>

//Se define un struct llamado Punto, contiene 2 miembros: x y y
struct Punto {
    int x;
    int y;
};

//Definimos la funcion NumAleatorio que retorna una estructura Punto
struct Punto NumAleatorio(){
    //Se define una variable punto de tipo struct Punto
    struct Punto punto;

    //Inicializar el generador de numero aleatorios
    srand(time(NULL));

    //Generamos los numeros aleatorios para las dos variables x y y
    punto.x = rand()%100;
    punto.y = rand()%100;

    //Se retorna la variable punto
    return punto;
}

int main(){
    //Creamos una variable punto de tipo struct Punto que va a recibir lo que retorna la funcion NumAleatorio
    struct Punto punto = NumAleatorio();
    //Se imprimen los valores
    printf("Coordenada x: %d\n", punto.x);
    printf("Coordenada y: %d\n", punto.y);
}