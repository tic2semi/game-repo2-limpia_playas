#include <SFML/Graphics.hpp>
#include<time.h>
#include<stdlib.h>
#include <iostream>
using namespace sf;
using namespace std;
int main(int argc, char *argv[]){
	RenderWindow w(VideoMode(640,480),"botellasjuego avance 1");
	Texture t;
	Sprite s;
	srand(time(NULL));
	t.loadFromFile("botella.png");
	s.setTexture(t);
	
	float calle,pos_x,pos_y;
	
	calle=(rand()%3);

	if (calle == 0)
	{
		pos_x=(rand()%640);
		pos_y=(rand()%160);
		
		t.loadFromFile("botella.png");
		s.setPosition(pos_x, pos_y);
	}
	if (calle==1)
	{
		pos_x=(rand()%640);
		pos_y=(rand()%160+160);
		t.loadFromFile("botella.png");
		s.setPosition(pos_x, pos_y);
	}
	if (calle==2)
	{
		pos_x=(rand()%640);
		pos_y=(rand()%160+320);
		t.loadFromFile("botella.png");
		s.setPosition(pos_x, pos_y);
	}
	
	pos_x=(pos_x+(pos_x/2));
	while(w.isOpen()) {
		Event e;
		while(w.pollEvent(e)) {
			if(e.type == Event::Closed)
				w.close();	
		}
		
		w.clear(Color(255,255,255,255));
		w.draw(s);
		w.display();
	}
	return 0;
}
	
	
