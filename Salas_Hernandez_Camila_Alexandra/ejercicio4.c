#include <stdio.h>
#include <stdlib.h>  
#include <string.h>  

//Se define un struct llamado Empleado, contiene 2 miembros
struct Empleado {
    char nombre[50];
    int salario;
};

//Se define un struct llamado Departamento, que contiene 3 miembros
struct Departamento {
    int nEmpleados;        
    struct Empleado* empleados;  // Arreglo de Empleado dinámico 
};

int main(){
    //Se crea variable Ventas de tipo struct Departamento 
    struct Departamento Ventas;
    //Se le asigna el valor al numero de empleados
    Ventas.nEmpleados = 3;
    //Se hace la asignacion de memoria
    Ventas.empleados = (struct Empleado*)malloc(Ventas.nEmpleados * sizeof(struct Empleado));

    //Se les asigna nombre a los 3 empleados 
    strcpy(Ventas.empleados[0].nombre, "Abigail"); 
    strcpy(Ventas.empleados[1].nombre, "Fernanda"); 
    strcpy(Ventas.empleados[2].nombre, "Camila");
    
    //Se les asigna salario a los 3 empleados 
    Ventas.empleados[0].salario = 15000;
    Ventas.empleados[1].salario = 12000;
    Ventas.empleados[2].salario = 18000;

    //Se imprime toda la informacion 
    printf("----------------------------------------\n");
    printf("Departamento\n");
    printf("Numero de Empleados: %d\n", Ventas.nEmpleados);
    printf("----------------------------------------\n");
    printf("Empleados\n");
    for (int i = 0; i < Ventas.nEmpleados; i++) {
        printf("Empleado #%d: %s, Salario: %d\n", i + 1, Ventas.empleados[i].nombre, Ventas.empleados[i].salario);
    }

    //Se libera memoria
    free(Ventas.empleados);
    return 0;
}


