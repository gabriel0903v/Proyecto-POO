#include "Percusion.h"
#include <iostream>

using namespace std;

    Percusion::Percusion(const string& marca, const string& modelo, double precio, const string& descripcion):Product(marca, modelo, precio, descripcion)
{
}


    void Percusion::mostrarDetalles()
{
        cout << "Producto de Percusion: ";
        Product::mostrarDetalles();
}
