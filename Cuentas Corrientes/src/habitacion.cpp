//Clase para mantenimiento de clientes
//Programado por Astrid Ruíz 02/05/25

//Actualizaciones y correcciiones
//Programado por Astriz Ruíz 11/05/25

#include "habitacion.h"
#include "bitacora.h"
#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<cstdlib>
#include<conio.h>
#include<iomanip>
#include "usuarios.h"

using namespace std;

extern usuarios usuariosrRegistrado;

void habitacion::menu()
{
    int choice;
	char x;

	do
    {
	system("cls");

	cout<<"\t\t\t-------------------------------"<<endl;
	cout<<"\t\t\t |   SISTEMA GESTION DE HABITACION |"<<endl;
	cout<<"\t\t\t-------------------------------"<<endl;
	cout<<"\t\t\t 1. Ingreso Habitacion"<<endl;
	cout<<"\t\t\t 2. Despliegue Habitacion"<<endl;
	cout<<"\t\t\t 3. Modifica Habitacion"<<endl;
	cout<<"\t\t\t 4. Busca Habitacion"<<endl;
	cout<<"\t\t\t 5. Borra Habitacion"<<endl;
	cout<<"\t\t\t 6. Reporte Habitacion" << endl;
	cout<<"\t\t\t 7. Salida"<<endl;

	cout<<"\t\t\t-------------------------------"<<endl;
	cout<<"\t\t\tOpcion a escoger:[1/2/3/4/5/6/7]"<<endl;
	cout<<"\t\t\t-------------------------------"<<endl;
    cout<<"\t\t\tIngresa tu Opcion: ";
    cin>>choice;

    switch(choice)
    {
    case 1:
    	do
    	{
    		insertar();
    		cout<<"\n\t\t\t Agrega otra habitacion (Y,N): ";
    		cin>>x;
		}while(x=='y'||x=='Y');
		break;
	case 2:
		desplegar();
		break;
	case 3:
		modificar();
		break;
	case 4:
		buscar();
		break;
	case 5:
		borrar();
		break;
	case 6:
	    reporte();
		break;
    case 7:
		break;
	default:
		cout<<"\n\t\t\t Opcion invalida...Por favor prueba otra vez..";
		cin.get();
	}
  }while(choice!= 7);
}
void habitacion::insertar()
{
	system("cls");
	fstream file;
	char confirmar; //Variable para guardar la respuesta de la confirmacion
	cout<<"\n------------------------------------------------------------------------------------------------------------------------";
	cout<<"\n-------------------------------------------------Agregar Habitación ---------------------------------------------"<<endl;
	cout<<"\t\t\tIngresa Id Habitacion        : ";
	cin>>id;
	cout<<"\t\t\tIngresa Tipo Habitacion     : ";
	cin>>nombre;
	cout<<"\t\t\tIngresa Tipo Cama de Habitacion   : ";
	cin>>telefono;
	cout<<"\t\t\tIngresa Precio Habitación  : ";
	cin>>nit;
	cout<<"\t\t\tIngresa estatus  : ";
	cin>>estatus;

	cout << "\n\t\t\t¿Deseas guardar los datos? (s/n): ";
    cin >> confirmar;

    if (confirmar == 's' || confirmar == 'S'){

	file.open("habitacion.txt", ios::app | ios::out);
	file<<left<<setw(15)<< id <<left<<setw(15)<< nombre <<left<<setw(15)<< telefono <<left<< setw(15) << nit << left << setw(15) << estatus << "\n";
	file.close();

	// Guardar en reportes.txt
	ofstream reporteFile;
    reporteFile.open("reportesHabitacion.txt", ios::app | ios::out);
    reporteFile << left << setw(15) << id << left << setw(15) << nombre<< left << setw(15) << telefono << left << setw(15) << nit << left << setw(15) << estatus << "\n";
    reporteFile.close();

    bitacora auditoria;
    auditoria.insertar(usuariosrRegistrado.getNombre(), "8011", "INS"); //ingreso a las bitácoras
}
}
void habitacion::desplegar()
{
	system("cls");
	fstream file;
	int total=0;
	cout<<"\n-------------------------Tabla de Detalles de Habitacion -------------------------"<<endl;
	file.open("habitacion.txt",ios::in);
	if(!file)
	{
		cout<<"\n\t\t\tNo hay informacion...";
		file.close();
	}
	else
	{
		file >> id >> nombre >> telefono >> nit;
		while(!file.eof())
		{
			total++;
			cout<<"\n\n\t\t\t Id Habitacion: "<<id<<endl;
			cout<<"\t\t\t Tipo habitacion: "<<nombre<<endl;
            cout<<"\t\t\t Tipo de Cama: "<<telefono<<endl;
            cout<<"\t\t\t precio: "<<nit<<endl;
            cout<<"\t\t\tIngresa estatus  : "<<estatus<<endl;


			file >> id >> nombre >> telefono >>nit >>estatus;
		}
		if(total==0)
		{
			cout<<"\n\t\t\tNo hay informacion...";
		}
		system("pause");
	}
	file.close();
    bitacora auditoria;
    auditoria.insertar(usuariosrRegistrado.getNombre(), "8011", "MC");//Muestra el cliente de la bitacora
}
void habitacion::modificar()
{
	system("cls");
	fstream file,file1;
	string participant_id;
	int found=0;
	cout<<"\n-------------------------Modificacion Detalles Habitacion-------------------------"<<endl;
	file.open("habitacion.txt",ios::in);
	if(!file)
	{
		cout<<"\n\t\t\tNo hay informacion..,";
		file.close();
	}
	else
	{
		cout<<"\n Ingrese Id de la habitacion que quiere modificar: ";
		cin>>participant_id;
		file1.open("temporal.txt",ios::app | ios::out); //Archivo para modificaciones
		file >> id >> nombre >> telefono >> nit;
		while(!file.eof())
		{
			if(participant_id!=id)
			{
			 file1<<left<<setw(15)<< id <<left<<setw(15)<< nombre <<left<<setw(15)<< telefono <<left<<setw(15)<< nit << left << setw(15) << estatus << "\n";
			}
			else
			{
				cout<<"\t\t\tIngrese Id Habitacion: ";
				cin>>id;
				cout<<"\t\t\tIngrese Tipo Habitacion: ";
				cin>>nombre;
				cout<<"\t\t\tIngrese Tipo Cama: ";
				cin>>telefono;
				cout<<"\t\t\tIngrese Precio: ";
				cin>>nit;
				cout<<"\t\t\tIngresa estatus  : ";
                cin>>estatus;

				file1<<left<<setw(15)<< id <<left<<setw(15)<< nombre <<left<<setw(15)<< telefono <<left<<setw(15)<< nit << left << setw(15) << estatus << "\n";
				found++;
			}
			file >> id >> nombre >> telefono >> nit >> estatus;

		}
		file1.close();
		file.close();
		remove("habitacion.txt");
		rename("temporal.txt","habitacion.txt");
        bitacora auditoria;
        auditoria.insertar(usuariosrRegistrado.getNombre(), "8011", "UPD"); //Actualizacion datos cliente
	}
}
void habitacion::buscar()
{
	system("cls");
	fstream file;
	int found=0;
	file.open("habitacion.txt",ios::in);
	if(!file)
	{
		cout<<"\n-------------------------Datos de la habitacion buscada------------------------"<<endl;
		cout<<"\n\t\t\tNo hay informacion...";
	}
	else
	{
		string participant_id;
		cout<<"\n-------------------------Datos de la habitacino Buscada------------------------"<<endl;
		cout<<"\nIngrese Id de la habitacion que quiere buscar: ";
		cin>>participant_id;
		file >> id >> nombre >> telefono >> nit >> estatus;
		while(!file.eof())
		{
			if(participant_id==id)
			{
				cout<<"\n\n\t\t\t Id Habitacion: "<<id<<endl;
				cout<<"\t\t\t Tipo Habitacion: "<<nombre<<endl;
				cout<<"\t\t\t Tipo Cama: "<<telefono<<endl;
				cout<<"\t\t\t precio: "<<nit<<endl;
				cout<<"\t\t\tIngresa estatus  : "<<estatus<<endl;

				found++;
				system("pause");
			}
			file >> id >> nombre >> telefono >> nit >> estatus;
		}
		if(found==0)
		{
			cout<<"\n\t\t\t Persona no encontrada...";
		}
		file.close();
        bitacora auditoria;
        auditoria.insertar(usuariosrRegistrado.getNombre(), "8011", "BH"); //Busqueda cliente en bitacora
	}
}
void habitacion::borrar()
{
	system("cls");
	fstream file,file1;
	string participant_id;
	int found=0;
	cout<<"\n-------------------------Detalles habitacion a Borrar-------------------------"<<endl;
	file.open("habitacion.txt",ios::in);
	if(!file)
	{
		cout<<"\n\t\t\tNo hay informacion...";
		file.close();
	}
	else
	{
		cout<<"\n Ingrese el Id de la habitacion que quiere borrar: ";
		cin>>participant_id;
		file1.open("temporal.txt",ios::app | ios::out);
		file >> id >> nombre >> telefono >> nit;
		while(!file.eof())
		{
			if(participant_id!= id)
			{
				file1<<left<<setw(15)<< id <<left<<setw(15)<< nombre <<left<<setw(15)<< telefono << left<<setw(15)<< nit << left << setw(15) << estatus << "\n";
			}
			else
			{
				found++;
				cout << "\n\t\t\tBorrado de informacion exitoso";
			}
			file >> id >> nombre >> telefono >> nit >> estatus;
		}
		if(found==0)
		{
			cout<<"\n\t\t\t Id Habitacion no encontrada...";
		}
		file1.close();
		file.close();
		remove("habitacion.txt");
		rename("temporal.txt","habitacion.txt");
        bitacora auditoria;
        auditoria.insertar(usuariosrRegistrado.getNombre(), "8011", "DEL"); //Eliminar cliente de bitacora
	}
}

