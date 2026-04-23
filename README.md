# Epitaph

A simple and minimalist text editor written in C/C++ for Windows and Linux as a project for learning (and, well, maybe a little for fun), distributed under the MIT License.

I believe in the superiority of Assembly, C, and C++ over other languages, which is why I chose them for this project. I also appreciate the aesthetic appeal of software that looks raw and technical, and that was my motivation for designing the interface the way it is. As for functionality, I’ve always preferred software that does exactly what it’s supposed to do, without unnecessary frills or endless features and capabilities.

Despite my aversion to unnecessary features, I will still be adding some features that aren’t strictly necessary or mandatory; however, the final software in the [Releases](https://github.com/childofsorrow08/Epitaph/releases) page will include both a minimal and a full version, and those who compile manually will be able to choose which features to enable and which to disable.

Currently in the early stages of development.

If you'd like to learn more, you can check out these other documents:
- Acknowledgments for inspiration/ideas: [THANKS.md](docs/THANKS.md)
- A list of the libraries and tools used to assist in development, along with our thanks to them: [THIRD-PARTY.md](docs/THIRD-PARTY.md)
- If you'd like to contribute to the project, you can learn more about the needs or opportunities here: [CONTRIBUTING.md](docs/CONTRIBUTING.md)
- A to-do list where I write down (and sometimes forget) everything I plan to do: [TODO.md](docs/TODO.md)

If you need current dev branch, [you can find it here](https://github.com/childofsorrow08/Epitaph/tree/salvation).

# How to build

> **Note:** If you want to download a ready-to-use, compiled program, you can find it on the [project's release page](https://github.com/childofsorrow08/Epitaph/releases).

**Dependencies:**
- **CMake**, at least 3.25 version.
- **C/C++ compiler** (MinGW for Windows, GCC for Linux).
- **Lua**, to compile assets into binary arrays.

## How to build on Windows:

> **Note:** I haven't worked on MSVC support yet, so **MinGW** is recommended for compiling this project. I'm not sure what issues you might encounter with other Windows compilers.

> **Note:** This project also includes the **MinGW Toolchain** in the `cmake` directory, which will allow you to compile it on Windows while running on Linux.

## How to build on Linux: