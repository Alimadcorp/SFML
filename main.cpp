#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

// SFML tutorials: https://sfml-dev.org/tutorials/3.1/window/window
using namespace sf;
using namespace std;

int main() {
  // declare a RenderWindow window
  RenderWindow window(VideoMode({600, 400}), "SFML");

  // create a loop that runs until window.isOpen()
  while (window.isOpen()) {
    // poll and process events
    while (const optional event = window.pollEvent()) {
      if (event->is<Event::Closed>())
        window.close();
    }

    window.clear(Color::Black);
    window.display();
  }

  return 0;
}