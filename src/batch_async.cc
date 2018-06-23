#if defined(JS_ENGINE_V8) or defined(JS_ENGINE_MOZJS) or \
    defined(JS_ENGINE_CHAKRA)
#include <leveldb/write_batch.h>
#include "batch.h"
#include "batch_async.h"

namespace leveldown {

/** NEXT WORKER **/

BatchWriteWorker::BatchWriteWorker(Batch* batch, NanCallback* callback)
    : AsyncWorker(NULL, callback), batch(batch){};

BatchWriteWorker::~BatchWriteWorker() {}

void BatchWriteWorker::Execute() { SetStatus(batch->Write()); }

}  // namespace leveldown
#endif
