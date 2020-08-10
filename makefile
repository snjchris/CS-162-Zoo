#referenced makefile lecture and make help
CXX = g++
CXXFLAGS = -std=c++0x 
CXXFLAGS += -Wall 
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g
#CXXFLAGS += -O3
LDFLAGS = -lboost_date_time

OBJS = zoo.o animal.o tiger.o main.o penguin.o turtle.o

SRCS =zoo.cpp animal.cpp tiger.cpp main.cpp penguin.cpp turtle.cpp

HEADERS = zoo.hpp animal.hpp tiger.hpp penguin.hpp turtle.hpp 

lab1: ${OBJS} ${HEADERS}
	${CXX} ${LDFLAGS} ${OBJS} -o proj2

${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

clean:
	rm *.o proj2
