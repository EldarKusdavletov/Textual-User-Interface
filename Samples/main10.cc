// 60x30 rendering
#include "widget.h"
#include <iostream>

using namespace std;

static void print(ostream &out, widget const &root, unsigned int w, unsigned int h) {
	for (unsigned int y = 0; y < h; y++) {
		for (unsigned int x = 0; x < w; x++)
			out << root.char_at(x, y, w, h);
		out << '\n';
	}
	out << flush;
}

int main() {
	widget *w =
    new overlapping(
        new window(
            new vertical_split(
                new vertical_split(
                    new label("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"),
                    new window(
                        new stretchy)),
                new vertical_split(
                    new label("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"),
                    new window(
                        new stretchy())))),
        new window(
            new overlapping(
                new checkerboard('.', '.'),
                new window(
                    new stretchy()))));
	print(cout, *w, 60, 30);
	delete w;
	return 0;
}
