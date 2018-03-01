//
//  hook.hpp
//  imgui_sdl_osx
//
//  Created by downstate on 28.02.2018.
//  Copyright © 2018 downstate. All rights reserved.
//

#ifndef hook_hpp
#define hook_hpp

#include <OpenGL/gl.h>
#include <SDL2/SDL.h>
#include "dlfcn.h"
#include "rd_route.h"
#include "imgui.h"
#include "imgui_impl_sdl.h"

namespace SDLHook {
    void Init();
    void DrawUI();
    SDL_Window* GetCurrentWindow();
    SDL_GLContext CreateContext(SDL_Window* window);
    SDL_GLContext GetCurrentContext();
    int MakeCurrent(SDL_Window* window, SDL_GLContext context);
    void SwapWindow(SDL_Window* window);
    char* GetClipboardText(void);
    int SetClipboardText(const char* text);
    SDL_Keymod GetModState(void);
    void GetWindowSize(SDL_Window* window, int* w, int* h);
    void GetDrawableSize(SDL_Window* window, int* w, int* h);
    Uint32 GetWindowFlags(SDL_Window* window);
    Uint32 GetTicks(void);
    Uint32 GetMouseState(int* x, int* y);
    int ShowCursor(int toggle);
}

#endif /* hook_hpp */
