#ifndef INVENTARIO_H
#define INVENTARIO_H

using namespace std;

#include <vector>
#include "Product.h"

class Inventario {
private:
    vector<Product*> productos;

public:
    ~Inventario();
    void agregarProducto(Product* producto);
    Product* buscarProductoPorModelo(const string& modelo) const;
    Product* buscarProductoPorMarca(const string& marca) const;
    bool eliminarProductoPorModelo(const string& modelo);
    void mostrarTodosLosProductos() const;
};

#endif
