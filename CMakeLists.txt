project(SoundRoom)
cmake_minimum_required(VERSION 2.6)
find_package(Qt4 REQUIRED)	
include(${QT_USE_FILE})

enable_testing()
set(TEST ON CACHE BOOL "Build tests") # TODO Turning this off doesn't work. 

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_HOME_DIRECTORY}/cmake)
include_directories(${CMAKE_HOME_DIRECTORY} ${QT_INCLUDES} ${CMAKE_CURRENT_BINARY_DIR})

set(SoundRoom_SRCS
	SoundRoom.cpp 
	MainWindow.cpp
	View.cpp
	speaker.cpp
	complex.cpp
)
set(SoundRoom_LIB
	${QT_QTCORE_LIBRARY} 
	${QT_LIBRARIES}
	/usr/lib/libQtOpenGL.so
)


if(TEST)
	add_library(SoundRoomlib SHARED ${SoundRoom_SRCS}) # TODO, HACK this is all not very pretty. the library is not needed
	target_link_libraries(SoundRoomlib ${SoundRoom_LIB})
	add_subdirectory(tests)
endif()

qt4_automoc(${SoundRoom_SRCS})
add_executable(SoundRoom ${SoundRoom_SRCS} main.cpp)
target_link_libraries(SoundRoom ${SoundRoom_LIB})

