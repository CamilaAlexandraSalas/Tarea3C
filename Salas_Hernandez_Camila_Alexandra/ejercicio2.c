#include <stdio.h>
#include <string.h>

//Se define un struct llamado Producto, contiene 3 miembros: nombre, precio, cantidad
struct Producto {
    char nombre[50];
    int precio;
    int cantidad;
};

int main(){
    //Inicializamos la variable en 0 para despues poder calcular el inventario 
    int valorTotalInventario=0;
    //Se declara un arreglo de 10 productos, y los llenamos con sus valores
    struct Producto productos[10]={
        {"Yogurt", 30, 10},
        {"Crema", 50, 8},
        {"Lechera", 60, 6},
        {"Gelatina", 25, 12},
        {"Danonino", 10, 4},
        {"Yakult", 8, 10},
        {"Leche", 30, 12},
        {"Flan", 15, 5},
        {"Tostadas", 25, 6},
        {"Pan", 10, 3}
    };
    
    //Calculando el valor total del inventario
    for (int i=0; i<10; i++) {
        valorTotalInventario+=productos[i].precio*productos[i].cantidad;
    }

    //Imprimiendo el valor total de inventario
    printf("Valor total de inventario:$%d\n", valorTotalInventario);

}

