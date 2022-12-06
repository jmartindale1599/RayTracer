
#include "Renderer.h"

#include "Objects/Sphere.h"

#include "Objects/Scene.h"

#include <iostream>

int main(int, char**){

    Renderer renderer; 

    renderer.Initialize(); 
    
    renderer.CreateWindow(600, 300); 
    
    Canvas canvas(600, 300, renderer);

    Scene scene;

    scene.AddObject(std::make_unique<Sphere>(glm::vec3{ 1, 0, -1 }, 0.5f, std::make_unique<Lambertian>(color3(0.5f, 0, 0.7f))));

    scene.AddObject(std::make_unique<Sphere>(glm::vec3{ -3.75f, 5.62f, -6 }, 7.5f, std::make_unique<Lambertian>(color3(0.5f, 0, 0))));

    scene.AddObject(std::make_unique<Sphere>(glm::vec3{ 0, -100.5f, -1 }, 100.0f, std::make_unique<Lambertian>(color3(0.2f, 0.3f, 0))));

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

        renderer.Render(canvas, scene);

        //for (int i = 0; i < 25000; i++) {

        //    canvas.DrawPoint({ random(0,400), random(0,300) }, { random01(),random01(),random01(),1 });

        //}

        canvas.Update();

        renderer.CopyCanvas(canvas);

        renderer.Present();

    }
    
    renderer.Shutdown(); 
    
    return 0;

}
