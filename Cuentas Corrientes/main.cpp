//Menu modificado por Astrid Ru�z 9959 24 2976 - Agregu� menu de seguridad para usuarios y agregu� backup
#include <iostream>
#include <cstdlib>
#include "usuarios.h"
#include "catalogos.h"
#include "procesos.h"
#include "bitacora.h"
#include "habitacion.h"
#include <limits>

using namespace std;

extern habitacion habitaciones;

void menuGeneral();
void menuInicio();
void menuUsuarios();
void menuBackup();

// Objetos
usuarios usuariosrRegistrado;
Catalogos catalogo;
bitacora auditorias;

int main()
{
    try {
        menuInicio();
    } catch (exception &e){
        cout << "\n\t\t Error ocurrido: " << e.what() << endl; //En caso de un erro en medio de la ejecucion
    }

    system("cls");
    cout << "\n\t\tSALIENDO DEL SISTEMA...\n";
    return 0;
}

void menuInicio() {
    int opcion;
    bool accesoUsuarios;

    do {
        system("cls");
        cout << "\n\t\t--------------------------------------" << endl;
        cout << "\t\t   SISTEMA DE USUARIOS - MENU ARCHIVOS  " << endl;
        cout << "\t\t--------------------------------------" << endl << endl;
        cout << "\t\t1. Iniciar Sesi�n" << endl;
        cout << "\t\t2. Registrarse" << endl;
        cout << "\t\t3. Gesti�n de Usuarios" << endl;
        cout << "\t\t4. Backup y Respaldo" << endl;
        cout << "\t\t5. Salir" << endl;
        cout << "\t\tSeleccione una opci�n: ";
        cin >> opcion;
        cin.ignore();

        switch (opcion) {
            case 1:
                system("cls");
                accesoUsuarios = usuariosrRegistrado.loginUsuarios();
                if (accesoUsuarios) {
                    menuGeneral();
                    return;
                }
                break;
            case 2:
                system ("cls");
                usuariosrRegistrado.registrarUsuario();
                 break;
            case 3:
                system("cls");
                if (usuariosrRegistrado.getNombre().empty()) {
                    cout << "\n\t\tDebe iniciar sesi�n para acceder a esta funci�n." << endl;
                     system("pause"); // <-- Pausa para que se lean los mensajes
                    if (!usuariosrRegistrado.loginUsuarios()) {
                        cout << "\n\t\tInicio de sesi�n fallido. No se puede acceder a Gesti�n de Usuarios." << endl;
                        system("pause"); // <-- Pausa para que se lean los mensajes
                        break;
                    }
                }
                menuUsuarios(); // ya est� autenticado aqu�
                break;
            case 4:
                system("cls");
                if (usuariosrRegistrado.getNombre().empty()) {
                    cout << "\n\t\tDebe iniciar sesi�n para acceder a esta funci�n." << endl;
                    system("pause"); // <-- Pausa para que se lean los mensajes
                    if (!usuariosrRegistrado.loginUsuarios()) {
                        cout << "\n\t\tInicio de sesi�n fallido. No se puede acceder a Backup." << endl;
                        system("pause"); // <-- Pausa para que se lean los mensajes
                        break;
                    }
                }
                menuBackup();
                break;
            case 5:
                return; // Salir del programa
            default:
                cout << "\n\t\tOpci�n inv�lida. Intente de nuevo." << endl;
                system("pause");
        }
    } while (opcion != 5);
}

