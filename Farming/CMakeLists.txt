set(HEADER_FILES
	include/Farming.h
	FarmingApp.h
	Utilities.h
	FarmingWindow.h
	WindowImplementation.h
	ThirdParty/codeGLFW/WindowGLFW.h
	Image.h
	ImageImplementation.h
	ThirdParty/codeOpenGL/ImageOpenGL.h
	Shaders.h
	ShadersImplementation.h
	ThirdParty/codeOpenGL/ShadersOpenGL.h
	Renderer.h
	RendererImplementation.h
	ThirdParty/codeOpenGL/RendererOpenGL.h
	Events.h
	FarmingKeys.h
	Unit.h
	Map.h
	Physics.h
)

set(SOURCE_FILES
	FarmingApp.cpp
	FarmingWindow.cpp
	ThirdParty/codeGLFW/WindowGLFW.cpp
	Image.cpp
	ThirdParty/codeOpenGL/ImageOpenGL.cpp
	Shaders.cpp
	ThirdParty/codeOpenGL/ShadersOpenGL.cpp
	Renderer.cpp
	ThirdParty/codeOpenGL/RendererOpenGL.cpp
	Events.cpp
	Unit.cpp
	Map.cpp
	Physics.cpp
)

add_library(Farming SHARED ${HEADER_FILES} ${SOURCE_FILES})

target_compile_definitions(Farming
	PUBLIC
		$<$<CONFIG:Debug>:FARMING_DEBUG=2>
		$<$<CONFIG:RelWithDebInfo>:FARMING_DEBUG=1>
		FARMING_GLFW
	PRIVATE
		FARMING_LIB
		FARMING_OPENGL
)

if(MSVC)
	target_compile_definitions(Farming PUBLIC FARMING_MSVC)
endif()

target_include_directories(Farming PRIVATE ${CMAKE_SOURCE_DIR}/Farming)
target_include_directories(Farming PRIVATE ${CMAKE_SOURCE_DIR}/glfw/include)
target_include_directories(Farming PRIVATE ${CMAKE_SOURCE_DIR}/glad/include)
target_include_directories(Farming PRIVATE ${CMAKE_SOURCE_DIR}/stbi)

target_link_libraries(Farming glfw glad stbi)

target_precompile_headers(Farming PRIVATE pch.h)

file(COPY Assets DESTINATION ${PROJECT_BINARY_DIR}/Farming)