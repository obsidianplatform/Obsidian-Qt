# Obsidian Qt Wallet

# Build for Linux
The build has been tested on Unbuntu 16.04 LTS and on Windows 10 WSL with Ubuntu 16.04.

The process for the headless daemon is as follows:
git clone https://github.com/obsidianplatform/obsidian-qt.git
cd obsidian-qt
sudo ./build.sh

Type ps ax to check the daemon is running. Stop the daemon with sudoi kill [pid]

To build the Qt Wallet, please build the daemon first, as the script installs dependencies. Then run

qmake
make

This will build obsidian-qt. Run it with sudo ./obsidian-qt.

To run the Qt Wallet on Windows, you need to install an X server, like XMing and start it. To run the Linux version on Windows, type:

sudo DISPLAY=localhost:0.0 ./obsidian-qt

sudo DISPLAY=localhost:0.0 ./obsidian-qt -connect=40.68.27.143:56660

Including libsodium for SHA 512
==============================================================
libsodium must first be installed:
wget https://download.libsodium.org/libsodium/releases/LATEST.tar.gz
tar -xvzf LATEST.tar.gz
cd libsodium-1.0.13
./configure
make && make check
make install
ldconfig

update makefile,unix like so:
xLDFLAGS=$(LDHARDENING) $(LDFLAGS) -lsodium

use it in the source:
#include <sodium.h>
..
 if (sodium_init() == -1) {
        return 1;
    }
    fprintf(stdout, "libsodium is working correctly!");

build the daemon:
./quickbuild
-> done, works!


Development process
===========================

Developers work in their own trees, then submit pull requests when
they think their feature or bug fix is ready.

The patch will be accepted if there is broad consensus that it is a
good thing.  Developers should expect to rework and resubmit patches
if they don't match the project's coding conventions (see coding.txt)
or are controversial.

The master branch is regularly built and tested, but is not guaranteed
to be completely stable. Tags are regularly created to indicate new
stable release versions of Obsidian.

Feature branches are created when there are major new features being
worked on by several people.

From time to time a pull request will become outdated. If this occurs, and
the pull is no longer automatically mergeable; a comment on the pull will
be used to issue a warning of closure. The pull will be closed 15 days
after the warning if action is not taken by the author. Pull requests closed
in this manner will have their corresponding issue labeled 'stagnant'.

Issues with no commits will be given a similar warning, and closed after
15 days from their last activity. Issues closed in this manner will be 
labeled 'stale'.
