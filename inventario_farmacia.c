#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct {
    char nombre[50];
    int cantidad;
    float precio;
} Producto;

Producto productos[MAX];
int totalProductos = 0;

// Función para validar entrada de enteros positivos
int obtenerEnteroPositivo() {
    int valor;
    while (1) {
        if (scanf("%d", &valor) != 1 || valor <= 0) {
            printf("Entrada inválida. Por favor, ingrese un número entero positivo: ");
            while (getchar() != '\n'); // Limpiar el buffer
        } else {
            break;
        }
    }
    return valor;
}

// Función para validar entrada de flotantes positivos
float obtenerFlotantePositivo() {
    float valor;
    while (1) {
        if (scanf("%f", &valor) != 1 || valor <= 0.0) {
            printf("Entrada inválida. Por favor, ingrese un número positivo: ");
            while (getchar() != '\n'); // Limpiar el buffer
        } else {
            break;
        }
    }
    return valor;
}

void ingresarProducto() {
    if (totalProductos >= MAX) {
        printf("El inventario está lleno.\n");
        return;
    }
    printf("Ingrese el nombre del producto: ");
    while (getchar() != '\n'); // Limpiar el buffer
    scanf(" %[^\n]", productos[totalProductos].nombre);

    printf("Ingrese la cantidad: ");
    productos[totalProductos].cantidad = obtenerEnteroPositivo();

    printf("Ingrese el precio: ");
    productos[totalProductos].precio = obtenerFlotantePositivo();

    totalProductos++;
    printf("Producto ingresado con éxito.\n");
}

void listarProductos() {
    if (totalProductos == 0) {
        printf("No hay productos en el inventario.\n");
        return;
    }
    printf("Lista de productos:\n");
    for (int i = 0; i < totalProductos; i++) {
        printf("%d. %s - Cantidad: %d - Precio: %.2f\n",
               i + 1, productos[i].nombre, productos[i].cantidad, productos[i].precio);
    }
}

void eliminarProducto() {
    if (totalProductos == 0) {
        printf("No hay productos en el inventario para eliminar.\n");
        return;
    }
    listarProductos();

    printf("Ingrese el número del producto a eliminar: ");
    int id = obtenerEnteroPositivo();
    if (id < 1 || id > totalProductos) {
        printf("ID inválido.\n");
        return;
    }

    for (int i = id - 1; i < totalProductos - 1; i++) {
        productos[i] = productos[i + 1];
    }
    totalProductos--;
    printf("Producto eliminado con éxito.\n");
}

void editarProducto() {
    if (totalProductos == 0) {
        printf("No hay productos en el inventario para editar.\n");
        return;
    }
    listarProductos();

    printf("Ingrese el número del producto a editar: ");
    int id = obtenerEnteroPositivo();
    if (id < 1 || id > totalProductos) {
        printf("ID inválido.\n");
        return;
    }

    printf("Editar producto: %s\n", productos[id - 1].nombre);
    printf("Ingrese el nuevo nombre: ");
    while (getchar() != '\n'); // Limpiar el buffer
    scanf(" %[^\n]", productos[id - 1].nombre);

    printf("Ingrese la nueva cantidad: ");
    productos[id - 1].cantidad = obtenerEnteroPositivo();

    printf("Ingrese el nuevo precio: ");
    productos[id - 1].precio = obtenerFlotantePositivo();

    printf("Producto editado con éxito.\n");
}

int main() {
    int opcion;
    do {
        printf("\nSistema de Inventarios\n");
        printf("1. Ingresar producto\n");
        printf("2. Listar productos\n");
        printf("3. Editar producto\n");
        printf("4. Eliminar producto\n");
        printf("5. Salir\n");
        printf("Seleccione una opción: ");
        opcion = obtenerEnteroPositivo();

        switch (opcion) {
            case 1: ingresarProducto(); break;
            case 2: listarProductos(); break;
            case 3: editarProducto(); break;
            case 4: eliminarProducto(); break;
            case 5: printf("Saliendo...\n"); break;
            default: printf("Opción inválida.\n");
        }
    } while (opcion != 5);

    return 0;
}
