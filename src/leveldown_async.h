#if defined(JS_ENGINE_V8) or defined(JS_ENGINE_MOZJS) or \
    defined(JS_ENGINE_CHAKRA)

#ifndef LD_LEVELDOWN_ASYNC_H
#define LD_LEVELDOWN_ASYNC_H

#include <node.h>
#include "async.h"

namespace leveldown {

class DestroyWorker : public AsyncWorker {
 public:
  DestroyWorker(jxcore::JXString &location, NanCallback *callback);

  virtual ~DestroyWorker();
  virtual void Execute();

 private:
  jxcore::JXString location;
};

class RepairWorker : public AsyncWorker {
 public:
  RepairWorker(jxcore::JXString &location, NanCallback *callback);

  virtual ~RepairWorker();
  virtual void Execute();

 private:
  jxcore::JXString location;
};

}  // namespace leveldown

#endif
#endif
