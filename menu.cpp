
#include"menu.h"

void Menu::inicio()
{
    fondo  =load_bitmap("imagen/fondo0.bmp",NULL);
    fondo1 =load_bitmap("imagen/fondo1.bmp",NULL);
    fondo2 =load_bitmap("imagen/fondo2.bmp",NULL);
    fondo3 =load_bitmap("imagen/fondo3.bmp",NULL);
    cursor =load_bitmap("imagen/puntero.bmp",NULL);
    over  = load_bitmap("imagen/gameover.bmp",NULL);
    fnivel= load_bitmap("imagen/nivel.bmp",NULL);
    imag_vida =load_bitmap("imagen/vidac.bmp",NULL);
    explo2 = load_bitmap  ("imagen/explo2.bmp",NULL);
}

int Menu::draw(BITMAP*lienzo)
{
    draw_sprite(lienzo,fondo,0,0);
    if(mouse_x>190&&mouse_x<360&&mouse_y>180&&mouse_y<210)
    {
        draw_sprite(lienzo,fondo1,0,0);
        if(mouse_b & 1)
        {
            return 1;
        }
    }
    if(mouse_x>150&&mouse_x<380&&mouse_y>260&&mouse_y<2900)
    {
        draw_sprite(lienzo,fondo2,0,0);
        if(mouse_b &1)
        {

        }
    }
    if(mouse_x>210&&mouse_x<320&&mouse_y>340&&mouse_y<370)
    {
        draw_sprite(lienzo,fondo3,0,0);
        if(mouse_b &1)
        {
            return 2;
        }
    }

    draw_sprite(lienzo,cursor,mouse_x,mouse_y);
}

void Menu::gameover(BITMAP*buffer)
{

    draw_sprite(buffer,over,0,0);
}

void Menu::nivel(BITMAP*buffer)
{
    draw_sprite(buffer,fnivel,0,0);
}

void Menu::vidas(BITMAP*buffer, int op)
{
        switch(op)
        {
        case 1:masked_blit(imag_vida,buffer,0,0,35,10,40,31);
            break;
        case 2:
            masked_blit(imag_vida,buffer,0,0,35,10,80,31);
            break;
        case 3:draw_sprite(buffer,imag_vida,30,30);
            break;
        }

}

void Menu::explocion(BITMAP*buffer,int x,int y)
{

}
