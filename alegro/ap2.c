#include <stdio.h>
#include <stdlib.h>
#include <allegro5/allegro5.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_primitives.h>

void must_init(bool test, const char *description)
{
    if(test) return;

    printf("couldn't initialize %s\n", description);
    exit(1);
}

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

    must_init(al_init_primitives_addon(), "primitives");

    al_register_event_source(queue, al_get_keyboard_event_source());
    al_register_event_source(queue, al_get_display_event_source(disp));
    al_register_event_source(queue, al_get_timer_event_source(timer));

    bool done = false;
    bool redraw = true;
    ALLEGRO_EVENT event;

    float x, y;
    x = 100;
    y = 100;


    #define KEY_SEEN     1 //0000 0001
    #define KEY_DOWN     2 //0000 0010

    unsigned char key[ALLEGRO_KEY_MAX];//arr de todas las posibles keys
    memset(key, 0, sizeof(key));//Setea el arr en 0


    al_start_timer(timer);
    while(1)
    {
        al_wait_for_event(queue, &event);

        switch(event.type)
        {
            case ALLEGRO_EVENT_TIMER:
                if(key[ALLEGRO_KEY_UP])//Va a haber un cambio si se mantiene la tecla apretada, mov continuo, es TRUE si ~KEY_DOWN or ~KEY_SEEN
                    y--;
                if(key[ALLEGRO_KEY_DOWN])
                    y++;
                if(key[ALLEGRO_KEY_LEFT])
                    x--;
                if(key[ALLEGRO_KEY_RIGHT])
                    x++;

                if(key[ALLEGRO_KEY_ESCAPE])
                    done = true;

                for(int i = 0; i < ALLEGRO_KEY_MAX; i++)
                    key[i] &= ~KEY_SEEN;//Borro el bit KEY_SEEN, el primer bit, mantengo el resto igual

                redraw = true;
                break;
/* When a key is first pressed down (ALLEGRO_EVENT_KEY_DOWN, se detecta cuando el usuario baja la tecla sin necesidad de soltarla)
, two of the bits are set to 1 in the key's corresponding entry in our key array:
00000000 // unpressed
00000011 // pressed
*/
            case ALLEGRO_EVENT_KEY_DOWN://sucede le evento de precionar una tecla-> guardo la info en la tecla correspondiente en el arr
                key[event.keyboard.keycode] = KEY_SEEN| KEY_DOWN;//prendo los dos prmeros bits
                break;
/*When the key is released, an ALLEGRO_EVENT_KEY_UP event is fired.
 The KEY_DOWN bit is then cleared to 0:
 00000001 // released, but not yet handled by game logic
 00000010 // logic has run, key is still pressed
00000000 // logic has run, key is no longer pressed
 */
            case ALLEGRO_EVENT_KEY_UP:
                key[event.keyboard.keycode] &= ~KEY_DOWN;//Borre el bit KEY_DOWN
                break;

            case ALLEGRO_EVENT_DISPLAY_CLOSE:
                done = true;
                break;
        }

        if(done)
            break;

        if(redraw && al_is_event_queue_empty(queue))
        {
            al_clear_to_color(al_map_rgb(0, 0, 0));
            al_draw_textf(font, al_map_rgb(255, 255, 255), 0, 0, 0, "X: %.1f Y: %.1f", x, y);
            al_draw_filled_rectangle(x, y, x + 10, y + 10, al_map_rgb(255, 0, 0));

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