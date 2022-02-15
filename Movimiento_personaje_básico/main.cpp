//Añadimos las siguientes librerias
#include <SFML/Graphics.hpp>	
#include <iostream>
#include <string>

using namespace sf;

int main(int argc, char *argv[]){
	int ancho=1080;
	int alto=720;
	
	RenderWindow w(VideoMode(ancho,alto),"Movimiento_básico");
	w.setFramerateLimit(60);
	
	//Definimos variables
	Texture t;
	Sprite s;
	
	int num_imagen=1;
	int incremento=-1;
	std::string num_imagen_st="";
	
	int ancho_imagen;
	int alto_imagen;
	int x;
	int y;
	
	alto_imagen = s.getLocalBounds().height;
	ancho_imagen = s.getLocalBounds().width;
	x=175;
	y=130;
	
	//Poner en pantalla el primer sprite
	t.loadFromFile("Run (1).png");
	s.setTexture(t);
	s.setPosition(x, y);
	
	while(w.isOpen()) {
		Event e;
		while(w.pollEvent(e)) {
			if(e.type == Event::Closed)
				w.close();	
		}
		
		w.clear(Color(255,255,255,255));
		w.draw(s);
		w.display();
		w.clear();
		
		//Cargar la siguiente imagen para crear un movimiento(error)
		num_imagen_st= "Run ("+std::to_string(num_imagen)+ ").png";
		
		t.loadFromFile(num_imagen_st);
		s.setTexture(t);
		
		
		if (Keyboard::isKeyPressed(Keyboard::Right)) s.move(6,0); 	//Condicional a traves del cual el personaje va hacia la derecha si presiona en el teclado la derecha
		if (Keyboard::isKeyPressed(Keyboard::Left)) s.move(-6,0);	//Condicional a traves del cual el personaje va hacia la izquierda si presiona en el teclado la izquierda
		
		// Condicionales a través de los cuales se debería cambiar el sprite o la imagen, con la finalidad de crear sensación de movimiento
		if (num_imagen==15){
			incremento=(-incremento);
		}
		
		if (num_imagen==1){
			incremento=(-incremento);
		}
		
		num_imagen+=incremento;
		
	}
	return 0;
}

