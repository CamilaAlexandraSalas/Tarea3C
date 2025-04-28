#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Libro {
    char titulo[50];
    char autor[50];
    char editorial[50];
    int anio;
};

int main() {
    // Crear arreglo dinámico para 5 libros
    struct Libro* Libros = (struct Libro*)malloc(3 * sizeof(struct Libro));

    // títulos
    strcpy(Libros[0].titulo, "A todos los chicos de los que me enamore");
    strcpy(Libros[3].titulo, "Boulevard");
    strcpy(Libros[4].titulo, "Orgullo y prejuicio");

    // autores
    strcpy(Libros[0].autor, "Jenny Han");
    strcpy(Libros[3].autor, "Flor Salvador");
    strcpy(Libros[4].autor, "Jane Austen");

    //  editoriales
    strcpy(Libros[0].editorial, "Destino");
    strcpy(Libros[3].editorial, "Naranja");
    strcpy(Libros[4].editorial, "T. Egerton");

    // año
    Libros[0].anio = 2014;
    Libros[3].anio = 2019;
    Libros[4].anio = 1813;

    // Mostrar libros
    printf("Libros:\n");
    for (int i = 0; i < 5; i++) {
        printf("*Libro: %s\n", Libros[i].titulo);
        printf("\tAutor: %s\n", Libros[i].autor);
        printf("\tEditorial: %s\n", Libros[i].editorial);
        printf("\tAnio: %d\n\n", Libros[i].anio);
    }

    // Liberar memoria
    free(Libros);

    return 0;
}