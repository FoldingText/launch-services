#ifndef SRC_LAUNCHSERVICES_MAC_H_
#define SRC_LAUNCHSERVICES_MAC_H_

#include "launchservices.h"

#import <Cocoa/Cocoa.h>

namespace launchservices {

  class MacLaunchServices : public LaunchServicesImplementation {
    public:
      MacLaunchServices();
      ~MacLaunchServices();

      int RegisterURL(const std::string& urlString, bool update);
      std::string GetDefaultRoleHandlerForContentType(const std::string& contentTypeString, int rolesMask);
      int SetDefaultRoleHandlerForContentType(const std::string& contentTypeString, int rolesMask, const std::string& bundleIDString);
  };

}

#endif  // SRC_LAUNCHSERVICES_MAC_H_