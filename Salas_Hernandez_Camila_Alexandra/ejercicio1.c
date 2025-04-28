#include <stdio.h>
#include <string.h>

//Se define un struct llamado Coche, contiene 5 miembros: marca, modelo, color, anio, precio
struct Coche {
    char marca[20];
    char modelo[20];
    char color[20];
    int anio;
    int precio;
};

//Funcion para imprimir la informacion del coche
void Imprimir(struct Coche coche){
    printf("Marca: %s\n", coche.marca);
    printf("Modelo: %s\n", coche.modelo);
    printf("Color: %s\n", coche.color);
    printf("Anio: %d\n", coche.anio);
    printf("Precio: %d\n", coche.precio);
}

int main(){
    //Creando una variable coche de tipo struct Coche y dandole sus valores iniciales 
    struct Coche coche = {"Volkswagen","Jetta", "Negro", 2022, 300000};
    printf("---Valores Iniciales---\n");
    //Impriminedo los valores de coche 
    Imprimir(coche);
    //Se define el apuntador que apunta a coche 
    struct Coche *ptrcoche = &coche;

    //Definiendo nuevos valores de coche con el apuntador
    strcpy(ptrcoche->marca, "Nissan");
    strcpy(ptrcoche->modelo, "Versa");
    strcpy(ptrcoche->color, "Gris");
    ptrcoche->anio = 2020;
    ptrcoche->precio=200000;

    //Imprimimos nuevamente los valores de coche para ver los nuevos valores que ya se modificaron con el apuntador
    printf("---Valores Nuevos---\n");
    Imprimir(coche);
}

