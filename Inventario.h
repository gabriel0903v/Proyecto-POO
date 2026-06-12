#ifndef CUERDAS_H
#define CUERDAS_H

#include "Product.h"

class Cuerdas : public Product
{
public:

    Cuerdas(const string& marca, const string& modelo, double precio, const string& descripcion);


    void mostrarDetalles();
};

#endif
