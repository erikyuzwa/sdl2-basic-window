
#include <SDL.h>

SDL_Window* window;
SDL_Renderer* renderer;

int main(int argc, char* argv[]) {

    int quit = 0;
    SDL_Event event;

    int w = 800;
    int h = 600;
    int windowed = 1;

    int result = SDL_Init(SDL_INIT_EVERYTHING);
    if (result < 0) return -1;

    Uint32 flags = SDL_WINDOW_SHOWN;
    window = SDL_CreateWindow("basic window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, w, h, flags);
    if (window == NULL) goto CLEANUP_AND_QUIT;

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (renderer == NULL) goto CLEANUP_AND_QUIT;

    while (!quit) {
        while ( SDL_PollEvent( &event ) != 0 ) {
            switch (event.type) {
                case SDL_WINDOWEVENT_SIZE_CHANGED:
                    w = event.window.data1;
                    h = event.window.data2;
                    SDL_RenderPresent(renderer);
                break;
                case SDL_QUIT:
                    quit = 1;
                break;
                case SDL_KEYUP:
                    switch (event.key.keysym.sym) {
                        case SDLK_ESCAPE:
                            quit = 1;
                        break;
                        case SDLK_F1:
                            windowed = !windowed;
                            if (windowed) {
                                SDL_SetWindowFullscreen(window, SDL_FALSE);
                            } else {
                                SDL_SetWindowFullscreen(window, SDL_TRUE);
                            }
                        break;

                    }
                break;
            }
        }

        // do stuff
        SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
        SDL_RenderClear(renderer);

        SDL_RenderPresent(renderer);
        SDL_Delay(10);
    }



    CLEANUP_AND_QUIT:
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    SDL_Quit();

    return 0;
}
