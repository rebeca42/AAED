//
//  simbolo.hpp
//  Simbolo
//
//  Created by Maria Vazquez on 23/1/21.
//
/*
 ESPECIFICACIÓN
 
 Necesitamos una estructura Trazo compuesta por un sentido(izq,der,arriba,abajo)
 que representa la dirección del trazo
 
 Necesitamos una clase Simbolo compuesta por una pila dinamica de trazos, las
 operaciones a realizar son:
 
 
 */
#ifndef simbolo_hpp
#define simbolo_hpp

#include <stdio.h>
#include <iostream>
#include "piladinam.hpp"
typedef struct
{
    enum sentido {Izquierda,Derecha,Arriba,Abajo};
}Trazo;

class Simbolo
{
public:
    //Postcondicion: Crea un Simbolo vacio
    Simbolo(){}
    
    //Precondición: Que exista un Simbolo
    //Postcondición: Añadir un trazo al final de un simbolo
    void añadir_trazo(Trazo t);
    
    //Precondición: Existe un Simbolo no vacio, recibe el numero de trazos
    //que se quieren deshacer
    //Postcondicion: Elimina los ultimos n trazos
    void deshacer_trazos(int n);
    
    //Precondición: Existe un Simbolo no vacio, recibe el eje de simetria
    //(Eje X=1, Eje y=2, Eje XY=3)
    //Postcondición: Devuelve el simbolo simétrico respecto al eje indicado
    Simbolo simetria(int eje);
    
private:
    Pila<Trazo> p;
};
#endif /* simbolo_hpp */
