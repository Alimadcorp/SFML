@echo off
g++ -std=c++17 main.cpp -I"C:/SFML/include" -L"C:/SFML/lib" -lsfml-graphics -lsfml-window -lsfml-system -lsfml-network -lsfml-audio -lopengl32 -lglu32 -o build/game.exe
if %errorlevel% equ 0 (
    cd build
    game.exe
    cd ..
)
pause
