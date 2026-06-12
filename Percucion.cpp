#include <iostream>
#include <limits>

#include <chrono>
#include <thread>

#include "Menu.h"
#include "Inventario.h"
#include "Product.h"
#include "Cuerdas.h"
#include "Percusion.h"
#include "Viento.h"
#include "Otros.h"

using namespace std;
Menu::Menu()
{
    //ctor
}

void Menu::pantallitaCarga()
{
    const int delay = 200; // estos son milisegundos
    const int delay2=2000;
    const int numPuntos = 10; // numero de puntos en la barra de carga

    int i;
    cout << "Cargando";
    for (i = 0; i < numPuntos; ++i)
    {
        cout << ".";
        cout.flush(); // Asegura que el punto se muestre inmediatamente
        this_thread::sleep_for(chrono::milliseconds(delay));
    }
    cout << "\nCarga completa!\n";
    this_thread::sleep_for(chrono::milliseconds(delay2));
    system("cls");
}

void Menu::menuPrincipal()
{
    Inventario inventario;
    string marca, modelo, descripcion, tipo;
    double precio;
    bool precioValido;
    char choice;

    do
    {
        cout << "\nPresione enter para continuar";
        cin.get();
        pantallitaCarga();   //descomenta esto gabo
        cout << "Elige una opcion:" << endl;
        cout << "1- Agregar un nuevo instrumento" << endl;
        cout << "2- Buscar instrumento por nombre" << endl;
        cout << "3- Eliminar instrumento" << endl;
        cout << "4- Mostrar lista de instrumentos" << endl;
        cout << "5- Menu de opciones especiales" << endl;
        cout << "6- Salir" << endl;
        cout << "Su opcion es: ";
        cin >> choice;

        //limpieza de buffer, es pa' no leer caracteres adicionales
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        //Ah perrillo, 'tas bien pesado
        switch (choice)
        {
        case '1':
            cout << "Ingrese el tipo de producto (Elegir cuerdas, percusion, viento u otros): ";
            getline(cin, tipo);
            cout << "Ingrese la marca: "; getline(cin, marca);
            cout << "Ingrese el modelo: "; getline(cin, modelo);
            //Ya pude, wuacha man
            while (!precioValido)  // Continúa hasta que precioValido sea verdadero, o sea hasta que sea un numero
                {
                cout << "Ingrese el precio: ";
                if (cin >> precio)
                {
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpia el buffer después de la entrada válida
                    precioValido = true; // Cambia la bandera a verdadero para salir del bucle
                }
                else
                    {
                        cout << "Entrada invalida. Por favor, ingrese un numero para el precio." << endl;
                        cin.clear(); // Restablecer el estado de cin
                        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Descartar la entrada incorrecta
                    }
                }
            cout << "Ingrese una descripcion: "; getline(cin, descripcion);
            if (tipo == "cuerdas" || tipo == "Cuerdas")
            {
                inventario.agregarProducto(new Cuerdas(marca, modelo, precio, descripcion));
            }
            else if (tipo == "percusion" || tipo == "Percusion")
            {
                inventario.agregarProducto(new Percusion(marca, modelo, precio, descripcion));
            }
            else if (tipo == "viento" || tipo == "Viento")
            {
                inventario.agregarProducto(new Viento(marca, modelo, precio, descripcion));
            }
            else if (tipo == "otros" || tipo == "Otros")
            {
                inventario.agregarProducto(new Otros(marca, modelo, precio, descripcion));
            }
            else
            {
                cout << "Tipo de producto no reconocido.\n";
            }
            break;
        case '2':
            cout << "Ingrese el modelo del producto a buscar: ";
            getline(cin, modelo);
            {
                Product* producto = inventario.buscarProductoPorModelo(modelo);
                if (producto)
                {
                    producto->mostrarDetalles();
                }
                else
                {
                    cout << "Producto no encontrado.\n";
                }
            }
            break;
        case '3':
            cout << "Ingrese el modelo del producto a eliminar: ";
            getline(cin, modelo);
            if (!inventario.eliminarProductoPorModelo(modelo))
            {
                cout << "Error al intentar eliminar el producto.\n";
            }
            break;
        case '4':
            inventario.mostrarTodosLosProductos();
            break;
        case '5':
        {
            char opcionEspecial;
            cout << "Que funcion especial deseas realizar?\n";
            cout << "a) Comparar precios de dos productos por sus modelos\n";
            cout << "b) Suma sin descuento de dos productos\n";
            cout << "c) Suma con descuento de dos productos\n";
            cout << "d) Aplicar 5% de descuento en un solo producto\n";
            cout << "e) Aplicar 5% de incremento en un solo producto\n";
            cout << "f) Salir"<<endl;
            cout << "Seleccione una opcion: "; cin >> opcionEspecial;
            switch (opcionEspecial)
            {
            case 'a':
            case 'A': {
                string modelo1, modelo2;
                cout << "Ingrese el modelo del primer producto: "; cin >> modelo1;
                cout << "Ingrese el modelo del segundo producto: "; cin >> modelo2;

                // Buscar productos por sus marcas
                Product* producto1 = inventario.buscarProductoPorModelo(modelo1);
                Product* producto2 = inventario.buscarProductoPorModelo(modelo2);
                // Verificar si los productos existen
                if (producto1 && producto2) {
                    // Comparar precios de los productos
                    if (*producto1 == *producto2) {
                        cout << "Los productos tienen el mismo precio." << endl;
                    }
                    else {
                        cout << "Los productos tienen precios diferentes." << endl;
                    }
                }
                else {
                    cout << "No se encontraron productos con las marcas proporcionadas." << endl;
                }
                break;
            }
            case 'b':
            case 'B': {
                string modelo1, modelo2;
                cout << "Ingrese el modelo del primer producto: "; cin >> modelo1;
                cout << "Ingrese el modelo del segundo producto: "; cin >> modelo2;

                // Buscar productos por sus marcas
                Product* producto1 = inventario.buscarProductoPorModelo(modelo1);
                Product* producto2 = inventario.buscarProductoPorModelo(modelo2);
                // Verificar si los productos existen
                if (producto1 && producto2) {
                    // Sumar los precios de los productos
                    cout << "La suma de los precios es: " << (*producto1 + *producto2) << endl;
                }
                else {
                    cout << "No se encontraron productos con las marcas proporcionadas." << endl;
                }
                break;
            }
            case 'c':
            case 'C': {
                string modelo1, modelo2;
                cout << "Ingrese el modelo del primer producto: "; cin >> modelo1;
                cout << "Ingrese el modelo del segundo producto: "; cin >> modelo2;

                // Buscar productos por sus marcas
                Product* producto1 = inventario.buscarProductoPorModelo(modelo1);
                Product* producto2 = inventario.buscarProductoPorModelo(modelo2);
                // Verificar si los productos existen
                if (producto1 && producto2) {
                    // Calcular el total con descuento
                    double total_descuento = (*producto1 - *producto2);
                    cout << "El total con descuento del 15% es: " << total_descuento << endl;
                }
                else {
                    cout << "No se encontraron productos con las marcas proporcionadas." << endl;
                }
                break;
            }
            case 'd':
            case 'D': {
                string modelo;
                cout << "Ingrese el modelo del producto: "; cin >> modelo;
                // Buscar producto por marca
                Product* producto = inventario.buscarProductoPorModelo(modelo);

                // Verificar si el producto existe
                if (producto) {
                    // Aplicar descuento del 5%
                    double precio_descuento = -(*producto);
                    cout << "El precio con descuento del 5% es: " << precio_descuento << endl;
                }
                else {
                    cout << "No se encontro un producto con la marca proporcionada." << endl;
                }
                break;
            }
            case 'e':
            case 'E': {
                string modelo;
                cout << "Ingrese la marca del producto: "; cin >> modelo;

                // Buscar producto por marca
                Product* producto = inventario.buscarProductoPorModelo(modelo);

                // Verificar si el producto existe
                if (producto) {
                    // Aumentar el precio en un 5%
                    double precio_aumentado = +(*producto);
                    cout << "El precio aumentado en un 5% es: " << precio_aumentado << endl;
                }
                else {
                    cout << "No se encontro un producto con la marca proporcionada." << endl;
                }
                break;
            }
            case 'f':
            case 'F': //esta antes era la i gabo, ojo
                cout << "volviendo" << endl;
                break;
            default:
                cout << "Opcion no valida. Intente nuevamente." << endl;
                break;
            }
            break;
        case '6':
            cout << "Saliendo..." << endl;
            break;
        default:
            cout << "Esta opcion es invalida, intente otra vez" << endl;
            break;
        }
    }
    }
    while (choice != '6');
}
