#include <SFML/Graphics.hpp>

int main() {
    // Crear una ventana de 800x600 píxeles
    sf::RenderWindow window(sf::VideoMode(800, 600), "Crosshair");

    // Cargar la textura del crosshair
    sf::Texture crosshairTexture;
    if (!crosshairTexture.loadFromFile("ruta/al/archivo/crosshair.png")) {
        return -1; // Asegúrate de que la imagen está en la carpeta adecuada
    }

    // Crear el sprite del crosshair
    sf::Sprite crosshairSprite;
    crosshairSprite.setTexture(crosshairTexture);

    // Centrar el crosshair en la pantalla
    crosshairSprite.setPosition(
        (window.getSize().x - crosshairSprite.getGlobalBounds().width) / 2,
        (window.getSize().y - crosshairSprite.getGlobalBounds().height) / 2
    );

    // Loop principal
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        // Limpiar la pantalla, dibujar el crosshair y mostrar
        window.clear();
        window.draw(crosshairSprite);
        window.display();
    }

    return 0;
}