# Определяем компилятор и флаги

CC = g++.exe
CFLAGS = -Wall -g

# Определяем имена файлов
DLL_NAME1 = Level.dll
DLL_NAME2 = PulseReader.dll
EXE_NAME = main.exe

# Исходные файлы
DLL_SOURCES2 = PulseReader.cpp
DLL_SOURCES1 = Level.cpp 
EXE_SOURCES = main.cpp

# Правило по умолчанию
all: $(DLL_NAME1) $(DLL_NAME2) $(EXE_NAME) 

# Правило для сборки DLL
$(DLL_NAME1): $(DLL_SOURCES1)
	$(CC) $(CFLAGS) -shared -o $@ $^

$(DLL_NAME2): $(DLL_SOURCES2)
	$(CC) $(CFLAGS) -shared -o $@ $^

# Правило для сборки EXE
$(EXE_NAME): $(EXE_SOURCES)
	$(CC) $(CFLAGS) -L. -l PulseReader -l Level -o $@ $^

# Правило для очистки
clean:
	rm -f $(DLL_NAME1) $(DLL_NAME2) $(EXE_NAME) 
