# Определяем компилятор и флаги

CC = g++.exe
CFLAGS = -Wall -g

# Определяем имена файлов
DLL_NAME1 = PulseReader.dll
DLL_NAME2 = Level.dll
DLL_NAME3 = tomom.dll
DLL_NAME4 = port.dll
EXE_NAME = main.exe

# Исходные файлы
DLL_SOURCES1 = PulseReader.cpp
DLL_SOURCES2 = Level.cpp
DLL_SOURCES3 = tomom.cpp
DLL_SOURCES4 = port.cpp 
EXE_SOURCES = main.cpp

# Правило по умолчанию
all: $(DLL_NAME1) $(DLL_NAME2) $(DLL_NAME3) $(DLL_NAME4) $(EXE_NAME) 

# Правило для сборки DLL
$(DLL_NAME1): $(DLL_SOURCES1)
	$(CC) $(CFLAGS) -shared -o $@ $^

$(DLL_NAME2): $(DLL_SOURCES2)
	$(CC) $(CFLAGS) -shared -o $@ $^

$(DLL_NAME3): $(DLL_SOURCES3)
	$(CC) $(CFLAGS) -shared -o $@ $^

$(DLL_NAME4): $(DLL_SOURCES4)
	$(CC) $(CFLAGS) -shared -o $@ $^

# Правило для сборки EXE
$(EXE_NAME): $(DLL_NAME1) $(DLL_NAME2) $(DLL_NAME3) $(DLL_NAME4) $(EXE_SOURCES)
	$(CC) $(CFLAGS) -L. -l PulseReader -l Level -l tomom -l port -o $@ $^

# Правило для очистки
clean:
	rm -f $(DLL_NAME1) $(DLL_NAME2) $(DLL_NAME3) $(DLL_NAME4) $(EXE_NAME)
