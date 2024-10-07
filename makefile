# Compiler and compiler flags
CXX = g++
CXXFLAGS = -std=c++11 -Wall

# Executable name
TARGET = smart_home

# Source files
SRCS = TestingMain.cpp Subject.h Observers.h MotionSensor.cpp Alarm.cpp Lights.cpp Doors.cpp Command.h MacroRoutine.cpp OnOffCommand.cpp LockDoorCommand.cpp UnLockDoorCommand.cpp

# Object files
OBJS = $(SRCS:.cpp=.o)

# Default target to build the executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Rule to build object files from source files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Run the executable
run: $(TARGET)
	./$(TARGET)

# Clean up build files
clean:
	rm -f $(OBJS) $(TARGET)

# Phony targets
.PHONY: clean run
