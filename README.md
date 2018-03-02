# imgui_sdl_osx 

The main difference between this and __SDL_GL_SwapWindow__ hooking approach on Linux is that you need to hook every single function you want to use.  

Another one is that to render anything you need to call original __SDL_GL_SwapWindow__ before you actually call __SDL_GL_MakeCurrent__ (with original context as one of the arguments).  

And the last but not the least, you need to call __glFlush()__ in the end of yours __SDL_GL_SwapWindow__ override function so you could get rid of flickering effect.  


You can replace *rd_route* with for example *mach_override* or even implement your own pattern scanner, this repo is just a proof of concept.  

### Usage
1) Open project in XCode.  
2) Install *SDL2* library with [Homebrew](https://brew.sh/).  
```
brew install sdl2
```
3) Build the project.
4) Inject the lib. (for example with [osxinj](https://github.com/scen/osxinj)) 


### Credits:
- [ImGui](https://github.com/ocornut/imgui)
- [scen](https://github.com/scen) for his [libemryo](https://github.com/scen/libembryo)


### Thanks to:
- [@aixxe](https://github.com/aixxe) and his [SDL2 hooking example on Linux](https://github.com/aixxe/imgui-sdl-csgo)
- [@LWSS](https://github.com/LWSS) and [@Marc3842h](https://github.com/Marc3842h)
- [@aKalisch](https://github.com/aKalisch) for [his suggestions](https://github.com/dwnste/imgui_sdl_osx/issues/2)
