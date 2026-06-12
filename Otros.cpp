#include "Inventario.h"
#include <iostream>

using namespace std;

Inventario::~Inventario()
{
    for (Product* producto : productos)
    {}
}

void Inventario::agregarProducto(Product* producto)
{
    productos.push_back(producto);
    cout << "Producto agregado exitosamente.\n";
}

Product* Inventario::buscarProductoPorModelo(const string& modelo) const
{
    for (Product* producto : productos)
    {
        if (producto->getModelo() == modelo)
        {
            return producto;
        }
    }
    return nullptr;
}
Product* Inventario::buscarProductoPorMarca(const string& marca) const
{
    for (Product* producto : productos) {
        if (producto->getMarca() == marca)
        {
            return producto;
        }
    }
    return nullptr;
}

bool Inventario::eliminarProductoPorModelo(const string& modelo)
{
    string choice;
    for (auto it = productos.begin(); it != productos.end(); ++it)
     {
        if ((*it)->getModelo() == modelo)
        {
            cout<<"¿Quieres continuar?"<<endl;
            cout<<"1-Si\n2-No\nElige una opcion: ";
            getline(cin, choice);
            if (choice=="1")
            {
                delete *it;
                productos.erase(it);
                cout << "Producto eliminado.\n";
                return true;
            }
            else
                cout<<"Accion cancelada..."<<endl;
        }
    }
    cout << "Producto no encontrado.\n";
    return false;
}

void Inventario::mostrarTodosLosProductos() const
{
    if (productos.empty())
    {
        std::cout << "No hay productos registrados.\n";
        return;
    }
    for (const auto& producto : productos)
    {
        producto->mostrarDetalles();
    }
}
