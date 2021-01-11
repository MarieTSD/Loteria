#include <iostream>
#include <allegro.h>
#include <stdlib.h>
#include <conio.h>
#include <stdio.h>
#include <unistd.h>
#include <fstream>


//Prototipos
void menu(char []);
void instrucciones(char []);
void presentacion(char []);
int salir(bool salida);
int juego(char nickname[]);
void llenar(int m[4][3], int ren, int col);
void carta(int vec[25]);
int cruz(int m1[4][3],int m2[4][3],int x2[4][3],int y2[4][3],int vec[25],char nickname[]);
int esquinas(int m1[4][3],int m2[4][3],int x2[4][3],int y2[4][3],int vec[25],char nickname[]);
int todo(int m1[4][3],int m2[4][3],int x2[4][3],int y2[4][3],int vec[25],char nickname[]);
int clic(int numero, int xn, int yn);
void clic2(int numero2, int xh, int yh);
int tipo(char nickname[]);
void ganar3();
void lose();
void score(char [],int pts);

//-------------------GIF---------------------
volatile int exit_program;
void fecha_programa() { exit_program = TRUE; }
END_OF_FUNCTION(fecha_programa)

volatile int ticks;
void tick_counter() { ticks++; }
END_OF_FUNCTION(tick_counter)

volatile int milisegundos;
void msec_counter() { milisegundos++; }
END_OF_FUNCTION(msec_counter)
//-------------------FIG---------------------

using namespace std;

int main()
{
    allegro_init();
    install_keyboard();
    install_mouse();
    install_timer();
    install_sound(DIGI_AUTODETECT, MIDI_AUTODETECT, 0);
     SAMPLE *btn = load_wav("ding.wav");


    system("color F0");

    //---------------------------Alex
     if(set_gfx_mode(GFX_SAFE, 800, 600, 0,0)!=0){
        set_gfx_mode(GFX_TEXT,0,0,0,0);
        allegro_message("Incapaz de entrar a modo grafico\n%s\n",allegro_error);
        }
    BITMAP *buffer=create_bitmap(800,600);
    set_window_title("............BIENVENIDO............");

      char nom[30];
        char c;
        int i=0, x=360, y=300;
        textout(screen, font,"Ingresa tu nickname: ", 340, 275, makecol(255,0,0));
        while(c!=KEY_ENTER){
            c= readkey() >>8;
            switch(c){

                case KEY_A: textout(screen,font,"A", x,y, makecol(0,255,255));fflush(stdin);nom[i]='A';fflush(stdin);cout<<"2"<<endl;break;
                case KEY_B: textout(screen,font,"B", x,y, makecol(0,255,255));fflush(stdin);nom[i]='B';break;
                case KEY_C: textout(screen,font,"C", x,y, makecol(0,255,255));fflush(stdin);nom[i]='C';break;
                case KEY_D: textout(screen,font,"D", x,y, makecol(0,255,255));fflush(stdin);nom[i]='D';break;
                case KEY_E: textout(screen,font,"E", x,y, makecol(0,255,255));fflush(stdin);nom[i]='E';break;
                case KEY_F: textout(screen,font,"F", x,y, makecol(0,255,255));fflush(stdin);nom[i]='F';break;
                case KEY_G: textout(screen,font,"G", x,y, makecol(0,255,255));fflush(stdin);nom[i]='G';break;
                case KEY_H: textout(screen,font,"H", x,y, makecol(0,255,255));fflush(stdin);nom[i]='H';break;
                case KEY_I: textout(screen,font,"I", x,y, makecol(0,255,255));fflush(stdin);nom[i]='I';break;
                case KEY_J: textout(screen,font,"J", x,y, makecol(0,255,255));fflush(stdin);nom[i]='J';break;
                case KEY_K: textout(screen,font,"K", x,y, makecol(0,255,255));fflush(stdin);nom[i]='K';break;
                case KEY_L: textout(screen,font,"L", x,y, makecol(0,255,255));fflush(stdin);nom[i]='L';break;
                case KEY_M: textout(screen,font,"M", x,y, makecol(0,255,255));fflush(stdin);nom[i]='M';break;
                case KEY_N: textout(screen,font,"N", x,y, makecol(0,255,255));fflush(stdin);nom[i]='N';break;
                case KEY_O: textout(screen,font,"O", x,y, makecol(0,255,255));fflush(stdin);nom[i]='O';break;
                case KEY_P: textout(screen,font,"P", x,y, makecol(0,255,255));fflush(stdin);nom[i]='P';break;
                case KEY_Q: textout(screen,font,"Q", x,y, makecol(0,255,255));fflush(stdin);nom[i]='Q';break;
                case KEY_R: textout(screen,font,"R", x,y, makecol(0,255,255));fflush(stdin);nom[i]='R';break;
                case KEY_S: textout(screen,font,"S", x,y, makecol(0,255,255));fflush(stdin);nom[i]='S';break;
                case KEY_T: textout(screen,font,"T", x,y, makecol(0,255,255));fflush(stdin);nom[i]='T';break;
                case KEY_U: textout(screen,font,"U", x,y, makecol(0,255,255));fflush(stdin);nom[i]='U';break;
                case KEY_V: textout(screen,font,"V", x,y, makecol(0,255,255));fflush(stdin);nom[i]='V';break;
                case KEY_W: textout(screen,font,"W", x,y, makecol(0,255,255));fflush(stdin);nom[i]='W';break;
                case KEY_X: textout(screen,font,"X", x,y, makecol(0,255,255));fflush(stdin);nom[i]='X';break;
                case KEY_Y: textout(screen,font,"Y", x,y, makecol(0,255,255));fflush(stdin);nom[i]='Y';break;
                case KEY_Z: textout(screen,font,"Z", x,y, makecol(0,255,255));fflush(stdin);nom[i]='Z';break;
                case KEY_ENTER:textout(screen,font,".", x,y, makecol(0,255,255));nom[i]='.';
                play_sample(btn,200,150,1000,0);
                presentacion(nom);break;
                case KEY_SPACE:textout(screen,font,"_", x,y, makecol(0,255,255));fflush(stdin);nom[i]='_';break;
                case KEY_ESC:textout(screen,font,"_", x,y, makecol(0,255,255));fflush(stdin);nom[i]='_';break;
                case KEY_0: textout(screen,font,"0", x,y, makecol(0,255,255));fflush(stdin);nom[i]='0';break;
                case KEY_1: textout(screen,font,"1", x,y, makecol(0,255,255));fflush(stdin);nom[i]='1';break;
                case KEY_2: textout(screen,font,"2", x,y, makecol(0,255,255));fflush(stdin);nom[i]='2';break;
                case KEY_3: textout(screen,font,"3", x,y, makecol(0,255,255));fflush(stdin);nom[i]='3';break;
                case KEY_4: textout(screen,font,"4", x,y, makecol(0,255,255));fflush(stdin);nom[i]='4';break;
                case KEY_5: textout(screen,font,"5", x,y, makecol(0,255,255));fflush(stdin);nom[i]='5';break;
                case KEY_6: textout(screen,font,"6", x,y, makecol(0,255,255));fflush(stdin);nom[i]='6';break;
                case KEY_7: textout(screen,font,"7", x,y, makecol(0,255,255));fflush(stdin);nom[i]='7';break;
                case KEY_8: textout(screen,font,"8", x,y, makecol(0,255,255));fflush(stdin);nom[i]='8';break;
                case KEY_9: textout(screen,font,"9", x,y, makecol(0,255,255));fflush(stdin);nom[i]='9';break;
            }
            i++;
            x=x+8;
        }
    allegro_exit();
    readkey();

    return 0;
}END_OF_MAIN()

void lose(){ //internet
  set_color_depth(32);
  set_gfx_mode(GFX_AUTODETECT_WINDOWED, 800, 600, 0, 0);
  set_window_title("Perdiste !!");

  exit_program = FALSE;
  LOCK_FUNCTION(fecha_programa);
  LOCK_VARIABLE(exit_program);
  set_close_button_callback(fecha_programa);

  ticks = 0;
  LOCK_FUNCTION(tick_counter);
  LOCK_VARIABLE(ticks);
  install_int_ex(tick_counter, BPS_TO_TIMER(60));

  milisegundos = 0;
  LOCK_FUNCTION(msec_counter);
  LOCK_VARIABLE(milisegundos);
  install_int_ex(msec_counter, MSEC_TO_TIMER(1));


  ///BITMAPS
  BITMAP* buffer = create_bitmap(SCREEN_W, SCREEN_H);

  BITMAP* link_esq[4];
  link_esq[0] = load_bitmap("lose.bmp", NULL);
  link_esq[1] = load_bitmap("wo1.bmp", NULL);
  link_esq[2] = load_bitmap("wo2.bmp", NULL);
  link_esq[3] = load_bitmap("wo3.bmp", NULL);


SAMPLE *btn = load_wav("perder.wav");
    play_sample(btn,200,150,1000,0);
  //BITMAP* link_dir = load_bitmap("link_dir.bmp", NULL);

  ///Variáveis
  int num_frames = 4;
  //int frame_w = link_dir->w / num_frames;
  int frame_atual;
  int tempo_troca = 250;

  ///GAME LOOP
  while(!key[KEY_SPACE])
  {
     while(ticks > 0 && !exit_program)
     {
      //INPUT
      if(key[KEY_SPACE])
       fecha_programa();

      //UPDATE
      frame_atual = (milisegundos / tempo_troca) % num_frames;

      //DRAW
      draw_sprite(buffer, link_esq[frame_atual], 0, 0);
      //masked_blit(link_dir, buffer, frame_atual * frame_w, 0, 400, 300, frame_w, link_dir->h);

      draw_sprite(screen, buffer, 0, 0);
      clear_to_color(buffer, makecol(255,255,255));

     ticks--;
     }
  }

  ///FINAL
  destroy_bitmap(buffer);
//  destroy_bitmap(link_dir);
  destroy_bitmap(link_esq[0]);
  destroy_bitmap(link_esq[1]);
  destroy_bitmap(link_esq[2]);
  destroy_bitmap(link_esq[3]);
  destroy_sample(btn);

}

