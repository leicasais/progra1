#include <stdio.h>
#include <allegro5/allegro5.h>//Agrego core library, tine los timers
#include <allegro5/allegro_font.h>//Agrego Addon para render(mostrar texto en pantalla o dibujar) text 
//Inicializacion del codigo. 
int main(void)
{
    typedef ALLEGRO_EVENT al_event_t;
    //INICIALIZACION

    //Permisos para allegro
    
    if(!al_init())//Inicia todo lo ncecesario para que empiece a usar Allegro
    {
        printf("couldn't initialize allegro\n");
        return 1;
    }

    if(!al_install_keyboard())//Enables keyboard input
    {
        printf("couldn't initialize keyboard\n");
        return 1;
    }


    //Inicializamos variables
    ALLEGRO_TIMER* timer = al_create_timer(1.0/10);//30 FPS (frames por seg, cambia en 1 seg 30 veces) quiero 30 evento de temporisador en 1 segundo
    if(!timer)
    {
        printf("couldn't initialize timer\n");
        return 1;
    }

    ALLEGRO_EVENT_QUEUE* queue = al_create_event_queue();//Create a new, empty event queue, returning a pointer to the newly created object if successful. Returns NULL on error.
    if(!queue)
    {
        printf("couldn't initialize queue\n");
        return 1;
    }
    ALLEGRO_DISPLAY* disp = al_create_display(520, 800);//tells Allegro to create a 320x200 pixel window
    if(!disp)
    {
        printf("couldn't initialize display\n");
        return 1;
    }
    ALLEGRO_FONT* font = al_create_builtin_font();//Guarda la fuente con la que voy a escribir los textos. Fuente pixeleada
    if(!font)
    {
        printf("couldn't initialize font\n");
        return 1;
    }


    //Registro los eventos, decirle al programa q este atento por si sucede un cambio guardarlo en la queue(FIFO)
    al_register_event_source(queue, al_get_keyboard_event_source());
    al_register_event_source(queue, al_get_display_event_source(disp));
    al_register_event_source(queue, al_get_timer_event_source(timer));

    /*The main loop: (Se repite constantemente mientras que el juego esta ejecutandose)
1. Accept input from the player (if given), reaccion en tiempo real de las acciones del jugador, teclado, mouse
2. Advance the games variables by a single frame-> THE GAME LOGIC, actualizacion de todo lo que sucede en el mundo del juego en forma de las variables
3. Render the grafics acording to the variables, dibuja todo en patalla para actualizar la posicion del juego, se hace en fps, actualizaciones continuas para simular la continuidad de los frames, imagenes, como si fuera la vida real
    */ 
    bool redraw= true;
    ALLEGRO_EVENT event;//defino la var event del tipo ALLEGRO_EVENT -> estruct muy grande que divide por tipo de evento, lo podemos saber usando event.type (por ej puede ser ALLEGRO_EVENT_TIMER), segun el tipo podes acceder a datos especificos  
    
    al_start_timer(timer);
    int col=0;
    while(1){
        al_wait_for_event(queue, &event);//your program's running process will block until something relevant happens, an event, in the queue. Util por q evitas que el juego este constantemente revisando y realizando op innecesarias, repetir el bocle a la maxima velocidad para chekear todo el tiempo si pasa algo en la queue.
        //Now event has useful info on what just happend
        if(event.type == ALLEGRO_EVENT_TIMER){
            redraw = true;//time to advance a frame
        }
        else if((event.type==ALLEGRO_EVENT_KEY_DOWN)||(event.type==ALLEGRO_EVENT_DISPLAY_CLOSE)){
            break;//Once the loop is broken, the program more or less immediately quits. That's our "press any key to exit" mechanism sorted!
        }
        if(redraw && al_is_event_queue_empty(queue)){//runs only when you're ready to redraw and all pending events have been processed.
            al_clear_to_color(al_map_rgb(col,col,col));//Clears the display and fills it with a coulour (0,0,0)=black
            al_draw_text(font, al_map_rgb(255,255,255), 260, 400, ALLEGRO_ALIGN_CENTRE, "Hello world!"); //Draws the text "Hello world!" in white (255,255,255), at position (0, 0) (top-left corner of the screen).The last 0 refers to text alignment (in this case, ALLEGRO_ALIGN_LEFT — left-aligned).
            /*void al_draw_text(ALLEGRO_FONT *font,
                  ALLEGRO_COLOR color,
                  float x, float y,
                  int flags,               //ALLEGRO_ALIGN_LEFT → (0)The text starts at x ; ALLEGRO_ALIGN_CENTRE → The center of the text is placed at x ; ALLEGRO_ALIGN_RIGHT → The text is aligned to the right, ending at x 
                  const char *text);*/
            col++;
            if(col>255){
                col=0;
            }            
            al_flip_display();//displays everything you've drawn since the last flip — because Allegro uses double buffering-> Instead of drawing directly to the screen, you draw on a hidden (back) buffer — and only when it’s ready, you show the whole thing at once. If you drew directly to the screen, you'd see things appear one at a time — that's called tearing or flickering.
            redraw= false;//Reset the redraw flag
        }
    }  

    //Shutdown, freeing resourses :  Todo lo que vos pedís al sistema (memoria, archivos, imágenes, ventanas, fuentes, etc.), vos lo tenés que liberar.Ocupa memoria RAM. Si no la liberás, se queda ocupando espacio aunque ya no la uses.

    al_destroy_font(font);
    al_destroy_display(disp);
    al_destroy_timer(timer);
    al_destroy_event_queue(queue);

return 0;
    return 0;
}

