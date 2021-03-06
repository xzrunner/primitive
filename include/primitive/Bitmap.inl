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
    auto sz = m_width * m_height * channels;
    try {
        m_pixels = new T[sz];
    } catch (...) {
        m_pixels = nullptr;
    }
    if (m_pixels) {
        memset(m_pixels, 0, sizeof(T) * sz);
    }
}

template <typename T>
Bitmap<T>::~Bitmap()
{
    delete[] m_pixels;
}

}