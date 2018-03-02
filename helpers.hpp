//
//  helpers.hpp
//  imgui_sdl_osx
//
//  Created by downstate on 02.03.2018.
//  Copyright © 2018 downstate. All rights reserved.
//

#ifndef helpers_hpp
#define helpers_hpp

#include <stdio.h>
#include <stdint.h>

namespace helpers {
    uintptr_t GetAbsoluteAddress(uintptr_t dwAddress, uintptr_t memoryPtr, uintptr_t startOffset, uintptr_t size);
}

#endif /* helpers_hpp */
