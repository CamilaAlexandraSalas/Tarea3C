#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Se define un struct llamado Libro, contiene 4 miembros: titulo, autor, editorial, anio
struct Libro {
    char titulo[50];
    char autor[50];
    char editorial[50];
    int anio;
};

int main(){
    //Creamos un arreglo dinamico de 5 libros por medio de malloc
    struct Libro* Libros = (struct Libro*)malloc(5 * sizeof(struct Libro));

    //Llenamos los valores de los 5 libros que hicimos anteriormente 
    struct Libro libros[5] = {
        {"A todos los chicos de los que me enamore", "Jenny Han", "Destino", 2014},
        {"Despues de ti", "Jojo Moyes", "Suma", 2015},
        {"Heartstopper", "Alice Oseman", "VRYA", 2018},
        {"Boulevard", "Flor M. Salvador", "Naranja", 2019},
        {"Orgullo y prejuicio", "Jane Austen", "T. Egerton", 1813}
    };

    //Imprimimos los valores de cada libro
    printf("-----Libros-----\n");
    for (int i = 0; i < 5; i++) {
        printf("*Libro: %s\n", libros[i].titulo);
        printf("\tAutor: %s\n", libros[i].autor);
        printf("\tEditorial: %s\n", libros[i].editorial);
        printf("\tAnio: %d\n\n", libros[i].anio);

    }

    //Liberamos memoria
    free(Libros);

}