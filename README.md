# imgui_sdl_osx 

To render anything you need to call original __SDL_GL_SwapWindow__ before you actually call __SDL_GL_MakeCurrent__ (with original context as one of the arguments).  

Moreover, you need to call __glFlush()__ in the bottom of your __SDL_GL_SwapWindow__ override function to get rid of flickering effect.  

### Usage
1) Install *SDL2* library with [Homebrew](https://brew.sh/).  
```bash
brew install sdl2
```
2) Open project in XCode.  
3) Build the project.
4) Inject the lib. (for example with [osxinj](https://github.com/scen/osxinj)) 


### Credits:
- [ImGui](https://github.com/ocornut/imgui)
- [scen](https://github.com/scen) for his [libembryo](https://github.com/scen/libembryo)


### Thanks to:
- [@aixxe](https://github.com/aixxe) and his [SDL2 hooking example on Linux](https://github.com/aixxe/imgui-sdl-csgo)
- [@LWSS](https://github.com/LWSS) and [@Marc3842h](https://github.com/Marc3842h)
- [@aKalisch](https://github.com/aKalisch) for [his suggestions](https://github.com/dwnste/imgui_sdl_osx/issues/2)
