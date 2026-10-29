# SFML Starter Project

### Easily install and get started with SFML, without the headache of tedious setup!

Want a video tutorial? [Coming soon](https://www.youtube.com/watch?v=xvFZjo5PgG0)

---

## Quickstart

1. **Clone or Download:** Clone this repository using `git clone` OR download the ZIP file and extract it.
2. **Linux Setup:** If you are on Linux, open a terminal, run `sudo apt update && sudo apt install build-essential libsfml-dev`, and skip to **Step 6**.
3. **Windows Downloads:** Download [WinLibs Compiler](https://github.com/brechtsanders/winlibs_mingw/releases/download/14.2.0posix-19.1.1-12.0.0-ucrt-r2/winlibs-x86_64-posix-seh-gcc-14.2.0-mingw-w64ucrt-12.0.0-r2.7z) and [MinGW SFML 3.1.0](https://www.sfml-dev.org/files/SFML-3.1.0-windows-gcc-14.2.0-mingw-64-bit.zip). (If you're on Windows 10 you might need [7z](https://github.com/ip7z/7zip/releases/download/26.05/7z2605-x64.msi)).
4. **Extract Files:** Extract both downloaded archives to `C:\`, then rename the `SFML-3.1.0` folder to exactly `SFML` (so the path is `C:\SFML`).
5. **Set System Variables:** Add `C:\SFML\bin` and `C:\mingw64\bin` to your system `PATH`, OR simply run `setup.bat` included in this repository.
6. **Open in VSCode:** Open this project folder in VSCode and write your SFML application in `main.cpp`.
7. **Compile & Run:**
   - **Windows:** Press `CTRL + SHIFT + B` or double-click `run.bat`.
   - **Linux:** Run `./run.sh` in your terminal.

> **Note:** Put all your images, audio files, fonts, and other assets inside the `build/assets/` directory.

---

## Build & Publish

When you are ready to share your application with others:

* **Windows:**
  1. Execute `run.bat` once to ensure all required DLLs and built files are generated
  2. Compress/zip the contents of the `build/` folder and share that `.zip`.
* **Linux:**
  1. Execute `run.sh` once
  2. Compress/zip the contents of the `build/` folder to distribute.

---

## Safe to Delete

To keep your workspace clean depending on your operating system:

* **Windows Developers:** You can safely delete `run.sh`, `build/lib/`, and `build/run_linux.sh`.
* **Linux Developers:** You can safely delete `run.bat`, `setup.bat`, and all `.dll` files in `build/` (`build/*.dll`).

---

## Further Links & Documentation

Ready to start coding? Begin reading the official SFML documentation here:
[SFML Tutorials (Window Module)](https://sfml-dev.org/tutorials/3.1/window/window)
