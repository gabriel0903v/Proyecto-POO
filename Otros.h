#ifndef MENU_H
#define MENU_H
#include <chrono>
#include <thread>
#include <iostream>

#include "Menu.h"
#include "Inventario.h"
#include "Product.h"
#include "Cuerdas.h"
#include "Percusion.h"
#include "Viento.h"
#include "Otros.h"

using namespace std;

class Menu
{
    public:
        Menu();
        void menuPrincipal();
        void pantallitaCarga();

        protected:

    private:
};

#endif // MENU_H`
