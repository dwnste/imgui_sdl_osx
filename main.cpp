//
//  main.cpp
//  imgui_sdl_osx
//
//  Created by downstate on 28.02.2018.
//  Copyright © 2018 downstate. All rights reserved.
//

#include "main.hpp"


int __attribute__((constructor))
attach()
{
    SDLHook::Init();

    return 0;
}

void __attribute__((constructor))
detach()
{
    
}
