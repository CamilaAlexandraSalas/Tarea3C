#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Se define un struct llamado Paciente, contiene 4 miembros: nombre, edad, prioridad, y puntero al sig paciente
struct Paciente {
    char nombre[50];
    int edad;
    int prioridad; 
    // Puntero al siguiente paciente, haciendo uso de lista ligadas
    struct Paciente* sig; 
};

//Funcion para agregar un Paciente a la lista ligada, recibe como parametro un doble apuntador(head) a un struct Paciente, nombre, edad y proridad
void Agregar(struct Paciente** head, char nombre[50], int edad, int prioridad) {
    //Creamos la memoria dinamica con malloc para un struct Paciente, y se crea la variable nuevoPaciente que apunta a la memoria que acabamos de crear
    struct Paciente* nuevoPaciente = (struct Paciente*)malloc(sizeof(struct Paciente));
    //Le asignamos los valores que pasamos como parametro a la funcion 
    strcpy(nuevoPaciente->nombre, nombre);
    nuevoPaciente->edad = edad;
    nuevoPaciente->prioridad = prioridad;
    //Al primer elemento de la lista lo llamaremos head, que asi conmumente se les llama al primer elemento de la lista ligada
    //El nuevo paciente apunta al primero de la lista (head)
    nuevoPaciente->sig = *head; 
    //Hacemos que el nuevo paciente sea ahora el primero 
    *head = nuevoPaciente; 
}

//Funcion para eliminar un Paciente de la lista ligada, que recibe como parametro un doble apuntador(head) a un struct Paciente y el nombre
void Eliminar(struct Paciente** head, char nombre[50]) {
    //Inicializamos el apuntador actual con la dirección del primer nodo de la lista
    struct Paciente* actual = *head;
    //Inicializamos anterior con NULL para mantener la referencia al nodo anterior mientras se recorres la lista.
    struct Paciente* anterior = NULL;

    // Condicion por si el paciente es el primero de la lista
    if (actual != NULL && strcmp(actual->nombre, nombre) == 0) {
        // El primer paciente ahora es el siguiente
        *head = actual->sig;
        // Liberamos la memoria 
        free(actual); 
        return;
    }
    //Si lo anterior no se cumple
    // Con esta condicion buscamos el paciente en la lista, recorremos la lista haciendo uso de anterior y actual
    //Mientras actual no sea NULL todavia existen mas pacientes(nodos)
    while (actual != NULL && strcmp(actual->nombre, nombre) != 0) {
        //Actualizando para seguir recorriendo nodo por nodo
        anterior = actual;
        actual = actual->sig;
    }
    //Si no se cumplen cualquiera de las dos condiciones anteriores es que el paciente no existe en la lista
    //Si actual es igual a NULL es que ya acabo de recorrer la lista y no encontro el paciente 
    if (actual == NULL) {
        printf("-----No se encontro el paciente %s-----\n", nombre);
        return;
    }

    //Desenlazmos el paciente de la lista
    anterior->sig = actual->sig;
    // Liberamos la memoria de ese paciente
    free(actual); 
}

//Funcion para imprimir la lista ligada, que recibe como parametro un apuntador que apunta a un struct Paciente
//Le llamamos head por que en listas ligadas asi se les llama al primer nodo
void Imprimir(struct Paciente* head) {
    //Hacemos que actual apunte al primer nodo de la lista 
    struct Paciente* actual = head;
    //Imprimimos la informacion del paciente actual 
    //Mientras actual sea diferente de NULL significa que todavia no ha llegado al final de la lista, es decir hay mas pacientes(nodos)
    while (actual != NULL) {
        printf("Nombre: %s\n", actual->nombre);
        printf("\tEdad: %d\n", actual->edad);
        printf("\tPrioridad: %d\n\n", actual->prioridad);
        // Pasamos al siguiente paciente, actualizamos actual
        actual = actual->sig; 
    }
}

int main() {
    //Inicializamos la lista en NULL es decir, va a estar vacia
    struct Paciente* listaPacientes = NULL; 

    // Agregamos pacientes a la lista
    Agregar(&listaPacientes, "Abigail Lopez", 26, 2);
    Agregar(&listaPacientes, "Fernanda Garcia", 32, 1);
    Agregar(&listaPacientes, "Camila Salas", 28, 1);
    Agregar(&listaPacientes, "Renata Banos", 39, 3);
    Agregar(&listaPacientes, "Leslie Jaramillo", 67, 2);

    //Imprimimos la lista
    printf("-----PACIENTES------\n");
    Imprimir(listaPacientes);

    // Eliminamos pacientes que si existe
    Eliminar(&listaPacientes, "Renata Banos");
    //Eliminamos un paciente que no existe
    Eliminar(&listaPacientes, "Valeria Perez");

    // Imprimimos nuevamente la lista para ver que se haya eliminado el paciente Renata
    printf("\n-----Lista pacientes-----\n");
    Imprimir(listaPacientes);

    // Liberamos la memoria de la lista
    struct Paciente* temp;
    while (listaPacientes != NULL) {
        temp = listaPacientes;
        listaPacientes = listaPacientes->sig;
        free(temp);
    }
}