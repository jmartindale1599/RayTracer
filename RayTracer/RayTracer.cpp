
#include "Renderer.h"

#include <iostream>

int main(int, char**){

    Renderer renderer; 

    renderer.Initialize(); 
    
    renderer.CreateWindow(400, 300); 
    
    Canvas canvas(400, 300, renderer);



    bool quit = false; 
    
    while (!quit) { 
    
        SDL_Event event; 
        
        SDL_PollEvent(&event); 
        
        switch (event.type) {
        
            case SDL_QUIT:
                
                quit = true; 
            
            break; 
        
            case SDL_KEYDOWN:

                switch (event.key.keysym.sym){

                case SDLK_ESCAPE:
                    
                    quit = true;
                    
                    break;
                
                }
                
                break;

        } 

        //render scene
    
        canvas.Clear({0, 0, 0, 1 });

        for (int i = 0; i < 25000; i++) {

            canvas.DrawPoint({ random(0,400), random(0,300) }, { random01(),random01(),random01(),1 });

        }

        canvas.Update();

        renderer.CopyCanvas(canvas);

        renderer.Present();

    }
    
    renderer.Shutdown(); 
    
    return 0;

}
