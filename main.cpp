#include <iostream>
#include <math.h>
#include <cstring>
#include <string>
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <sstream>
#include<time.h>

#include "Persona.h"
#include "Pelicula.h"
#include "Prestamo.h"

using namespace std;

Pelicula registrarPelicula()
{
    char nombre[100];
    char nombreD[100];
    char apellidosD[100];
    char nacionalidadD[100];
    int annio;
    char genero[100];
    char productora[100];
    int minutos;

    cout << "Nombre de pelicula"<<endl;
    cin >> nombre;

    cout << "Nombre del director"<<endl;
    cin >> nombreD;

    cout << "Apellidos del director"<<endl;
    cin >> apellidosD;

    cout << "Nacionalidad del director"<<endl;
    cin >> nacionalidadD;

    cout << "Annio de la pelicula"<<endl;
    cin >> annio;

    cout << "Genero de la pelicula"<<endl;
    cin >> genero;

    cout << "Productora de la pelicula"<<endl;
    cin >> productora;

    cout << "Minutos de la pelicula"<<endl;
    cin >> minutos;

    return  Pelicula(nombre,Persona(nombreD,apellidosD,nacionalidadD),annio,genero,productora,minutos);
}

Persona registrarUsuario()
{
    char nombreD[100];
    char apellidosD[100];
    char nacionalidadD[100];

    cout << "Nombre del usuario"<<endl;
    cin >> nombreD;

    cout << "Apellidos del usuario"<<endl;
    cin >> apellidosD;

    cout << "Nacionalidad del usuario"<<endl;
    cin >> nacionalidadD;


    return  Persona(nombreD,apellidosD,nacionalidadD);
}

Prestamo registrarPrestamo(int pelicula)
{
    int usuario;
    char fechaInicial[100];

    cout << "Numero  del usuario"<<endl;
    cin >> usuario;

    cout << "Fecha del prestamo"<<endl;
    cin >> fechaInicial;

    return  Prestamo(usuario,pelicula,fechaInicial);
}


void mostrarPeliculas(Pelicula peliculas[10],int peliculasC){
    for (int i = 0; i < peliculasC; ++i) {
        cout << "<==== Pelicula #" << i << "===>"<<endl;
        peliculas[i].toString();
        cout << "   <===============>"<<endl;
    }
}

void menuPeliculas(){
    cout << "<========= MENU ===================>"<<endl;
    cout << "<=== 1.- Registrar pelicula ======>"<<endl;
    cout << "<=== 2.- Editar pelicula =========>"<<endl;
    cout << "<=== 3.- Eliminar pelicula =======>"<<endl;
    cout << "<=== 4.- Consultar Director ======>"<<endl;
    cout << "<=== 5.- Consultar información ===>"<<endl;
    cout << "<=================================>"<<endl;
}

void menuUsuarios(){
    cout << "<========= MENU ===================>"<<endl;
    cout << "<=== 1.- Registrar usuarios ======>"<<endl;
    cout << "<=== 2.- Editar usuario =========>"<<endl;
    cout << "<=== 3.- Eliminar usuario =======>"<<endl;
    cout << "<=== 4.- Consultar usuario ======>"<<endl;
    cout << "<=================================>"<<endl;
}

void menuPrestamos(){
    cout << "<========= MENU =================>"<<endl;
    cout << "<=== 1.- Realizar prestamo ======>"<<endl;
    cout << "<=== 2.- Devolver pelicula ======>"<<endl;
    cout << "<=== 3.- Consultar prestamo =====>"<<endl;
    cout << "<=== 4.- Regresar ===============>"<<endl;
    cout << "<================================>"<<endl;
}

void menu(){
    cout << "<========= MENU ===================>"<<endl;
    cout << "<=== 1.- Administrar usuarios ======>"<<endl;
    cout << "<=== 2.- Administrar peliculas =========>"<<endl;
    cout << "<=== 3.- Administrar prestamos =======>"<<endl;
    cout << "<=================================>"<<endl;
}

