#include "funciones.h"
#include <stdio.h>

int main(){
    int validar, opc1, opc2;
    struct Libro libros[10];
    int cont_Libros = 0;

   do
   {
    printf("Gestion de Biblioteca\n");
    printf("Puedes elegir entre las siguientes opciones:\n");
    printf("1. Agregar libro\n");
    printf("2. Mostrar libros\n");
    printf("3. Buscar libro por titulo o ID \n");
    printf("4. Modificar estado del libro\n");
    printf("5. Editar datos del libro\n");
    printf("6. Eliminar libro\n");
    validar=scanf("%d", &opc1);
    validardatos(validar, &opc1, 'i');
    switch (opc1)
    {
    case 1:
        Registro(&libros[cont_Libros], &cont_Libros);
        break;
    case 2:
        mostarLibros(libros, &cont_Libros);
        break;  
    case 3:
        buscarLibro(libros, &cont_Libros);
        break;  
    case 4:
        ModificarEstado(libros, &cont_Libros);
        break;
    case 5:
        editardatoslibro(libros, &cont_Libros);
        break;
    case 6:
        eliminarlibro(libros, &cont_Libros);
        break;  
    default:
        printf("Opcion no valida, por favor intente de nuevo.\n");
        break;
    }

    
    printf("Desea realizar otra operacion? 1.Si 2.No\n");
    validar=scanf("%d", &opc2);
    validardatos(validar, &opc2, 'i');
   } while (opc2==1);
   
    return 0;
}