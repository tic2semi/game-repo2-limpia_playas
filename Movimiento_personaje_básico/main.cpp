//A?adimos las siguientes librerias
#include <SFML/Graphics.hpp>	
#include <iostream>
#include <string>
#include <stdlib.h> 

using namespace sf;

void temporizador_ralentiza(){
	int seconds=0;
	for(seconds=0 ; seconds<2750 ; seconds++)
	{
		std::cout << seconds << "segundos" << std::endl;
	}
}

int main(int argc, char *argv[]){
	int ancho=1080;
	int alto=720;
	
	RenderWindow w(VideoMode(ancho,alto),"Movimiento_b?sico");
	w.setFramerateLimit(60);
	
	//Definimos variables
	Texture t;
	Sprite s;
	
	int num_imagen=1;
	int incremento=-1;
	std::string num_imagen_st="";
	
	int ancho_imagen;
	int alto_imagen;
	float x;
	float y;
	int salto_valor=-200;
	int descenso_valor=200;
	
	alto_imagen = s.getLocalBounds().height;
	ancho_imagen = s.getLocalBounds().width;
	x=175;
	y=100;
	
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
		
		
		if (Keyboard::isKeyPressed(Keyboard::Up)) {
			
			if(y>100){
			
			s.move(0,salto_valor);
			temporizador_ralentiza();
			
		}}
		
		if (Keyboard::isKeyPressed(Keyboard::Down)) {
			
			if(y<300){
				
				s.move(0,descenso_valor);
				temporizador_ralentiza();
				
			}
			 
			if(y<500 && y!=100){
				
				s.move(0,descenso_valor);
				temporizador_ralentiza();
			}
		}
		if (Keyboard::isKeyPressed(Keyboard::Right)) s.move(6,0); 	//Condicional a traves del cual el personaje va hacia la derecha si presiona en el teclado la derecha
		if (Keyboard::isKeyPressed(Keyboard::Left)) s.move(-6,0);	//Condicional a traves del cual el personaje va hacia la izquierda si presiona en el teclado la izquierda
		
		// Condicionales a trav?s de los cuales se deber?a cambiar el sprite o la imagen, con la finalidad de crear sensaci?n de movimiento
		if (num_imagen==15){
			incremento=(-incremento);
		}
		
		if (num_imagen==1){
			incremento=(-incremento);
		}
		
		num_imagen+=incremento;
		std::cout << y << "/";
		y=s.getPosition().y;
		x=s.getPosition().x;	
	}
	return 0;
}


