//
// Created by jsoto on 26/05/2020.
//

#ifndef UNTITLED_PRESTAMO_H
#define UNTITLED_PRESTAMO_H


class Prestamo {
    private:
        int usuario;
        int pelicula;
        char fechaInicial[100];
        char fechaFinal[100];
        int estatus;
    public:
        Prestamo();
        Prestamo(int,int,char []);
        void devolucion(char []);
        int getUsuario();
        int getPelicula();
        int getEstatus();
        void toString();
};


#endif //UNTITLED_PRESTAMO_H
