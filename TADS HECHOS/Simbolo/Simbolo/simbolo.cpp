//
//  simbolo.cpp
//  Simbolo
//
//  Created by Maria Vazquez on 23/1/21.
//

#include "simbolo.hpp"
#include "piladinam.hpp"
//Precondición: Que exista un Simbolo
//Postcondición: Añadir un trazo al final de un simbolo
void añadir_trazo(Trazo t)
{
    p.push(t);
}

//Precondición: Existe un Simbolo no vacio, recibe el numero de trazos
//que se quieren deshacer
//Postcondicion: Elimina los ultimos n trazos
void deshacer_trazos(int n)
{
    int i=0;
    while(i<n && !p.vacia())
    {
        p.pop();
        i++;
    }
}

//Precondición: Existe un Simbolo no vacio, recibe el eje de simetria
//(Eje X=1, Eje Y=2, Eje XY=3)
//Postcondición: Devuelve el simbolo simétrico respecto al eje indicado
Simbolo simetria(int eje)
{
    Simbolo aux;
    Simbolo final;
    if(eje == 1)//EJE X
    {
        while(!p.vacia())
        {
            if(p.tope().sentido == Arriba)
            {
                p.tope().sentido = Abajo;
            }
            if(p.tope.sentido == Abajo)
            {
                p.tope().sentido = Arriba;
            }
            aux.push(p.tope());
            p.pop();
        }
    }
    else if(eje == 2)//EJE Y
    {
        while(!p.vacia())
        {
            if(p.tope().sentido == Izquierda)
            {
                p.tope().sentido = Derecha;
            }
            if(p.tope.sentido == Derecha)
            {
                p.tope().sentido = Izquierda;
            }
            aux.push(p.tope());
            p.pop();
        }
    }
    else if(eje == 3)
    {
        while(!p.vacia())
        {
            if(p.tope().sentido == Arriba)
            {
                p.tope().sentido = Abajo;
            }
            if(p.tope.sentido == Abajo)
            {
                p.tope().sentido = Arriba;
            }
            if(p.tope().sentido == Izquierda)
            {
                p.tope().sentido = Derecha;
            }
            if(p.tope.sentido == Derecha)
            {
                p.tope().sentido = Izquierda;
            }
            aux.push(p.tope());
            p.pop();
        }
    }
    while(!aux.vacia())
    {
        final.push(aux.tope());
        aux.pop();
    }
    return final;
}
