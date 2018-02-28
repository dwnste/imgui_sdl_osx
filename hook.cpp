//
//  hook.cpp
//  imgui_sdl_osx
//
//  Created by downstate on 28.02.2018.
//  Copyright © 2018 downstate. All rights reserved.
//

#include "hook.hpp"

// Here we store pointers to original functions.
SDL_GLContext (*Original_SDL_GL_CreateContext)(SDL_Window* window);
SDL_GLContext (*Original_SDL_GL_GetCurrentContext)(void);
int (*Original_SDL_GL_MakeCurrent)(SDL_Window* window, SDL_GLContext context);
void (*Original_SDL_GL_SwapWindow)(SDL_Window* window);
char* (*Original_SDL_GetClipboardText)(void);
int (*Original_SDL_SetClipboardText)(const char* text);
SDL_Keymod (*Original_SDL_GetModState)(void);
void (*Original_SDL_GetWindowSize)(SDL_Window* window, int* w, int* h);
void (*Original_SDL_GL_GetDrawableSize)(SDL_Window* window, int* w, int* h);
Uint32 (*Original_SDL_GetWindowFlags)(SDL_Window* window);
Uint32 (*Original_SDL_GetTicks)(void);
Uint32 (*Original_SDL_GetMouseState)(int* x, int* y);
int (*Original_SDL_ShowCursor)(int toggle);


SDL_GLContext SDLHook::CreateContext(SDL_Window* window) {
    return Original_SDL_GL_CreateContext(window);
}

SDL_GLContext SDLHook::GetCurrentContext(void) {
    return Original_SDL_GL_GetCurrentContext();
}

int SDLHook::MakeCurrent(SDL_Window* window, SDL_GLContext context) {
    return Original_SDL_GL_MakeCurrent(window, context);
}

char* SDLHook::GetClipboardText(void) {
    return Original_SDL_GetClipboardText();
}

int SDLHook::SetClipboardText(const char* text) {
    return Original_SDL_SetClipboardText(text);
}

SDL_Keymod SDLHook::GetModState(void) {
    return Original_SDL_GetModState();
}

void SDLHook::GetWindowSize(SDL_Window* window, int* w, int* h) {
    Original_SDL_GetWindowSize(window, w, h);
}

void SDLHook::GetDrawableSize(SDL_Window* window, int* w, int* h) {
    Original_SDL_GL_GetDrawableSize(window, w, h);
}

Uint32 SDLHook::GetWindowFlags(SDL_Window* window) {
    return Original_SDL_GetWindowFlags(window);
}

Uint32 SDLHook::GetTicks(void) {
    return Original_SDL_GetTicks();
}

Uint32 SDLHook::GetMouseState(int* x, int* y) {
    return Original_SDL_GetMouseState(x, y);
}

int SDLHook::ShowCursor(int toggle) {
    return Original_SDL_ShowCursor(toggle);
}


// Store our rendering context.
static SDL_GLContext context = NULL;


// Draw anything we need inside SDL_GL_SwapWindow hook
void SDLHook::SwapWindow(SDL_Window* window) {
    // Get the current rendering context.
    static SDL_GLContext original_context = SDLHook::GetCurrentContext();
    
    // Create our own rendering context and initialize ImGui.
    if (!context)
    {
        context = SDLHook::CreateContext(window);
        ImGui_ImplSdl_Init(window);
    }
    
    // Switch to our context.
    SDLHook::MakeCurrent(window, context);
    
    // Rendering
    ImGui_ImplSdl_NewFrame(window);
    
    ImGui::Text("Hello world!");
    ImGui::TextColored(ImVec4(0.52, 0.06, 0.95, 1.0), "Sample text");
    ImGui::Render();
    
    // For some reason you need to call the original SwapWindow at first.
    Original_SDL_GL_SwapWindow(window);
    // Then switch back to original context.
    SDLHook::MakeCurrent(window, original_context);
    // Without this guy you will get flickering effect.
    glFlush();
}

// Here we actually hook all the symbols we need to use.
// (including the these we need in imgui_impl_sdl)
void SDLHook::Init() {
    rd_route(
         dlsym(RTLD_DEFAULT, "SDL_GL_CreateContext"),
         (void *)SDLHook::CreateContext,
         (void **)&Original_SDL_GL_CreateContext
    );
    
    rd_route(
         dlsym(RTLD_DEFAULT, "SDL_GL_GetCurrentContext"),
         (void *)SDLHook::GetCurrentContext,
         (void **)&Original_SDL_GL_GetCurrentContext
    );
    
    rd_route(
         dlsym(RTLD_DEFAULT, "SDL_GL_MakeCurrent"),
         (void *)SDLHook::MakeCurrent,
         (void **)&Original_SDL_GL_MakeCurrent
    );
    
    rd_route(
         dlsym(RTLD_DEFAULT, "SDL_GL_SwapWindow"),
         (void *)SDLHook::SwapWindow,
         (void **)&Original_SDL_GL_SwapWindow
    );
    
    rd_route(
         dlsym(RTLD_DEFAULT, "SDL_GetClipboardText"),
         (void *)SDLHook::GetClipboardText,
         (void **)&Original_SDL_GetClipboardText
    );
    
    rd_route(
         dlsym(RTLD_DEFAULT, "SDL_SetClipboardText"),
         (void *)SDLHook::SetClipboardText,
         (void **)&Original_SDL_SetClipboardText
    );
    
    rd_route(
         dlsym(RTLD_DEFAULT, "SDL_GetModState"),
         (void *)SDLHook::GetModState,
         (void **)&Original_SDL_GetModState
    );
    
    rd_route(
         dlsym(RTLD_DEFAULT, "SDL_GetWindowSize"),
         (void *)SDLHook::GetWindowSize,
         (void **)&Original_SDL_GetWindowSize
    );
    
    rd_route(
         dlsym(RTLD_DEFAULT, "SDL_GL_GetDrawableSize"),
         (void *)SDLHook::GetDrawableSize,
         (void **)&Original_SDL_GL_GetDrawableSize
    );
    
    rd_route(
         dlsym(RTLD_DEFAULT, "SDL_GetWindowFlags"),
         (void *)SDLHook::GetWindowFlags,
         (void **)&Original_SDL_GetWindowFlags
    );
    
    rd_route(
         dlsym(RTLD_DEFAULT, "SDL_GetTicks"),
         (void *)SDLHook::GetTicks,
         (void **)&Original_SDL_GetTicks
    );
    
    rd_route(
         dlsym(RTLD_DEFAULT, "SDL_GetMouseState"),
         (void *)SDLHook::GetMouseState,
         (void **)&Original_SDL_GetMouseState
    );
    
    rd_route(
         dlsym(RTLD_DEFAULT, "SDL_ShowCursor"),
         (void *)SDLHook::ShowCursor,
         (void **)&Original_SDL_ShowCursor
    );
}
