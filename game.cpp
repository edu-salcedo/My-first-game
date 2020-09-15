
#include "game.h"
#include "nave.h"
Game::Game()
{
    start();
    buffer = create_bitmap(SCREEN_W,SCREEN_H);
    nivel=1;
    numenemigo = 0;
}

void Game::init()
{
    fondo = new Fondo();
    menu.inicio();
    main();
    shutdown();
    delete fondo;

}


void Game::draw()
{
    draw_sprite(screen,buffer,0,0);
    clear_to_color(buffer,0x000000);
}

void Game::update()
{

}

void Game::main()
{
    Alarma alarm_bala;     /// objeto  alarma para manejar los tiempos de dibujo de sprite de la bala
    Nave *nave= new Nave();
    bool salir=false;
    int vid_nave=3;
    int op,t=0;
    while(!salir)
    {
        op=menu.draw(buffer);  /// dibuja el menu y nos retorna por ahora 1 o 2
        if (op==1)
        {
            while(!key[KEY_ESC]&&!key[KEY_ENTER])
            {
            level();
            gameover=false;
            while(!key[KEY_ESC] && !gameover)    /// gamelopp
            {
                fondo->draw(buffer); ///  se dibuja el fondo
                nave->draw(buffer) ;   ///  se dibuja la nave
                nave->update();
                menu.vidas(buffer,vid_nave);/// se muestran nuestas vidas

                   if (nave->getvida()<=0)       /// si la vida de nuestra nave <= 0
                            {
                                //if(t==2)
                               // {
                                nave->setvida(100);
                                vid_nave--;
                                 //t=0;
                                 //}         ///tenemos tres vidas  en total si llega 0 se acaba el juego
                               // else {t++;}
                            }
                            if (vid_nave<1)
                            {
                                delete nave;        /// si nuestra nave se queda sin vida se elimina la nave
                                while(!key[KEY_ENTER])       ///bucle para que nos dibuje la pantalla de game over
                                {
                                    menu.gameover(buffer);
                                    draw();
                                }
                                gameover =true;
                            }

                for(itenemy = enemy.begin(); itenemy != enemy.end(); itenemy++)  ///iterador de la lista para dibujar enemigos
                {
                    (*itenemy)->update(buffer);   /// cada enemigo de la lista  "itenemy"    llama a su metodo update

                    if ((rand()%1000)>998)  ///condicion para que solo se cree balas enemigas si  el (rand) es mayor a 997
                    {
                        bala_enemy.push_back(new Bala((*itenemy)->getx()+21,(*itenemy)->gety()+50,2)); /// se crean las balas enemigas
                    }
                    for (itbalaEne=bala_enemy.begin(); itbalaEne!= bala_enemy.end(); itbalaEne++)  ///iterador para recorrer todas las balas creadas
                    {
                        (*itbalaEne)->mov(buffer);  ///se dibujan las balas enemigas
                        if ((*itbalaEne)->gety()>SCREEN_H || (*itbalaEne)->getx() >= nave->getx() && (*itbalaEne)->getx() <= nave->getx()+50 &&   ///condicion para que  baje de vida si la bala enemiga coliciona con nuetra nave
                                (*itbalaEne)->gety() >= nave->gety() &&(*itbalaEne)->gety() <= nave->gety()+50 )
                        {
                            delete (*itbalaEne);
                            bala_enemy.erase(itbalaEne);
                            nave->setvida((nave->getvida()-10)); ///con cada colicion de la bala enemiga con nuestra nave la vida disminuye
                        }
                    }

                }

                if (key[KEY_SPACE]&& alarm_bala.timer(10))   ///condicion para manejar el timepo de  creacion  de las  balas
                {

                    balas.push_back(new Bala(nave->getx()+20,nave->gety(),1));  /// se crea una lista de balas
                }

                for(itbala = balas.begin(); itbala != balas.end(); itbala++)   /// se dibujan las balas
                {
                    (*itbala)->mov(buffer); ///cada bala de la lista "itbala" llama a  su metodo mov

                    if (!((*itbala)->gety()>0))   ///  si la bala sale de pantalla
                    {
                        delete (*itbala);
                        balas.remove(*itbala);  /// se elimina la bala

                    }
                }
                for(itenemy = enemy.begin(); itenemy != enemy.end(); itenemy++)     /// volvemos a llamar al iterador de enemigos para detectar coliciones
                {
                    for(itbala = balas.begin(); itbala != balas.end(); itbala++)
                    {
                        if((*itbala)->getx() >= (*itenemy)->getx() && (*itbala)->getx() <= (*itenemy)->getx()+30 &&  ///condicion para que cuando la bala toque los enemigos  desaparesca
                                (*itbala)->gety() >= (*itenemy)->gety() && (*itbala)->gety() <= (*itenemy)->gety()+30)
                        {
                            delete (*itbala);
                            balas.remove(*itbala);
                            (*itenemy)->setvida((*itenemy)->getvida()-10);    /// con cada colicion de la bala la vida del enemigo disminuye

                            if ((*itenemy)->getvida()<1)   ///si la vida del enemigo es menor a 0
                            {
                                delete (*itenemy);   /// se elimina el la imagen del enemigo
                                enemy.remove(*itenemy); /// se remueve el enemigo
                                numenemigo--;
                            }
                        }
                    }

                }

                if (!numenemigo)             ///si todos los enemigos son eliminados
                {
                     for(itbala = balas.begin(); itbala != balas.end(); itbala++)
                    {
                        delete (*itbala);            /// se eliminan todas las balas de nuestra nave
                        balas.remove(*itbala);
                    }
                    nave->sety(nave->gety()-1); /// perdemos el control de la nave hasta pasar al siguiente nivel
                    nave->setx((SCREEN_W/2)-20);

                    rest(1);
                    if (nave->gety()<0)      ///cuando nuestra nave salga de pantalla
                    {
                        while(!key[KEY_SPACE])
                        {
                            menu.nivel(buffer);   /// se dibuja el fondo de siguiente nivel
                            draw();
                            gameover =true;
                        }
                        nivel++;
                        nave->setx(SCREEN_W/2.2);  /// seteamos las cordenadas de nuestra nave para el siguiente nivel
                        nave->sety(SCREEN_H/1.2);
                    }
                }
                    for (itaste= aste.begin();itaste!=aste.end();itaste++)
                    {
                        (*itaste)->update(buffer);    ///       lista para que se muestren los asteroides

                        if ((*itaste)->getx()+50 >= nave->getx() && (*itaste)->getx() <= nave->getx()+40 &&   ///condicion para que  baje de vida si el easteroide coliciona con nuetra nave
                                (*itaste)->gety()+155 >= nave->gety() &&(*itaste)->gety() <= nave->gety()+40 )
                        {
                            delete (*itaste);
                            aste.erase(itaste);       /// se elimina el asteroide
                            nave->setvida(nave->getvida()-50);
                        }
                    }




                draw();  /// se limpia el buffer en el segundo while

            } /// llave de cierre del tercer while

            }///  llave de cierre del segundo while
        }
        if(op==2)
        {
            salir=true;
        }
        draw();     /// se limpia el buffer antes de la llave del primer while
    } /// llave  de cierre del primer while
    nave->~Nave();
}



