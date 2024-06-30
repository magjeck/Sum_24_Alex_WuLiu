set(HEADER_FILES
	include/Farming.h
	FarmingApp.h
	Utilities.h
)

set(SOURCE_FILES
	FarmingApp.cpp
)

add_library(Farming SHARED ${HEADER_FILES} ${SOURCE_FILES})

target_compile_definitions(Farming
	PUBLIC
		$<$<CONFIG:Debug>:FARMING_DEBUG=2>
		$<$<CONFIG:RelWithDebInfo>:FARMING_DEBUG=1>
	PRIVATE
		FARMING_LIB
)

if(MSVC)
	target_compile_definitions(Farming PUBLIC FARMING_MSVC)
endif()

target_precompile_headers(Farming PRIVATE pch.h)