#include <stdio.h>
#include <string.h>

//Se define un struct llamado Producto, contiene 3 miembros
struct Producto {
    char nombre[50];
    int precio;
    int cantidad;
};

int main(){
    int valorTotalInventario = 0;
    //Se declara un arreglo de 4 productos
    struct Producto productos[4];

    //Llenado el primer producto
    strcpy(productos[0].nombre, "Yogurt");
    productos[0].precio = 30;
    productos[0].cantidad = 10;

    //Llenado el segundo producto
    strcpy(productos[1].nombre, "Crema");
    productos[1].precio = 50;
    productos[1].cantidad = 8;

    //Llenando el tercer producto
    strcpy(productos[2].nombre, "Lechera");
    productos[2].precio = 60;
    productos[2].cantidad = 6;

    //Llenando el cuarto producto
    strcpy(productos[3].nombre, "Gelatina");
    productos[3].precio = 25;
    productos[3].cantidad = 12;
    
    //Calculando el valor total del inventario
    for (int i = 0; i < 4; i++) {
        valorTotalInventario += productos[i].precio * productos[i].cantidad;
    }

    //Imprimiendo el valor total del inventario
    printf("El valor total del inventario es: %d\n", valorTotalInventario);

}

