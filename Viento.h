#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>
#include <iostream>

using namespace std;

class Product
{
protected:
    string marca;
    string modelo;
    double precio;
    string descripcion;

public:
    Product(const string& marca = "", const string& modelo = "",
                double precio = 0.0, const string& descripcion = "");

    // Metodos gets y sets
    string getMarca();
    void setMarca(const string& marca);

    string getModelo();
    void setModelo(const string& modelo);

    double getPrecio();
    void setPrecio(double precio);

    string getDescripcion();
    void setDescripcion(const string& descripcion);

    // Polimorfismo
    virtual void mostrarDetalles() const;


    // Sobrecarga del operador de igualdad para comparar precios
    bool operator==(const Product& otro) const;

    // Sobrecarga del operador +
    double operator+(const Product& otro) const;

    // Sobrecarga del operador -
    double operator-(const Product& otro) const;

    // Sobrecarga del operador - para aplicar un descuento del 5%
    double operator-() const;

    // Sobrecarga del operador + para aumentar el precio en un 5%
    double operator+() const;
};

#endif

