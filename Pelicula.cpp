//
// Created by jsoto on 21/05/2020.
//
#include <iostream>
#include <cstring>
#include "Pelicula.h"

using namespace std;

Pelicula::Pelicula() {

}

Pelicula::Pelicula(char nombre[100], Persona director, int annio, char genero[100], char productora[100], int minutos) {
   strcpy(this->nombre,nombre);
   this->director = director;
   this->annio = annio;
   strcpy(this->genero,genero);
   strcpy(this->productora,productora);
   this->minutos = minutos;
}

void Pelicula::getDirector() {
    this->director.toString();
}

void Pelicula::toString() {
    cout << "Información de la pelicula"<<endl;
    cout << "Nombre: "<< this->nombre<<endl;
    this->director.toString();
    cout << "Annio: "<<this->annio<<endl;
    cout << "Genero: "<<this->genero<<endl;
    cout << "Productora: "<<this->productora<<endl;
    cout << "Minutos: "<< this->minutos<<endl;
}