#ifndef PERCUSION_H
#define PERCUSION_H


#include "Product.h"

class Percusion : public Product
{
public:

    Percusion(const std::string& marca, const std::string& modelo, double precio, const std::string& descripcion);


    void mostrarDetalles();
};

#endif
