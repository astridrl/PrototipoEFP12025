#ifndef HABITACION_H
#define HABITACION_H

#include<iostream>

using namespace std;
class habitacion
{
    public:
        void menu();
		void insertar();
		void desplegar();
		void modificar();
		void buscar();
		void borrar();
		void reporte();

    protected:

    private:
        string nombre, telefono, nit;
		string id;
		string estatus;
};

#endif // HABITACION_H



