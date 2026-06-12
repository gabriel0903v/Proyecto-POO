#include "Cuerdas.h"

    // Constructor de la clase derivada que invoca al constructor del padre.
Cuerdas::Cuerdas(const string& marca, const string& modelo, double precio, const string& descripcion):Product(marca, modelo, precio, descripcion)
{
}

    //chale
    // Método sobreescrito para mostrar detalles del producto de cuerdas.
void Cuerdas::mostrarDetalles()
{
    cout << "Producto de Cuerdas: ";
        Product::mostrarDetalles();
}
