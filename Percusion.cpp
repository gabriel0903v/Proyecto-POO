#include "Otros.h"
#include <iostream>

using namespace std;

    Otros::Otros(const string& marca, const string& modelo, double precio, const string& descripcion):Product(marca, modelo, precio, descripcion)
        {
        }

    void Otros::mostrarDetalles()
    {
        cout << "Producto de Viento: ";
        Product::mostrarDetalles();
    }
