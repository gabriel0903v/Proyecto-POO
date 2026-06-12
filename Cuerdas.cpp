#ifndef VIENTO_H
#define VIENTO_H


#include "Product.h"

class Viento : public Product {
public:

    Viento(const string& marca, const string& modelo, double precio, const string& descripcion);
    void mostrarDetalles();
};

#endif
