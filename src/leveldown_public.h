#if defined(JS_ENGINE_V8) or defined(JS_ENGINE_MOZJS)
// JXcore uses this file to embed Leveldown

#include <node.h>

namespace leveldown {
  extern void RegisterModule(JS_HANDLE_OBJECT_REF target);
}
#endif