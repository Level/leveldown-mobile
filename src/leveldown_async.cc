#if defined(JS_ENGINE_V8) or defined(JS_ENGINE_MOZJS) or \
    defined(JS_ENGINE_CHAKRA)

#include <leveldb/db.h>

#include "leveldown.h"
#include "leveldown_async.h"

namespace leveldown {

/** DESTROY WORKER **/

DestroyWorker::DestroyWorker(jxcore::JXString &location, NanCallback *callback)
    : AsyncWorker(NULL, callback), location(location){};

DestroyWorker::~DestroyWorker() { location.Dispose(); }

void DestroyWorker::Execute() {
  leveldb::Options options;
  SetStatus(leveldb::DestroyDB(*location, options));
}

/** REPAIR WORKER **/

RepairWorker::RepairWorker(jxcore::JXString &location, NanCallback *callback)
    : AsyncWorker(NULL, callback), location(location){};

RepairWorker::~RepairWorker() { location.Dispose(); }

void RepairWorker::Execute() {
  leveldb::Options options;
  SetStatus(leveldb::RepairDB(*location, options));
}

}  // namespace leveldown
#endif
