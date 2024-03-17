# Makefile

CC = g++  # 编译器

# 编译选项
CFLAGS = -Wall -g

# 测试样例
INPUT = 2.in

#测试输出
OUTPUT = out.txt

# 目标文件
TARGET = myprogram

# 源文件
SOURCES = xxx.cpp

# 头文件路径
INCLUDES = -I.

# 生成目标文件列表
OBJECTS = $(SOURCES:.cpp=.o)

# 默认目标，编译整个程序
all: $(TARGET)

# 链接目标文件生成可执行文件
$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) $(INCLUDES) -o $(TARGET) $(OBJECTS)
	./${TARGET} < ${INPUT} > ${OUTPUT}

# 生成目标文件
%.o: %.cpp
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@ 

# 清理生成的文件
clean:
	rm -f $(TARGET) $(OBJECTS)
