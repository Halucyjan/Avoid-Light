#include "End.h"

End::End(float _x, float _y)
{
    pos.x = _x;
    pos.y = _y;

    end.setRadius(rad);
    end.setFillColor(sf::Color::Green);
    end.setPosition(pos);
}

void End::draw(sf::RenderWindow& window)
{
    window.draw(end);
}
