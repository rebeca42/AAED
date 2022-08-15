#include "Cocina.hpp"

Cocina::Cocina(int l){
	assert(lon > 0);
	
	lon = l;
}

int Cocina::comprobar_mueble(Mueble m, int i)const{
	int s;
	int j=0;
	
	typename Lista<Mueble>::posicion pos = pared.primera();
	
	if(pared.primera() == pared.fin() && lon >= m.anchura){
		s = 1;
	} else {
		while(pos != pared.fin() && j<i){
			pos = pared.siguiente(pos);
			j++;
		}
        if(pared.elemento(pos).lateral > (m.lateral+m.anchura) && ((pared.elemento(pared.anterior(pos)).lateral+pared.elemento(pared.anterior(pos)).anchura) < (m.lateral)))
        {
			s = 1;
		}
        else if((lon-(pared.elemento(pared.anterior(pos)).lateral+pared.elemento(pared.anterior(pos)).lateral)) >= m.anchura)
        {
			s = 1;
		}
        else
        {
			s = 0;
		}
	}
	return s;
}

void Cocina::colocar_mueble(Mueble m, int i){
	int j=0;
	typename Lista<Mueble>::posicion pos = pared.primera();
	
	if(comprobar_mueble(m,i) == 1){
		while(pos != pared.fin() && j<i){
			pos = pared.siguiente(pos);
			j++;
		}
		pared.insertar(m,pos);
	}
}

Mueble Cocina::mueble_iesimo(int i)const{
	int j=0;
	typename Lista<Mueble>::posicion pos = pared.primera();
	
	while(pos != pared.fin() && j<i){
		pos = pared.siguiente(pos);
		j++;
	}
	
	return pared.elemento(pared.anterior(pos));
}

void Cocina::eliminar_mueble(int i){
	int j=0;
	typename Lista<Mueble>::posicion pos = pared.primera();
	
	while(pos != pared.fin() && j<i){
		pos = pared.siguiente(pos);
		j++;
	}
	
	pared.eliminar(pared.anterior(pos));
}

void Cocina::juntar_mueble(int i){
	int j=0;
	typename Lista<Mueble>::posicion pos = pared.primera();
	
	if(i==0){
		pared.elemento(pared.primera()).lateral = 0;
	} else {
		while(pos != pared.fin() && j<i){
			pos = pared.siguiente(pos);
			j++;
		}
		pared.elemento(pos).lateral = pared.elemento(pared.anterior(pos)).lateral + pared.elemento(pared.anterior(pos)).anchura + 1;
		}					
}

Cocina::~Cocina(){};
	
