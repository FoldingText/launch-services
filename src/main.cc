#include "nan.h"
#include "launchservices.h"

using node::ObjectWrap;
using namespace launchservices;
using namespace v8;

namespace {

  class LaunchServices : public ObjectWrap {
    LaunchServicesImplementation* impl;

    static NAN_METHOD(New) {
      NanScope();
      LaunchServices* that = new LaunchServices();
      that->Wrap(args.This());
      NanReturnValue(args.This());
    }

    static NAN_METHOD(RegisterURL) {
      NanScope();
      if (args.Length() < 1) {
        return NanThrowError("Bad argument");
      }
      LaunchServices* that = ObjectWrap::Unwrap<LaunchServices>(args.Holder());
      std::string urlString = *String::Utf8Value(args[0]);
      int result = that->impl->RegisterURL(urlString, true);
      NanReturnValue(NanNew(result));
    }

    static NAN_METHOD(GetDefaultRoleHandlerForContentType) {
      NanScope();
      if (args.Length() < 2) {
        return NanThrowError("Bad argument");
      }

      LaunchServices* that = ObjectWrap::Unwrap<LaunchServices>(args.Holder());
      std::string contentTypeString = *String::Utf8Value(args[0]);
      int rolesMask = -1;
      std::string handlerBundleID = that->impl->GetDefaultRoleHandlerForContentType(contentTypeString, rolesMask);
      if (handlerBundleID.empty()) {
        NanReturnUndefined();
      } else {
        NanReturnValue(NanNew(handlerBundleID));
      }
    }

    static NAN_METHOD(SetDefaultRoleHandlerForContentType) {
      NanScope();
      if (args.Length() < 3) {
        return NanThrowError("Bad argument");
      }

      LaunchServices* that = ObjectWrap::Unwrap<LaunchServices>(args.Holder());
      std::string contentTypeString = *String::Utf8Value(args[0]);
      int rolesMask = -1;
      std::string bundleIDString = *String::Utf8Value(args[2]);
      int result = that->impl->SetDefaultRoleHandlerForContentType(contentTypeString, rolesMask, bundleIDString);
      NanReturnValue(NanNew(result));
    }

    LaunchServices() {
      impl = LaunchServicesFactory::CreateLaunchServices();
    }

    virtual ~LaunchServices() {
      delete impl;
    }

   public:
    static void Init(Handle<Object> exports) {
      Local<FunctionTemplate> tpl = NanNew<FunctionTemplate>(LaunchServices::New);

      tpl->SetClassName(NanNew<String>("LaunchServices"));
      tpl->InstanceTemplate()->SetInternalFieldCount(1);

      NODE_SET_METHOD(tpl->InstanceTemplate(), "registerURL", LaunchServices::RegisterURL);
      NODE_SET_METHOD(tpl->InstanceTemplate(), "getDefaultRoleHandlerForContentType", LaunchServices::GetDefaultRoleHandlerForContentType);
      NODE_SET_METHOD(tpl->InstanceTemplate(), "setDefaultRoleHandlerForContentType", LaunchServices::SetDefaultRoleHandlerForContentType);

      exports->Set(NanNew("LaunchServices"), tpl->GetFunction());
    }
  };

  void Init(Handle<Object> exports, Handle<Object> module) {
    LaunchServices::Init(exports);
  }

}

NODE_MODULE(launchservices, Init)
