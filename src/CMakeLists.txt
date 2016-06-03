
add_subdirectory(data)

add_executable(nuk main.cpp ${DATA_SRC})
target_link_libraries(nuk ${LIBS})


