dmenu - dynamic menu
====================

My favourite/custom dmenu patch.


Includes the following Patches:
- [border](https://tools.suckless.org/dmenu/patches/border/ "dmenu-border")
- [Line height](https://tools.suckless.org/dmenu/patches/line-height/ "dmenu-line-height")
- [center](https://tools.suckless.org/dmenu/patches/center/ "dmenu-center")
- [fuzzymatch](https://tools.suckless.org/dmenu/patches/fuzzymatch/ "dmenu-fuzzymatch")
- [fuzzyhighlight](https://tools.suckless.org/dmenu/patches/fuzzyhighlight/ "dmenu-fuzzyhighlight")
- [numbers](https://tools.suckless.org/dmenu/patches/numbers/ "dmenu-numbers")

Requirements
------------
- dmenu 4.9 
- Xlib header files.

Installation
-------------

    ~$ sudo apt-get install libxcb-xinerama0
    ~$ git clone https://git.suckless.org/dmenu
    ~$ cd dmenu
    ~$ sudo make install

Usage
-----
    Usage: dmenu_run [OPTION] ...

       -c     dmenu appears centered on the screen.

       -i     dmenu matches menu items case insensitively.

       -bw pixel
              Size of the window border

       -l lines
              dmenu lists items vertically, with the given number of lines.

       -h height
              dmenu uses a menu line of at least 'height' pixels tall, but no less than 8.
