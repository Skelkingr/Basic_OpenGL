#include "Texture.h"

Texture::Texture()
    :
    m_ID(0)
{}

void Texture::Bind()
{
    glBindTexture(GL_TEXTURE_2D, m_ID);
}

bool Texture::Load(const std::string& fileName)
{
    SDL_Surface* textureData = IMG_Load(fileName.c_str());
    if (!textureData)
    {
        std::cout << "[ERR] Failed to load texture: " << fileName << std::endl;
        return false;
    }

    GLsizei width = textureData->w;
    GLsizei height = textureData->h;
    Uint8* pixels = (Uint8*)textureData->pixels;
    Uint8 depth = textureData->format->BytesPerPixel;
    GLint format = (depth == 4) ? GL_RGBA : GL_RGB;

    glGenTextures(1, &m_ID);

    glBindTexture(GL_TEXTURE_2D, m_ID);
    
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

        glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, pixels);
    
    glBindTexture(GL_TEXTURE_2D, 0);

    SDL_FreeSurface(textureData);

    return true;
}

void Texture::Unbind()
{
    glBindTexture(GL_TEXTURE_2D, 0);
}

void Texture::Unload()
{
    glDeleteTextures(1, &m_ID);
}
