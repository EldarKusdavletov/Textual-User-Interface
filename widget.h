#ifndef WIDGET_H
#define WIDGET_H

#include <iostream>
using namespace std;

class widget {
public:
    virtual ~widget() {}
    virtual widget* copy() const = 0;
    virtual char char_at(unsigned int x, unsigned int y, unsigned int width, unsigned int height) const = 0;
};

class label : public widget {
    string s;
public:
    label(string s) : s(s) {}
    widget* copy() const { return new label(this->s); }
    char char_at(unsigned int, unsigned int, unsigned int, unsigned int) const;
};

class checkerboard : public widget {
    char a, b;
public:
    checkerboard(char a, char b) : a(a), b(b) {}
    widget* copy() const { return new checkerboard(this->a, this->b); }
    char char_at(unsigned int, unsigned int, unsigned int, unsigned int) const;
};

class stretchy : public widget {
public:
    stretchy() {}
    widget* copy() const { return new stretchy(); }
    char char_at(unsigned int, unsigned int, unsigned int, unsigned int) const;
};

class vertical_split : public widget {
    widget *a, *b;
public:
    vertical_split(widget *a, widget *b) : a(a), b(b) {}
    ~vertical_split() { delete a; delete b; }
    vertical_split(vertical_split const &other) : a(other.a->copy()), b(other.b->copy()) {}
    vertical_split& operator=(vertical_split const &other) {
        delete this->a; delete this->b;
        this->a = other.a->copy(); this->b = other.b->copy();
        return *this;
    }
    widget* copy() const { return new vertical_split(this->a->copy(), this->b->copy()); }
    char char_at(unsigned int, unsigned int, unsigned int, unsigned int) const;
};

class window : public widget {
    widget *a;
public:
    window(widget *a) : a(a) {}
    ~window() { delete a; }
    window(window const &other) : a(other.a->copy()) {}
    window& operator=(window const &other) {
        delete this->a;
        this->a = other.a->copy();
        return *this;
    }
    widget* copy() const { return new window(this->a->copy()); }
    char char_at(unsigned int, unsigned int, unsigned int, unsigned int) const;
};

class overlapping : public widget {
    widget *a;
    widget *b;
public:
    overlapping(widget *a, widget *b) : a(a), b(b) {}
    ~overlapping() { delete a; delete b; }
    overlapping(overlapping const &other) : a(other.a->copy()), b(other.b->copy()) {}
    overlapping& operator=(overlapping const &other) {
        delete this->a; delete this->b;
        this->a = other.a->copy(); this->b = other.b->copy();
        return *this;
    }
    widget* copy() const { return new overlapping(this->a->copy(), this->b->copy()); }
    char char_at(unsigned int, unsigned int, unsigned int, unsigned int) const;
};

#endif