#ifndef OTROS_H
#define OTROS_H


#include "Product.h"

class Otros : public Product {
public:
    // Constructor de la clase derivada que invoca al constructor del padre.
    Otros(const string& marca, const string& modelo, double precio, const string& descripcion);

    void mostrarDetalles();
};

#endif
