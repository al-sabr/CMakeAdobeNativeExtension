#pragma once
#include "FlashRuntimeExtensions.h"

extern "C"
{
	__declspec(dllexport) void CMakeAdobeNativeExtensionInitializer(void** extData, FREContextInitializer* ctxInitializer, FREContextFinalizer* ctxFinalizer);

	__declspec(dllexport) void CMakeAdobeNativeExtensionFinalizer(void* extData);
}