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

    //Llenamos los titulos de los 5 libros
    strcpy(Libros[0].titulo, "A todos los chicos de los que me enamore");
    strcpy(Libros[1].titulo, "Despues de ti");
    strcpy(Libros[2].titulo, "Heartstopper");
    strcpy(Libros[3].titulo, "Boulevard");
    strcpy(Libros[4].titulo, "Orgullo y prejuicio");

    //Llenamos los autores de los 5 libros
    strcpy(Libros[0].autor, "Jenny Han");
    strcpy(Libros[1].autor, "Jojo Moyes");
    strcpy(Libros[2].autor, "Alice Oseman");
    strcpy(Libros[3].autor, "Flor Salvador");
    strcpy(Libros[4].autor, "Jane Austen");

    //Llenamos las editoriales de los 5 libros
    strcpy(Libros[0].editorial, "Destino");
    strcpy(Libros[1].editorial, "Suma");
    strcpy(Libros[2].editorial, "VRYA");
    strcpy(Libros[3].editorial, "Naranja");
    strcpy(Libros[4].editorial, "T. Egerton");

    //Llenando el año de los 5 libros
    Libros[0].anio = 2014;
    Libros[1].anio = 2015;
    Libros[2].anio = 2018;
    Libros[3].anio = 2019;
    Libros[4].anio = 1813;

    //Imprimimos los valores de cada libro
    printf("-----Libros-----\n");
    for (int i = 0; i < 5; i++) {
        printf("*Libro: %s\n", Libros[i].titulo);
        printf("\tAutor: %s\n", Libros[i].autor);
        printf("\tEditorial: %s\n", Libros[i].editorial);
        printf("\tAnio: %d\n\n", Libros[i].anio);

    }

    //Liberamos memoria
    free(Libros);

}