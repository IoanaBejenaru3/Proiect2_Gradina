@rem
@echo off
g++ -c -o obj/Gradina.o src/Gradina.cpp
g++ -c -o obj/Floare.o src/Floare.cpp
g++ -c -o obj/Bujor.o src/Bujor.cpp
g++ -c -o obj/Trandafir.o src/Trandafir.cpp
g++ -c -o main.o main.cpp
g++ -o main main.o obj/Gradina.o obj/Floare.o obj/Bujor.o obj/Trandafir.o -g
main.exe
pause
@echo on