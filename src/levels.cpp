#include "Levels.hpp"
#include "GameObject.hpp"
#include "Player.hpp"
#include "Globals.hpp"
#include "utils.hpp"
#include <SDL.h>
#include <iostream>
#include <vector>

//calls the function fitting for the stage and returns the vector generated by the function

std::vector<std::vector<Tile*>>* levels::setUpLevel(int p_level, SDL_Renderer* p_renderer)
{
	switch(p_level)
	{
		case 1:
			return(setUpLevel1(p_renderer));
            break;
		default:
			std::cout << "Error: Level does not exist: Level " << p_level << "\n";
            return(NULL);
	}
}

//sets up all tiles for level 1 in a 2d vector and returns a pointer to it

std::vector<std::vector<Tile*>>* levels::setUpLevel1(SDL_Renderer* p_renderer)
{
	int rows {constants::window::h/(constants::tileSprite::h*constants::scale)};
	int columns {constants::window::w/(constants::tileSprite::w*constants::scale)};

	std::vector<std::vector<Tile*>>* tiles = new std::vector<std::vector<Tile*>>(rows, std::vector<Tile*>(columns, NULL));

    SDL_Texture* grassTexture = utils::loadTexture("../res/tileset/sortedTileset.png", p_renderer);

	for (int i = 0; i < rows; ++i) 
	{
		switch(i)
		{
			case 10:
				(*tiles)[i][7] = new Tile(grassTexture, utils::createRect(0, 0, constants::tileSprite::w, constants::tileSprite::h)
										  	  , utils::createRect(7*constants::scale*constants::tileSprite::w, i*constants::scale*constants::tileSprite::h
										  	  , constants::tileSprite::w*constants::scale, constants::tileSprite::h*constants::scale));
				break;
			case 11:
				for (int j = 5; j < columns; ++j)
				{
					(*tiles)[i][j] = new Tile(grassTexture, utils::createRect(0, 0, constants::tileSprite::w, constants::tileSprite::h)
										  	  , utils::createRect(j*constants::scale*constants::tileSprite::w, i*constants::scale*constants::tileSprite::h
										  	  , constants::tileSprite::w*constants::scale, constants::tileSprite::h*constants::scale));
				}	
				break;
			default:
				if(i >= 12)
				{
					for(int j = 0; j < columns; ++j)
					{
							(*tiles)[i][j] = new Tile(grassTexture, utils::createRect(0, 0, constants::tileSprite::w, constants::tileSprite::h)
										  			  , utils::createRect(j*constants::scale*constants::tileSprite::w, i*constants::scale*constants::tileSprite::h
										  		 	  , constants::tileSprite::w*constants::scale, constants::tileSprite::h*constants::scale));
					}
				}
				break;	
		}
    }

	utils::selectTiles(*tiles);	

	return(tiles);
}