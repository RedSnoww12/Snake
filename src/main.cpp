#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <cstdlib>
#include "../includes/Menu.hpp"
#include <stdio.h>

int size = 30;
int width = size*size, height = size*size;
int num = 3;
int dir = 1;
int score = 0;
int TIME_SNAKE = 100;


struct Snake{

  int x = 0, y = 0;
	   
}s[100];

struct Fruit{
  int x,y;
}f;

int Action(sf::Sound *sound_sabre){

  
  for(int i = num; i>0 ; i--){
    
    s[i].x = s[i-1].x;
    s[i].y = s[i-1].y;
      
  }

  if (dir == 0) s[0].y -= 1;
  if (dir == 1) s[0].x += 1;
  if (dir == 2) s[0].y += 1;
  if (dir == 3) s[0].x -= 1;
  
  if (s[0].x == f.x && s[0].y == f.y)
    {
      sound_sabre->play();
      num = num + 1;
      f.x = rand()%size;
      f.y = rand()%size;
      score = score + 10;
    }

  if (s[0].x < 0) s[0].x = size;
  if (s[0].x > size) s[0].x = 0;
  if (s[0].y < 0) s[0].y = size;
  if (s[0].y > size) s[0].y = 0;

  for(int i = 1; i<num; i++)
    {
      if (s[0].x == s[i].x && s[0].y == s[i].y) return 1;
    }
  
  return 0;
}


int main () {


  int check_key = 0;

  sf::SoundBuffer buffer_sabre;
  buffer_sabre.loadFromFile("./son/sabre.wav");

  sf::Sound sound_sabre;
  sound_sabre.setBuffer(buffer_sabre);

  sf::SoundBuffer buffer;
  sf::SoundBuffer buffer1;
  sf::SoundBuffer buffer2;
  sf::SoundBuffer bufferF;
  buffer.loadFromFile("./son/son_menu.wav");
  buffer1.loadFromFile("./son/son_phase1.wav");
  buffer2.loadFromFile("./son/son_phase2.wav");
  bufferF.loadFromFile("./son/son_phaseFinal.wav");


  sf::Sound sound_menu;
  sf::Sound sound_phase1;
  sf::Sound sound_phase2;
  sf::Sound sound_phaseF;
  sound_menu.setBuffer(buffer);
  sound_menu.setVolume(60.f);
  sound_menu.play();

  sound_phase1.setBuffer(buffer1);
  sound_phase1.setVolume(40.f);
  
  sound_phase2.setBuffer(buffer2);
  sound_phase2.setVolume(40.f);

  sound_phaseF.setBuffer(bufferF);
  sound_phaseF.setVolume(40.f);
  
  
  sf::RenderWindow app(sf::VideoMode(width,height),"Snake");
  app.setFramerateLimit(60);



  sf::Texture fond;
  fond.loadFromFile("");
  sf::Sprite sprite;
  sprite.setTexture(fond);

  sf::Texture map;
  map.loadFromFile("./img/map.jpg");
  sf::Sprite sprite_map;
  sprite_map.setTexture(map);
  
  sf::RectangleShape snake(sf::Vector2f(size,size));
  snake.setFillColor(sf::Color::Green);
  
  sf::RectangleShape fruit(sf::Vector2f(size,size));
  fruit.setFillColor(sf::Color::Red);

  sprite.setScale(0.5, 0.8);
  sprite_map.setScale(1,1.25);
  
  sf::Clock timer;
  
  f.x = rand()%size;
  f.y = rand()%size;

  Menu menu(900,900);

  int musiqueIsPlaying = 0;
  int choixUser=0;
  
  while(app.isOpen()) {

    if(choixUser == 0)
    {
      app.clear();
      menu.draw(app);
      app.display();

    }

    sf::Event event;
    while(app.pollEvent(event))
    {
      if(choixUser == 0)
      {
        if(event.type == sf::Event::KeyPressed)
        {
          if(event.key.code == sf::Keyboard::Up)
          {
            menu.MoveUp();
          }
          else if(event.key.code == sf::Keyboard::Down)
          {
            menu.MoveDown();
          }
          if(event.key.code == sf::Keyboard::Enter)
          {
            if(menu.GetPressedItem() == 0) choixUser = 1;
            else if(menu.GetPressedItem() == 1) choixUser = 2;
            else if(menu.GetPressedItem() == 2) choixUser = 3;
          }
        }
      }

      switch(event.type)
      {


        case sf::Event::Closed:
          app.close();
          break;

        case sf::Event::KeyReleased:
          if(event.key.code == sf::Keyboard::Escape)
            app.close();
          break;
      }
    }

    if(choixUser==1){
      
      if(check_key == 0)
      {
        sound_menu.stop();
        sound_phase1.play();
        check_key = 1;
      }
      

      if (timer.getElapsedTime().asMilliseconds()>TIME_SNAKE)
        {
          if(Action(&sound_sabre) == 1) app.close();
          timer.restart();
        }
      
      if(dir != 2)
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) dir = 0;
      if(dir != 3)
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) dir = 1;
      if(dir != 0)
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) dir = 2;
      if(dir != 1)
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) dir = 3;
      
      app.clear();
      app.draw(sprite_map);
      for (int i = 0; i < num; i++) 
      {
        snake.setPosition(s[i].x*size, s[i].y*size);
        app.draw(snake);
      }
      
      fruit.setPosition(f.x*size, f.y*size);
      app.draw(fruit);
      
      app.display();
    }

    if (score==130 && check_key == 1)
    {
      sound_phase1.stop();
      sound_phase2.play();

      map.loadFromFile("./img/maxresdefault.jpg");
      sprite_map.setTexture(map);
      app.clear();
      app.draw(sprite_map);
      app.display();

      TIME_SNAKE = TIME_SNAKE - 40;
      check_key = 2;
    }

    if (score==260 && check_key == 2)
    {
      sound_phase2.stop();
      sound_phaseF.play();

      map.loadFromFile("./img/final.jpg");
      sprite_map.setTexture(map);
      app.clear();
      app.draw(sprite_map);
      app.display();

      TIME_SNAKE = TIME_SNAKE - 30;
      check_key = 3;
    }

    else if(choixUser==3){
      app.clear();
      app.close();
    }

  }
  return 0;
}
