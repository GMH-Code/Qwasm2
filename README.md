Qwasm2
======

This is an unofficial WebAssembly port of the engine behind the 3D first-person shooter *Quake 2*.

[Run Qwasm2 in your browser here](https://gmh-code.github.io/qwasm2/).

Qwasm2 is based upon *Yamagi Quake II*, and inherits changes to the original game.  These alterations may include changes to performance, memory usage, and visual effects.

OpenGL ES 3.x hardware accelerated rendering is available in-browser.  This is translated to WebGL 2.x, and it contains many impressive visual effects.  The OpenGL 1.x and software renderers also work, which have fewer GPU requirements.

Also available are:

- [Qwasm](https://gmh-code.github.io/qwasm/) ([source](https://github.com/GMH-Code/Qwasm) based on id's original *Quake* engine code)
- [Dwasm](https://gmh-code.github.io/dwasm/) ([source](https://github.com/GMH-Code/Dwasm) based on *PrBoom+* and the *DOOM* engine)

PAK Files
---------

This project needs resource files to run.  These are usually embedded in `PAK` containers, and can be maps, textures, models, sounds, and more.  It is also possible to use raw files instead.

Playing an Open Source Game
---------------------------

If you have one or more `PAK` files provided by another Open Source project that supports the original Quake 2 engine, those files should be drop-in compatible.

If these third-party game files include any native libraries, such as `gamex86.dll` or `gamex86.so`, they will need separate porting.

Playing the Demo Version of Quake 2
-----------------------------------

The demo PAK can be extracted from this file, widely available online:

    Filename: q2-314-demo-x86.exe
    File size: 39,015,499 bytes (37 MiB)
    SHA1: 5B4DEDC59CEEE306956A3E48A8BDF6DD33BC91ED
    SHA256: 7ACE5A43983F10D6BDC9D9B6E17A1032BA6223118D389BD170DF89B945A04A1E

You do *not* need to run this installer.  You can open the executable by using software like *7-Zip* or *WinRAR*.

The required file is in `Install/Data/baseq2`, and should match the following:

    Filename: pak0.pak
    File size: 49,951,322 bytes (47 MiB)
    SHA1: B86E8878A8E8706595CEEBE88B3E6B4C1BA5BCAB
    SHA256: CAE257182F34D3913F3D663E1D7CF865D668FEDA6AF393D4ECF3E9E408B48D09

Playing the Full Version of Quake 2
-----------------------------------

This PAK file is the bare minimum needed to play the full version of the original game:

    Filename: pak0.pak
    File size: 183,997,730 bytes (175 MiB)
    SHA1: 1DD586A3230D1AC5BFD34E57CC796000D4C252C2
    SHA256: 1CE99EB11E7E251CCDF690858EFFBA79836DBE5E32A4083AD00A13ECDA491679

If you have the original CD, this file can be found in `Install/Data/baseq2`.

### Updating the Full Version

If you want to add the V3.20 update (recommended) which fixes bugs and other issues, grab this file online:

    Filename: q2-3.20-x86-full.exe
    File size: 13,842,432 bytes (13 MiB)
    SHA1: F0BECCE2618827C08CEB5C99575E1ED3D1FC003E
    SHA256: EE1B430258D5FC5A897EF47C6246F5DA11DE885F4C29FBECA005FF27924700BE

You can extract `pak1.pak` and `pak2.pak` without running the executable, using the same method as the demo version.  These are the details of the files contained in the `baseq2` folder:

    Filename: pak1.pak
    File size: 12,992,754 bytes (12 MiB)
    SHA1: 588EF09965DEE539521B4EB6DA4337CE78A2EA21
    SHA256: 678210ECD1B27DDE1C645660333A1A7B139D849425793859657F804D379B62AD

    Filename: pak2.pak
    File size: 45,055 bytes (43 KiB)
    SHA1: 67E76A7F3234646507AE59EC1BF755637C1DAD03
    SHA256: CB88D584EF939D08E24433A6CF86274737303FAC2BBD94415927A75E6B269DD8

These two files can be placed in the same folder as `pak0.pak` to update the game.

### Licence Warnings

The licence for the demo version of Quake 2 only appears to permit duplication of the self-extracting archive (executable) that was originally obtained from an official source, so it appears as though, understandably, the archive's contents cannot be distributed nor embedded separately.

The full version carries an even more restrictive licence -- so do not be tempted to host the full version on a public server!

In-Browser Saving
-----------------

If you use the `Save` option or change the settings in-game, this project will attempt to commit those changes to browser storage.  These changes should persist after a browser reload.

Saving PAK files to storage isn't implemented as they are large and this can cause a substantial lag when the filesystem is synched.

Command-Line Arguments
----------------------

Like the desktop version of Quake 2, you can pass arguments to this version at runtime.  By default, the query portion of the URL is used, but the JavaScript code can be modified to use anything else, such as an input text box.

### Example

Let's say you were using the default template, serving the page locally, and you wanted to:

1. Start the software renderer, and
2. Start with the resolution set to 1920x1080.

To do this, you can start the game with `+set vid_renderer soft +set r_mode 21`.

In Qwasm2, you can append a single `?` to the end of the URL and place `&` between each parameter and value, where you would usually put a space.  This would look something like:

    https://127.0.0.1/?+set&vid_renderer&soft&+set&r_mode&21

Recording Demos
---------------

Recording demos is supported, and the recordings can span multiple levels.  You can start one by typing something like this in the console, after starting a game:

    record mydemo

To stop the demo:

    stop

The file will be saved in the browser database, but you will also be given the opportunity to export it if you want to.

The demo can be played back with `map mydemo.dm2`.  If it starts in a paused state, press `Esc` twice.

Physical Gamepads & Joysticks
-----------------------------

Attached gamepads and dual analogue controls should work, providing your browser supports their functionality.

Networking Support
------------------

WebSockets support for multiplayer has not yet been added.

It should be possible to connect to a WebSockets proxy to enable online play, but Qwasm2 will need rebuilding with the appropriate proxy configuration.

Mods and Mission Packs
----------------------

Game behaviour modifications and enhancements are supported, but since the QuakeC interpreter was only present in the first *Quake*, mods and mission packs now require separate compilation into WebAssembly.

Due to an Emscripten limitation with loading dynamic libraries from subfolders at startup, you must make sure these ported files include the game name and are located in the same directory as all the other `.wasm` files.  For example, the default game type `baseq2` is named `game_baseq2.wasm` instead of `baseq2/gamex86.dll` or `baseq2/gamex86.so`.

Mission pack code is *not* currently part of the Qwasm2 build.

If you want to add extra mods or mission packs, follow these steps:

1. Compile the mods or mission packs you want to include into WebAssembly.
2. Specify the compiled libraries with `WASM_EXTRA_GAMES="/path/to/file1.wasm /path/to/file2.wasm"` (and so on) when compiling Qwasm2 with `emmake make`.
3. After the compilation is complete, copy the `.wasm` files to the `release` folder.

It is likely that third-party modules will not 'just work'!  Some code adjustment to them may be necessary.

Known Issues / Workarounds
--------------------------

These affect lesser-used video switches and restarts, and they should normally go unnoticed.  Nevertheless, they may be fixed in the future.

You can always force a specific renderer on startup with `+set vid_renderer gles3`, `+set vid_renderer gl1` or `+set vid_renderer soft`, to ensure the game starts in the way you want.

### OpenGL 1.x Renderer

These problems appear to be specific to GL4ES:

- Starting this renderer after starting another (including the software renderer) will intentionally switch the display to software mode, because otherwise the canvas becomes blank.
- This renderer also cannot be restarted due to a corruption of the 3D environment, meaning you cannot change display modes without reverting to the software renderer.

Usage of the software renderer will likely be saved in the user's configuration, so to get back to OpenGL 1.x mode after reverting, restart the game with the appropriate command-line parameter.

### OpenGL ES 3.x Renderer

These problems appear to be due to an inability to switch the WebGL context to a different version at runtime:

- You cannot switch to another renderer, not even software mode, after this one has successfully started.

- You cannot switch to this renderer if you used a different one.

### Heap Usage

The Quake 2 engine heap (an area of RAM for game objects) is dynamic, meaning it can allocate and de-allocate memory pages from system RAM depending on how much is required.  Memory allocated in Qwasm2's heap should be reused once allocated, but unlike on desktop systems, freed pages will *not* be completely returned to system RAM, because WebAssembly does not appear to support that yet.

How to Build on Linux for WebAssembly
-------------------------------------

### EMSDK

This is required to build both GL4ES and Qwasm2.

Clone or download EMSDK: https://emscripten.org/docs/getting_started/downloads.html

Install and fully activate the latest version, as per the instructions.

### GL4ES

This is currently required to build the OpenGL 1.x part of Qwasm2, which can run in WebGL 1.x.  If you start the game up in OpenGL ES 3.x (WebGL 2.x) or software mode, it will not be initialised or used.  At a future date, this library may be completely removed.

Clone or download GL4ES: https://ptitseb.github.io/gl4es/

There is a change you must make before proceeding with the build:

1. Open `CMakeLists.txt` in a text editor.
2. Search the file for `Emscripten`.  There should be only one match.
3. In the next line (starting with `add_definitions`), add `-fPIC` before the closing bracket.

Remember to keep this customised ('PIC') copy of GL4ES separate from any other version.

Now run the GL4ES *Emscripten* build according to the instructions on: https://ptitseb.github.io/gl4es/COMPILE.html

### Qwasm2

1. Switch to the Qwasm2 folder.
2. Run `emmake make GL4ES_PATH=/home/user/gl4es_pic`, substituting the GL4ES path as appropriate.  Your Emscripten installation will be automatically detected and used for the build.

The build will output the following into the `release` folder:

    index.html
    index.js
    index.data
    index.wasm
    game_baseq2.wasm
    ref_soft.wasm
    ref_gl1.wasm
    ref_gles3.wasm

Note that the game will not properly boot without PAK and/or other files being present in `wasm/baseq2`.  It is not legal to host nor embed any of the original game's PAK files (or their contents) on a public server, regardless of whether you have the demo or full version, so do not be tempted to do this.  In any case, licence compliance is your responsibility.

To massively reduce bandwidth and download time, compress all the files using GZip (or better, Brotli) compression, host the files statically, and verify the web browser is doing the decompression for each file.

-----

This project is not affiliated with, endorsed by, or in any way connected to id Software, Bethesda Softworks, or ZeniMax Media.  All trademarks and copyrights are the property of their respective owners.
