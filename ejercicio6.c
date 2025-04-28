#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// estrucutara de los datos que integra el libro
struct Libro {
    char titulo[100];
    char autor[100];
    int anio;
    bool disponible;
};

// estrucutura para agregar,eliminar y mostrar
void agregarLibro(struct Libro **catalogo, int *total);
void eliminarLibro(struct Libro **catalogo, int *total, int posicion);
void mostrarCatalogo(struct Libro *catalogo, int total);

int main() {
    // catálogo usando memoria dinámica
    int totalLibros = 7;
    struct Libro *catalogo = (struct Libro*)malloc(totalLibros * sizeof(struct Libro));
    
    // Creamos 7libros iniciales
    strcpy(catalogo[0].titulo, "Harry Potter y la piedra filosofal");
    strcpy(catalogo[0].autor, "J.K. Rowling");
    catalogo[0].anio = 1997;
    catalogo[0].disponible = true;
    
    strcpy(catalogo[1].titulo, "Bajo la misma estrella");
    strcpy(catalogo[1].autor, "John Green");
    catalogo[1].anio = 2012;
    catalogo[1].disponible = true;

    strcpy(catalogo[2].titulo, "Percy Jackson y el ladrón del rayo");
    strcpy(catalogo[2].autor, "Rick Riordan");
    catalogo[2].anio = 2005;
    catalogo[2].disponible = true;
    
    strcpy(catalogo[3].titulo, "Las ventajas de ser invisible");
    strcpy(catalogo[3].autor, "Stephen Chbosky");
    catalogo[3].anio = 1999;
    catalogo[3].disponible = true;
    
    strcpy(catalogo[4].titulo, "Orgullo y prejuicio");
    strcpy(catalogo[4].autor, "Jane Austen");
    catalogo[4].anio = 1813;
    catalogo[4].disponible = true;
    
    strcpy(catalogo[5].titulo, "El Hobbit");
    strcpy(catalogo[5].autor, "J.R.R. Tolkien");
    catalogo[5].anio = 1937;
    catalogo[5].disponible = false;
    
    strcpy(catalogo[6].titulo, "Coraline");
    strcpy(catalogo[6].autor, "Neil Gaiman");
    catalogo[6].anio = 2002;
    catalogo[6].disponible = false;
    
    // muestra un pequeño menú del catálgo inicial
    printf(" \nCATALÓGO INICIAL \n");
    mostrarCatalogo(catalogo, totalLibros);
    
    // se elminarn tres libros especificos (los de la posición 1, 2 y 4)
    eliminarLibro(&catalogo, &totalLibros, 1);
    eliminarLibro(&catalogo, &totalLibros, 2);
    eliminarLibro(&catalogo, &totalLibros, 4);
    
    // muestra un pequeño menú del catálgo actualizado
    printf("\n CATALÓGO ACTUALIZADO \n ");
    mostrarCatalogo(catalogo, totalLibros);
    
    // libera memoria al final
    free(catalogo);
    
    return 0;
}

//funció  para agregar libros
void agregarLibro(struct Libro **catalogo, int *total) {
    *total += 1;
    *catalogo = (struct Libro*)realloc(*catalogo, (*total) * sizeof(struct Libro));
    
    printf("\nIngresa el titulo del libro: \n");
    scanf(" %[^\n]", (*catalogo)[*total-1].titulo);
    
    printf("Ingresa el  autor: ");
    scanf(" %[^\n]", (*catalogo)[*total-1].autor);
    
    printf("Ingresa el año: ");
    scanf("%d", &(*catalogo)[*total-1].anio);
    
    (*catalogo)[*total-1].disponible = true;
    
    printf("Libro correctamente agregado\n");
}

//  función para eliminar libros
void eliminarLibro(struct Libro **catalogo, int *total, int posicion) {
    if(posicion < 0 || posicion >= *total) {
        printf("Posicion invalida!\n");
        return;
    }
    
    // se mueven  los libros siguientes uno hacía atras
    for(int i = posicion; i < *total-1; i++) {
        (*catalogo)[i] = (*catalogo)[i+1];
    }
    
    *total -= 1;
    *catalogo = (struct Libro*)realloc(*catalogo, (*total) * sizeof(struct Libro));
    
    printf("Libro en posicion %d eliminado.\n", posicion);
}

// se vuelve s mortar el catálogo
void mostrarCatalogo(struct Libro *catalogo, int total) {
    if(total == 0) {
        printf("\nCatalógo esta vacio.\n");
        return;
    }
    
    for(int i = 0; i < total; i++) {
        printf("\nLibro #%d\n", i+1);
        printf("Titulo: %s\n", catalogo[i].titulo);
        printf("Autor: %s\n", catalogo[i].autor);
        printf("Año: %d\n", catalogo[i].anio);
        printf("Disponible: %s\n", catalogo[i].disponible ? "Si" : "No");
    }
    printf("\nTotal de libros: %d\n", total);
}