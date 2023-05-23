//Actividad diagnostico Diego Enrique Vargas
//Domindo 21 de marzo de 2023

#include <iostream>
#include <string>
#include "habitacion2.h"
#include "hotel2.h"


Habitacion::Habitacion()
{
    numero = 0;
    nombre = "";
    adulto = 0;
    infantes = 0;
    credito = 1000.0;
    cargo = 0.0;
    disponible = true;
}

Habitacion::Habitacion(int num_hab)
{
    numero = num_hab;
    disponible = true;
}

bool Habitacion::checkIn()
{
    if (disponible == true)
            {
                std::cout << "Introduzca el nombre del huesped: " <<  std::endl;
                std::getline(std::cin, nombre);
                std::cout << "Introduzca el numero de adultos: " <<  std::endl;
                std::cin >> adulto;
                std::cout << "Introduzca el numero de niños: " <<  std::endl;
                std::cin >> infantes;
                std::cout << "Introduzca los creditos disponibles: " <<  std::endl;
                std::cin >> credito;
                disponible = false;
                return true;
            }
            else
            {
                return false;
            }
}

bool Habitacion::checkOut()
{
    if (disponible == false)
            {
                nombre = "";
                adulto = 0;
                infantes = 0;
                cargo = 0.0;
                credito = 0.0;
                disponible = true;
                return true;
                std::cout << "Checkout completado" << std::endl;
            }   
            else
            {
                std::cout << "Habitacion vacia" << std::endl;
                return false;
            }
}

double Habitacion::getTarifaBase()
{
    double tarifaBase = adulto * 450 + infantes *150;
    return tarifaBase;
}

bool Habitacion::realizarCargo(double nuevo_cargo)
{
    if (nuevo_cargo >= 0 && (nuevo_cargo + cargo) <= credito)
            {
                cargo = cargo + nuevo_cargo;
                std::cout << "Cargo realizado con exito" << std::endl;
                return true;
            }
            else
            {
                std::cout << "Limite de credito excedido!" << std::endl;
                return false;
            }
}

std::string Habitacion::toString()
{
    std::string informacion = std::to_string(numero) + ",Huespued: " + nombre + ",Tarifa Base: " + std::to_string(this->getTarifaBase()) + ",Cargos: " + std::to_string(cargo);
    return informacion;
}

Hotel::Hotel(std::string nuevo_nombre)
{
    {
        numHabitaciones = 50;
        Habitacion habitaciones[numHabitaciones];
        for (int i = 0; i < numHabitaciones; i++)
        {
            Habitacion contenedor(i);
            habitaciones[i] = contenedor;
        }
        nombre = nuevo_nombre;
    }
}

int Hotel::checkIn()
{
    int valorReal;
        for (int i = 0; i < numHabitaciones; i++)
        {
            if (habitaciones[i].getDisponible() == true)
            {
                habitaciones[i].checkIn();
                valorReal = habitaciones[i].getNumero() + 100;
                std::cout << "Completado el check in de la habitacion numero " << valorReal << std::endl;
                return valorReal;
            }
        }
        std::cout << "No hay habitaciones disponibles" << std::endl;
        return -1;
}

bool Hotel::checkOut()
{
    int habActual;
    std::cout << "Introduzca la habitacion para hacer checkout (Con valores de 100): " << std::endl;
    std::cin >> habActual;
    habActual = habActual - 100;
    std::cout << "Haciendo checkout de la habitacion: " << std::endl;
    return habitaciones[habActual].checkOut();
}

bool Hotel::relizarCargosHabitacion()
{
    int habActual;
    int cargoPend;
    std::cout << "Introduzca la habitacion para hacer cargos: " << std::endl;
    std::cin >> habActual;
    habActual = habActual - 100;
    std::cout << "Introduzca el cargo: " << std::endl;
    std::cin >> cargoPend;
    return habitaciones[habActual].realizarCargo(cargoPend);
}

double Hotel::getTotalXTarifaBase()
{
    double total;
        for (int i = 0; i < numHabitaciones; i++)
        {
            if (habitaciones[i].getDisponible() == false)
            {
                total = total + habitaciones[i].getTarifaBase();
            }
        }
    std::cout << "Total de ganancias de hoy: " << total << std::endl;
    return total;
}

void Hotel::imprimeOcupacion()
{
    for (int i = 0; i < numHabitaciones; i++)
    {
        if (habitaciones[i].getDisponible() == false)
            {
                std::cout << habitaciones[i].toString() << std::endl;
            }
     }
}

int main()
{
    int opcion = 100;
    std::string nombreHot;

    std::cout << "Introduzca un nombre para su hotel: " << std::endl;
    std::cin >> nombreHot;

    Hotel nuestroHotel(nombreHot);

    
    while (opcion != 0)
    {
        std::cout << "Bienvenido al sistema de manejo de hotel, escoge una opcion: " << std::endl;
        std::cout << "[1] Hacer check in" << std::endl;
        std::cout << "[2] Hacer check out" << std::endl;
        std::cout << "[3] Realizar cargo a habitacion" << std::endl;
        std::cout << "[4] Revisar total de tarifa base " << std::endl;
        std::cout << "[5] Imprimir ocupacion" << std::endl;
        std::cout << "[0] Salir del programa" << std::endl;
        std::cin >> opcion;
        std::cin.ignore();

        if (opcion == 1)
        {
            nuestroHotel.checkIn();
        }
        else if (opcion == 2)
        {
            nuestroHotel.checkOut();
        }
        else if (opcion == 3)
        {
            nuestroHotel.relizarCargosHabitacion();
        }
        else if (opcion == 4)
        {
            nuestroHotel.getTotalXTarifaBase();
        }
        else if (opcion == 5)
        {
            nuestroHotel.imprimeOcupacion();
        }
        else if (opcion == 0)
        {
            std::cout << "Saliendo del programa" << std::endl; 
        }
        else
        {
            std::cout << "Opcion invalida, intentelo de nuevo..." << std::endl;
        }
    }
};