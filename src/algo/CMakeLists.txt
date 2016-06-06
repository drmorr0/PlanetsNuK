
set(ALGO_SRC
	dbscan.cpp
	)

add_library(algo_LIBS ${ALGO_SRC})
target_link_libraries(algo_LIBS)
