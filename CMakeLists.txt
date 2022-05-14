# NOTA IMPORTANTE !! è necessario che la variabile d'ambiente PICO_SDK_PATH sia settata !
# export PICO_SDK_PATH="~/Documents/Università-local/pico-sdk"

#per le funzionalita USB devono essere presenti nel sdk e attivate qui sotto 

#imposta la versione minima necessaria di CMake
cmake_minimum_required(VERSION 3.12)

#Fa riferimento a un file libreria che è presente nel SDK
include($ENV{PICO_SDK_PATH}/external/pico_sdk_import.cmake)

#settare i nome del progetto o target
set (PROJECT_NAME template)

#settare i linguaggi supportati
project(${PROJECT_NAME} C CXX ASM)

#set i requirements dei linguaggi 
set (CMAKE_C_STANDARD 11)
set (CMAKE_CXX_STANDARD 17)

#Crea una subdirectory al interno del progetto con le librerie necessarie
pico_sdk_init()

#Aggiungere la lista degli eseguibili
add_executable(${PROJECT_NAME}
    main.c)

#Gerera file adizionali nella cartella build tra cui il .UF2 !!
pico_add_extra_outputs(${PROJECT_NAME})

#Aggiunge le librerie usate nei sorgenti 
target_link_libraries(${PROJECT_NAME} 
    pico_stdlib
    )
#aggiunge il supporto per l'usb e uart debug 
pico_enable_stdio_usb(${PROJECT_NAME} 1)
pico_enable_stdio_uart(${PROJECT_NAME} 0)