void Game::level()
{
    switch(nivel)
    {
    case 1:
        for (int i=0; i<6; i++)
        {
            int p= rand()%550;                      ///creo numeros aleatorios y las asigno a la cordenada "Y" de los enemigos
            int c=rand()%200;
            enemy.push_back(new Enemigo(p,c));   /// crea una lista de los enemigos
            numenemigo++;
        }
        break;

    case 2:
        for (int i=0; i<8; i++)
        {
            int p= rand()%550;                      ///creo numeros aleatorios y las asigno a la cordenada "Y" de los enemigos
            int c=rand()%200;
            enemy.push_back(new Enemigo(p,c));   /// crea una lista de los enemigos
            numenemigo++;
        }
         for (int j=0; j<3; j++)
         {
             int n= 80+rand()%90;                      ///creo numeros aleatorios y las asigno a la cordenada "Y" de los enemigos
             aste.push_back(new Asteroide(n*j,(j*200)*-1));
         }

        break;

    }
}



void Game::start()       /// metodo  que inicia  la libreria allegro
{
    int depth, res;
    allegro_init();
    depth = desktop_color_depth();
    if (depth == 0)
        depth = 32;
    set_color_depth(depth);
    res = set_gfx_mode(GFX_AUTODETECT_WINDOWED, 600, 600, 0, 0);
    if (res != 0)
    {
        allegro_message(allegro_error);
        exit(-1);
    }

    install_timer();
    install_keyboard();
    install_mouse();

}

void Game::shutdown()          /// metodo para cerrar allegro
{
    clear_keybuf();
    set_gfx_mode(GFX_TEXT,0,0,0,0);
    allegro_exit();
}