void ganar3(){ //internet
  set_color_depth(32);
  set_gfx_mode(GFX_AUTODETECT_WINDOWED, 800, 600, 0, 0);
  set_window_title("Ganaste !!");

  exit_program = FALSE;
  LOCK_FUNCTION(fecha_programa);
  LOCK_VARIABLE(exit_program);
  set_close_button_callback(fecha_programa);

  ticks = 0;
  LOCK_FUNCTION(tick_counter);
  LOCK_VARIABLE(ticks);
  install_int_ex(tick_counter, BPS_TO_TIMER(60));

  milisegundos = 0;
  LOCK_FUNCTION(msec_counter);
  LOCK_VARIABLE(milisegundos);
  install_int_ex(msec_counter, MSEC_TO_TIMER(1));


  ///BITMAPS
  BITMAP* buffer = create_bitmap(SCREEN_W, SCREEN_H);

  BITMAP* link_esq[8];
  link_esq[0] = load_bitmap("win.bmp", NULL);
  link_esq[1] = load_bitmap("win2.bmp", NULL);
  link_esq[2] = load_bitmap("win3.bmp", NULL);
  link_esq[3] = load_bitmap("win4.bmp", NULL);
  link_esq[4] = load_bitmap("win5.bmp", NULL);
  link_esq[5] = load_bitmap("win6.bmp", NULL);
  link_esq[6] = load_bitmap("win7.bmp", NULL);
  link_esq[7] = load_bitmap("win8.bmp", NULL);
  link_esq[8] = load_bitmap("win9.bmp", NULL);

SAMPLE *btn = load_wav("ganar.wav");
    play_sample(btn,200,150,1000,0);
  //BITMAP* link_dir = load_bitmap("link_dir.bmp", NULL);

  ///Variáveis
  int num_frames = 8;
  //int frame_w = link_dir->w / num_frames;
  int frame_atual;
  int tempo_troca = 200;

  ///GAME LOOP
  while(!key[KEY_SPACE])
  {
     while(ticks > 0 && !exit_program)
     {
      //INPUT
      if(key[KEY_SPACE])
       fecha_programa();

      //UPDATE
      frame_atual = (milisegundos / tempo_troca) % num_frames;

      //DRAW
      draw_sprite(buffer, link_esq[frame_atual], 0, 0);
      //masked_blit(link_dir, buffer, frame_atual * frame_w, 0, 400, 300, frame_w, link_dir->h);

      draw_sprite(screen, buffer, 0, 0);
      clear_to_color(buffer, makecol(255,255,255));

     ticks--;
     }
  }

  ///FINAL
  destroy_bitmap(buffer);
//  destroy_bitmap(link_dir);
  destroy_bitmap(link_esq[0]);
  destroy_bitmap(link_esq[1]);
  destroy_bitmap(link_esq[2]);
  destroy_bitmap(link_esq[3]);
  destroy_sample(btn);

}

void presentacion(char nickname[]){

    int sali;
    set_window_title("PORTADA");  //para el nombre de la ventana
    set_gfx_mode(GFX_AUTODETECT_WINDOWED, 800, 600, 0, 0);  //creas el tamano de la ventana
    BITMAP *buffer=create_bitmap(800,600);
    BITMAP *logo = load_bitmap("log2.bmp", NULL);
    BITMAP *logo2 = load_bitmap("log3.bmp", NULL);
    BITMAP *cursor = load_bitmap("cursor.bmp", NULL);

    SAMPLE *btn = load_wav("ding.wav");

    bool salida=TRUE;

    while(salida){
        if(mouse_x>694 && mouse_x<793  &&
            mouse_y>517 && mouse_y<591){
                blit(logo2,buffer, 0,0, 0,0, 800,600);
                //play_sample(btn,200,150,1000,0);
                if (mouse_b & 1){
                    play_sample(btn,200,150,1000,0);
                    menu(nickname);
                    break;
                }
        }else
            blit(logo,buffer, 0,0, 0,0, 800,600);

        //rectfill(buffer, 2, 2, ancho-4, alto-4, 0xDF1680);
	   //rectfill(buffer, 30, 30, ancho-30, alto-30, 0x000000);
       textout_centre_ex(buffer, font, "INTEGRANTES", 800/2, 300, 0xAEB404, 0xFFFFFF);
       textout_centre_ex(buffer, font, "Jose Ramon Robledo Aguilar", 800/2, 350, 0x000000, 0xFFFFFF);
       textout_centre_ex(buffer, font, "Carlos Alejandro Gonzales Campos", 800/2, 380, 0x000000, 0xFFFFFF);
       textout_centre_ex(buffer, font, "Mariela Teresa Serna Davila", 800/2, 410, 0x000000, 0xFFFFFF);
       textout_centre_ex(buffer, font, "-- L O T E R I A --", 800/2, 460, 0xAEB404, 0xFFFFFF);

        masked_blit(cursor,buffer,0,0,mouse_x,mouse_y,13,22);
        blit(buffer,screen, 0,0, 0,0, 800,600);

    }

}


void menu(char nickname[]){//menu
    set_window_title("Menu de Loteria");
    set_gfx_mode(GFX_AUTODETECT_WINDOWED, 800, 600, 0, 0);
    int ju;

    BITMAP *buffer=create_bitmap(800,600);
    BITMAP *lot = load_bitmap("lot.bmp", NULL);
    BITMAP *menu2 = load_bitmap("menu2.bmp", NULL);
    BITMAP *menu3 = load_bitmap("menu3.bmp", NULL);
    BITMAP *menu4 = load_bitmap("menu4.bmp", NULL);
    BITMAP *menu5 = load_bitmap("menu5.bmp", NULL);
    BITMAP *cursor = load_bitmap("cursor.bmp", NULL);
    BITMAP *instrcut = load_bitmap("instruct.bmp", NULL);
    BITMAP *record = load_bitmap("records.bmp", NULL);

    //MIDI *fondo = load_midi("Mariachi Loco - Mariachi Mexicano.mid");
    //play_midi(fondo, 1); // el 1: para que se repita la cancion, 0: no se repite
    SAMPLE *maria = load_wav("mariachi.wav");
    play_sample(maria,200,150,1000,0);

    SAMPLE *btn = load_wav("ding.wav");
    //play_sample(btn,200,150,1000,0);

    set_volume(230, 200);//no se por que

    //SAMPLE *click = load_midi("Mariachi Loco - Mariachi Mexicano.mid"); //click
BITMAP *cargando = load_bitmap("cargando.bmp",0);
BITMAP *cargando1 = load_bitmap("cargando1.bmp",0);
BITMAP *cargando2 = load_bitmap("cargando2.bmp",0);
BITMAP *cargando3=load_bitmap("cargando3.bmp",0);
int i;

    blit (lot, screen, 0, 0 ,0, 0, 800, 600);

    bool salida=TRUE;

    while(salida){
        if(mouse_x > 148 && mouse_x < 648 &&
           mouse_y > 120 && mouse_y < 188){
            blit (menu2, buffer, 0, 0 ,0, 0, 800, 600);
            if (mouse_b & 1){
                play_sample(btn,200,150,1000,0);
                destroy_sample(maria);
                allegro_exit();
                allegro_init();
                 install_keyboard();
                 install_mouse();
                install_timer();
                show_mouse(screen);
                set_gfx_mode(GFX_AUTODETECT_WINDOWED,900,700,0,0);
                for(i=0; i<13; i++){
                    blit(cargando,screen,0,0,0,0,900,700);
                    rest(200);
                    blit(cargando1,screen,0,0,0,0,900,700);
                    rest(200);
                    blit(cargando2,screen,0,0,0,0,900,700);
                    rest(200);
                    blit(cargando3,screen,0,0,0,0,900,700);
                    rest(200);
                }
                destroy_bitmap(cargando);
                destroy_bitmap(cargando1);
                destroy_bitmap(cargando2);
                destroy_bitmap(cargando3);
                ju=juego(nickname);
                if(ju==1){
                  lose();
                }else if(ju>1){
                   ganar3();
                }
            }
        }else if(mouse_x>250 && mouse_x<544  &&
                 mouse_y>213 && mouse_y<280){
            blit(menu3,buffer,0,0, 0,0, 800,600);
                if (mouse_b & 1){
                    blit (record, screen, 0, 0 ,0, 0, 800, 600);
                    destroy_sample(maria);
                    play_sample(btn,200,150,1000,0);
                    score(nickname,ju);
                }
        }
        else if(mouse_x>145 && mouse_x<645  &&
                mouse_y>310 && mouse_y<377){
            blit(menu4,buffer,0,0, 0,0, 800,600);
                if (mouse_b & 1){
                    blit (instrcut, screen, 0, 0 ,0, 0, 800, 600);
                    destroy_sample(maria);
                    play_sample(btn,200,150,1000,0);
                    instrucciones(nickname);
                }
        }
        else if(mouse_x>310 && mouse_x<483  &&
                mouse_y>409 && mouse_y<478){
            blit(menu5,buffer,0,0, 0,0, 800,600);
            if(mouse_b&1)
                play_sample(btn,200,150,1000,0);
                salida=salir(salida);
              //  salida=false;
        }
        else
            blit(lot,buffer, 0,0, 0,0, 800,600);

        masked_blit(cursor,buffer,0,0,mouse_x,mouse_y,13,22);
        blit(buffer,screen, 0,0, 0,0, 800,600);

    }
        // destroy_bitmap(buffer);
}
int salir(bool salida){
    if(mouse_b==1)
        salida=false;
    return salida;
}
void score(char nickname[],int pts){

    BITMAP *buffer=create_bitmap(800,600);
    BITMAP *fondo1=load_bitmap("fondo1.bmp", NULL);
    BITMAP *fondo2=load_bitmap("fondo3.bmp", NULL);
    BITMAP *cursor=load_bitmap("cursor. bmp", NULL);
    int a=198,b=123;
    SAMPLE *btn = load_wav("ding.wav");

    bool salida=false;

    fstream file;
    file.open("points.txt", ios::out|ios::app);
    file<<nickname<<" "<<pts<<endl;
    file.close();

   file.open("points.txt", ios::in);
    file.clear();
    file.seekg(0);
    //int set_window_close_button(int enable);
    while(!salida){
        if(mouse_x<792 && mouse_x>677 && mouse_y>554 && mouse_y<588){
            blit(fondo2,buffer,0,0,0,0,800,600);
            if(mouse_b & 1){
                play_sample(btn,200,150,1000,0);
                menu(nickname);
                break;
                //salida=true;
            }
        }else
        blit(fondo1, buffer,0,0,0,0,800,600);

    while(file>>nickname>>pts){
        textprintf_ex(fondo1,font, a, b,0xff0000,-1,"%9s ---> %3d", nickname, pts);
        b=b+15;
        cout<<endl<<5;
    }

    show_mouse(buffer);
    blit(buffer,screen,0,0,0,0,800,600);

   }
   file.close();
   destroy_bitmap(buffer);
}

