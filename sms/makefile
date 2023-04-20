SRC=main.cpp sms.cpp tests.cpp Telephone.cpp Reseau.cpp Message.cpp Media.cpp Son.cpp Image.cpp Video.cpp Mms.cpp
#SRC=$(wildcard *.cpp)  
EXE=sms

CXXFLAGS+=-Wall -Wextra -MMD -g -O2
LDFLAGS= 

OBJ=$(addprefix build/,$(SRC:.cpp=.o))
DEP=$(addprefix build/,$(SRC:.cpp=.d))

all: $(OBJ)
	$(CXX) -o $(EXE) $^ $(LDFLAGS)

build/%.o: %.cpp
	@mkdir -p build
	$(CXX) $(CXXFLAGS) -o $@ -c $<

clean:
	rm -rf build core *.gch

-include $(DEP)
