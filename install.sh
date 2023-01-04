cmake -B build -S . -DCMAKE_BUILD_TYPE=Release
cmake --build build --parallel

sudo cmake --install build --prefix /usr/local

## OR

# qmake
# make
# sudo make install DESTDIR=/usr/local