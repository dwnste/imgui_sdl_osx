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
#include "imgui.h"
#include "imgui_impl_sdl_gl2.h"
#include "module.hpp"
#include "helpers.hpp"

namespace SDLHook {
    void Init();
    void SwapWindow(SDL_Window* window);
}

#endif /* hook_hpp */
