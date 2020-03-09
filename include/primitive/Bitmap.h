#pragma once

#include <vector>

namespace prim
{

template <typename T>
class Bitmap
{
public:
    Bitmap(size_t width, size_t height, size_t channels = 3);

    size_t Width() const { return m_width; }
    size_t Height() const { return m_height; }

    size_t Channels() const { return m_channels; }

    auto& GetValues() const { return m_values; }
    void SetValues(const std::vector<T>& values);

protected:
    size_t m_width = 0, m_height = 0;
    size_t m_channels = 3;

    std::vector<T> m_values;

}; // Bitmap

}

#include "primitive/Bitmap.inl"