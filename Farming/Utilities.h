#pragma once

#define GAME_FARMING_START(ClassName) \
int main()\
{\
	ClassName game;\
	game.Run();\
	return 0;\
}

#ifdef FARMING_MSVC
	#ifdef FARMING_LIB
		#define FARMING_API __declspec(dllexport)
	#else
		#define FARMING_API __declspec(dllimport)
	#endif
#else
	#define FARMING_API
#endif


#ifdef FARMING_DEBUG==2
	#define FARMING_LOG(x) std::cout<<x<<std::endl;
	#define FARMING_ERROR(x) std::cout<<x<<std::endl;
#elif defined FARMING_DEBUG==1
	#define FARMING_LOG(x)
	#define FARMING_ERROR(x) std::cout<<x<<std::endl;
#else
	#define FARMING_LOG(x)
	#define FARMING_ERROR(x)
#endif