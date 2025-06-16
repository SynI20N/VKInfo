project(VKInfoDriver)

# Tell CMake to run moc when necessary:
set(CMAKE_AUTOMOC ON)
# As moc files are generated in the binary dir, tell CMake
# to always look for includes there:
set(CMAKE_INCLUDE_CURRENT_DIR ON)

add_executable(${PROJECT_NAME} 
  include/mainwidget.h
  
  src/main.cc
  src/mainwidget.cc
)

find_package(Qt5Widgets REQUIRED)

qt5_use_modules(${PROJECT_NAME}  Widgets)

include_directories(${CMAKE_SOURCE_DIR}/VKInfoLib)

target_link_libraries(${PROJECT_NAME} VKInfoLib)

install(TARGETS ${PROJECT_NAME} RUNTIME DESTINATION bin)