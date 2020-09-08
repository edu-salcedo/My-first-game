
#pragma once
#include <allegro.h>
class Actor
{
   protected:
       int x;
       int y;
       int vida;
   public:
     Actor();
    virtual~Actor();
    virtual void draw(BITMAP*);
    virtual void update(BITMAP*);
    virtual void destroy();
    void setvida(int _vida){vida =_vida;}
    void setx(int _x){x =_x;}
    void sety(int _y){y =_y;}
    int getx(){return x;}
    int gety(){return y;}
    int getvida(){return vida;}
};
