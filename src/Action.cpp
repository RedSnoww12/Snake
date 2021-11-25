#include "../includes/Action.hpp"

int Action(sf::Sound *sound_sabre, Snake *s, appleSprite *f, int *num, int *dir, int size, int *score){

  
  for(int i = *num; i>0 ; i--){
    
    s[i].x = s[i-1].x;
    s[i].y = s[i-1].y;
      
  }

  if (*dir == 0) s[0].y -= 1;
  if (*dir == 1) s[0].x += 1;
  if (*dir == 2) s[0].y += 1;
  if (*dir == 3) s[0].x -= 1;
  
  if (s[0].x == f->x && s[0].y == f->y)
    {
      sound_sabre->play();
      *num = *num + 1;
      f->x = rand()%size;
      f->y = rand()%size;
      *score = *score + 10;
    }

  if (s[0].x < 0) s[0].x = size;
  if (s[0].x > size) s[0].x = 0;
  if (s[0].y < 0) s[0].y = size;
  if (s[0].y > size) s[0].y = 0;

  for(int i = 1; i<*num; i++)
    {
      if (s[0].x == s[i].x && s[0].y == s[i].y) return 1;
    }
  
  return 0;
}