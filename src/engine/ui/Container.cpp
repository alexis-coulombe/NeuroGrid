#include "Container.h"
#include "../Graphics.h"
#include "../utility/Asset.h"

SDL_Rect rectToDraw;

Container::Container(Bounds2 bounds) : bounds(bounds) {
  rectToDraw = {(int) bounds.position.x,(int) bounds.position.y,(int) bounds.size.x,(int) bounds.size.y};
}

void Container::render() {
  rectToDraw = {(int) bounds.position.x,(int) bounds.position.y,(int) bounds.size.x,(int) bounds.size.y};

  SDL_SetRenderDrawColor(Window::renderer,  255, 0, 0, 255);
  SDL_RenderDrawRect(Window::renderer, &rectToDraw);
}

void Container::setBounds(Bounds2 newBounds) {
  this->bounds = newBounds;
}