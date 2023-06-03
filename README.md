# Textual-User-Interface

C++ implementation of a simple TUI (Textual User Interface).

There are written a number of TUI elements, described below, that renders graphically to ASCII text.  
All of them from a common **widget** abstract class.

*label*  
Renders a simple string, all on one line. For any y coordinate other than 0, or for any x coordinate
beyond the length of the string, simply returns a space character. Otherwise, returns the appropriate
character from the string. If the string is too long for the given width, then the last three characters
returned are ...

*checkerboard*  
Renders two characters, over and over again, in a checkerboard pattern. For example, if
the two characters are A and B, then even-numbered rows would be rendered ABABABAB... and so on,
and odd-numbered rows would be rendered BABABABA...

*stretchy*  
Renders a pattern that looks like something being stretched vertically. All characters on the
top-most and bottom-most rows are . (period). All characters on the 2nd top-most and 2nd bottom-most rows are : (full colon). All characters in the middle rows (if there are any) are | (vertical bar). 

*vertical split*  
Composed of two pointers to widget objects, a “top” and a “bottom”. If the height of
the vertical split as a whole is h, then the height of the top element is ⌊h / 2⌋ and the height of the bottom element is ⌈h / 2⌉.

*window*  
Displays a frame around another widget object. The frame is composed of - (hyphen), | (vertical bar) and + (plus) symbols. 

*overlapping*  
Composed of two pointers to widget objects, the “back” and the “front”. If the dimensions of the overlapping are w and h, then the dimensions of the back and front are ⌊2w / 3⌋ and ⌊2h / 3⌋. The “back” widget is in the upper-left and is partially obscured by the “front“ widget, which is in the bottom-right.
