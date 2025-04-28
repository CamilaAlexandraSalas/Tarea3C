#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct Empleado {
    char nombre[50];
    char apellido[50];
    int edad;
    char puesto[50];
    int salario;
    int antiguedad; // en años
};

struct Departamento {
    int nEmpleados;
    struct Empleado* empleados; //cremos el arreglo dinámico de Empleado
};

int main() {
    // cración un departamento
    struct Departamento ventas;

    //  número de empleados
    ventas.nEmpleados = 2;

    // adignamod memoria dinámica para el arreglo de empleados
    ventas.empleados = (struct Empleado*)malloc(ventas.nEmpleados * sizeof(struct Empleado));

    //se verificas si se asigno
    if (ventas.empleados == NULL) {
        printf("Error al asignar memoria!\n");
        return 1; // sale si no se pudo asignar memoria
    }

    //  creamos dos empeleados
    strcpy(ventas.empleados[0].nombre, "Carlos");
    strcpy(ventas.empleados[0].apellido, "Sánchez");
    ventas.empleados[0].edad = 30;
    strcpy(ventas.empleados[0].puesto, "Vendedor");
    ventas.empleados[0].salario = 22000;
    ventas.empleados[0].antiguedad = 5;

   
    strcpy(ventas.empleados[2].nombre, "Javier");
    strcpy(ventas.empleados[2].apellido, "Mendoza");
    ventas.empleados[2].edad = 35;
    strcpy(ventas.empleados[2].puesto, "Supervisor");
    ventas.empleados[2].salario = 28000;
    ventas.empleados[2].antiguedad = 8;

    // muesta la información de los empleados
    printf("Departamento de Ventas\n");
    printf("Número de empleados: %d\n", ventas.nEmpleados);
    for (int i = 0; i < ventas.nEmpleados; i++) {
        printf("\nEmpleado %d:\n", i+1);
        printf("Nombre: %s %s\n", ventas.empleados[i].nombre, ventas.empleados[i].apellido);
        printf("Edad: %d años\n", ventas.empleados[i].edad);
        printf("Puesto: %s\n", ventas.empleados[i].puesto);
        printf("Salario: $%d\n", ventas.empleados[i].salario);
        printf("Antigüedad: %d años\n", ventas.empleados[i].antiguedad);
    }

    // libera memoria dinámica
    free(ventas.empleados);

    return 0;
}
