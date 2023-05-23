#ifndef HOTEL2_H
#define HOTEL2_H
#include <iostream>
#include <string>
#include "habitacion2.h"

    class Hotel
    {
    private:
        int numHabitaciones;
        std::string nombre;
        Habitacion habitaciones[50];
    public:
        Hotel(std::string nuevo_nombre);
        int checkIn();
        bool checkOut();
        bool relizarCargosHabitacion();
        double getTotalXTarifaBase();
        void imprimeOcupacion();
    };
#endif