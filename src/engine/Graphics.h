#ifndef ASM_GRAPHICS_H
#define ASM_GRAPHICS_H

#include "utility/Color.h"
#include "utility/Vector2f.h"
#include "utility/Bounds2.h"
#include "Window.h"
#include <SDL_render.h>
#include <map>
#include "utility/Texture.h"
#include "Font.h"

class Graphics {
 public:
	enum TextureMirror {
		NONE = SDL_FLIP_NONE,
		HORIZONTAL = SDL_FLIP_HORIZONTAL,
		VERTICAL = SDL_FLIP_VERTICAL,
		BOTH = SDL_FLIP_HORIZONTAL | SDL_FLIP_VERTICAL
	};
	enum TextureBlendMode {
		NORMAL = SDL_BLENDMODE_BLEND,
		ADDITIVE = SDL_BLENDMODE_ADD
	};
	enum TextureScaleMode {
		NEAREST = SDL_ScaleModeNearest,
		LINEAR = SDL_ScaleModeLinear
	};
	enum TextAlignement {
		LEFT,
		CENTER,
		RIGHT
	};

	// Primitives
	static void drawLine(Vector2f start, Vector2f end, Color color);
	static void drawRectEmpty(Bounds2 bounds, Color color);
	static void drawRectSolid(Bounds2 bounds, Color color);

	// Textures
	static void drawTexture(Texture *texture, Vector2f position, Color color = Color::WHITE, Vector2f size = Vector2f(-1, -1), float rotation = 0, Vector2f pivot = Vector2f(-1, -1), TextureMirror mirror = NONE, Bounds2 source = Bounds2(-1, -1, -1, -1), TextureBlendMode blendMode = NORMAL, TextureScaleMode scaleMode = LINEAR);

	// Fonts
	static inline std::map<std::string, SDL_Texture*> textCache = {};
	static Bounds2 drawString(Font *font, std::string text, Vector2f position, Color color, TextAlignement alignement = LEFT, bool measureOnly = false);
 private:
	static void drawPrimitiveSetup(Color color);
	static void drawTextureSetup(SDL_Texture *textureHandle, Color color, TextureBlendMode blendMode, TextureScaleMode scaleMode);
};

#endif //ASM_GRAPHICS_H
