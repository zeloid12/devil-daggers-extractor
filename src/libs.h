#ifdef _DEBUG
#define WXWIDGETS_LIB_PATH "../ext/wxwidgets/lib/debug/"
#define WXWIDGETS_LIB_EXT "d.lib"
#else
#define WXWIDGETS_LIB_PATH "../ext/wxwidgets/lib/release/"
#define WXWIDGETS_LIB_EXT ".lib"
#endif

#define WXWIDGETS_LIB(LIB) WXWIDGETS_LIB_PATH #LIB WXWIDGETS_LIB_EXT

#pragma comment(lib, WXWIDGETS_LIB(wxbase31u))