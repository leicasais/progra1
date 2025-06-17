#include <stdio.h>
#include <stdlib.h>
#include <allegro5/allegro5.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>//Primtives-> graphics programming, simple lines, shapes and points are referred to as primitives.

void must_init(bool test, const char *description)//to make our initialization phase a bit less unruly with a slick check that each step executes successfully. If it doesn't, the failure is printed to the terminal and the program exits immediately 
{
    if(test) return;//Sale de la funcion y no pasa nda

    printf("couldn't initialize %s\n", description);
    exit(1);//termina la ejecucion del programa
}

int main()
{
    must_init(al_init(), "allegro");
    must_init(al_install_keyboard(), "keyboard");
    must_init(al_init_image_addon(), "image addon");//bitmap=img
    must_init(al_init_primitives_addon(), "primitives");

    ALLEGRO_TIMER* timer = al_create_timer(1.0 / 30.0);
    must_init(timer, "timer");

    ALLEGRO_EVENT_QUEUE* queue = al_create_event_queue();
    must_init(queue, "queue");

    //Smooth the edges, Usás las funciones antes de crear el display o cargar bitmaps, para que esos objetos se creen con esas configuraciones:
    al_set_new_display_option(ALLEGRO_SAMPLE_BUFFERS, 1, ALLEGRO_SUGGEST);//“Quiero usar antialiasing por multisampling, si es posible”.ALLEGRO_SAMPLE_BUFFERS → activa el uso de buffers de muestreo múltiple (para suavizar bordes).1 → pedís 1 buffer de multisample (esencialmente: activás el multisampling).ALLEGRO_SUGGEST → lo pedís si está disponible, pero no es obligatorio (si el sistema no lo soporta, no da error).
    al_set_new_display_option(ALLEGRO_SAMPLES, 8, ALLEGRO_SUGGEST);//ALLEGRO_SAMPLES → cuántas muestras por píxel querés en el multisampling (más = más suave, pero más costoso).8 → muy buena calidad (4 es común, 8 es excelente).
    al_set_new_bitmap_flags(ALLEGRO_MIN_LINEAR | ALLEGRO_MAG_LINEAR);//ALLEGRO_MIN_LINEAR → usa interpolación lineal al achicar la imagen (en lugar de hacerlo "a los saltos").ALLEGRO_MAG_LINEAR → usa interpolación lineal al agrandar la imagen.

    ALLEGRO_DISPLAY* disp = al_create_display(640, 480);
    must_init(disp, "display");

    ALLEGRO_FONT* font = al_create_builtin_font();
    must_init(font, "font");

    ALLEGRO_BITMAP* mysha = al_load_bitmap("mysha.png");
    must_init(mysha, "mysha");

    al_register_event_source(queue, al_get_keyboard_event_source());
    al_register_event_source(queue, al_get_display_event_source(disp));
    al_register_event_source(queue, al_get_timer_event_source(timer));

    bool done = false;
    bool redraw = true;
    ALLEGRO_EVENT event;

    al_start_timer(timer);
    while(1)
    {
        al_wait_for_event(queue, &event);

        switch(event.type)
        {
            case ALLEGRO_EVENT_TIMER:
                // game logic goes here.
                redraw = true;
                break;

            case ALLEGRO_EVENT_KEY_DOWN:
            case ALLEGRO_EVENT_DISPLAY_CLOSE:
                done = true;
                break;
        }

        if(done)
            break;

        if(redraw && al_is_event_queue_empty(queue))
        {
            al_clear_to_color(al_map_rgb(0, 0, 0));
            al_draw_text(font, al_map_rgb(255, 255, 255), 0, 0, 0, "Hello world!");

            al_draw_bitmap(mysha, 200, 200, 0);

            al_draw_filled_triangle(35, 350, 85, 375, 35, 400, al_map_rgb_f(0, 1, 0));
            /*al_draw_filled_triangle(
                x1, y1,   // vértice 1
                x2, y2,   // vértice 2
                x3, y3,   // vértice 3
                color     // color del triángulo
            );*/
            al_draw_filled_rectangle(120, 160, 340, 340, al_map_rgba_f(0, 0, 0.5, 0.5));
            //al_draw_filled_rectangle(x1, y1, x2, y2, color), vetice superior izq, vertice inf derecho
            al_draw_circle(450, 370, 30, al_map_rgb_f(1, 0, 1), 2);
            /*al_draw_circle(
                float cx, float cy,     // centro del círculo (x, y)
                float radius,           // radio
                ALLEGRO_COLOR color,    // color del borde
                float thickness          // grosor de la línea
            );*/
            al_draw_line(440, 110, 460, 210, al_map_rgb_f(1, 0, 0), 1);
            al_draw_line(500, 220, 570, 200, al_map_rgb_f(1, 1, 0), 1);
            /*al_draw_line(
                float x1, float y1,   // punto inicial
                float x2, float y2,   // punto final
                ALLEGRO_COLOR color,  // color de la línea
                float thickness       // grosor
            );*/
            ALLEGRO_VERTEX v[] = {
                { .x = 210, .y = 320, .z = 8, .color = al_map_rgb_f(1, 0, 0) },
                { .x = 330, .y = 320, .z = 0, .color = al_map_rgb_f(0, 1, 0) },
                { .x = 210, .y = 420, .z = 0, .color = al_map_rgb_f(0, 0, 1) },
                { .x = 330, .y = 420, .z = 0, .color = al_map_rgb_f(1, 1, 0) },
            };
            al_draw_prim(v, NULL, NULL, 0, 4, ALLEGRO_PRIM_LINE_STRIP);//other option ALLEGRO_PRIM_TRIANGLE_STRIP

            al_flip_display();

            redraw = false;
        }
    }

    al_destroy_font(font);
    al_destroy_display(disp);
    al_destroy_timer(timer);
    al_destroy_event_queue(queue);
    al_destroy_bitmap(mysha);

    return 0;
}