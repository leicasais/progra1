#include <stdio.h>
#include <stdlib.h>
#include <allegro5/allegro5.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>


enum BOUNCER_TYPE {//Define all of the things we are animating
    BT_HELLO = 0,//Le asigna numeros a cda variable enumerandolas en orden crecinete a partir del 0
    BT_MYSHA,
    BT_TRIANGLE,
    BT_RECTANGLE_1,
    BT_CIRCLE,
    BT_LINE1,
    BT_LINE2,
    BT_N//num final 
};

typedef struct BOUNCER
{
    float x, y;//posicion final en el frame
    float dx, dy;//Velociad/desplasamiento por frame. number of pixels they'll move every frame.
    int type;//thing a la q le corresponden los dtos
} BOUNCER;

void def_BOUNCER(BOUNCER *mat);
void must_init(bool test, const char *description);
void actualizar_pos(BOUNCER *mat);
void actualizacion(BOUNCER *mat, ALLEGRO_FONT* font, ALLEGRO_BITMAP* mysha);

int main()
{
    must_init(al_init(), "allegro");
    must_init(al_install_keyboard(), "keyboard");

    ALLEGRO_TIMER* timer = al_create_timer(1.0 / 30.0);
    must_init(timer, "timer");

    ALLEGRO_EVENT_QUEUE* queue = al_create_event_queue();
    must_init(queue, "queue");

    al_set_new_display_option(ALLEGRO_SAMPLE_BUFFERS, 1, ALLEGRO_SUGGEST);
    al_set_new_display_option(ALLEGRO_SAMPLES, 8, ALLEGRO_SUGGEST);
    al_set_new_bitmap_flags(ALLEGRO_MIN_LINEAR | ALLEGRO_MAG_LINEAR);

    ALLEGRO_DISPLAY* disp = al_create_display(640, 480);
    must_init(disp, "display");

    ALLEGRO_FONT* font = al_create_builtin_font();
    must_init(font, "font");

    must_init(al_init_image_addon(), "image addon");
    ALLEGRO_BITMAP* mysha = al_load_bitmap("mysha.png");
    must_init(mysha, "mysha");

    must_init(al_init_primitives_addon(), "primitives");

    al_register_event_source(queue, al_get_keyboard_event_source());
    al_register_event_source(queue, al_get_display_event_source(disp));
    al_register_event_source(queue, al_get_timer_event_source(timer));

    bool done = false;
    bool redraw = true;
    ALLEGRO_EVENT event;

    BOUNCER obj[BT_N];//lista con todos los bouncers del programa
    BOUNCER obj2[BT_N];
    def_BOUNCER(obj);
    def_BOUNCER(obj2);

    al_start_timer(timer);
    while(1)//empieza la GAME LOGIC
    {
        al_wait_for_event(queue, &event);

        switch(event.type)
        {
            case ALLEGRO_EVENT_TIMER:
                actualizar_pos(obj);
                actualizar_pos(obj2);
                redraw = true;
                break;

            case ALLEGRO_EVENT_KEY_DOWN:
            case ALLEGRO_EVENT_DISPLAY_CLOSE:
                done = true;
                break;
        }

        if(done)
            break;

        if(redraw && al_is_event_queue_empty(queue))//Updating the render code
        {
            al_clear_to_color(al_map_rgb(0, 0, 0));//borra el frame anterior
            actualizacion(obj,font,mysha);
            actualizacion(obj2,font,mysha);
            al_flip_display();
            redraw = false;
        }
    }

    al_destroy_bitmap(mysha);
    al_destroy_font(font);
    al_destroy_display(disp);
    al_destroy_timer(timer);
    al_destroy_event_queue(queue);

    return 0;
}

//Funciones

void must_init(bool test, const char *description)
{
    if(test) return;

    printf("couldn't initialize %s\n", description);
    exit(1);
}

void def_BOUNCER(BOUNCER *mat){//Le asigno numeros random a la posicion y velocidad de cada elemento de la flia pasada como argumento de fun (mat)
    for(int i = 0; i < BT_N; i++)//le asigno los argumentos a cda bouncer
    {
        BOUNCER* b = &mat[i];
        //rand(), da un num entero aleatorio entre 0 y RAND_MAX (una constante grande, por ejemplo 32767).
        b->x = rand() % 640;//random position on the screen. % 640 limita ese número a un valor entre 0 y 639 (el resto nunca puede ser => divisor).
        b->y = rand() % 480;
        b->dx = ((((float)rand()) / RAND_MAX) - 0.5) * 2 * 6;//random velocidad entre -6 y +6
        b->dy = ((((float)rand()) / RAND_MAX) - 0.5) * 2 * 4;//random velocidad entre -4 y +4
        b->type = i;
    }
}

void actualizar_pos(BOUNCER *mat){
    for(int i = 0; i < BT_N; i++)
    {
        BOUNCER* b = &mat[i];//change their x and y coordinates by adding each dimension's respective velocity (dx, dy) to them.
        b->x += b->dx;
        b->y += b->dy;

        //consider what happens if each object is about to go off screen
        if(b->x < 0)
        {
            b->x  *= -1;//make sure that the object isn't out-of-bounds any more by putting it back within-bounds by the amount it came out - so if x == -2, it becomes x == 2.
            b->dx *= -1;//it's bumped into the left or right, we invert dx so that it immediately starts travelling in the other direction
        }
        if(b->x > 640)
        {
            b->x = 2*640 - b->x;
            b->dx *= -1;
        }
        if(b->y < 0)
        {
            b->y  *= -1;
            b->dy *= -1;
        }
        if(b->y > 480)
        {
            b->y = 2*480 - b->y;
            b->dy *= -1;
        }
    }
}
void actualizacion(BOUNCER *mat, ALLEGRO_FONT* font, ALLEGRO_BITMAP* mysha){
    for(int i = 0; i < BT_N; i++)//the inclusion of b->x and b->y. As these values get updated on every frame (as we saw earlier), the text appears to mov
                {
                    BOUNCER* b = &mat[i];
                    switch(b->type)
                    {
                        case BT_HELLO:
                            al_draw_text(font, al_map_rgb(255, 255, 255), b->x, b->y, 0, "Hello world!");
                            break;

                        case BT_MYSHA:
                            al_draw_bitmap(mysha, b->x, b->y, 0);
                            break;

                        case BT_TRIANGLE:
                            al_draw_filled_triangle(b->x, b->y, b->x + 50, b->y + 25, b->x, b->y + 50, al_map_rgb_f(0, 1, 0));
                            break;

                        case BT_RECTANGLE_1:
                            al_draw_filled_rectangle(b->x, b->y, b->x + 100, b->y + 80, al_map_rgba_f(0, 0, 0.5, 0.5));
                            break;

                        case BT_CIRCLE:
                            al_draw_circle(b->x, b->y, 30, al_map_rgb_f(1, 0, 1), 2);
                            break;

                        case BT_LINE1:
                            al_draw_line(b->x, b->y, b->x + 20, b->y + 100, al_map_rgb_f(1, 0, 0), 1);
                            break;

                        case BT_LINE2:
                            al_draw_line(b->x, b->y, b->x + 70, b->y - 20, al_map_rgb_f(1, 1, 0), 1);
                            break;
                    }
                }
}