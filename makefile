# Makefile

GCC=g++ -std=c++11
RELEASE_NAME=proj1
RELEASE_FILES=\
	makefile\
	LOG.txt\
	*.cpp\
	*.h\
	*.pdf


all: Dynamic.exe Memoized.exe

main.o: main.cpp algorithm.h
	${GCC} -c main.cpp

Dynamic.o: main.o Dynamic.cpp algorithm.h
	${GCC} -c Dynamic.cpp

Dynamic.exe: main.o Dynamic.o
	${GCC} -o Dynamic.exe Dynamic.o main.o

Memoized.o: main.o Memoized.cpp algorithm.h
	${GCC} -c Memoized.cpp

Memoized.exe: main.o Memoized.o
	${GCC} -o Memoized.exe Memoized.o main.o

clean:
	rm -f *.o *.exe *.tar

release:
	@echo "Creating project tar for turn in..."
	tar cf ${RELEASE_NAME}.tar ${RELEASE_FILES}
