#include <Windows.h>
#include "dllMain.h"

using namespace std;

FREContext ctx;

HMODULE dllHandle;

BOOL APIENTRY DllMain(HMODULE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved) {

	dllHandle = hModule;

	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
		break;
	case DLL_THREAD_ATTACH:
		break;
	case DLL_THREAD_DETACH:
		break;
	case DLL_PROCESS_DETACH:
		break;
	}
	return TRUE;
}

void contextInitializer(void *extData, const uint8_t * ctxType, FREContext aneCtx, uint32_t * numFunctionsToSet, const FRENamedFunction ** functionsToSet)
{
	ctx = aneCtx;

	// Create mapping between function names and pointers in an array of FRENamedFunction.
	// These are the functions that you will call from ActionScript -
	// effectively the interface of your native library.
	// Each member of the array contains the following information:
	// { function name as it will be called from ActionScript,
	//   any data that should be passed to the function,
	//   a pointer to the implementation of the function in the native library }
	static FRENamedFunction extensionFunctions[] =
	{
		{}
		//{ (const uint8_t*)"coreInitialization", NULL, &coreInitialization },
	};

	// Tell AIR how many functions there are in the array:
	*numFunctionsToSet = sizeof(extensionFunctions) / sizeof(FRENamedFunction);

	// Set the output parameter to point to the array we filled in:
	*functionsToSet = extensionFunctions;
}

void contextFinalizer(FREContext ctx)
{
	return;
}

extern "C" {

	__declspec(dllexport) void CMakeAdobeNativeExtensionInitializer(void** extData, FREContextInitializer* ctxInitializer, FREContextFinalizer* ctxFinalizer)
	{
		//MessageBox(NULL, (LPCWSTR)L"FractalExtensionInitializer", (LPCWSTR)L"Debug", MB_ICONINFORMATION);
		*ctxInitializer = &contextInitializer; // The name of function that will intialize the extension context
		*ctxFinalizer = &contextFinalizer; // The name of function that will finalize the extension context
	}

	__declspec(dllexport) void CMakeAdobeNativeExtensionFinalizer(void* extData)
	{
		return;
	}

}