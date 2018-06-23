#if defined(JS_ENGINE_V8) or defined(JS_ENGINE_MOZJS) or \
    defined(JS_ENGINE_CHAKRA)

#include <node.h>

#include "leveldown.h"
#include "database.h"
#include "iterator.h"
#include "batch.h"
#include "leveldown_async.h"

namespace leveldown {

JS_LOCAL_METHOD(DestroyDB) {
  if (args.Length() < 2 || !args.IsString(0) || !args.IsFunction(1)) {
    THROW_EXCEPTION("DestroyDB expects (string, function) parameters");
  }

  jxcore::JXString location;
  args.GetString(0, &location);

  JS_LOCAL_FUNCTION fnc = JS_TYPE_TO_LOCAL_FUNCTION(args.GetAsFunction(1));
  NanCallback* callback = new NanCallback(fnc);

  location.DisableAutoGC();
  DestroyWorker* worker = new DestroyWorker(location, callback);

  NanAsyncQueueWorker(worker);
}
JS_METHOD_END

JS_LOCAL_METHOD(RepairDB) {
  if (args.Length() < 2 || !args.IsString(0) || !args.IsFunction(1)) {
    THROW_EXCEPTION("repair() requires `location` and `callback` arguments");
  }

  jxcore::JXString location;
  args.GetString(0, &location);

  JS_LOCAL_FUNCTION fnc = JS_TYPE_TO_LOCAL_FUNCTION(args.GetAsFunction(1));
  NanCallback* callback = new NanCallback(fnc);

  location.DisableAutoGC();

  RepairWorker* worker = new RepairWorker(location, callback);

  NanAsyncQueueWorker(worker);
}
JS_METHOD_END

class LeveldownWrap {
 public:
  static DEFINE_JS_METHOD(New);

  INIT_NAMED_CLASS_MEMBERS(leveldown, LeveldownWrap) {
    Database::Initialize(target);
    leveldown::Iterator::Initialize(target);
    leveldown::Batch::Initialize(target);

    SET_CLASS_METHOD("repair", RepairDB, 0);
    SET_CLASS_METHOD("destroy", DestroyDB, 0);
  }
  END_INIT_NAMED_MEMBERS(leveldown)
};

JS_METHOD(LeveldownWrap, New) {
  JS_LOCAL_STRING location = JS_TYPE_TO_LOCAL_STRING(args.GetAsString(0));
  RETURN_PARAM(Database::NewInstance(location));
}
JS_METHOD_END

void RegisterModule(JS_HANDLE_OBJECT_REF target) {
  JS_ENTER_SCOPE();

  LeveldownWrap::Initialize(target);
}

#ifndef JXCORE_EMBEDS_LEVELDOWN
NODE_MODULE(leveldown, RegisterModule);
#endif

}  // namespace leveldown
#endif
