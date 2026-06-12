#include "Product.h"
#include <iostream>

using namespace std;

Product::Product(const string& marca, const string& modelo, double precio, const string& descripcion)
    {
        this->marca=marca;
        this->modelo=modelo;
        this->precio=precio;
        this->descripcion=descripcion;
    }

string Product::getMarca()
{
    return marca;
}

void Product::setMarca(const string& marca)
{
    this->marca = marca;
}

string Product::getModelo()
{
    return modelo;
}

void Product::setModelo(const string& modelo)
{
    this->modelo = modelo;
}

double Product::getPrecio()
{
    return precio;
}

void Product::setPrecio(double precio)
{
    this->precio = precio;
}

string Product::getDescripcion()
{
    return descripcion;
}

void Product::setDescripcion(const string& descripcion)
{
    this->descripcion = descripcion;
}

void Product::mostrarDetalles() const
{
    cout<<"Marca: "<<marca<<", Modelo: "<<modelo<<", Precio: $" <<precio<<", Descripcion: "<<descripcion<<endl;
}

bool Product::operator==(const Product& otro) const {
    // Compara solo los precios de dos productos para determinar si son iguales
    return (precio == otro.precio);
}

// Implementacion de la sobrecarga del operador +
double Product::operator+(const Product& otro) const {
    return precio + otro.precio;
}

// Implementacion de la sobrecarga del operador -
double Product::operator-(const Product& otro) const {
    double total = precio + otro.precio; // Suma de los precios
    double descuento = total * 0.15; // Calcula el 15% de descuento
    return total - descuento; // Devuelve el total con el descuento aplicado
}

// Implementacion de la sobrecarga del operador -
double Product::operator-() const {
    double descuento = precio * 0.05; // Descuento del 5%
    return precio - descuento; // Devuelve el precio con el descuento aplicado
}

// Implementacion de la sobrecarga del operador +
double Product::operator+() const {
    double aumento = precio * 0.05; // Aumento del 5%
    return precio + aumento; // Devuelve el precio con el aumento aplicado
}
