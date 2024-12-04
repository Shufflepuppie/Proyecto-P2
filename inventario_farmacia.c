<<<<<<< HEAD
#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nombre[50];
    int cantidad;
    float precio;
} Producto;

Producto* productos = NULL;
int totalProductos = 0;

// Función para validar entrada de enteros positivos
int obtenerEnteroPositivo() {
    int valor;
    while (1) {
        if (scanf("%d", &valor) != 1 || valor <= 0) {
            printf("Entrada inválida. Por favor, ingrese una de las opciones: ");
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
            printf("Entrada inválida. Por favor, ingrese una de las opciones: ");
            while (getchar() != '\n'); // Limpiar el buffer
        } else {
            break;
        }
    }
    return valor;
}

void ingresarProducto() {
    productos = realloc(productos, (totalProductos + 1) * sizeof(Producto));
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
    int id;
    listarProductos();
    if (totalProductos == 0) return;

    printf("Ingrese el número del producto a eliminar: ");
    id = obtenerEnteroPositivo();
    if (id < 1 || id > totalProductos) {
        printf("ID inválido.\n");
        return;
    }

    for (int i = id - 1; i < totalProductos - 1; i++) {
        productos[i] = productos[i + 1];
    }
    totalProductos--;
    productos = realloc(productos, totalProductos * sizeof(Producto));
    printf("Producto eliminado con éxito.\n");
}

void editarProducto() {
    int id;
    listarProductos();
    if (totalProductos == 0) return;

    printf("Ingrese el número del producto a editar: ");
    id = obtenerEnteroPositivo();
    if (id < 1 || id > totalProductos) {
        printf("ID inválido.\n");
        return;
    }

    printf("Ingrese el nuevo nombre: ");
    while (getchar() != '\n'); // Limpiar el buffer
    scanf(" %[^\n]", productos[id - 1].nombre);

    printf("Ingrese la nueva cantidad (entero positivo): ");
    productos[id - 1].cantidad = obtenerEnteroPositivo();

    printf("Ingrese el nuevo precio (número positivo): ");
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

    free(productos);  // Liberar memoria dinámica
    return 0;
}
=======
#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nombre[50];
    int cantidad;
    float precio;
} Producto;

Producto* productos = NULL;
int totalProductos = 0;

// Función para validar entrada de enteros positivos
int obtenerEnteroPositivo() {
    int valor;
    while (1) {
        if (scanf("%d", &valor) != 1 || valor <= 0) {
            printf("Entrada inválida. Por favor, ingrese una de las opciones: ");
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
            printf("Entrada inválida. Por favor, ingrese una de las opciones: ");
            while (getchar() != '\n'); // Limpiar el buffer
        } else {
            break;
        }
    }
    return valor;
}

void ingresarProducto() {
    productos = realloc(productos, (totalProductos + 1) * sizeof(Producto));
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
    int id;
    listarProductos();
    if (totalProductos == 0) return;

    printf("Ingrese el número del producto a eliminar: ");
    id = obtenerEnteroPositivo();
    if (id < 1 || id > totalProductos) {
        printf("ID inválido.\n");
        return;
    }

    for (int i = id - 1; i < totalProductos - 1; i++) {
        productos[i] = productos[i + 1];
    }
    totalProductos--;
    productos = realloc(productos, totalProductos * sizeof(Producto));
    printf("Producto eliminado con éxito.\n");
}

void editarProducto() {
    int id;
    listarProductos();
    if (totalProductos == 0) return;

    printf("Ingrese el número del producto a editar: ");
    id = obtenerEnteroPositivo();
    if (id < 1 || id > totalProductos) {
        printf("ID inválido.\n");
        return;
    }

    printf("Ingrese el nuevo nombre: ");
    while (getchar() != '\n'); // Limpiar el buffer
    scanf(" %[^\n]", productos[id - 1].nombre);

    printf("Ingrese la nueva cantidad (entero positivo): ");
    productos[id - 1].cantidad = obtenerEnteroPositivo();

    printf("Ingrese el nuevo precio (número positivo): ");
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

    free(productos);  // Liberar memoria dinámica
    return 0;
}
>>>>>>> c824cdcd8010b5e623802091fa7ae92a54f30197
