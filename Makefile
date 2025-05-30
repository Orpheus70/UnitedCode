CC = g++
CFLAGS = -Wall -g

# Определяем имена файлов
DLL_NAME1 = tomom.dll
DLL_NAME2 = port.dll
EXE_NAME = main.exe

# Исходные файлы
DLL_SOURCES1 = tomom.cpp
DLL_SOURCES2 = port.cpp  
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
	$(CC) $(CFLAGS) -L. -l tomom -l port -o $@ $^

# Правило для очистки
clean:
	rm -f $(DLL_NAME1) $(DLL_NAME2) $(EXE_NAME)