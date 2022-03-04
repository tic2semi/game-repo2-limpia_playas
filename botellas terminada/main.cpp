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
	Clock clock;
	Time t_ahora;
	Time t_ult_botella=seconds(0);
	Time t_transcurrido;
	
	
	while(w.isOpen()) {
		Event e;
	
		t_ahora=clock.getElapsedTime();
		
		t_transcurrido=(t_ahora-t_ult_botella);

	
	cout<<t_transcurrido.asSeconds()<<endl;
	
		if(t_transcurrido.asSeconds()>=10){
			
			/*cout<<"dibujar botellas"<<endl;*/
			calle=(rand()%3);
			if (calle == 0){
				pos_x=610;
				pos_y=(100);
				
			
				
			}
			
			if (calle==1)
			{
				pos_x=610;
				pos_y=(300);
				
	
				
				
				
				
			}
			if (calle==2){
				pos_x=610;
				pos_y=(500);
				
				
				
			
				
				
				
			}
			
			/*cout << t_transcurrido.asSeconds() << endl;*/
			clock.restart();
			
		}
		
		
		
		s.setPosition(pos_x, pos_y);
		pos_x=(pos_x-0.5);
		cout<<pos_x<< "posicion x"<< endl;
		t.loadFromFile("botella.png");
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
	
	
