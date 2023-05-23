#ifndef HABITACION2_H
#define HABITACION2_H
#include <iostream>
#include <string>

    class Habitacion
    {
    private:
        int numero; //Numero de Habitacion
        std::string nombre; //Nombre del huesped
        int adulto; //Numero de adultos
        int infantes; //Numero de infantes
        double credito; //Voucher abierto
        double cargo; //$ de cargos adicionales
        bool disponible; //La habitacion esta libre?
    public:
        Habitacion();
        Habitacion(int num_hab);
        //Getter Numero
        int getNumero() { return numero;}
        //Getter Disponible
        bool getDisponible() { return disponible; }
        //Funcion de CheckIn
        bool checkIn();
        //Funcion de CheckOut
        bool checkOut();
        //Funcion Tarifa Base
        double getTarifaBase();
        //Funcion Cargo
        bool realizarCargo(double nuevo_cargo);
        //Funcion que pasa la informacion a una string
        std::string toString();
    };
#endif