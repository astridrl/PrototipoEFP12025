#include "bitacora.h"

#include<iostream>
#include<fstream>
#include<cstdlib>
#include<conio.h>
#include<iomanip>

using namespace std;

bitacora::bitacora()
{
    //ctor
}

void bitacora::menu(){
    int choice;
    char x;
    do{
        system("cls");
        cout<<"\t\t\t-------------------------------"<<endl;
        cout<<"\t\t\t |   SISTEMA GESTION BITACORA  |"<<endl;
        cout<<"\t\t\t-------------------------------"<<endl;
        cout<<"\t\t\t 1. Despliegue Bitacora"<<endl;
        cout<<"\t\t\t 2. Exit"<<endl;
        cout<<"\t\t\t-------------------------------"<<endl;
        cout<<"\t\t\tOpcion a escoger:[1/2]"<<endl;
        cout<<"\t\t\t-------------------------------"<<endl;
        cout<<"\t\t\tIngresa tu Opcion: ";
        cin>>choice;

        switch (choice){
        case 1:
            desplegar();
            break;
        case 2:
            break;
        default:
            cout <<"\n\t\t\t Opccion invalida intente denuevo...";
            cin.get();
        }
    }while (choice !=2);
}

//Se encarga de llevar el registro de acciones que se realizan
void bitacora::insertar(string nombre, string aplicacion, string accion){
    system("cls");
    fstream file;
    file.open("bitacora.txt", ios::app | ios::out);

    //se obtine la fecha y la hora en que se realiza la accion
    time_t now = time(0);
    tm *ltm = localtime(&now);
    char fecha[30];
    strftime(fecha, sizeof(fecha), "%Y-%m-%d %H:%M:%S", ltm); //formato: mm-dd-yyyy hh:mm AM/PM

    file<<left<<setw(15)<<nombre<<left<<setw(15)
    <<aplicacion<<left<<setw(15)<<accion<<fecha<<"\n";
    file.close();
}

void bitacora::desplegar(){

    system("cls");
    fstream file;
    int total=0;
	cout<<"\n-------------------------Tabla de Detalles de Bitacora -------------------------"<<endl;
	file.open("bitacora.txt", ios::in);

	if(!file){
	    cout<<"\n\t\t\tNo hay informacion..";
	    file.close();
	}
	else{
        file >> nombre >> aplicacion >> accion >> fecha;
        while (!file.eof()){
            total++;
            cout <<"\n\n\t\t\t Nombre Usuario: " << nombre<<endl;
            cout <<"\t\t\t No. Aplicacion: " <<aplicacion<<endl;
            cout <<"\t\t\t Accion Realizada: "<< accion<< endl;
            cout <<"\t\t\t Fecha y Hora: "<<fecha<< endl;

            file >> nombre >> aplicacion >> accion >> fecha;
        }

        system ("pause");

        if (total==0){
            cout <<"\n\t\t\t No hay informacion...";
        }
        system("cls");
	}
	file.close();

	system ("cls");
}
