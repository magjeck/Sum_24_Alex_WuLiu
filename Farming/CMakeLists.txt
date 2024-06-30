set(HEADER_FILES
	include/Farming.h
	FarmingApp.h
	Utilities.h
	FarmingWindow.h
	WindowImplementation.h
	ThirdParty/codeGLFW/WindowGLFW.h
)

set(SOURCE_FILES
	FarmingApp.cpp
	FarmingWindow.cpp
	ThirdParty/codeGLFW/WindowGLFW.cpp
)

add_library(Farming SHARED ${HEADER_FILES} ${SOURCE_FILES})

target_compile_definitions(Farming
	PUBLIC
		$<$<CONFIG:Debug>:FARMING_DEBUG=2>
		$<$<CONFIG:RelWithDebInfo>:FARMING_DEBUG=1>
	PRIVATE
		FARMING_LIB
		FARMING_GLFW
)

if(MSVC)
	target_compile_definitions(Farming PUBLIC FARMING_MSVC)
endif()

target_include_directories(Farming PRIVATE ${CMAKE_SOURCE_DIR}/Farming)
target_include_directories(Farming PRIVATE ${CMAKE_SOURCE_DIR}/glfw/include)

target_link_libraries(Farming glfw)

target_precompile_headers(Farming PRIVATE pch.h)