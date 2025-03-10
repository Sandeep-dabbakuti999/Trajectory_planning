add_executable(${EXECUTABLE_NAME} "main.cpp")
target_link_libraries(${EXECUTABLE_NAME} PUBLIC ${DATA_LIBRARY} ${FRENET_LIBRARY} ${OPTIMIZE_LIBRARY})