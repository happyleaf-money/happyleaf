
Debian
====================
This directory contains files used to package happyleafd/happyleaf-qt
for Debian-based Linux systems. If you compile happyleafd/happyleaf-qt yourself, there are some useful files here.

## happyleaf: URI support ##


happyleaf-qt.desktop  (Gnome / Open Desktop)
To install:

	sudo desktop-file-install happyleaf-qt.desktop
	sudo update-desktop-database

If you build yourself, you will either need to modify the paths in
the .desktop file or copy or symlink your happyleafqt binary to `/usr/bin`
and the `../../share/pixmaps/happyleaf128.png` to `/usr/share/pixmaps`

happyleaf-qt.protocol (KDE)

