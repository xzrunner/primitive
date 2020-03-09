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
    m_values.resize(m_width * m_height * channels, 0);
}

template <typename T>
void Bitmap<T>::SetValues(const std::vector<T>& values)
{
    if (m_width * m_height * m_channels != values.size()) {
        return;
    }

    assert(m_values.size() == values.size());
    m_values = values;
}

}