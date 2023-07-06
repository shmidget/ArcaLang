all:
	cls
	@echo Compilation Starting...
	g++ -c src/*.cpp
	g++ -o main.exe *.o
	del *.o 
	@echo Running executable
	@.\main.exe tests/HelloWorld.arca
	@del main.exe 