void instrucciones(char nickname[]){
    set_window_title("INSTRUCCIONES");
    install_mouse();

    BITMAP *buffer=create_bitmap(800,600);
    BITMAP *instrcut = load_bitmap("instruct.bmp", NULL);
    BITMAP *instruct2 = load_bitmap("instruct2.bmp", NULL);
    BITMAP *cursor = load_bitmap("cursor.bmp", NULL);
    SAMPLE *btn = load_wav("ding.wav");

    blit (instrcut, screen, 0, 0 ,0, 0, 800, 600);

    bool salida=true;

    while(salida){
        if(mouse_x>675 && mouse_x<797  &&
                mouse_y>553 && mouse_y<597){
            blit(instruct2,buffer,0,0, 0,0, 800,600);
                if (mouse_b & 1){
                        play_sample(btn,200,150,1000,0);
                        menu(nickname);
                        return;
                }
        }
        else
            blit(instrcut,buffer, 0,0, 0,0, 800,600);

        masked_blit(cursor,buffer,0,0,mouse_x,mouse_y,13,22);
        blit(buffer,screen, 0,0, 0,0, 800,600);
    }
}

int juego(char nickname[]){
   int m1[4][3];
 int m2[4][3];
  int ren=4;
  int col=3;
  llenar(m1,ren,col);
  llenar(m2,ren,col);
  //Para la pantalla
  int vec[25];
   carta(vec);
 //   allegro_init();
  install_keyboard();
  install_mouse();
  install_timer();
  show_mouse(screen);
 // set_gfx_mode(GFX_AUTODETECT_WINDOWED,900,700,0,0);
  set_color_depth(24);
//void set_window_close_hook(void (*proc)());
//set_mouse_speed(,); //PARA LA VELOCIDAD DEL RATON
    //PARA EL TIPO DE JUEGO
  int tip;
  tip = tipo(nickname);
  if(tip==0){
    return 0;
  }
  BITMAP *portada = load_bitmap("Portadanueva2.bmp", NULL);
  BITMAP *a = load_bitmap("Arbol1.bmp", 0);
  BITMAP *b= load_bitmap("Bailarin1.bmp",0);
  BITMAP *c=load_bitmap("Bandera1.bmp",0);
  BITMAP *d=load_bitmap("Bandolon1.bmp",0);
  BITMAP *e=load_bitmap("Bota1.bmp",0);
  BITMAP *f=load_bitmap("Botella1.bmp",0);
  BITMAP *g=load_bitmap("Camaron1.bmp",0);
  BITMAP *h=load_bitmap("Campana1.bmp",0);
  BITMAP *i=load_bitmap("Cazo1.bmp",0);
  BITMAP *j=load_bitmap("Corona1.bmp",0);
  BITMAP *k=load_bitmap("Cotorro1.bmp",0);
  BITMAP *l=load_bitmap("Dama1.bmp",0);
  BITMAP *m=load_bitmap("Garza1.bmp",0);
  BITMAP *n=load_bitmap("Jaras1.bmp",0);
  BITMAP *o=load_bitmap("Luna1.bmp",0);
  BITMAP *p=load_bitmap("Melon1.bmp",0);
  BITMAP *q=load_bitmap("Musico1.bmp",0);
  BITMAP *r=load_bitmap("Pera1.bmp",0);
  BITMAP *s=load_bitmap("Rana1.bmp",0);
  BITMAP *t=load_bitmap("Rosa1.bmp",0);
  BITMAP *u=load_bitmap("Sirena1.bmp",0);
  BITMAP *v=load_bitmap("Sol1.bmp",0);
  BITMAP *w=load_bitmap("Tambor1.bmp",0);
  BITMAP *y=load_bitmap("Valiente1.bmp",0);
  BITMAP *z=load_bitmap("Venado1.bmp",0);

  int x1[4][3]={{50,150,250},{50,150,250}, {50,150,250} , {50,150,250} };
  int y1[4][3]={{88,88,88},{238,238,238}, {388,388,388},{538,538,538}};
   int x2[4][3]={ {400,500,600},{400,500,600},{400,500,600},{400,500,600}};
   int y2[4][3]={{88,88,88},{238,238,238}, {388,388,388},{538,538,538}};

  blit(portada,screen,0,0,0,0,900,700);
  int i1, j1,num;
  //Para el jugador
  for(i1=0; i1<ren; i1++){
    for(j1=0; j1<col; j1++){
            num=m1[i1][j1];
        switch(num){
         case 0: blit(a ,screen, 0,0,x1[i1][j1] ,y1[i1][j1] , 100,150); break;
         case 1: blit(b,screen, 0,0,x1[i1][j1] ,y1[i1][j1] , 100,150); break;
         case 2: blit(c ,screen, 0,0,x1[i1][j1] ,y1[i1][j1] , 100,150); break;
         case 3: blit(d ,screen, 0,0,x1[i1][j1] ,y1[i1][j1] , 100,150); break;
         case 4: blit( e,screen, 0,0,x1[i1][j1] ,y1[i1][j1] , 100,150); break;
         case 5: blit( f,screen, 0,0,x1[i1][j1] ,y1[i1][j1] , 100,150); break;
         case 6: blit(g ,screen, 0,0,x1[i1][j1] ,y1[i1][j1] , 100,150); break;
         case 7: blit(h ,screen, 0,0,x1[i1][j1] ,y1[i1][j1] , 100,150); break;
         case 8: blit(i ,screen, 0,0,x1[i1][j1] ,y1[i1][j1] , 100,150); break;
         case 9: blit(j ,screen, 0,0,x1[i1][j1] ,y1[i1][j1] , 100,150); break;
         case 10: blit(k ,screen, 0,0,x1[i1][j1] ,y1[i1][j1] , 100,150); break;
         case 11: blit(l ,screen, 0,0,x1[i1][j1] ,y1[i1][j1] , 100,150); break;
         case 12: blit(m ,screen, 0,0,x1[i1][j1] ,y1[i1][j1] , 100,150); break;
         case 13: blit(n ,screen, 0,0,x1[i1][j1] ,y1[i1][j1] , 100,150); break;
         case 14: blit(o ,screen, 0,0,x1[i1][j1] ,y1[i1][j1] , 100,150); break;
         case 15: blit(p ,screen, 0,0,x1[i1][j1] ,y1[i1][j1] , 100,150); break;
         case 16: blit(q ,screen, 0,0,x1[i1][j1] ,y1[i1][j1] , 100,150);break;
         case 17: blit(r ,screen, 0,0,x1[i1][j1] ,y1[i1][j1] , 100,150); break;
         case 18: blit(s ,screen, 0,0,x1[i1][j1] ,y1[i1][j1] , 100,150); break;
         case 19: blit(t ,screen, 0,0,x1[i1][j1] ,y1[i1][j1] , 100,150); break;
         case 20: blit(u ,screen, 0,0,x1[i1][j1] ,y1[i1][j1] , 100,150); break;
         case 21: blit(v ,screen, 0,0,x1[i1][j1] ,y1[i1][j1] , 100,150); break;
         case 22: blit(w ,screen, 0,0,x1[i1][j1] ,y1[i1][j1] , 100,150); break;
         case 23: blit(y ,screen, 0,0,x1[i1][j1] ,y1[i1][j1] , 100,150); break;
         case 24: blit(z ,screen, 0,0,x1[i1][j1] ,y1[i1][j1] , 100,150); break;
        }
    }
  }

 // Para LA COMPU
 for(i1=0; i1<ren; i1++){
    for(j1=0; j1<col; j1++){
            num=m2[i1][j1];
        switch(num){
         case 0: blit(a ,screen, 0,0,x2[i1][j1] ,y2[i1][j1] , 100,150); break;
         case 1: blit(b,screen, 0,0,x2[i1][j1] ,y2[i1][j1] , 100,150); break;
         case 2: blit(c ,screen, 0,0,x2[i1][j1] ,y2[i1][j1] , 100,150); break;
         case 3: blit(d ,screen, 0,0,x2[i1][j1] ,y2[i1][j1] , 100,150); break;
         case 4: blit( e,screen, 0,0,x2[i1][j1] ,y2[i1][j1] , 100,150); break;
         case 5: blit( f,screen, 0,0,x2[i1][j1] ,y2[i1][j1] , 100,150); break;
         case 6: blit(g ,screen, 0,0,x2[i1][j1] ,y2[i1][j1] , 100,150); break;
         case 7: blit(h ,screen, 0,0,x2[i1][j1] ,y2[i1][j1] , 100,150); break;
         case 8: blit(i ,screen, 0,0,x2[i1][j1] ,y2[i1][j1] , 100,150); break;
         case 9: blit(j ,screen, 0,0,x2[i1][j1] ,y2[i1][j1] , 100,150); break;
         case 10: blit(k ,screen, 0,0,x2[i1][j1] ,y2[i1][j1] , 100,150); break;
         case 11: blit(l ,screen, 0,0,x2[i1][j1] ,y2[i1][j1] , 100,150); break;
         case 12: blit(m ,screen, 0,0,x2[i1][j1] ,y2[i1][j1] , 100,150); break;
         case 13: blit(n ,screen, 0,0,x2[i1][j1] ,y2[i1][j1] , 100,150); break;
         case 14: blit(o ,screen, 0,0,x2[i1][j1] ,y2[i1][j1] , 100,150); break;
         case 15: blit(p ,screen, 0,0,x2[i1][j1] ,y2[i1][j1] , 100,150); break;
         case 16: blit(q ,screen, 0,0,x2[i1][j1] ,y2[i1][j1] , 100,150);break;
         case 17: blit(r ,screen, 0,0,x2[i1][j1] ,y2[i1][j1] , 100,150); break;
         case 18: blit(s ,screen, 0,0,x2[i1][j1] ,y2[i1][j1] , 100,150); break;
         case 19: blit(t ,screen, 0,0,x2[i1][j1] ,y2[i1][j1] , 100,150); break;
         case 20: blit(u ,screen, 0,0,x2[i1][j1] ,y2[i1][j1] , 100,150); break;
         case 21: blit(v ,screen, 0,0,x2[i1][j1] ,y2[i1][j1] , 100,150); break;
         case 22: blit(w ,screen, 0,0,x2[i1][j1] ,y2[i1][j1] , 100,150); break;
         case 23: blit(y ,screen, 0,0,x2[i1][j1] ,y2[i1][j1] , 100,150); break;
         case 24: blit(z ,screen, 0,0,x2[i1][j1] ,y2[i1][j1] , 100,150); break;
        }
      }
     }

// PARA LOS TIPOS DE JUEGOS
    int resultado;
   switch(tip){
    case 1: resultado= esquinas(m1,m2,x2,y2,vec,nickname); break;
    case 2: resultado= cruz(m1,m2,x2,y2,vec,nickname);break;
    case 3: resultado= todo(m1,m2,x2,y2,vec,nickname); break;
   }
   destroy_bitmap(portada);
   destroy_bitmap(a);
   destroy_bitmap(b);
   destroy_bitmap(c);
   destroy_bitmap(d);
   destroy_bitmap(e);
   destroy_bitmap(f);
   destroy_bitmap(g);
   destroy_bitmap(h);
   destroy_bitmap(i);
   destroy_bitmap(j);
   destroy_bitmap(k);
   destroy_bitmap(l);
   destroy_bitmap(m);
   destroy_bitmap(n);
   destroy_bitmap(o);
   destroy_bitmap(p);
   destroy_bitmap(q);
   destroy_bitmap(r);
   destroy_bitmap(s);
   destroy_bitmap(t);
   destroy_bitmap(u);
   destroy_bitmap(v);
   destroy_bitmap(w);
   destroy_bitmap(y);
   destroy_bitmap(z);
return resultado;


}