int main(){
    Pelicula peliculas[10];
    Persona usuarios[10];
    Prestamo prestamos[100];
    int peliculasC = 0, usuariosC = 0, prestamosC = 0, op, no;
    bool pw = true, pp = true;
    char fechaFinal[100];

    while(pw){
        menu();
        cin >> op;

        switch (op) {
            case 1:
                menuUsuarios();
                cin >> op;
                switch (op) {
                    case 1:
                        usuarios[usuariosC] = registrarUsuario();
                        usuariosC++;
                        break;
                    case 2:
                        cout << "Ingrese el numero de usuario"<<endl;
                        cin >> no;

                        usuarios[no].toString();
                        usuarios[no] = registrarUsuario();
                        break;
                    case 3:
                        cout << "Ingrese el numero de usuario"<<endl;
                        cin >> no;

                        usuarios[no].toString();

                        pp = true;
                        for (int i = 0; i < prestamosC; ++i) {
                            //si entra al if quiere decir que tiene un prestamo activo
                            if(prestamos[i].getUsuario() == no && prestamos[i].getEstatus()==1){
                                pp = false;
                            }
                        }

                        if(pp){
                            usuarios[no] = Persona();
                        }else{
                            cout << "El usuario tiene prestamos activos"<<endl;
                        }
                        s
                        break;
                    case 4:
                        cout << "Ingrese el numero de usuario"<<endl;
                        cin >> no;

                        usuarios[no].toString();
                        break;

                }
                break;
            case 2:
                menuPeliculas();
                cin >> op;
                switch (op) {
                    case 1:
                        peliculas[peliculasC] = registrarPelicula();
                        peliculasC++;
                        break;
                    case 2:
                        cout << "Ingrese el numero de pelicula"<<endl;
                        cin >> no;

                        peliculas[no].toString();
                        peliculas[no] = registrarPelicula();
                        break;
                    case 3:
                        cout << "Ingrese el numero de pelicula"<<endl;
                        cin >> no;

                        peliculas[no].toString();

                        pp = true;
                        for (int i = 0; i < prestamosC; ++i) {
                            if(prestamos[i].getPelicula()==no && prestamos[i].getEstatus()==1){
                                pp = false;
                            }
                        }

                        if(pp){
                            peliculas[no] = Pelicula();
                        }else{
                            cout << "La pelicula tiene prestamos activos"<<endl;
                        }

                        break;
                    case 4:
                        cout << "Ingrese el numero de pelicula"<<endl;
                        cin >> no;

                        peliculas[no].getDirector();
                        break;
                    case 5:
                        cout << "Ingrese el numero de pelicula"<<endl;
                        cin >> no;

                        peliculas[no].toString();
                        break;

                }
                break;
            case 3:
                menuPrestamos();
                cin >> op;
                switch (op) {
                    case 1:
                        mostrarPeliculas(peliculas,peliculasC);
                        cout << "Ingrese el numero de la pelicula:"<<endl;
                        cin >> no;

                        pp = true;
                        for (int i = 0; i < prestamosC; ++i) {
                            //si entra al if quiere decir que la pelicula esta prestada
                            if(prestamos[i].getPelicula() == no && prestamos[i].getEstatus() == 1){
                                pp = false;
                            }
                        }

                        if(pp == true){ //si nunca entro al if, el libro no esta prestado
                            prestamos[prestamosC] = registrarPrestamo(no);
                            prestamosC++;
                        }else{
                            cout << "El pelicula ya esta prestada"<<endl;
                        }

                        break;
                    case 2:
                        cout << "Qué prestamo quiere devolver?"<<endl;
                        cin >> no;

                        usuarios[prestamos[no].getUsuario()].toString();
                        peliculas[prestamos[no].getPelicula()].toString();
                        prestamos[no].toString();

                        if(prestamos[no].getEstatus()==1){
                            cout << "Fecha de entrega"<<endl;
                            cin >> fechaFinal;

                            prestamos[no].devolucion(fechaFinal);

                            cout << "Ha devuelto la pelicula"<<endl;
                        }else{
                            cout << "El prestamo ha sido finalizado anteriormente"<<endl;
                        }



                        break;
                    case 3:
                        cout << "Qué prestamo quiere consultar?"<<endl;
                        cin >> no;

                        usuarios[prestamos[no].getUsuario()].toString();

                        peliculas[prestamos[no].getPelicula()].toString();

                        prestamos[no].toString();
                        break;
//s
                }
                break;
            default:
                pw = false;
                break;
        }
    }

    return 0;
}