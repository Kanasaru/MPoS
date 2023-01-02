# mpos
My helpers library for building games in C with SDL based on SDL.
<br><br>

# Building From Source
1. Install dependencies
2. Clone [mpos](https://github.com/kanasaru/mpos)
3. Open directory in the terminal
4. Type ```make```
5. Type ```make deploy``` or copy header and lib files to os's library path
<br><br>

# Documentation
On [my website](https://bitbyteopen.org) I'll **try** to write about the 
development process. Everything else, at least that's how I initially 
determined it, goes into the documentation.
Simple markdown files are used for this.
<br><br>

# Contribution
mpos is intended as an open source project and therefore lives from 
people who contribute to making the game better. Support is welcome.
<br><br>

# Credits
- [Simple DirectMedia Layer](https://www.libsdl.org)

# Dependencies
mpos is strongly dependent on SDL, SDL_ttf, SDL_mixer and SDL_image.
Dependency versions:
* SDL >= 2.0.0
* SDL_mixer >= 2.0.0
* SDL_image >= 2.0.0
* SDL_ttf >= 2.0.0

## Installation with Homebrew
```bash
/bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"
brew install sdl2
brew install sdl2_ttf
brew install sdl2_mixer
brew install sdl2_image
```

# License
mpos is available under the [zlib license](https://www.zlib.net/zlib_license.html):

This software is provided 'as-is', without any express or implied
warranty.  In no event will the authors be held liable for any damages
arising from the use of this software.

Permission is granted to anyone to use this software for any purpose,
including commercial applications, and to alter it and redistribute it
freely, subject to the following restrictions:

1. The origin of this software must not be misrepresented; you must not
   claim that you wrote the original software. If you use this software
   in a product, an acknowledgment in the product documentation would be
   appreciated but is not required.
2. Altered source versions must be plainly marked as such, and must not be
   misrepresented as being the original software.
3. This notice may not be removed or altered from any source distribution.
