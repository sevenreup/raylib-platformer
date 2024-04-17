prepare: 
	cmake --preset=default

@build: src/main.cpp
	cmake --build build

run: src/main.cpp
	cmake --build build
	./build/Platformer.exe