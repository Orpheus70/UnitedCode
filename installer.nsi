; Установщик для набора DLL и CPP файлов

OutFile "MyLibraryInstaller.exe"         ; Имя выходного файла
InstallDir "$DESKTOP\Lib"                ; Путь установки — папка Lib на рабочем столе
RequestExecutionLevel user  ; 🚫 Без запроса прав администратора

Name "My Library Installer"
Caption "Установка библиотек в Lib"

ShowInstDetails show                     ; Показывать процесс установки

Section "Установка файлов"

  SetOutPath "$INSTDIR"                  ; Установочная директория

  ; DLL-файлы
  File "PulseReader.dll"
  File "Level.dll"
  File "tomom.dll"
  File "port.dll"

  ; EXE-файл
  File "main.exe"

  ; txt-файлы
  File Pulse,SpO2.txt
  File input.txt
  File Read.txt

  ; Примеры на C++
  File "examplePulseReader.cpp"
  File "LMexample.cpp"
  File "examplePort.cpp"
  File "exampleTomom.cpp"

SectionEnd