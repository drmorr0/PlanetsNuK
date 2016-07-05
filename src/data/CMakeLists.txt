
set(DATA_SRC
	planet.cpp
	sector.cpp
	ship.cpp
)

add_library(data_LIBS ${DATA_SRC})
target_link_libraries(data_LIBS ${Jsoncpp_LIBRARIES})
