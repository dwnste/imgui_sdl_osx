//
//  helpers.cpp
//  imgui_sdl_osx
//
//  Created by downstate on 02.03.2018.
//  Copyright © 2018 downstate. All rights reserved.
//

#include "helpers.hpp"
namespace helpers {
    uintptr_t GetAbsoluteAddress(uintptr_t dwAddress, uintptr_t memoryPtr, uintptr_t startOffset, uintptr_t size) {
        uintptr_t signatureAddress = memoryPtr + startOffset;
        uintptr_t fileOffset = signatureAddress - dwAddress;
        uintptr_t offset = *reinterpret_cast<uint32_t*>(signatureAddress);
        
        return dwAddress + (offset + fileOffset) + size;
    }
}
