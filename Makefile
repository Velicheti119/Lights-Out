CXX = g++
CXXFLAGS = -std=c++14 -Werror=vla
OBJECTS = cell.o grid.o subject.o textdisplay.o main.o
DEPENDS = ${OBJECTS:.o}
EXEC = a4q3

${EXEC} : ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

clean :
	rm ${DEPENDS} ${OBJECTS}

-include ${DEPENDS}