int tipo(char nickname[]){
  install_mouse();
  install_timer();
  BITMAP *t = load_bitmap("tipo.bmp",0);
  BITMAP *tipo1= load_bitmap("tipo1.bmp",0);
  BITMAP *tipo2=load_bitmap("tipo2.bmp",0);
  BITMAP *tipo3=load_bitmap("tipo3.bmp",0);
  BITMAP *tipo4=load_bitmap("tipo4.bmp",0);
  show_mouse(screen);
  blit(t,screen,0,0,0,0,900,700);
  bool salida;
  salida=false;
  while(!salida){
    if(mouse_x>34 && mouse_x<263 && mouse_y>207 && mouse_y<574){
        blit(tipo1,screen,0,0,0,0,900,700);
        if(mouse_b & 1){
            return 1;
        }
    } else if(mouse_x>337 && mouse_x<563 && mouse_y>207 && mouse_y<574){
           blit(tipo2,screen,0,0,0,0,900,700);
           if(mouse_b & 1){
            return 2;
           }
    } else if(mouse_x>637 && mouse_x<863 && mouse_y>207 && mouse_y<574){
           blit(tipo3,screen,0,0,0,0,900,700);
           if(mouse_b & 1){
            return 3;
           }
    } else if(mouse_x>761 && mouse_x<890 && mouse_y>649 && mouse_y<687){
         blit(tipo4,screen,0,0,0,0,900,700);
         if(mouse_b & 1){
            menu(nickname);
         }
    } else blit(t, screen,0,0,0,0,900,700);
  }
  destroy_bitmap(t);
  destroy_bitmap(tipo1);
  destroy_bitmap(tipo2);
  destroy_bitmap(tipo3);
  destroy_bitmap(tipo4);
  return 0;
}

void llenar(int m[4][3], int r, int c){
  int vec[r*c];
  int z,ban,i,j,num;
  z=r*c;
  for (i=0; i<z; i++){
    	ban=0;
        srand(time(NULL));
		num= 0 + rand () % (24-0+1);
        for(j=0; j<i; j++){
        	if(vec[j]==num){
        		ban=1;
        		break;
        	}
        }
        if(ban==0){
          vec[i]=num;
        }
        else{
        	i--;
        }
    }
    int a, b;
    z=0;
    for(a=0; a<r; a++){
        for(b=0; b<c; b++){
            m[a][b]=vec[z++];
        }
    }
}

void carta(int vec[25]){
     int zz,ban,i2,j2,numero;

  zz=25;
  for (i2=0; i2<zz; i2++){
    	ban=0;
    	srand(time(NULL));
		numero= 0 + rand () % (24-0+1);
        for(j2=0; j2<i2; j2++){
        	if(vec[j2]==numero){
        		ban=1;
        		break;
        	}
        }
        if(ban==0){
          vec[i2]=numero;

        }
        else{
        	i2--;
         }
      }
}

