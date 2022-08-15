//
//  Cubilete.cpp
//  Prueba
//
//  Created by Maria Vazquez on 28/12/20.
//

#include "Cubilete.hpp"
#include <iostream>

cubilete::cubilete(){};

bool cubilete::bien_colocada_ordenada(Pila<tCubo> pila)
{
    bool comprobar=true;
    Pila<tCubo>aux;
    tCubo cubo1;
    while(comprobar != false && !pila.vacia())
    {
        cubo1=pila.tope();
        pila.pop();
        
        if((cubo1.tam < (pila.tope().tam)) && (cubo1.coloc == 2) && (pila.tope().coloc == 2))
        {
            aux.push(cubo1);
            cubo1=pila.tope();
            pila.pop();
        }
        else
        {
            comprobar=false;
        }
    }
    return comprobar;
}
Pila<tCubo> cubilete::simular_juego()
{
    Pila<tCubo> aux = p;
    Pila<tCubo> aux1;
    tCubo cubo1,cubo2,cubo3;
    
    while(bien_colocada_ordenada(aux) != true)
    {
        cubo1=aux.tope();
        aux.pop();
        cubo2=aux.tope();
        aux.pop();
        
        while(!aux.vacia())
        {
            if(cubo1.tam<cubo2.tam)
            {
                aux1.push(cubo1);
                cubo1=aux.tope();
            }
            else{
                aux1.push(cubo2);
                cubo2=aux.tope();
            }
            aux.pop();
        }
        cubo3=aux1.tope();
        if(cubo1.tam == cubo3.tam && cubo1.coloc == cubo3.coloc)
        {
            aux1.push(cubo2);
        }
        else{
            aux1.push(cubo1);
        }
        while(!aux1.vacia())
        {
            aux.push(aux1.tope());
            aux1.pop();
        }

    }
    return aux;
}
