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
	widget *w = new window(new vertical_split(new label("This is some text"), new label("and some more text")));
	print(cout, *w, 20, 10);
	delete w;
	return 0;
}