int cruz(int m1[4][3],int m2[4][3],int x2[4][3],int y2[4][3],int vec[25],char nickname[]){
 install_keyboard();
 install_timer();
  install_mouse();
  install_sound(DIGI_AUTODETECT, MIDI_AUTODETECT, 0);
  SAMPLE *arbols = load_wav("ARBOL.wav");
  SAMPLE *bailarins = load_wav("BAILARIN.wav");
  SAMPLE *banderas = load_wav("BANDERA.wav");
  SAMPLE *bandolons = load_wav("BANDOLON.wav");
  SAMPLE *botas = load_wav("BOTA.wav");
  SAMPLE *botellas = load_wav("BOTELLA.wav");
  SAMPLE *camarons = load_wav("CAMARON.wav");
  SAMPLE *campanas = load_wav("CAMPANA.wav");
  SAMPLE *cazos = load_wav("CAZO.wav");
  SAMPLE *coronas = load_wav("CORONA.wav");
  SAMPLE *cotorros = load_wav("COTORRO.wav");
  SAMPLE *damas = load_wav("DAMA.wav");
  SAMPLE *garzas = load_wav("GARZA.wav");
  SAMPLE *jarass = load_wav("JARAS.wav");
  SAMPLE *lunas = load_wav("LUNA.wav");
  SAMPLE *melons = load_wav("MELON.wav");
  SAMPLE *musicos = load_wav("MUSICO.wav");
  SAMPLE *peras = load_wav("PERA.wav");
  SAMPLE *ranas = load_wav("RANA.wav");
  SAMPLE *rosas = load_wav("ROSA.wav");
  SAMPLE *sirenas = load_wav("SIRENA.wav");
  SAMPLE *sols = load_wav("SOL.wav");
  SAMPLE *tambors = load_wav("TAMBOR.wav");
  SAMPLE *valientes = load_wav("VALIENTE.wav");
  SAMPLE *venados = load_wav("VENADO.wav");
  set_volume(230, 200);
  int aa,conteo,conteo2,acum, xh,yh,l,h,numero2;
  acum=0;
  conteo=0;
  conteo2=0;
  aa=0;
  BITMAP *arbol= load_bitmap("Arbol.bmp", 0);
  BITMAP *bailarin= load_bitmap("Bailarin.bmp",0);
  BITMAP *bandera=load_bitmap("Bandera.bmp",0);
  BITMAP *bandolon=load_bitmap("Bandolon.bmp",0);
  BITMAP *bota=load_bitmap("Bota.bmp",0);
  BITMAP *botella=load_bitmap("Botella.bmp",0);
  BITMAP *camaron=load_bitmap("Camaron.bmp",0);
  BITMAP *campana=load_bitmap("Campana.bmp",0);
  BITMAP *cazo=load_bitmap("Cazo.bmp",0);
  BITMAP *corona=load_bitmap("Corona.bmp",0);
  BITMAP *cotorro=load_bitmap("Cotorro.bmp",0);
  BITMAP *dama=load_bitmap("Dama.bmp",0);
  BITMAP *garza=load_bitmap("Garza.bmp",0);
  BITMAP *jaras=load_bitmap("Jaras.bmp",0);
  BITMAP *luna=load_bitmap("Luna.bmp",0);
  BITMAP *melon=load_bitmap("Melon.bmp",0);
  BITMAP *musico=load_bitmap("Musico.bmp",0);
  BITMAP *pera=load_bitmap("Pera.bmp",0);
  BITMAP *rana=load_bitmap("Rana.bmp",0);
  BITMAP *rosa=load_bitmap("Rosa.bmp",0);
  BITMAP *sirena=load_bitmap("Sirena.bmp",0);
  BITMAP *sol=load_bitmap("Sol.bmp",0);
  BITMAP *tambor=load_bitmap("Tambor.bmp",0);
  BITMAP *valiente=load_bitmap("Valiente.bmp",0);
  BITMAP *venado=load_bitmap("Venado.bmp",0);
BITMAP *rojo=load_bitmap("salirrojo.bmp",0);
BITMAP *negro=load_bitmap("salirneg.bmp",0);

    do{
        //Para mostrar la carta
        switch(vec[aa]){
         case 0: blit(arbol,screen,0,0,736,242,150,235); play_sample(arbols,200,150,1000,0); break;
         case 1: blit(bailarin,screen,0,0,736,242,150,235); play_sample(bailarins,200,150,1000,0); break;
         case 2: blit(bandera,screen,0,0,736,242,150,235); play_sample(banderas,200,150,1000,0);break;
         case 3: blit(bandolon,screen,0,0,736,242,150,235); play_sample(bandolons,200,150,1000,0); break;
         case 4: blit(bota,screen,0,0,736,242,150,235); play_sample(botas,200,150,1000,0); break;
         case 5: blit(botella,screen,0,0,736,242,150,235); play_sample(botellas,200,150,1000,0); break;
         case 6: blit(camaron,screen,0,0,736,242,150,235); play_sample(camarons,200,150,1000,0); break;
         case 7: blit(campana,screen,0,0,736,242,150,235); play_sample(campanas,200,150,1000,0);break;
         case 8: blit(cazo,screen,0,0,736,242,150,235); play_sample(cazos,200,150,1000,0);break;
         case 9:  blit(corona,screen,0,0,736,242,150,235); play_sample(coronas,200,150,1000,0);break;
         case 10: blit(cotorro,screen,0,0,736,242,150,235); play_sample(cotorros,200,150,1000,0);break;
         case 11: blit(dama,screen,0,0,736,242,150,235);  play_sample(damas,200,150,1000,0); break;
         case 12: blit(garza,screen,0,0,736,242,150,235); play_sample(garzas,200,150,1000,0);break;
         case 13: blit(jaras,screen,0,0,736,242,150,235); play_sample(jarass,200,150,1000,0);break;
         case 14: blit(luna,screen,0,0,736,242,150,235); play_sample(lunas,200,150,1000,0);break;
         case 15: blit(melon,screen,0,0,736,242,150,235); play_sample(melons,200,150,1000,0);break;
         case 16: blit(musico,screen,0,0,736,242,150,235); play_sample(musicos,200,150,1000,0);break;
         case 17: blit(pera,screen,0,0,736,242,150,235); play_sample(peras,200,150,1000,0);break;
         case 18: blit(rana,screen,0,0,736,242,150,235); play_sample(ranas,200,150,1000,0);break;
         case 19: blit(rosa,screen,0,0,736,242,150,235); play_sample(rosas,200,150,1000,0);break;
         case 20: blit(sirena,screen,0,0,736,242,150,235); play_sample(sirenas,200,150,1000,0);break;
         case 21: blit(sol,screen,0,0,736,242,150,235); play_sample(sols,200,150,1000,0);break;
         case 22: blit(tambor,screen,0,0,736,242,150,235); play_sample(tambors,200,150,1000,0);break;
         case 23: blit(valiente,screen,0,0,736,242,150,235); play_sample(valientes,200,150,1000,0);break;
         case 24: blit(venado,screen,0,0,736,242,150,235); play_sample(venados,200,150,1000,0);break;
        }
     int numero,res,xn,yn;
     rest(5000);
        if(mouse_x >50 && mouse_x < 150 && mouse_y > 88 && mouse_y <238){
            if(vec[aa]==m1[0][0]){
               numero=vec[aa];
                xn=50; yn=88;
                res=clic(numero,xn,yn);
                acum+=res;
              }
        } else if(mouse_x >150 && mouse_x < 250 && mouse_y > 88 && mouse_y<238){
              if(vec[aa] == m1[0][1]){
                   numero=vec[aa];
                   xn=150; yn=88;
                   res=clic(numero,xn,yn);
                   res+=200;
                   acum+=res; conteo++;
                }
        }else if(mouse_x>250 && mouse_x<350 && mouse_y >88 && mouse_y<238){
               if(vec[aa] == m1[0][2]){
                   numero=vec[aa];
                   xn=250; yn=88;
                   res=clic(numero,xn,yn);
                   acum+=res;
                 }
        }else if(mouse_x>50 && mouse_x<150 && mouse_y>238 && mouse_y<388){
                if(vec[aa] == m1[1][0]){
                   numero=vec[aa];
                   xn=50; yn=238;
                   res=clic(numero,xn,yn);
                   res+=200;
                   acum+=res; conteo++;
                  }
        }else if(mouse_x>150 && mouse_x<250 && mouse_y>238 && mouse_y<388){
                if(vec[aa] ==m1[1][1]){
                   numero=vec[aa];
                   xn=150; yn=238;
                   res=clic(numero,xn,yn);
                   res+=200;
                   acum+=res; conteo++;
                 }
        }else if(mouse_x>250 && mouse_x<350 && mouse_y>238 && mouse_y<388){
               if(vec[aa] ==m1[1][2]){
                   numero=vec[aa];
                   xn=250; yn=238;
                   res=clic(numero,xn,yn);
                   res+=200;
                   acum+=res; conteo++;
                 }
        }else if(mouse_x>50 && mouse_x<150 && mouse_y > 388 && mouse_y<538){
               if(vec[aa] ==m1[2][0]){
                   numero=vec[aa];
                   xn=50; yn=388;
                   res=clic(numero,xn,yn);
                   acum+=res;
                 }
        }else if(mouse_x>150 && mouse_x<250 && mouse_y>388 && mouse_y<538){
               if(vec[aa] ==m1[2][1]){
                   numero=vec[aa];
                   xn=150; yn=388;
                   res=clic(numero,xn,yn);
                   res+=200;
                   acum+=res; conteo++;
                 }
        }else if(mouse_x>250 && mouse_x<350 && mouse_y>388 && mouse_y<538){
                if(vec[aa] == m1[2][2]){
                   numero=vec[aa];
                   xn=250; yn=388;
                   res=clic(numero,xn,yn);
                   acum+=res;
                 }
        }else if(mouse_x>50 && mouse_x<150 && mouse_y>538 && mouse_y<688){
                if(vec[aa] == m1[3][0]){
                   numero=vec[aa];
                   xn=50; yn=538;
                   res=clic(numero,xn,yn);
                   acum+=res;
                 }
        }else if(mouse_x>150 && mouse_x<250 && mouse_y>538 && mouse_y<688){
                if(vec[aa] == m1[3][1]){
                   numero=vec[aa];
                   xn=150; yn=538;
                   res=clic(numero,xn,yn);
                   res+=200;
                   acum+=res; conteo++;
                 }
        }else if(mouse_x>250 && mouse_x<350 && mouse_y>538 && mouse_y<688){
               if(vec[aa] == m1[3][2]){
                   numero=vec[aa];
                   xn=250; yn=538;
                   res=clic(numero,xn,yn);
                   acum+=res;
                 }
        }else if(mouse_x>755 && mouse_x<880 && mouse_y>626 && mouse_y<674){
                blit(rojo,screen,0,0,755,626,129,56);
                menu(nickname);
                break;
                //MANDAR LLAMAR LA FUNCION MENU
        }     else  blit(negro,screen,0,0,755,626,134,51);
     // masked_blit(cursor,screen,0,0,mouse_x,mouse_y,13,22);

        for(l=0; l<4; l++){
        for(h=0; h<3; h++){
            if(vec[aa]==m2[l][h]){
                xh=x2[l][h];
                yh=y2[l][h];
                numero2=vec[aa];
                clic2(numero2,xh,yh);
                if((vec[aa]==m2[0][1])||(vec[aa]==m2[1][0])||(vec[aa]==m2[1][1])||
                   (vec[aa]==m2[1][2])||(vec[aa]==m2[2][1])||(vec[aa]==m2[3][1])){
                    conteo2++;
                }
            }
        }
      }
     rest(2000);
     aa++;
  }while(aa<25 && conteo<6 && conteo2<6);
  destroy_sample(arbols);
destroy_sample(bailarins);
destroy_sample(banderas);
destroy_sample(bandolons);
destroy_sample(botas);
destroy_sample(botellas);
destroy_sample(camarons);
destroy_sample(campanas);
destroy_sample(cazos);
destroy_sample(coronas);
destroy_sample(cotorros);
destroy_sample(damas);
destroy_sample(garzas);
destroy_sample(jarass);
destroy_sample(lunas);
destroy_sample(melons);
destroy_sample(musicos);
destroy_sample(peras);
destroy_sample(ranas);
destroy_sample(rosas);
destroy_sample(sirenas);
destroy_sample(sols);
destroy_sample(tambors);
destroy_sample(valientes);
destroy_sample(venados);
  destroy_bitmap(arbol);
destroy_bitmap(bailarin);
destroy_bitmap(bandera);
destroy_bitmap(bandolon);
destroy_bitmap(bota);
destroy_bitmap(botella);
destroy_bitmap(camaron);
destroy_bitmap(campana);
destroy_bitmap(cazo);
destroy_bitmap(corona);
destroy_bitmap(cotorro);
destroy_bitmap(dama);
destroy_bitmap(garza);
destroy_bitmap(jaras);
destroy_bitmap(luna);
destroy_bitmap(melon);
destroy_bitmap(musico);
destroy_bitmap(pera);
destroy_bitmap(rana);
destroy_bitmap(rosa);
destroy_bitmap(sirena);
destroy_bitmap(sol);
destroy_bitmap(tambor);
destroy_bitmap(valiente);
destroy_bitmap(venado);
destroy_bitmap(rojo);
destroy_bitmap(negro);
  if(conteo==6){
    return acum;
  }else if(conteo2==6){
      return 1;
  } else return 0;
}

