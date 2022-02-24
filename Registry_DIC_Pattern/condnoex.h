#pragma once

#if defined _DEBUG && !defined NDEBUG
#	define BDEBUG	true
#else
#	define BDEBUG	false
#endif
#define cond_noex	noexcept( !BDEBUG )