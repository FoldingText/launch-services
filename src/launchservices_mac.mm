#include "launchservices_mac.h"

#import <Cocoa/Cocoa.h>

namespace launchservices {

  MacLaunchServices::MacLaunchServices() {
  }

  MacLaunchServices::~MacLaunchServices() {
  }

  int MacLaunchServices::RegisterURL(const std::string& urlString, bool update) {
    OSStatus status;
    @autoreleasepool {
      NSURL *url = [NSURL URLWithString:[NSString stringWithUTF8String:urlString.c_str()]];
      status = LSRegisterURL((CFURLRef)url, update);
    }
    return status;
  }

  std::string MacLaunchServices::GetDefaultRoleHandlerForContentType(const std::string& contentTypeString, int rolesMask) {
    std::string result;
    @autoreleasepool {
      NSString *contentType = [NSString stringWithUTF8String:contentTypeString.c_str()];
      NSString *bundleID = (__bridge NSString *) LSCopyDefaultRoleHandlerForContentType((CFStringRef)contentType, rolesMask);
      result = [bundleID UTF8String];
    }
    return result;
  }

  int MacLaunchServices::SetDefaultRoleHandlerForContentType(const std::string& contentTypeString, int rolesMask, const std::string& bundleIDString) {
    OSStatus status;
    @autoreleasepool {
      NSString *contentType = [NSString stringWithUTF8String:contentTypeString.c_str()];
      NSString *bundleID = [NSString stringWithUTF8String:bundleIDString.c_str()];
      status = LSSetDefaultRoleHandlerForContentType((CFStringRef)contentType, rolesMask, (CFStringRef)bundleID);
    }
    return status;
  }

  LaunchServicesImplementation* LaunchServicesFactory::CreateLaunchServices() {
    return new MacLaunchServices();
  }

}