void habitacion::reporte(){
    system("cls");
    fstream file;
    int found = 0;

    cout << "\n----------------------------- Reporte de Habitacion -----------------------------\n\n" << endl;
    file.open("habitacion.txt", ios::in);

    if (!file) {
        cout << "\n\t\t\tNo hay información...\n";
    }
    else {
        // Encabezado del reporte
        cout << left << setw(15) << "ID" << setw(30) << "Tipo" << setw(15) << "Tipo Cama"
             << setw(15) << "precio" << setw(30) << "estatus" << endl;
        cout << "-------------------------------------------------------------------------------\n";

        // Leer datos del archivo
        while (file >> id) {
            // Usamos getline para leer nombres con espacios
            file.ignore();  // Ignorar el salto de línea después del ID
            getline(file, nombre);
            file >> telefono >> nit >> estatus;

            found++;

            // Imprimir los datos del cliente
            cout << left << setw(15) << id << setw(30) << nombre << setw(15)
                 << telefono << setw(15) << nit << setw(15) << estatus << endl;
        }

        if (found == 0) {
            cout << "\n\t\t\tNo hay clientes registrados...\n";
        }
    }
    cout << endl;
    file.close();
    system("pause");

    // Guardar todos los clientes en el archivo de reporte
    ofstream reporteFile;
    reporteFile.open("reportesHabitacion.txt", ios::app);

    // Reabrimos el archivo para escribir todos los clientes
    file.open("habitacion.txt", ios::in);
    while (file >> id) {
        file.ignore(); // Ignorar salto de línea después del ID
        getline(file, nombre);
        file >> telefono >> nit >> estatus;

        // Escribir cada cliente en el reporte
        reporteFile << left << setw(15) << id << setw(30) << nombre
                    << setw(15) << telefono << setw(15) << nit << setw(15) << estatus << endl;
    }
    reporteFile.close();

    // Bitácora
    bitacora auditoria;
    auditoria.insertar(usuariosrRegistrado.getNombre(), "8011", "RPH"); // Reporte Cliente
}