int esquinas(int m1[4][3],int m2[4][3],int x2[4][3],int y2[4][3],int vec[25],char nickname[]){
  install_keyboard();
 install_timer();
  install_mouse();
  install_sound(DIGI_AUTODETECT, MIDI_AUTODETECT, 0);
  SAMPLE *arbols = load_wav("ARBOL.wav");
  SAMPLE *bailarins = load_wav("BAILARIN.wav");
  SAMPLE *banderas = load_wav("BANDERA.wav");
  SAMPLE *bandolons = load_wav("BANDOLON.wav");
  SAMPLE *botas = load_wav("BOTA.wav");
  SAMPLE *botellas = load_wav("BOTELLA.wav");
  SAMPLE *camarons = load_wav("CAMARON.wav");
  SAMPLE *campanas = load_wav("CAMPANA.wav");
  SAMPLE *cazos = load_wav("CAZO.wav");
  SAMPLE *coronas = load_wav("CORONA.wav");
  SAMPLE *cotorros = load_wav("COTORRO.wav");
  SAMPLE *damas = load_wav("DAMA.wav");
  SAMPLE *garzas = load_wav("GARZA.wav");
  SAMPLE *jarass = load_wav("JARAS.wav");
  SAMPLE *lunas = load_wav("LUNA.wav");
  SAMPLE *melons = load_wav("MELON.wav");
  SAMPLE *musicos = load_wav("MUSICO.wav");
  SAMPLE *peras = load_wav("PERA.wav");
  SAMPLE *ranas = load_wav("RANA.wav");
  SAMPLE *rosas = load_wav("ROSA.wav");
  SAMPLE *sirenas = load_wav("SIRENA.wav");
  SAMPLE *sols = load_wav("SOL.wav");
  SAMPLE *tambors = load_wav("TAMBOR.wav");
  SAMPLE *valientes = load_wav("VALIENTE.wav");
  SAMPLE *venados = load_wav("VENADO.wav");
  set_volume(230, 200);
  int aa,conteo,conteo2,acum, xh,yh,l,h,numero2;
  acum=0;
  conteo=0;
  conteo2=0;
  aa=0;
  BITMAP *arbol= load_bitmap("Arbol.bmp", 0);
  BITMAP *bailarin= load_bitmap("Bailarin.bmp",0);
  BITMAP *bandera=load_bitmap("Bandera.bmp",0);
  BITMAP *bandolon=load_bitmap("Bandolon.bmp",0);
  BITMAP *bota=load_bitmap("Bota.bmp",0);
  BITMAP *botella=load_bitmap("Botella.bmp",0);
  BITMAP *camaron=load_bitmap("Camaron.bmp",0);
  BITMAP *campana=load_bitmap("Campana.bmp",0);
  BITMAP *cazo=load_bitmap("Cazo.bmp",0);
  BITMAP *corona=load_bitmap("Corona.bmp",0);
  BITMAP *cotorro=load_bitmap("Cotorro.bmp",0);
  BITMAP *dama=load_bitmap("Dama.bmp",0);
  BITMAP *garza=load_bitmap("Garza.bmp",0);
  BITMAP *jaras=load_bitmap("Jaras.bmp",0);
  BITMAP *luna=load_bitmap("Luna.bmp",0);
  BITMAP *melon=load_bitmap("Melon.bmp",0);
  BITMAP *musico=load_bitmap("Musico.bmp",0);
  BITMAP *pera=load_bitmap("Pera.bmp",0);
  BITMAP *rana=load_bitmap("Rana.bmp",0);
  BITMAP *rosa=load_bitmap("Rosa.bmp",0);
  BITMAP *sirena=load_bitmap("Sirena.bmp",0);
  BITMAP *sol=load_bitmap("Sol.bmp",0);
  BITMAP *tambor=load_bitmap("Tambor.bmp",0);
  BITMAP *valiente=load_bitmap("Valiente.bmp",0);
  BITMAP *venado=load_bitmap("Venado.bmp",0);
BITMAP *rojo=load_bitmap("salirrojo.bmp",0);
BITMAP *negro=load_bitmap("salirneg.bmp",0);

    do{
        //Para mostrar la carta
        switch(vec[aa]){
         case 0: blit(arbol,screen,0,0,736,242,150,235); play_sample(arbols,200,150,1000,0); break;
         case 1: blit(bailarin,screen,0,0,736,242,150,235); play_sample(bailarins,200,150,1000,0); break;
         case 2: blit(bandera,screen,0,0,736,242,150,235); play_sample(banderas,200,150,1000,0);break;
         case 3: blit(bandolon,screen,0,0,736,242,150,235); play_sample(bandolons,200,150,1000,0); break;
         case 4: blit(bota,screen,0,0,736,242,150,235); play_sample(botas,200,150,1000,0); break;
         case 5: blit(botella,screen,0,0,736,242,150,235); play_sample(botellas,200,150,1000,0); break;
         case 6: blit(camaron,screen,0,0,736,242,150,235); play_sample(camarons,200,150,1000,0); break;
         case 7: blit(campana,screen,0,0,736,242,150,235); play_sample(campanas,200,150,1000,0);break;
         case 8: blit(cazo,screen,0,0,736,242,150,235); play_sample(cazos,200,150,1000,0);break;
         case 9:  blit(corona,screen,0,0,736,242,150,235); play_sample(coronas,200,150,1000,0);break;
         case 10: blit(cotorro,screen,0,0,736,242,150,235); play_sample(cotorros,200,150,1000,0);break;
         case 11: blit(dama,screen,0,0,736,242,150,235);  play_sample(damas,200,150,1000,0); break;
         case 12: blit(garza,screen,0,0,736,242,150,235); play_sample(garzas,200,150,1000,0);break;
         case 13: blit(jaras,screen,0,0,736,242,150,235); play_sample(jarass,200,150,1000,0);break;
         case 14: blit(luna,screen,0,0,736,242,150,235); play_sample(lunas,200,150,1000,0);break;
         case 15: blit(melon,screen,0,0,736,242,150,235); play_sample(melons,200,150,1000,0);break;
         case 16: blit(musico,screen,0,0,736,242,150,235); play_sample(musicos,200,150,1000,0);break;
         case 17: blit(pera,screen,0,0,736,242,150,235); play_sample(peras,200,150,1000,0);break;
         case 18: blit(rana,screen,0,0,736,242,150,235); play_sample(ranas,200,150,1000,0);break;
         case 19: blit(rosa,screen,0,0,736,242,150,235); play_sample(rosas,200,150,1000,0);break;
         case 20: blit(sirena,screen,0,0,736,242,150,235); play_sample(sirenas,200,150,1000,0);break;
         case 21: blit(sol,screen,0,0,736,242,150,235); play_sample(sols,200,150,1000,0);break;
         case 22: blit(tambor,screen,0,0,736,242,150,235); play_sample(tambors,200,150,1000,0);break;
         case 23: blit(valiente,screen,0,0,736,242,150,235); play_sample(valientes,200,150,1000,0);break;
         case 24: blit(venado,screen,0,0,736,242,150,235); play_sample(venados,200,150,1000,0);break;
        }
     int numero,res,xn,yn;
     rest(5000);
        if(mouse_x >50 && mouse_x < 150 && mouse_y > 88 && mouse_y <238){
            if(vec[aa]==m1[0][0]){
               numero=vec[aa];
                xn=50; yn=88;
                res=clic(numero,xn,yn);
                res+=300;
                acum+=res; conteo++;
              }
        } else if(mouse_x >150 && mouse_x < 250 && mouse_y > 88 && mouse_y<238){
              if(vec[aa] == m1[0][1]){
                   numero=vec[aa];
                   xn=150; yn=88;
                   res=clic(numero,xn,yn);
                   acum+=res;
                }
        }else if(mouse_x>250 && mouse_x<350 && mouse_y >88 && mouse_y<238){
               if(vec[aa] == m1[0][2]){
                   numero=vec[aa];
                   xn=250; yn=88;
                   res=clic(numero,xn,yn);
                   res+=300;
                   acum+=res; conteo++;
                 }
        }else if(mouse_x>50 && mouse_x<150 && mouse_y>238 && mouse_y<388){
                if(vec[aa] == m1[1][0]){
                   numero=vec[aa];
                   xn=50; yn=238;
                   res=clic(numero,xn,yn);
                   acum+=res;
                  }
        }else if(mouse_x>150 && mouse_x<250 && mouse_y>238 && mouse_y<388){
                if(vec[aa] ==m1[1][1]){
                   numero=vec[aa];
                   xn=150; yn=238;
                   res=clic(numero,xn,yn);
                   acum+=res;
                 }
        }else if(mouse_x>250 && mouse_x<350 && mouse_y>238 && mouse_y<388){
               if(vec[aa] ==m1[1][2]){
                   numero=vec[aa];
                   xn=250; yn=238;
                   res=clic(numero,xn,yn);
                   acum+=res;
                 }
        }else if(mouse_x>50 && mouse_x<150 && mouse_y > 388 && mouse_y<538){
               if(vec[aa] ==m1[2][0]){
                   numero=vec[aa];
                   xn=50; yn=388;
                   res=clic(numero,xn,yn);
                   acum+=res;
                 }
        }else if(mouse_x>150 && mouse_x<250 && mouse_y>388 && mouse_y<538){
               if(vec[aa] ==m1[2][1]){
                   numero=vec[aa];
                   xn=150; yn=388;
                   res=clic(numero,xn,yn);
                   acum+=res;
                 }
        }else if(mouse_x>250 && mouse_x<350 && mouse_y>388 && mouse_y<538){
                if(vec[aa] == m1[2][2]){
                   numero=vec[aa];
                   xn=250; yn=388;
                   res=clic(numero,xn,yn);
                   acum+=res;
                 }
        }else if(mouse_x>50 && mouse_x<150 && mouse_y>538 && mouse_y<688){
                if(vec[aa] == m1[3][0]){
                   numero=vec[aa];
                   xn=50; yn=538;
                   res=clic(numero,xn,yn);
                   res+=300;
                   acum+=res; conteo++;
                 }
        }else if(mouse_x>150 && mouse_x<250 && mouse_y>538 && mouse_y<688){
                if(vec[aa] == m1[3][1]){
                   numero=vec[aa];
                   xn=150; yn=538;
                   res=clic(numero,xn,yn);
                   acum+=res;
                 }
        }else if(mouse_x>250 && mouse_x<350 && mouse_y>538 && mouse_y<688){
               if(vec[aa] == m1[3][2]){
                   numero=vec[aa];
                   xn=250; yn=538;
                   res=clic(numero,xn,yn);
                   res+=300;
                   acum+=res; conteo++;
                 }
        }else if(mouse_x>755 && mouse_x<880 && mouse_y>626 && mouse_y<674){
                blit(rojo,screen,0,0,755,626,129,56);
                    menu(nickname);
                    break;
        }     else  blit(negro,screen,0,0,755,626,134,51);
     // masked_blit(cursor,screen,0,0,mouse_x,mouse_y,13,22);

        for(l=0; l<4; l++){
        for(h=0; h<3; h++){
            if(vec[aa]==m2[l][h]){
                xh=x2[l][h];
                yh=y2[l][h];
                numero2=vec[aa];
                clic2(numero2,xh,yh);
                if((vec[aa]==m2[0][0])||(vec[aa]==m2[0][2])||(vec[aa]==m2[3][0])||
                   (vec[aa]==m2[3][2])){
                    conteo2++;
                }
            }
        }
      }
     rest(2000);
     aa++;
  }while(aa<25 && conteo<4 && conteo2<4);
  destroy_sample(arbols);
destroy_sample(bailarins);
destroy_sample(banderas);
destroy_sample(bandolons);
destroy_sample(botas);
destroy_sample(botellas);
destroy_sample(camarons);
destroy_sample(campanas);
destroy_sample(cazos);
destroy_sample(coronas);
destroy_sample(cotorros);
destroy_sample(damas);
destroy_sample(garzas);
destroy_sample(jarass);
destroy_sample(lunas);
destroy_sample(melons);
destroy_sample(musicos);
destroy_sample(peras);
destroy_sample(ranas);
destroy_sample(rosas);
destroy_sample(sirenas);
destroy_sample(sols);
destroy_sample(tambors);
destroy_sample(valientes);
destroy_sample(venados);
  destroy_bitmap(arbol);
destroy_bitmap(bailarin);
destroy_bitmap(bandera);
destroy_bitmap(bandolon);
destroy_bitmap(bota);
destroy_bitmap(botella);
destroy_bitmap(camaron);
destroy_bitmap(campana);
destroy_bitmap(cazo);
destroy_bitmap(corona);
destroy_bitmap(cotorro);
destroy_bitmap(dama);
destroy_bitmap(garza);
destroy_bitmap(jaras);
destroy_bitmap(luna);
destroy_bitmap(melon);
destroy_bitmap(musico);
destroy_bitmap(pera);
destroy_bitmap(rana);
destroy_bitmap(rosa);
destroy_bitmap(sirena);
destroy_bitmap(sol);
destroy_bitmap(tambor);
destroy_bitmap(valiente);
destroy_bitmap(venado);
destroy_bitmap(rojo);
destroy_bitmap(negro);
  if(conteo==4){
    return acum;
  }else if(conteo2==4){
      return 1;
  } else return 0;

}

