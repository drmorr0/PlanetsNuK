
set(VIZ_SRC
	main.cpp
	window.cpp
	canvas.cpp
	scene.cpp
	planet_obj.cpp
	builder.cpp
	)

add_executable(nukviz ${VIZ_SRC})
target_link_libraries(nukviz data_LIBS util_LIBS algo_LIBS ${GTKMM_LIBRARIES} ${CAIROMM_LIBRARIES})

