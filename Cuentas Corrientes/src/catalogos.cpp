//Definicion de la clase catalogos

#include "catalogos.h"
#include "cliente.h"
#include "proveedor.h"
#include "acreedor.h"
#include "habitacion.h"
#include <iostream>
using namespace std;

//Declaracion de objetos
cliente clientes;
proveedor proveedores;
acreedor acreedores;
habitacion habitaciones;

Catalogos::Catalogos()
{
    //ctor
}

void Catalogos::menuCatalogos(){
    int opciones;
    do{
        system("cls"); // Limpia la pantalla
        cout << "\n\n\t\tMenu de Catalogos" << endl;
        cout << "\t\t------------------------" << endl;
        cout << "\t\t1. Catalogo de Habitacion" << endl;
        cout << "\t\t2. Volver al menu principal" << endl;
        cout<<"\t\t Opcion a escoger:[1/2]"<<endl;
        cout << "\n\t\t Ingrese una opcion: ";
        cin >> opciones;

        switch (opciones) {
            case 1:
                habitaciones.menu();
                break;
            case 2:
                break;
            default:
                cout << "n\t\tOpción no válida. Intente de nuevo" << endl;
                system("pause");
        }
    } while (opciones != 2); // Repite el menú hasta que el usuario quiera salir
}
