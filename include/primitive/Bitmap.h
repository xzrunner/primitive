#pragma once

#include <vector>

namespace prim
{

template <typename T>
class Bitmap
{
public:
    Bitmap(size_t width, size_t height, size_t channels = 3);
    ~Bitmap();

    size_t Width() const { return m_width; }
    size_t Height() const { return m_height; }

    size_t Channels() const { return m_channels; }

    T* GetPixels() { return m_pixels; }
    const T* GetPixels() const { return m_pixels; }

protected:
    size_t m_width = 0, m_height = 0;
    size_t m_channels = 3;

    T* m_pixels;

}; // Bitmap

}

#include "primitive/Bitmap.inl"