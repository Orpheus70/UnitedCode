# Определяем компилятор и флаги

CC = g++.exe
CFLAGS = -Wall -g

# Определяем имена файлов
EXE_NAME = main.exe

# Исходные файлы
EXE_SOURCES = main.cpp

# Правило по умолчанию
all: $(EXE_NAME) 


# Правило для сборки EXE
$(EXE_NAME): $(EXE_SOURCES)
	$(CC) $(CFLAGS) -L. -l PulseReader -l Level -l tomom -l port -o $@ $^

# Правило для очистки
clean:
	rm -f $(EXE_NAME)
