//
// Created by jsoto on 21/05/2020.
//

#ifndef UNTITLED_PELICULA_H
#define UNTITLED_PELICULA_H

#include "Persona.h"

class Pelicula {
    private:
        char nombre[100];
        Persona director;
        int annio;
        char genero[100];
        char productora[100];
        int minutos;
    public:
        Pelicula();
        Pelicula(char [], Persona,int, char[], char[], int);
        void getDirector();
        void toString();
};


#endif //UNTITLED_PELICULA_H
