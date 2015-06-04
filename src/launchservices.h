#ifndef SRC_LAUNCHSERVICES_H_
#define SRC_LAUNCHSERVICES_H_

#include <string>
#include <vector>

namespace launchservices {

  class LaunchServicesImplementation {
    public:
      // Adds a new word to the dictionary.
      // NB: When using Hunspell, this will not modify the .dic file; custom words must be added each
      // time the launchservices is created. Use a custom dictionary file.
      virtual int RegisterURL(const std::string& urlString, bool update) = 0;

      virtual std::string GetDefaultRoleHandlerForContentType(const std::string& contentTypeString, int rolesMask) = 0;
      virtual int SetDefaultRoleHandlerForContentType(const std::string& contentTypeString, int rolesMask, const std::string& bundleIDString) = 0;

      virtual ~LaunchServicesImplementation() {}
  };

  class LaunchServicesFactory {
    public:
      static LaunchServicesImplementation* CreateLaunchServices();
  };

}

#endif  // SRC_LAUNCHSERVICES_H_