#ifndef COCINA_H_
#define COCINA_H_

#include <cassert>
#include "TADListaDinamica.hpp"

typedef struct
{
	int lateral;
	int anchura;
}Mueble;

class Cocina{
	public:
        //Precondición: Recibe la longitud de la cocina la cual debe de ser mayor que 0
        //Postcondición: Crea una cocina vacia con la longitud dada
		Cocina(int l);
    
        //Precondición: Recibe un mueble y una posición
        //Postcondición: Devuelve 1 si se puede colocar en la posicón recibida y 0 de lo contrario
		int comprobar_mueble(Mueble m, int i)const;
    
        //Precondicion:Recibe un mueble y una posicion
        //Postcondición: Coloca el mueble en la posición recibida
		void colocar_mueble(Mueble m, int i);
    
        //Precondición: Recibe el numero del mueble empezando a contar por la izquierda
        //Postcondición: Devuelve el mueble iesimo
		Mueble mueble_iesimo(int i)const;
    
        //Precondición:Recibe el numero del mueble empezando a contar por la izquierda
        //Postcondición: Elimina el mueble iesimo
		void eliminar_mueble(int i);
    
        //Precondición: Recibe el numero del mueble empezando a contar por la izquierda
        //Postcondicion: Desplaza a la izquierda el mueble iesimo
		void juntar_mueble(int i);
    
        //Postcondición: Elimina la cocina
		~Cocina();
	private:
		Lista<Mueble> pared;
		int lon;
};

#endif