void menuUsuarios() {
    int choice;
    do {
        system("cls");
        cout << "\t\t\t-------------------------------------------------------" << endl;
        cout << "\t\t\t | SISTEMA GESTION DE SEGURIDAD - Cat�logo Habitacion|" << endl;
        cout << "\t\t\t-------------------------------------------------------" << endl;
        cout << "\t\t\t 1. Despliego de bitacora" << endl;
        cout << "\t\t\t 2. Ingreso Usuarios" << endl;
        cout << "\t\t\t 3. Consulta Usuarios" << endl;
        cout << "\t\t\t 4. Modificaci�n Usuarios" << endl;
        cout << "\t\t\t 5. Eliminaci�n Usuarios" << endl;
        cout << "\t\t\t 6. Retornar al men� anterior" << endl;
        cout << "\t\t\t-------------------------------------------------------" << endl;
        cout << "\t\t\tIngrese una opci�n: ";
        cin >> choice;

        switch (choice) {
        case 1:
            auditorias.menu ();
            break;
        case 2:
            usuariosrRegistrado.registrarUsuario();
            break;
        case 3:
            usuariosrRegistrado.consultarUsuarios();
            system("pause"); // <-- Pausa para que se lean los mensajes
            break;
        case 4:
            usuariosrRegistrado.modificarUsuario();
            break;
        case 5:
            usuariosrRegistrado.eliminarUsuario();
            break;
        case 6:
            break;
        default:
            cout << "n\t\tOpci�n no v�lida. Intente de nuevo" << endl;
        }

    } while (choice != 6);
}


void menuBackup() {
    int opcion;
    do {
        system("cls");
        cout << "\n\t\t---------------------------------" << endl;
        cout << "\t\t  MEN� DE BACKUP Y RESPALDO     " << endl;
        cout << "\t\t---------------------------------" << endl << endl;
        cout << "\t\t1. Realizar backup de usuarios" << endl;
        cout << "\t\t2. Restaurar desde backup" << endl;
        cout << "\t\t3. Retornar al men� anterior" << endl;
        cout << "\t\tSeleccione una opci�n: ";
        cin >> opcion;
        cin.ignore();

        switch (opcion) {
            case 1:
                usuariosrRegistrado.backupUsuarios();
                break;
            case 2:
                usuariosrRegistrado.restaurarBackup();
                break;
            case 3:
                break;
            default:
                cout << "\n\t\tOpci�n inv�lida. Intente de nuevo." << endl;
        }

        if (opcion != 3) {
            cout << "\n\t\tPresione Enter para continuar...";
            cin.get();
        }
    } while (opcion != 3);
}

void menuInformes() {
    //pago pag;
//Factura fac;
    //GestionCobros cob;

    int opcion;
    do {
        system("cls");
        cout << "\t\t\tUsuario en linea: " << usuariosrRegistrado.getNombre() << "\n" << endl;
        cout<<"\t\t\t-------------------------------"<<endl;
        cout<<"\t\t\t |   Menu de reportes      |"<<endl;
        cout<<"\t\t\t-------------------------------"<<endl;
        cout <<"\t\t\t1. Reporte" << endl;
        cout <<"\t\t\t2. Salir" << endl;
        cout <<"\n\t\tIngresa tu Opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
            habitaciones.reporte ();
            case 2:
                break;
            default:
                cout << "\t\tOpci�n inv�lida..." << endl;
                system("pause");
        }
    } while (opcion != 2);
}

void menuGeneral(){
    int opciones;
    do{
        system("cls"); // Limpia la pantalla
        cout << "\t\t\tUsuario en linea: " << usuariosrRegistrado.getNombre() << "\n" << endl;
        cout << "\n\n\t\tHabitacion - Menu" << endl;
        cout << "\t\t------------------------" << endl;
        cout << "\t\t1. Menu de Catalogos" << endl;
        cout << "\t\t2. Menu de Informes" << endl;
        cout << "\t\t3. Menu de Seguridad" << endl;
        cout << "\t\t5. Menu de Bitacora" << endl;
        cout << "\t\t6. Menu de Archivos (Usuarios)" << endl;
        cout << "\t\t7. Salir" << endl;
        cout << "\n\t\tIngrese una opcion: ";
        cin >> opciones;

        switch (opciones) {
            case 1:
                catalogo.menuCatalogos();
                break;
            case 2:
                menuInformes();
                break;
            case 3:
                menuUsuarios();
                break;
            case 4:
                //menuConfiguracion();
                break;
            case 5:
                auditorias.menu();
                break;
            case 6:
                menuInicio();
                break;
            case 7:
                cout << "\n\n\t\tSaliendo del sistema...\n" << endl;
                break;
            default:
                cout << "n\t\tOpci�n no v�lida. Intente de nuevo" << endl;
        }
    } while (opciones != 7); // Repite el men� hasta que el usuario quiera salir

}
