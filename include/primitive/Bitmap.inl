#pragma once

#include <assert.h>

namespace prim
{

template <typename T>
Bitmap<T>::Bitmap(size_t width, size_t height, size_t channels)
    : m_width(width)
    , m_height(height)
    , m_channels(channels)
{
    m_pixels = new T[m_width * m_height * channels];
}

template <typename T>
Bitmap<T>::~Bitmap()
{
    delete[] m_pixels;
}

}