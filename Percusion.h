#ifndef PERCUSION_H
#define PERCUSION_H


#include "Product.h"

class Percusion : public Product {
public:
    // Constructor de la clase derivada que invoca al constructor del padre.
    Percusion(const std::string& marca, const std::string& modelo, double precio, const std::string& descripcion) :
        Product(marca, modelo, precio, descripcion) {}

    // Método sobreescrito para mostrar detalles específicos del producto de cuerdas.
    void mostrarDetalles() const override {
        std::cout << "Producto de Percusion: ";
        Product::mostrarDetalles();
    }
};

#endif
