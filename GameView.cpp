#include "GameView.h"

GameView::GameView(GameModel& model) :model(model){
    if (!font.loadFromFile("../troika.otf")) {
 return;
    }

    scoreText.setFont(font);
    scoreText.setCharacterSize(34);
    scoreText.setFillColor(sf::Color::White);
    scoreText.setPosition(10, 10);
    updateScoreText();
}

void GameView::draw(sf::RenderWindow& window)
{
    sf::Texture p;
    p.loadFromFile("../images/snake_green_blob_32.png");
    sf::Sprite body(p);

       for (const auto& part : model.snake.getBody())
       {
           body.setPosition(part.first * 20, part.second * 20);
           window.draw(body);
       }
    p.loadFromFile("../images/snake_green_head_32.png");
    sf::Sprite head(p);
    std::pair <int, int> part = model.snake.getBody()[0];
    body.setPosition(part.first * 20, part.second * 20);
    window.draw(body);




    sf::Texture s;
    s.loadFromFile("../images/apple_alt_32.png");
    sf::Sprite apple(s);
    // Draw the food
    apple.setPosition(model.food.getPosition().first * 20, model.food.getPosition().second * 20);
    window.draw(apple);

    // Draw the score text
    window.draw(scoreText);
}
void GameView::updateScoreText()
{
    scoreText.setString("Score: " + std::to_string(model.getScore()));
}
