//
// Created by Julio Anzaldo on 3/22/22.
//

#include "Fonts.h"

std::vector<sf::Font> Fonts::fonts(LASTFONT, sf::Font());
std::vector<bool> Fonts::loadedFonts(LASTFONT, false);

std::string Fonts::getFontPath(FontNames fontNames)
{
    switch(fontNames)
    {
        case YAAHOWU : return "Fonts/Yaahowu.ttf";
        case ARIAL : return "Fonts/Arial.ttf";
        case AGENT : return "Fonts/Agent.ttf";
        case LASTFONT : break;
    }
}

std::string Fonts::toString(FontNames fontNames)
{
    switch(fontNames)
    {
        case YAAHOWU : return "Yaahowu";
        case ARIAL : return "Arial";
        case AGENT : return "Agent";
        case LASTFONT: break;
    }
}

void Fonts::loadFont(FontNames fontNames)
{
    loadFont(fontNames, getFontPath(fontNames));
}

sf::Font& Fonts::getFont(FontNames fontNames)
{
    loadFont(fontNames);
    return fonts[fontNames];
}

void Fonts::loadFont(FontNames fontNames, std::string filepath)
{
    if(!loadedFonts[fontNames])
    {
        if(!fonts[fontNames].loadFromFile(filepath))
        {
            loadedFonts[fontNames] = true;
        }
    }
}

void Fonts::loadFonts()
{
    loadFont(AGENT, "fonts/Agent.ttf");
}
