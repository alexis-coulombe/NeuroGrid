#include "Graphics.h"

void Graphics::drawPrimitiveSetup(Color color) {
	SDL_SetRenderDrawColor(Window::renderer, color.R, color.G, color.B, color.A);
	SDL_SetRenderDrawBlendMode(Window::renderer, SDL_BLENDMODE_BLEND);
}

void Graphics::drawLine(Vector2f start, Vector2f end, Color color) {
	drawPrimitiveSetup(color);

	SDL_RenderDrawLine(Window::renderer, (int)start.x, (int)start.y, (int)end.x, (int)end.y);
}

void Graphics::drawRectEmpty(Bounds2 bounds, Color color) {
	drawPrimitiveSetup(color);

	SDL_Rect rect = {(int)bounds.position.x, (int)bounds.position.y, (int)bounds.size.x, (int)bounds.size.y};
	SDL_RenderDrawRect(Window::renderer, &rect);
}

void Graphics::drawRectSolid(Bounds2 bounds, Color color) {
	drawPrimitiveSetup(color);

	SDL_Rect rect = {(int)bounds.position.x, (int)bounds.position.y, (int)bounds.size.x, (int)bounds.size.y};
	SDL_RenderFillRect(Window::renderer, &rect);
}

void Graphics::drawTextureSetup(SDL_Texture *textureHandle, Color color, Graphics::TextureBlendMode blendMode, Graphics::TextureScaleMode scaleMode) {
	SDL_SetTextureColorMod(textureHandle, color.R, color.G, color.B);
	SDL_SetTextureAlphaMod(textureHandle, color.A);
	SDL_SetTextureBlendMode(textureHandle, (SDL_BlendMode)blendMode);
	SDL_SetTextureScaleMode(textureHandle, (SDL_ScaleMode)scaleMode);
}

void Graphics::drawTexture(Texture *texture, Vector2f position, Color color, Vector2f size, float rotation, Vector2f pivot, Graphics::TextureMirror mirror, Bounds2 source, Graphics::TextureBlendMode blendMode, Graphics::TextureScaleMode scaleMode) {
	drawTextureSetup(texture->handle, color, blendMode, scaleMode);

	SDL_Rect src;
	SDL_Rect dest;

	if (source.position.x != -1 && source.position.y != -1 && source.size.x != -1 && source.size.y != -1) {
		src.x = (int)source.position.x;
		src.y = (int)source.position.y;
		src.w = (int)source.size.x;
		src.h = (int)source.size.y;
		dest.x = (int)position.x;
		dest.y = (int)position.y;
		dest.w = (int)src.w;
		dest.h = (int)src.h;
	} else {
		src.x = 0;
		src.y = 0;
		src.w = texture->width;
		src.h = texture->height;
		dest.x = (int)position.x;
		dest.y = (int)position.y;
		dest.w = texture->width;
		dest.h = texture->height;
	}

	if (size.x != -1 && size.y != -1) {
		dest.w = (int)size.x;
		dest.h = (int)size.y;
	}

	SDL_Point center;

	if (pivot.x == -1 && pivot.y == -1) {
		center.x = dest.w / 2;
		center.y = dest.h / 2;
	} else {
		center.x = (int)pivot.x;
		center.y = (int)pivot.y;
	}

	SDL_RenderCopyEx(Window::renderer, texture->handle, &src, &dest, rotation, &center, (SDL_RendererFlip)mirror);
}

Bounds2 Graphics::drawString(Font *font, std::string text, Vector2f position, Color color, Graphics::TextAlignement alignement, bool measureOnly) {
	SDL_Color white = SDL_Color{255, 255, 255, 255};
	SDL_Texture *handle = nullptr;

	if (textCache.find(text + std::to_string(font->pointSize)) != textCache.end()) {
		handle = textCache[text + std::to_string(font->pointSize)];
	} else {
		SDL_Surface *surface = TTF_RenderText_Solid(font->handle, text.c_str(), white);
		handle = SDL_CreateTextureFromSurface(Window::renderer, surface);
		SDL_FreeSurface(surface);

		textCache[text + std::to_string(font->pointSize)] = handle;
	}

	uint format;
	int access, width, height;
	SDL_QueryTexture(handle, &format, &access, &width, &height);

	if (alignement == CENTER) {
		position.x -= (float)width / 2;
	} else if (alignement == RIGHT) {
		position.x -= (float)width;
	}

	if (!measureOnly) {
		Texture texture = Texture(handle, width, height);
		drawTexture(&texture, position, color);
	}

	return Bounds2(position, Vector2f((float)width, (float)height));
}