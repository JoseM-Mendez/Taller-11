#include "funciones.h"
#include <stdio.h>
#include <string.h>
void validardatos(int x, void *y, char tipo)
{
    int c, positivo;
    while ((c = getchar()) != '\n' && c != EOF);

    if (tipo=='i')
    {
        if ((*(int*)y)<0)
        {
             x=0;
        }
    }
    else if (tipo=='f')
    {
        if ((*(float*)y)<0)
        {
            x=0;
        }
    }
    while (x != 1)
    {
        printf("Ingrese un valor valido\n");
        {
        }
        if (tipo == 'i')
        {
            x = scanf("%d", (int*)y);
            while ((c = getchar()) != '\n' && c != EOF);
            if ((x==1)&&(*(int*)y<0))
            {
                printf("El numero no puede ser negativo.\n");
                x = 0;
            }
        }
        else if (tipo == 'f')
        {
            x = scanf("%f", (float*)y);
            while ((c = getchar()) != '\n' && c != EOF);
             if ((x==1)&&(*(float*)y<0))
            {
                printf("El numero no puede ser negativo.\n");
                x = 0;
            }
        }
    }
}
void Registro(struct Libro *a, int *cont)
{
    int validar;
   if ((*cont)<10)
   {
     do {
        printf("Ingrese el ID del libro: ");
        validar=scanf("%d", &a->id);
        validardatos(validar, &a->id, 'i');
    } while (a->id >= 10000);

    printf("Ingrese el titulo del libro: ");
    fgets(a->titulo, sizeof(a->titulo), stdin);
    BorrarSaltolinea(a->titulo);

    printf("Ingrese el anio de publicacion del libro: ");
    validar=scanf("%d", &a->publicacion_año);
    validardatos(validar, &a->publicacion_año, 'i');

    printf("Ingrese el autor del libro: ");
    fgets(a->autor, sizeof(a->autor), stdin);
    BorrarSaltolinea(a->autor);

    printf("Ingrese el estado del libro: ");
    fgets(a->estado, sizeof(a->estado), stdin);
    BorrarSaltolinea(a->estado);

    (*cont)++;
   }
   else
   {
    printf("Capacidad maxima de libros alcanzada.\n");
   }
   
}
void BorrarSaltolinea(char *a)
{
    int len = strlen(a);
    if (len > 0 && a[len - 1] == '\n'){ // se asegura de que la cadena no este vacia y de que el ultimo caracter si sea un salto de linea
        a[len - 1] = '\0'; // De haber un salto de linea, lo cambia por el valor nulo
    }
}
void mostarLibros(struct Libro *a, int *cont){
    printf("----------------------Libros registrados-------------------------\n");
    printf("%-5s %-13s %-11s %-13s %-15s\n", "ID", "Titulo", "Anio Pub.", "Autor", "Estado");
    for (int i = 0; i < (*cont); i++)
    {
        printf("%-5d %-13s %-11d %-13s %-15s\n", a[i].id, a[i].titulo, a[i].publicacion_año, a[i].autor, a[i].estado);
    }
    
}

void buscarLibro(struct Libro *a, int *cont){
    int validar, opc, IdBuscado, Encontrado=0;
    printf("Desea buscar el libro por: 1. Titulo 2. ID\n");
    validar=scanf("%d", &opc);
    validardatos(validar, &opc, 'i');

    switch (opc)
    {
    case 1:
        char tituloBuscado[100];
        printf("Ingrese el titulo del libro a buscar:\n");
        fgets(tituloBuscado, sizeof(tituloBuscado), stdin);
        BorrarSaltolinea(tituloBuscado);
        
        for (int i = 0; i < (*cont); i++)
        {
            if(_stricmp(a[i].titulo, tituloBuscado) == 0)
            {
                Encontrado=1;
                printf("%-5s %-13s %-11s %-13s %-15s\n", "ID", "Titulo", "Anio Pub.", "Autor", "Estado");
                printf("%-5d %-13s %-11d %-13s %-15s\n", a[i].id, a[i].titulo, a[i].publicacion_año, a[i].autor, a[i].estado);
                break;
            }

        }
        if (Encontrado==0)
        {
            printf("No se encontro el libro con el titulo proporcionado.\n");
        }
        break;
    case 2:
        
        printf("Ingrese el ID del libro a buscar:\n");
        validar=scanf("%d", &IdBuscado);
        validardatos(validar, &IdBuscado, 'i');
        for (int i = 0; i < (*cont); i++)
        {
            if (a[i].id == IdBuscado)
            {
                Encontrado=1;
                printf("%-5s %-13s %-11s %-13s %-15s\n", "ID", "Titulo", "Anio Pub.", "Autor", "Estado");
                printf("%-5d %-13s %-11d %-13s %-15s\n", a[i].id, a[i].titulo, a[i].publicacion_año, a[i].autor, a[i].estado);
                break;
            }
        }
        if (Encontrado==0)
        {
            printf("No se encontro el libro con el ID proporcionado.\n");
        }
        break;
    default:
        break;
    }
}

