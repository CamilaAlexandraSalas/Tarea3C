#include <stdio.h>

struct Producto {
    char nombre[20];
    int precio;
    int cantidad;
};

int main() {
    int total = 0;
    
    // inicializamos 10 productos de belleza 
    struct Producto productos[10] = {
        {"Labial", 150, 8},
        {"Rimel", 120, 5},
        {"Base", 250, 3},
        {"Sombras", 180, 6},
        {"Crema", 300, 4},
        {"Shampoo", 90, 10},
        {"Acondicionador", 95, 7},
        {"Esmalte", 50, 15},
        {"Desmaquillante", 130, 5},
        {"Protector", 200, 4}
    };
    
    // muestra en lista los productos en desgloce es decir la multipicacion de lo que hay
    printf(" Inventario:\n\n");
    
    for(int i = 0; i < 10; i++) {
        printf("%-15s $%d x %d\n", productos[i].nombre, productos[i].precio, productos[i].cantidad);
        total += productos[i].precio * productos[i].cantidad;
    }
    
    // muestra el total
    printf("\nInventario_final: $%d\n", total);
    
    return 0;
}