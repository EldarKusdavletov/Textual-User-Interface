#include "widget.h"

char label::char_at(unsigned int x, unsigned int y, unsigned int width, unsigned int height) const {
    if (y != 0 || x >= s.size()) return ' ';
    if (s.size() > width && x >= width - 3) return '.';
    return s[x];
}

char checkerboard::char_at(unsigned int x, unsigned int y, unsigned int width, unsigned int height) const {
    if ((x + y) % 2) return a;
    return b;
}

char stretchy::char_at(unsigned int x, unsigned int y, unsigned int width, unsigned int height) const {
    if (y == 0 || y == height - 1) return '.';
    if (y == 1 || y == height - 2) return ':';
    return '|';
}

char vertical_split::char_at(unsigned int x, unsigned int y, unsigned int width, unsigned int height) const {
    int top = height / 2;
    if (y < top) return a->char_at(x, y, width, top);
    return b->char_at(x, y - top, width, height - top);
}

char window::char_at(unsigned int x, unsigned int y, unsigned int width, unsigned int height) const {
    if ((x == 0 || x == width - 1) && (y == 0 || y == height - 1)) return '+';
    if (x == 0 || x == width - 1) return '|';
    if (y == 0 || y == height - 1) return '-';
    return a->char_at(x - 1, y - 1, width - 2, height - 2);
}

char overlapping::char_at(unsigned int x, unsigned int y, unsigned int width, unsigned int height) const {
    int new_width = 2 * width / 3, new_height = 2 * height / 3;
    if (x >= width - new_width && y >= height - new_height) return b->char_at(x - (width - new_width), y - (height - new_height), new_width, new_height);
    if (x < new_width && y < new_height) return a->char_at(x, y, new_width, new_height);
    return ' ';
}