void ModificarEstado(struct Libro *a, int *cont){
    int validar, IdBuscado, Encontrado=0, opc;
    printf("Modificar estado del libro\n");
    printf("Desea buscar el libro por su 1. Titulo 2. ID\n");
    validar=scanf("%d", &opc);
    validardatos(validar, &opc, 'i');
    switch (opc)
    {
    case 1:
        {
            char tituloBuscado[100];
            printf("Ingrese el titulo del libro a buscar:\n");
            fgets(tituloBuscado, sizeof(tituloBuscado), stdin);
            BorrarSaltolinea(tituloBuscado);
            
            for (int i = 0; i < (*cont); i++)
            {
                if(_stricmp(a[i].titulo, tituloBuscado) == 0)
                {
                    Encontrado=1;
                    printf("Ingrese el nuevo estado del libro:\n");
                    fgets(a[i].estado, sizeof(a[i].estado), stdin);
                    BorrarSaltolinea(a[i].estado);
                    printf("Estado del libro actualizado exitosamente.\n");
                    break;
                }

            }
            if (Encontrado==0)
            {
                printf("No se encontro el libro con el titulo proporcionado.\n");
            }
        }
        break;
    case 2:
        {
            printf("Ingrese el ID del libro a buscar:\n");
            validar=scanf("%d", &IdBuscado);
            validardatos(validar, &IdBuscado, 'i');
            for (int i = 0; i < (*cont); i++)
            {
                if (a[i].id == IdBuscado)
                {
                    Encontrado=1;
                    printf("Ingrese el nuevo estado del libro:\n");
                    fgets(a[i].estado, sizeof(a[i].estado), stdin);
                    BorrarSaltolinea(a[i].estado);
                    printf("Estado del libro actualizado exitosamente.\n");
                    break;
                }
            }
            if (Encontrado==0)
            {
                printf("No se encontro el libro con el ID proporcionado.\n");
            }
        }
        break;
    default:
        printf("Opcion no valida.\n");
        break;
    }
}

void editardatoslibro(struct Libro *a, int *cont){
    int validar, opc, IDBuscado, Encontrado=0;
    printf("Editar datos del libro\n");
    printf("Ingrese el ID del libro a editar:\n");
    validar=scanf("%d", &IDBuscado);
    validardatos(validar, &IDBuscado, 'i');
    for (int i = 0; i < (*cont); i++)
    {
        if (a[i].id == IDBuscado)
        {
            Encontrado=1;
            printf("Datos actuales del libro:\n");
            printf("%-5s %-13s %-11s %-13s %-15s\n", "ID", "Titulo", "Anio Pub.", "Autor", "Estado");
            printf("%-5d %-13s %-11d %-13s %-15s\n", a[i].id, a[i].titulo, a[i].publicacion_año, a[i].autor, a[i].estado);
            
            printf("Ingrese el dato que desea editar:\n");
            printf("1.Titulo\n");
            printf("2.Anio de publicacion\n");
            printf("3.Autor\n");
            validar=scanf("%d", &opc);
            validardatos(validar, &opc, 'i');
            switch (opc)
            {
            case 1:
                printf("Ingrese el nuevo titulo del libro:\n");
                fgets(a->titulo, sizeof(a->titulo), stdin);
                BorrarSaltolinea(a->titulo);
                break;
            
            case 2:
                printf("Ingrese el nuevo año de publicación:\n");
                validar = scanf("%d", &a->publicacion_año);
                validardatos(validar, &a->publicacion_año, 'i');
                break;

            case 3:
                printf("Ingrese el nuevo autor del libro:\n");
                fgets(a->autor, sizeof(a->autor), stdin);
                BorrarSaltolinea(a->autor);
                break;

            default:
                break;
            }
            printf("Datos del libro actualizados exitosamente.\n");
            break;
        }
    }
}

void eliminarlibro(struct Libro *a, int *cont){
    int validar, IDbusqueda, Encontrado = 0;
    printf("Ingrese el ID del libro a eliminar:\n");
    validar=scanf("%d", &IDbusqueda);
    validardatos(validar, &IDbusqueda, 'i');
    for (int i = 0; i < (*cont); i++)
    {
        if (a[i].id == IDbusqueda)
        {
            Encontrado=1;
            //La función desplazará los libros siguientes una posicion hacia atras
            for (int j = i; j < (*cont) - 1; j++)
            {
                a[j] = a[j + 1];
            }
            (*cont)--;
            printf("Libro eliminado exitosamente.\n");
            break;
        }
    }
    if (Encontrado==0)
    {
        printf("No se encontro el libro con el ID proporcionado.\n");
    }

}
