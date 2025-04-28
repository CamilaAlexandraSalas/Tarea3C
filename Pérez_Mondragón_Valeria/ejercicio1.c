#include <stdio.h>
#include <string.h>

// Definición de la estructura Coche
struct Coche {
    char marca[50];
    char modelo[50];
    int anio;
    float precio;
};

int main() {
    // instanciade Coche
    struct Coche miCoche;
    
    // asignamos valores  a Coche
    strcpy(miCoche.marca, "Toyota");
    strcpy(miCoche.modelo, "Corolla");
    miCoche.anio = 2020;
    miCoche.precio = 25000.50;
    
    // salida de los valores
    printf("Datos originales del coche:\n");
    printf("Marca: %s\n", miCoche.marca);
    printf("Modelo: %s\n", miCoche.modelo);
    printf("Año: %d\n", miCoche.anio);
    printf("Precio: %.2f\n\n", miCoche.precio);
    
    // el apuntador a  Coche
    struct Coche *ptrCoche;
    
    // asignamos la dirección de miCoche al apuntador
    ptrCoche = &miCoche;
    
    // modificación de los vaslores usando el apuntador
    strcpy(ptrCoche->marca, "Honda");  
    strcpy(ptrCoche->modelo, "Civic");
    ptrCoche->anio = 2022;
    ptrCoche->precio = 27500.75;
    
    // salida de los valores modificados
    printf("Datos modificados del coche:\n");
    printf("Marca: %s\n", ptrCoche->marca);
    printf("Modelo: %s\n", ptrCoche->modelo);
    printf("Año: %d\n", ptrCoche->anio);
    printf("Precio: %.2f\n", ptrCoche->precio);
    
    return 0;
}