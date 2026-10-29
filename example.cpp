#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <cmath>

using namespace sf;
using namespace std;

// game state variables
float p1_y = 300.f;
float p2_y = 300.f;
float bx = 400.f;
float by = 300.f;
float vx = 5.f;
float vy = 2.f;
int s1 = 0;
int s2 = 0;

int main() {
    RenderWindow win(VideoMode({800, 600}), "Pong");
    win.setVerticalSyncEnabled(true);

    // font and text for rendering score
    Font font("assets/font.ttf");

    Text txt(font);
    txt.setCharacterSize(30);
    txt.setFillColor(Color::White);

    // shapes for rendering
    RectangleShape p1({15.f, 100.f});
    p1.setOrigin({7.5f, 50.f});

    RectangleShape p2({15.f, 100.f});
    p2.setOrigin({7.5f, 50.f});

    CircleShape ball(8.f);
    ball.setOrigin({8.f, 8.f});

    RectangleShape net({2.f, 600.f});
    net.setPosition({400.f, 0.f});
    net.setFillColor(Color(100, 100, 100));

    // TODO: try out this cool trail effect by uncommenting the lines below and the lines at the end of code:
    // RectangleShape fade({800.f, 600.f});
    // fade.setPosition({0.f, 0.f}); // covers the whole screen
    // fade.setOutlineThickness(0.f); // disable outline
    // fade.setFillColor(Color(0.f, 0.f, 0.f, 150.f));

    while (win.isOpen()) {
        while (const auto ev = win.pollEvent()) {
            if (ev->is<Event::Closed>()) win.close();
        }

        // input and paddle movement
        if (Keyboard::isKeyPressed(Keyboard::Key::W) && p1_y > 50.f) p1_y -= 7.f;
        if (Keyboard::isKeyPressed(Keyboard::Key::S) && p1_y < 550.f) p1_y += 7.f;
        if (Keyboard::isKeyPressed(Keyboard::Key::Up) && p2_y > 50.f) p2_y -= 7.f;
        if (Keyboard::isKeyPressed(Keyboard::Key::Down) && p2_y < 550.f) p2_y += 7.f;

        // update ball position
        bx += vx;
        by += vy;

        // wall collision (top and bottom)
        if (by - 8.f <= 0.f || by + 8.f >= 600.f) {
            vy = -vy;
        }

        // manual left paddle collision math (aabb check)
        if (vx < 0.f && bx - 8.f <= 37.5f && bx + 8.f >= 22.5f) {
            if (by + 8.f >= p1_y - 50.f && by - 8.f <= p1_y + 50.f) {
                float diff = (by - p1_y) / 50.f; // normalize hit offset from -1 to 1
                float speed = sqrt(vx * vx + vy * vy) * 1.05f;
                float angle = diff * 0.8f; // angle factor
                vx = speed * cos(angle);
                vy = speed * sin(angle);
            }
        }

        // manual right paddle collision math (aabb check)
        if (vx > 0.f && bx + 8.f >= 762.5f && bx - 8.f <= 777.5f) {
            if (by + 8.f >= p2_y - 50.f && by - 8.f <= p2_y + 50.f) {
                float diff = (by - p2_y) / 50.f;
                float speed = sqrt(vx * vx + vy * vy) * 1.05f;
                float angle = diff * 0.8f;
                vx = -speed * cos(angle);
                vy = speed * sin(angle);
            }
        }

        // scoring and reset
        if (bx < 0.f) {
            s2++;
            bx = 400.f;
            by = 300.f;
            vx = 5.f;
            vy = 2.f;
        }
        if (bx > 800.f) {
            s1++;
            bx = 400.f;
            by = 300.f;
            vx = -5.f;
            vy = 2.f;
        }

        // update visual positions from state variables
        p1.setPosition({30.f, p1_y});
        p2.setPosition({770.f, p2_y});
        ball.setPosition({bx, by});

        // drawing

        // clear the window before next draw
        win.clear(Color::Black);
        // TODO: comment the ^ line above and uncomment the one below to enable the trail effect:
        // win.draw(fade);

        win.draw(net);
        win.draw(p1);
        win.draw(p2);
        win.draw(ball);

        // draw score text
        txt.setString(to_string(s1));
        txt.setPosition({350.f, 20.f});
        win.draw(txt);

        txt.setString(to_string(s2));
        txt.setPosition({430.f, 20.f});
        win.draw(txt);

        win.display();
    }

    return 0;
}
