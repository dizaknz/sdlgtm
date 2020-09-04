#include "SDL.h"
#include "SDL_image.h"

#define cols 88
#define rows 21

static char * text_xpm[] = {
  "88 21 7 1",
  "  c #FFFFFF",
  ": c #151515",
  "_ c #000000",
  "~ c #000000",
  "\\ c #000000",
  "/ c #000000",
  "| c #000000",
  "          _____            _____                _____                    _____          ",
  "         /\\    \\          /\\    \\              /\\    \\                  /\\    \\         ",
  "        /::\\____\\        /::\\    \\            /::\\    \\                /::\\____\\        ",
  "       /:::/    /       /::::\\    \\           \\:::\\    \\              /::::|   |        ",
  "      /:::/    /       /::::::\\    \\           \\:::\\    \\            /:::::|   |        ",
  "     /:::/    /       /:::/\\:::\\    \\           \\:::\\    \\          /::::::|   |        ",
  "    /:::/    /       /:::/  \\:::\\    \\           \\:::\\    \\        /:::/|::|   |        ",
  "   /:::/    /       /:::/    \\:::\\    \\          /::::\\    \\      /:::/ |::|   |        ",
  "  /:::/    /       /:::/    / \\:::\\    \\        /::::::\\    \\    /:::/  |::|___|______  ",
  " /:::/    /       /:::/    /   \\:::\\ ___\\      /:::/\\:::\\    \\  /:::/   |::::::::\\    \\ ",
  "/:::/____/       /:::/____/  ___\\:::|    |    /:::/  \\:::\\____\\/:::/    |:::::::::\\____\\",
  "\\:::\\    \\       \\:::\\    \\ /\\  /:::|____|   /:::/    \\::/    /\\::/    / ~~~~~/:::/    /",
  " \\:::\\    \\       \\:::\\    /::\\ \\::/    /   /:::/    / \\/____/  \\/____/      /:::/    / ",
  "  \\:::\\    \\       \\:::\\   \\:::\\ \\/____/   /:::/    /                       /:::/    /  ",
  "   \\:::\\    \\       \\:::\\   \\:::\\____\\    /:::/    /                       /:::/    /   ",
  "    \\:::\\    \\       \\:::\\  /:::/    /    \\::/    /                       /:::/    /    ",
  "     \\:::\\    \\       \\:::\\/:::/    /      \\/____/                       /:::/    /     ",
  "      \\:::\\    \\       \\::::::/    /                                    /:::/    /      ",
  "       \\:::\\____\\       \\::::/    /                                    /:::/    /       ",
  "        \\::/    /        \\::/____/                                     \\::/    /        ",
  "         \\/____/                                                        \\/____/         "};

int main(int argc, char *argv[]) {
  SDL_Window *window;
  SDL_Renderer *renderer;
  SDL_Surface *surface;
  SDL_Texture *texture;
  SDL_Event event;

  if (SDL_CreateWindowAndRenderer(0, 0, 0, &window, &renderer) < 0) {
    SDL_LogError(
      SDL_LOG_CATEGORY_APPLICATION,
      "SDL_CreateWindowAndRenderer() failed: %s", 
      SDL_GetError()
    );
    return(2);
  }

  surface = IMG_ReadXPMFromArray(text_xpm);
  texture = SDL_CreateTextureFromSurface(renderer, surface);
  if (!texture) {
    SDL_LogError(
      SDL_LOG_CATEGORY_APPLICATION,
      "Couldn't load texture: %s",
      SDL_GetError()
    );
    return(2);
  }
  SDL_FreeSurface(surface);
  SDL_SetWindowSize(window, cols, rows);
  
  while (1) {
    SDL_PollEvent(&event);
    if (event.type == SDL_QUIT) {
      break;
    }
    SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0x00);
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, texture, NULL, NULL);
    SDL_RenderPresent(renderer);
  }

  SDL_DestroyTexture(texture);
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);

  SDL_Quit();
  return(0);
}


