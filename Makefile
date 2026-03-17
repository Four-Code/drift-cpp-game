CXX = g++
CXXFLAGS = -g -std=c++17 -I. -MMD -MP
LDFLAGS = -lsfml-graphics -lsfml-window -lsfml-system

SRC = $(shell find . -name "*.cpp" -not -path "./.vscode/*")
OBJ = $(SRC:.cpp=.o)

app: $(OBJ)
	$(CXX) $(OBJ) -o app $(LDFLAGS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) app

-include $(OBJ:.o=.d)