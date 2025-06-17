#include <allegro5/allegro5.h>
#include "portlib.h"
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_primitives.h>
void must_init(bool test, const char*str);
int main(void){
    must_init(al_init(), "alegro");
    must_init(al_install_keyboard(), "install keyboard");
    must_init(al_init_primitives_addon(), "primitives");
    
    ALLEGRO_TIMER* timer = al_create_timer(1.0/40.0);
    must_init(timer,"timer");
    ALLEGRO_EVENT_QUEUE* queue = al_create_event_queue();
    must_init(queue,"queue");
    ALLEGRO_DISPLAY* disp = al_create_display(1000, 1000);
    must_init(disp,"display");
    ALLEGRO_FONT* font = al_create_builtin_font();
    must_init(font, "font");
    
    puerto_t puerto;
    puerto.d =0;//inicializo todos los puertos en 0

    al_register_event_source(queue, al_get_keyboard_event_source());
    al_register_event_source(queue, al_get_display_event_source(disp));
    al_register_event_source(queue, al_get_timer_event_source(timer));

    bool done = false;
    bool redraw = true;
    ALLEGRO_EVENT event;

    while(1){
        al_wait_for_event(queue, &event);
         switch(event.type)
        {
                
            case ALLEGRO_EVENT_KEY_DOWN:
                if(event.keyboard.keycode == ALLEGRO_KEY_T)//TOGGLE
                    TOGGLE(puerto.d);
                if(event.keyboard.keycode == ALLEGRO_KEY_C)
                    puerto.d=0;
                if(event.keyboard.keycode == ALLEGRO_KEY_S)
                    puerto.d=~0;
                if(event.keyboard.keycode == ALLEGRO_KEY_Q)
                    done=true;

                if(event.keyboard.keycode == ALLEGRO_KEY_ENTER)
                    redraw=true;
                if(event.keyboard.keycode != ALLEGRO_KEY_ESCAPE)
                    break;
        

            case ALLEGRO_EVENT_DISPLAY_CLOSE:
                done = true;
                break;
        }

        if(done)
            break;

        if(redraw && al_is_event_queue_empty(queue) )
        {
            float x, y;
            x=100;
            y=100;
            al_clear_to_color(al_map_rgb(0, 0, 0));
            al_draw_textf(font, al_map_rgb(255, 255, 255), 0, 0, 0, "Leds del puerto:");
            for(int n=0;n<8;n++){
                if(!BITGET(puerto.d, n)) al_draw_circle(x, y, 30, al_map_rgb_f(1, 1, 1), 3);
                else al_draw_filled_circle(x, y, 30, al_map_rgb_f(1,1,1));
                x+=80;
            }
            
            
            al_flip_display();

            redraw = false;
        }
    }
    al_destroy_font(font);
    al_destroy_display(disp);
    al_destroy_timer(timer);
    al_destroy_event_queue(queue);
    return 0;
}

//funciones 
void must_init(bool test, const char*str){
    if (!test){
        printf("Hubo un error al inicilizar %s", str);
        exit(1);
    }
}