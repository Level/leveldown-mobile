#if defined(JS_ENGINE_V8) or defined(JS_ENGINE_MOZJS) or \
    defined(JS_ENGINE_CHAKRA)
#ifndef LD_BATCH_ASYNC_H
#define LD_BATCH_ASYNC_H

#include <node.h>
#include "nan.h"

#include "async.h"
#include "batch.h"
#include "database.h"

namespace leveldown {

class BatchWriteWorker : public AsyncWorker {
 public:
  BatchWriteWorker(Batch* batch, NanCallback* callback);

  virtual ~BatchWriteWorker();
  virtual void Execute();

 private:
  Batch* batch;
};

}  // namespace leveldown

#endif
#endif
