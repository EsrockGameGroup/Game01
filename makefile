
FILES = $(notdir $(wildcard src/*.cpp))

SRCS = $(patsubst %.cpp,src/%.cpp,$(FILES))
OBJS = $(patsubst %.cpp,obj/%.o,$(FILES))

TARGET = Esrock.exe

$(TARGET): $(OBJS)
	g++ -Iinc $(OBJS) -o $(TARGET) -lsfml-graphics -lsfml-window -lsfml-system

obj/%.o: src/%.cpp
	g++ -Iinc -std=c++11 -c $< -o $@

clean:
	@rm -f obj/* 2> /dev/null
	@rm -f $(TARGET) 2> /dev/null