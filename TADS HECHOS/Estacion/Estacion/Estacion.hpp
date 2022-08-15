//
//  Estacion.hpp
//  Estacion
//
//  Created by Maria Vazquez on 4/1/21.
//

#ifndef Estacion_hpp
#define Estacion_hpp

#include <stdio.h>
#include <iostream>
#include "ListaD.h"
#include "ListaE.h"
using namespace std;

typedef struct
{
    int hora,minutos,dia,mes;
}Fecha;

typedef struct
{
    int codigo;
    Fecha f_salida;
    Fecha f_llegada;
    
}Tren;

typedef struct
{
    int codigo;
    ListaD<Tren> l_trenes;
    
}Via; //Cada via tiene un codigo y una lista de trenes

class Estacion
{
public:
    
    //Precondicion: Recibe un numero entero que se corresponde con el numero de vias transitables
    //Postcondicion: Crea una estacion con N vias transitables y dos vias muertas
    Estacion(int N):n(N+2){}
    
    //Precondicion:Existe una estanción y recibe un tren concreto y una Vía de transito libre de dicha estacion
    //Postcondicion: Introduce el Tren dado en la Vía dada
    void llegada_tren(Tren t, Via v);
    
    //Precondicion: Existe una estacion no vacia y recibe una vía no vacia
    //Postcondicion: Elimina el tren de la Vía dada
    void salida_tren(Via v);
    
    //Precondicion: Existe una estacion no vacia y recibe un tren que se encuentra en una via de transito
    //Postcondicion: Elimina el tren de la via de transito y lo añade a la via de estacionamiento
    void transito_estacionamiento(Tren t);
    
    //Precondicion: Existe una estacion no vacia y recibe un tren que se encuentra en la via de estacionamiento
    //Postcondicion: Elimina el tren de la via de estacionamiento y lo asigna a una via de transito libre
    void estacionamiento_transito(Tren t);
    
    //Precondicion: Existe una estacion no vacio y recibe un tren de la estacion
    //Postcondicion: Devuelve la via en la que se encuentra el tren dado
    Via encuentra_tren(Tren t)const;
    
    //Precondicion: Existe una estacion no vacia y recibe una vía no vacia de la estacion dada
    //Postcondicion: Devuelve el codigo del tren que se encuentra en la via dada
    int tren_via(Via v)const;
    
    //Postcondicion: Devuelve la lista de vias
    ListaE<Via> lista_vias()const{return l_vias;}
    
    //Postcondicion: Devuelve el tamaño de la estacion
    int tamaño()const{return n;}
    
private:
    int n;
    ListaE<Via> l_vias(n);
    
};

//Precondicion: Recibe una estacion no vacia y una fecha
//Postcondicion: Devuelve el estado de una estacion en la fecha dada
Estacion estado(Estacion t, Fecha f);
#endif /* Estacion_hpp */
