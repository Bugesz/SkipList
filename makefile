all: main

main: main.cpp
	g++ -O3 main.cpp -o main -w

clean:
	rm main
