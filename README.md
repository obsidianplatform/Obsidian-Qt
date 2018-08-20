# Obsidian-Qt - The Official ODN Wallets, supported by Obsidian Platform

Binaries for Windows, Ubuntu and MacOSX are available on the Releases tab:

https://github.com/obsidianplatform/Obsidian-Qt/releases


## Building Obsidian-QT
### Ubuntu
To install dependencies and build Obsidian-QT under Ubuntu,
open a terminal and then do the following:


clone the github repository
```
git clone https://github.com/obsidianplatform/Obsidian-Qt
```
move into Obsidian-Qt folder
```
cd Obsidian-Qt
```
run buildscript to build binarys,
when asked for a RPC-User and a RPC-Password,
choose a username and a secure password,
enter them and press **Enter**

```
./new-build.sh
```
This generates a folder called *binarys* where the newly build binarys for
*Obsidian-Qt* and *obsidiand* can be found.

#### staticaly linked builds
Statically linked builds are prefered when the binary should
be runnable on different other GNU/Linux systems then Ubuntu.
To build the binarys staticaly, just call the *new-build.sh*
with the *--static* parameter.
```
./new-build.sh --static
```
This builds the *Obsidian-QT* as well as *obsidiand* binarys staticaly.

## License

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.

Copyright (c) 2009-2018: see LICENSE

## Exclusion of Warranty and Liability
Warranty and Liability is excluded by the maximum possible extend allowed by the law.
