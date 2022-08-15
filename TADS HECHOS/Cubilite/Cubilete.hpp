//
//  Cubilete.hpp
//  Prueba
//
//  Created by Maria Vazquez on 28/12/20.
//
//USAREMOS UNA PILA DINAMICA, YA QUE NO CONOCEMOS EL ESPACIO QUE VAMOS A NECESITAR
//ADEMAS NECESITAMOS UNA ESTRUCTURA tCubo QUE ESTARÁ FORMADA POR EL TAMAÑO Y LA COLOCACIÓN(BOCAARRIBA, BOCAABAJO)
#ifndef Cubilete_hpp
#define Cubilete_hpp

#include <stdio.h>
#include "piladinam.hpp"
typedef struct
{
    int tam;
    int coloc; //1=BOCARRIBA 2=BOCABAJO
}tCubo;

class cubilete
{
public:
    //POSTCIONDICION: Crea un cubilete vacio
    cubilete();//Constructor predeterminado
    
    //PRECONDICION: Recibe una pila no vacia
    //POSTCIONDICION: Devuelve True si la pila esta ordenadenada y colocada false de lo contrario
    bool bien_colocada_ordenada(Pila<tCubo> pila);
    
    //PRECONDICION: Existe una pila de cubiletes no vacia
    //POSTCONDICION: Devuelve una pila con los cubiletes ordenados de mayor a menor
    Pila<tCubo> simular_juego();
    
    
private:
    Pila<tCubo> p; //Pila dinamica de tCubo
};
#endif /* Cubilete_hpp */
