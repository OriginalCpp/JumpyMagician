#include "GameObject.hpp"
#include <SDL.h>


GameObject::GameObject(){}

GameObject::GameObject(SDL_Texture* p_texture, SDL_Rect p_src, SDL_Rect p_dst, int p_w, int p_h)
	:texture{ p_texture }, x{ static_cast<float>(p_dst.x) }, y{ static_cast<float>(p_dst.y) }, src{p_src}, dst{p_dst}, w{p_w}, h{p_h}
{}

SDL_Texture* GameObject::getTexture()
{
	return(texture);
}

SDL_Rect* GameObject::getSrc()
{
	return(&src);
}

SDL_Rect* GameObject::getDst()
{
	return(&dst);
}

float GameObject::getX()
{
	return x;
}

float GameObject::getY()
{
	return y;
}

void GameObject::setX(float p_x)
{
	x = p_x;
}

void GameObject::setY(float p_y)
{
	y = p_y;
}

float* GameObject::getVector() {
	return(vector);
}

void GameObject::setVector(float p_x, float p_y) {
	vector[0] = p_x;
	vector[1] = p_y;
}

int GameObject::getH()
{
	return h;
}

int GameObject::getW()
{
	return w;
}

float* GameObject::getpP()
{
	return previousPos;
}