int todo(int m1[4][3],int m2[4][3],int x2[4][3],int y2[4][3],int vec[25],char nickname[]){
 install_keyboard();
 install_timer();
  install_mouse();
  install_sound(DIGI_AUTODETECT, MIDI_AUTODETECT, 0);
  SAMPLE *arbols = load_wav("ARBOL.wav");
  SAMPLE *bailarins = load_wav("BAILARIN.wav");
  SAMPLE *banderas = load_wav("BANDERA.wav");
  SAMPLE *bandolons = load_wav("BANDOLON.wav");
  SAMPLE *botas = load_wav("BOTA.wav");
  SAMPLE *botellas = load_wav("BOTELLA.wav");
  SAMPLE *camarons = load_wav("CAMARON.wav");
  SAMPLE *campanas = load_wav("CAMPANA.wav");
  SAMPLE *cazos = load_wav("CAZO.wav");
  SAMPLE *coronas = load_wav("CORONA.wav");
  SAMPLE *cotorros = load_wav("COTORRO.wav");
  SAMPLE *damas = load_wav("DAMA.wav");
  SAMPLE *garzas = load_wav("GARZA.wav");
  SAMPLE *jarass = load_wav("JARAS.wav");
  SAMPLE *lunas = load_wav("LUNA.wav");
  SAMPLE *melons = load_wav("MELON.wav");
  SAMPLE *musicos = load_wav("MUSICO.wav");
  SAMPLE *peras = load_wav("PERA.wav");
  SAMPLE *ranas = load_wav("RANA.wav");
  SAMPLE *rosas = load_wav("ROSA.wav");
  SAMPLE *sirenas = load_wav("SIRENA.wav");
  SAMPLE *sols = load_wav("SOL.wav");
  SAMPLE *tambors = load_wav("TAMBOR.wav");
  SAMPLE *valientes = load_wav("VALIENTE.wav");
  SAMPLE *venados = load_wav("VENADO.wav");
  set_volume(230, 200);
  int aa,conteo,conteo2,acum, xh,yh,l,h,numero2;
  acum=0;
  conteo=0;
  conteo2=0;
  aa=0;
  BITMAP *arbol= load_bitmap("Arbol.bmp", 0);
  BITMAP *bailarin= load_bitmap("Bailarin.bmp",0);
  BITMAP *bandera=load_bitmap("Bandera.bmp",0);
  BITMAP *bandolon=load_bitmap("Bandolon.bmp",0);
  BITMAP *bota=load_bitmap("Bota.bmp",0);
  BITMAP *botella=load_bitmap("Botella.bmp",0);
  BITMAP *camaron=load_bitmap("Camaron.bmp",0);
  BITMAP *campana=load_bitmap("Campana.bmp",0);
  BITMAP *cazo=load_bitmap("Cazo.bmp",0);
  BITMAP *corona=load_bitmap("Corona.bmp",0);
  BITMAP *cotorro=load_bitmap("Cotorro.bmp",0);
  BITMAP *dama=load_bitmap("Dama.bmp",0);
  BITMAP *garza=load_bitmap("Garza.bmp",0);
  BITMAP *jaras=load_bitmap("Jaras.bmp",0);
  BITMAP *luna=load_bitmap("Luna.bmp",0);
  BITMAP *melon=load_bitmap("Melon.bmp",0);
  BITMAP *musico=load_bitmap("Musico.bmp",0);
  BITMAP *pera=load_bitmap("Pera.bmp",0);
  BITMAP *rana=load_bitmap("Rana.bmp",0);
  BITMAP *rosa=load_bitmap("Rosa.bmp",0);
  BITMAP *sirena=load_bitmap("Sirena.bmp",0);
  BITMAP *sol=load_bitmap("Sol.bmp",0);
  BITMAP *tambor=load_bitmap("Tambor.bmp",0);
  BITMAP *valiente=load_bitmap("Valiente.bmp",0);
  BITMAP *venado=load_bitmap("Venado.bmp",0);
BITMAP *rojo=load_bitmap("salirrojo.bmp",0);
BITMAP *negro=load_bitmap("salirneg.bmp",0);

    do{
        //Para mostrar la carta
        switch(vec[aa]){
         case 0: blit(arbol,screen,0,0,736,242,150,235); play_sample(arbols,200,150,1000,0); break;
         case 1: blit(bailarin,screen,0,0,736,242,150,235); play_sample(bailarins,200,150,1000,0); break;
         case 2: blit(bandera,screen,0,0,736,242,150,235); play_sample(banderas,200,150,1000,0);break;
         case 3: blit(bandolon,screen,0,0,736,242,150,235); play_sample(bandolons,200,150,1000,0); break;
         case 4: blit(bota,screen,0,0,736,242,150,235); play_sample(botas,200,150,1000,0); break;
         case 5: blit(botella,screen,0,0,736,242,150,235); play_sample(botellas,200,150,1000,0); break;
         case 6: blit(camaron,screen,0,0,736,242,150,235); play_sample(camarons,200,150,1000,0); break;
         case 7: blit(campana,screen,0,0,736,242,150,235); play_sample(campanas,200,150,1000,0);break;
         case 8: blit(cazo,screen,0,0,736,242,150,235); play_sample(cazos,200,150,1000,0);break;
         case 9:  blit(corona,screen,0,0,736,242,150,235); play_sample(coronas,200,150,1000,0);break;
         case 10: blit(cotorro,screen,0,0,736,242,150,235); play_sample(cotorros,200,150,1000,0);break;
         case 11: blit(dama,screen,0,0,736,242,150,235);  play_sample(damas,200,150,1000,0); break;
         case 12: blit(garza,screen,0,0,736,242,150,235); play_sample(garzas,200,150,1000,0);break;
         case 13: blit(jaras,screen,0,0,736,242,150,235); play_sample(jarass,200,150,1000,0);break;
         case 14: blit(luna,screen,0,0,736,242,150,235); play_sample(lunas,200,150,1000,0);break;
         case 15: blit(melon,screen,0,0,736,242,150,235); play_sample(melons,200,150,1000,0);break;
         case 16: blit(musico,screen,0,0,736,242,150,235); play_sample(musicos,200,150,1000,0);break;
         case 17: blit(pera,screen,0,0,736,242,150,235); play_sample(peras,200,150,1000,0);break;
         case 18: blit(rana,screen,0,0,736,242,150,235); play_sample(ranas,200,150,1000,0);break;
         case 19: blit(rosa,screen,0,0,736,242,150,235); play_sample(rosas,200,150,1000,0);break;
         case 20: blit(sirena,screen,0,0,736,242,150,235); play_sample(sirenas,200,150,1000,0);break;
         case 21: blit(sol,screen,0,0,736,242,150,235); play_sample(sols,200,150,1000,0);break;
         case 22: blit(tambor,screen,0,0,736,242,150,235); play_sample(tambors,200,150,1000,0);break;
         case 23: blit(valiente,screen,0,0,736,242,150,235); play_sample(valientes,200,150,1000,0);break;
         case 24: blit(venado,screen,0,0,736,242,150,235); play_sample(venados,200,150,1000,0);break;
        }
     int numero,res,xn,yn;
            rest(5000);
        if(mouse_x >50 && mouse_x < 150 && mouse_y > 88 && mouse_y <238){
            if(vec[aa]==m1[0][0]){
               numero=vec[aa];
                xn=50; yn=88;
                res=clic(numero,xn,yn);
                res+=100;
                acum+=res; conteo++;
              }
        } else if(mouse_x >150 && mouse_x < 250 && mouse_y > 88 && mouse_y<238){
              if(vec[aa] == m1[0][1]){
                   numero=vec[aa];
                   xn=150; yn=88;
                   res=clic(numero,xn,yn);
                   res+=100;
                   acum+=res; conteo++;
                }
        }else if(mouse_x>250 && mouse_x<350 && mouse_y >88 && mouse_y<238){
               if(vec[aa] == m1[0][2]){
                   numero=vec[aa];
                   xn=250; yn=88;
                   res=clic(numero,xn,yn);
                   res+=100;
                   acum+=res; conteo++;
                 }
        }else if(mouse_x>50 && mouse_x<150 && mouse_y>238 && mouse_y<388){
                if(vec[aa] == m1[1][0]){
                   numero=vec[aa];
                   xn=50; yn=238;
                   res=clic(numero,xn,yn);
                   res+=100;
                   acum+=res; conteo++;
                  }
        }else if(mouse_x>150 && mouse_x<250 && mouse_y>238 && mouse_y<388){
                if(vec[aa] ==m1[1][1]){
                   numero=vec[aa];
                   xn=150; yn=238;
                   res=clic(numero,xn,yn);
                   res+=100;
                   acum+=res; conteo++;
                 }
        }else if(mouse_x>250 && mouse_x<350 && mouse_y>238 && mouse_y<388){
               if(vec[aa] ==m1[1][2]){
                   numero=vec[aa];
                   xn=250; yn=238;
                   res=clic(numero,xn,yn);
                   res+=100;
                   acum+=res; conteo++;
                 }
        }else if(mouse_x>50 && mouse_x<150 && mouse_y > 388 && mouse_y<538){
               if(vec[aa] ==m1[2][0]){
                   numero=vec[aa];
                   xn=50; yn=388;
                   res=clic(numero,xn,yn);
                   res+=100;
                   acum+=res; conteo++;
                 }
        }else if(mouse_x>150 && mouse_x<250 && mouse_y>388 && mouse_y<538){
               if(vec[aa] ==m1[2][1]){
                   numero=vec[aa];
                   xn=150; yn=388;
                   res=clic(numero,xn,yn);
                   res+=100;
                   acum+=res; conteo++;
                 }
        }else if(mouse_x>250 && mouse_x<350 && mouse_y>388 && mouse_y<538){
                if(vec[aa] == m1[2][2]){
                   numero=vec[aa];
                   xn=250; yn=388;
                   res=clic(numero,xn,yn);
                   res+=100;
                   acum+=res; conteo++;
                 }
        }else if(mouse_x>50 && mouse_x<150 && mouse_y>538 && mouse_y<688){
                if(vec[aa] == m1[3][0]){
                   numero=vec[aa];
                   xn=50; yn=538;
                   res=clic(numero,xn,yn);
                   res+=100;
                   acum+=res; conteo++;
                 }
        }else if(mouse_x>150 && mouse_x<250 && mouse_y>538 && mouse_y<688){
                if(vec[aa] == m1[3][1]){
                   numero=vec[aa];
                   xn=150; yn=538;
                   res=clic(numero,xn,yn);
                   res+=100;
                   acum+=res; conteo++;
                 }
        }else if(mouse_x>250 && mouse_x<350 && mouse_y>538 && mouse_y<688){
               if(vec[aa] == m1[3][2]){
                   numero=vec[aa];
                   xn=250; yn=538;
                   res=clic(numero,xn,yn);
                   res+=100;
                   acum+=res; conteo++;
                 }
        }else if(mouse_x>755 && mouse_x<880 && mouse_y>626 && mouse_y<674){
                blit(rojo,screen,0,0,755,626,129,56);
                    menu(nickname);
                    break;
        }     else  blit(negro,screen,0,0,755,626,134,51);
     // masked_blit(cursor,screen,0,0,mouse_x,mouse_y,13,22);

        for(l=0; l<4; l++){
        for(h=0; h<3; h++){
            if(vec[aa]==m2[l][h]){
                xh=x2[l][h];
                yh=y2[l][h];
                numero2=vec[aa];
                clic2(numero2,xh,yh);
                conteo2++;
            }
        }
      }
     rest(2000);
     aa++;
  }while(aa<25 && conteo<12 && conteo2<12);
  destroy_sample(arbols);
destroy_sample(bailarins);
destroy_sample(banderas);
destroy_sample(bandolons);
destroy_sample(botas);
destroy_sample(botellas);
destroy_sample(camarons);
destroy_sample(campanas);
destroy_sample(cazos);
destroy_sample(coronas);
destroy_sample(cotorros);
destroy_sample(damas);
destroy_sample(garzas);
destroy_sample(jarass);
destroy_sample(lunas);
destroy_sample(melons);
destroy_sample(musicos);
destroy_sample(peras);
destroy_sample(ranas);
destroy_sample(rosas);
destroy_sample(sirenas);
destroy_sample(sols);
destroy_sample(tambors);
destroy_sample(valientes);
destroy_sample(venados);
  destroy_bitmap(arbol);
destroy_bitmap(bailarin);
destroy_bitmap(bandera);
destroy_bitmap(bandolon);
destroy_bitmap(bota);
destroy_bitmap(botella);
destroy_bitmap(camaron);
destroy_bitmap(campana);
destroy_bitmap(cazo);
destroy_bitmap(corona);
destroy_bitmap(cotorro);
destroy_bitmap(dama);
destroy_bitmap(garza);
destroy_bitmap(jaras);
destroy_bitmap(luna);
destroy_bitmap(melon);
destroy_bitmap(musico);
destroy_bitmap(pera);
destroy_bitmap(rana);
destroy_bitmap(rosa);
destroy_bitmap(sirena);
destroy_bitmap(sol);
destroy_bitmap(tambor);
destroy_bitmap(valiente);
destroy_bitmap(venado);
destroy_bitmap(rojo);
destroy_bitmap(negro);
  if(conteo==12){
    return acum;
  }else if(conteo2==12){
    return 1;
  } else return 0;
}

