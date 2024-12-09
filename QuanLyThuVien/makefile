# Tên file thực thi
TARGET = LibrarySystemApp

# Trình biên dịch
CXX = C:/mingw64/bin/g++.exe

# Cờ biên dịch
CXXFLAGS = -Wall -std=c++11

# Các tệp nguồn và tệp đầu ra
SRC = main.cpp Book.cpp Member.cpp LoanRecord.cpp LibrarySystem.cpp Date.cpp
OBJ = $(SRC:.cpp=.o)

# Quy tắc mặc định: biên dịch toàn bộ
all: $(TARGET)

# Quy tắc để tạo tệp thực thi
$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJ)

# Quy tắc để biên dịch từng tệp .cpp thành .o
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Quy tắc làm sạch tệp .o và thực thi
clean:
	rm -f $(OBJ) $(TARGET)





