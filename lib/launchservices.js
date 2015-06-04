//var bindings = require('bindings')('LaunchServices');
var bindings = require('../build/Release/launchservices.node');
var LaunchServices = bindings.LaunchServices;

var defaultLaunchServices = null;
var ensureDefaultLaunchServices = function() {
  if (defaultLaunchServices) return;
  defaultLaunchServices = new LaunchServices();
};

var registerURL = function() {
  ensureDefaultLaunchServices();
  return defaultLaunchServices.registerURL.apply(defaultLaunchServices, arguments);
};

var getDefaultRoleHandlerForContentType = function() {
  ensureDefaultLaunchServices();
  return defaultLaunchServices.getDefaultRoleHandlerForContentType.apply(defaultLaunchServices, arguments);
};

var setDefaultRoleHandlerForContentType = function() {
  ensureDefaultLaunchServices();
  return defaultLaunchServices.setDefaultRoleHandlerForContentType.apply(defaultLaunchServices, arguments);
};

module.exports = {
  LSRolesNone: 1,
  LSRolesViewer: 2,
  LSRolesEditor: 4,
  LSRolesShell: 8,
  LSRolesAll: -1,

  registerURL: registerURL,
  getDefaultRoleHandlerForContentType: getDefaultRoleHandlerForContentType,
  setDefaultRoleHandlerForContentType: setDefaultRoleHandlerForContentType
};