int clic(int numero, int xn, int yn){

  BITMAP *a = load_bitmap("Arbol2.bmp", 0);
  BITMAP *b= load_bitmap("Bailarin2.bmp",0);
  BITMAP *c=load_bitmap("Bandera2.bmp",0);
  BITMAP *d=load_bitmap("Bandolon2.bmp",0);
  BITMAP *e=load_bitmap("Bota2.bmp",0);
  BITMAP *f=load_bitmap("Botella2.bmp",0);
  BITMAP *g=load_bitmap("Camaron2.bmp",0);
  BITMAP *h=load_bitmap("Campana2.bmp",0);
  BITMAP *i=load_bitmap("Cazo2.bmp",0);
  BITMAP *j=load_bitmap("Corona2.bmp",0);
  BITMAP *k=load_bitmap("Cotorro2.bmp",0);
  BITMAP *l=load_bitmap("Dama2.bmp",0);
  BITMAP *m=load_bitmap("Garza2.bmp",0);
  BITMAP *n=load_bitmap("Jaras2.bmp",0);
  BITMAP *o=load_bitmap("Luna2.bmp",0);
  BITMAP *p=load_bitmap("Melon2.bmp",0);
  BITMAP *q=load_bitmap("Musico2.bmp",0);
  BITMAP *r=load_bitmap("Pera2.bmp",0);
  BITMAP *s=load_bitmap("Rana2.bmp",0);
  BITMAP *t=load_bitmap("Rosa2.bmp",0);
  BITMAP *u=load_bitmap("Sirena2.bmp",0);
  BITMAP *v=load_bitmap("Sol2.bmp",0);
  BITMAP *w=load_bitmap("Tambor2.bmp",0);
  BITMAP *y=load_bitmap("Valiente2.bmp",0);
  BITMAP *z=load_bitmap("Venado2.bmp",0);
int punto;
  switch(numero){
         case 0: blit(a , screen, 0,0,xn,yn, 100,150); punto=9; break;
         case 1: blit(b, screen, 0,0,xn,yn, 100,150); punto=10; break;
         case 2: blit(c , screen, 0,0,xn,yn, 100,150); punto =12; break;
         case 3: blit(d , screen, 0,0,xn,yn, 100,150); punto=30;  break;
         case 4: blit( e, screen, 0,0,xn,yn, 100,150); punto=21; break;
         case 5: blit( f, screen, 0,0,xn,yn, 100,150); punto=33; break;
         case 6: blit(g , screen, 0,0,xn,yn, 100,150); punto=9; break;
         case 7: blit(h , screen, 0,0,xn,yn, 100,150); punto=17; break;
         case 8: blit(i , screen, 0,0,xn,yn, 100,150); punto=55; break;
         case 9: blit(j , screen, 0,0,xn,yn, 100,150); punto=14; break;
         case 10: blit(k , screen, 0,0,xn,yn, 100,150); punto=20; break;
         case 11: blit(l , screen, 0,0,xn,yn, 100,150); punto= 13; break;
         case 12: blit(m , screen, 0,0,xn,yn, 100,150); punto= 12; break;
         case 13: blit(n , screen, 0,0,xn,yn, 100,150); punto=49;break;
         case 14: blit(o , screen, 0,0,xn,yn, 100,150); punto=36;break;
         case 15: blit(p , screen, 0,0,xn,yn, 100,150); punto=28;break;
         case 16: blit(q , screen, 0,0,xn,yn, 100,150); punto=29;break;
         case 17: blit(r , screen, 0,0,xn,yn, 100,150); punto=13;break;
         case 18: blit(s , screen, 0,0,xn,yn, 100,150); punto=75;break;
         case 19: blit(t , screen, 0,0,xn,yn, 100,150); punto=13;break;
         case 20: blit(u , screen, 0,0,xn,yn, 100,150); punto=11;break;
         case 21: blit(v , screen, 0,0,xn,yn, 100,150); punto=10;break;
         case 22: blit(w , screen, 0,0,xn,yn, 100,150); punto=23;break;
         case 23: blit(y , screen, 0,0,xn,yn, 100,150); punto=12;break;
         case 24: blit(z , screen, 0,0,xn ,yn , 100,150); punto=10;break;
        }
        return punto;
}

void clic2(int numero2, int xh, int yh){
  BITMAP *a = load_bitmap("Arbol2.bmp", 0);
  BITMAP *b= load_bitmap("Bailarin2.bmp",0);
  BITMAP *c=load_bitmap("Bandera2.bmp",0);
  BITMAP *d=load_bitmap("Bandolon2.bmp",0);
  BITMAP *e=load_bitmap("Bota2.bmp",0);
  BITMAP *f=load_bitmap("Botella2.bmp",0);
  BITMAP *g=load_bitmap("Camaron2.bmp",0);
  BITMAP *h=load_bitmap("Campana2.bmp",0);
  BITMAP *i=load_bitmap("Cazo2.bmp",0);
  BITMAP *j=load_bitmap("Corona2.bmp",0);
  BITMAP *k=load_bitmap("Cotorro2.bmp",0);
  BITMAP *l=load_bitmap("Dama2.bmp",0);
  BITMAP *m=load_bitmap("Garza2.bmp",0);
  BITMAP *n=load_bitmap("Jaras2.bmp",0);
  BITMAP *o=load_bitmap("Luna2.bmp",0);
  BITMAP *p=load_bitmap("Melon2.bmp",0);
  BITMAP *q=load_bitmap("Musico2.bmp",0);
  BITMAP *r=load_bitmap("Pera2.bmp",0);
  BITMAP *s=load_bitmap("Rana2.bmp",0);
  BITMAP *t=load_bitmap("Rosa2.bmp",0);
  BITMAP *u=load_bitmap("Sirena2.bmp",0);
  BITMAP *v=load_bitmap("Sol2.bmp",0);
  BITMAP *w=load_bitmap("Tambor2.bmp",0);
  BITMAP *y=load_bitmap("Valiente2.bmp",0);
  BITMAP *z=load_bitmap("Venado2.bmp",0);

  switch(numero2){
         case 0: blit(a , screen, 0,0,xh,yh, 100,150); break;
         case 1: blit(b, screen, 0,0,xh,yh, 100,150); break;
         case 2: blit(c , screen, 0,0,xh,yh, 100,150); break;
         case 3: blit(d , screen, 0,0,xh,yh, 100,150); break;
         case 4: blit( e, screen, 0,0,xh,yh, 100,150); break;
         case 5: blit( f, screen, 0,0,xh,yh, 100,150); break;
         case 6: blit(g , screen, 0,0,xh,yh, 100,150); break;
         case 7: blit(h , screen, 0,0,xh,yh, 100,150); break;
         case 8: blit(i , screen, 0,0,xh,yh, 100,150); break;
         case 9: blit(j , screen, 0,0,xh,yh, 100,150); break;
         case 10: blit(k , screen, 0,0,xh,yh, 100,150); break;
         case 11: blit(l , screen, 0,0,xh,yh, 100,150); break;
         case 12: blit(m , screen, 0,0,xh,yh, 100,150); break;
         case 13: blit(n , screen, 0,0,xh,yh, 100,150); break;
         case 14: blit(o , screen, 0,0,xh,yh, 100,150); break;
         case 15: blit(p , screen, 0,0,xh,yh, 100,150); break;
         case 16: blit(q , screen, 0,0,xh,yh, 100,150);break;
         case 17: blit(r , screen, 0,0,xh,yh, 100,150); break;
         case 18: blit(s , screen, 0,0,xh,yh, 100,150); break;
         case 19: blit(t , screen, 0,0,xh,yh, 100,150); break;
         case 20: blit(u , screen, 0,0,xh,yh, 100,150); break;
         case 21: blit(v , screen, 0,0,xh,yh, 100,150); break;
         case 22: blit(w , screen, 0,0,xh,yh, 100,150); break;
         case 23: blit(y , screen, 0,0,xh,yh, 100,150); break;
         case 24: blit(z , screen, 0,0,xh ,yh , 100,150); break;
        }
}
