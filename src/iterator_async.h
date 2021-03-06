#if defined(JS_ENGINE_V8) or defined(JS_ENGINE_MOZJS) or \
    defined(JS_ENGINE_CHAKRA)

#ifndef LD_ITERATOR_ASYNC_H
#define LD_ITERATOR_ASYNC_H

#include <node.h>
#include "async.h"
#include "iterator.h"

namespace leveldown {

class NextWorker : public AsyncWorker {
 public:
  NextWorker(Iterator* iterator, NanCallback* callback,
             void (*localCallback)(Iterator*));

  virtual ~NextWorker();
  virtual void Execute();
  virtual void HandleOKCallback();

 private:
  Iterator* iterator;
  void (*localCallback)(Iterator*);
  std::vector<std::pair<std::string, std::string> > result;
  bool ok;
};

class EndWorker : public AsyncWorker {
 public:
  EndWorker(Iterator* iterator, NanCallback* callback);

  virtual ~EndWorker();
  virtual void Execute();
  virtual void HandleOKCallback();

 private:
  Iterator* iterator;
};

}  // namespace leveldown

#endif
#endif
