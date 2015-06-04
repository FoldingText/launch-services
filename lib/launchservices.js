//var bindings = require('bindings')('LaunchServices');
var bindings = require('../build/Release/launchservices.node');
var LaunchServices = bindings.LaunchServices;
var LSRolesNone = 1;
var LSRolesViewer = 2;
var LSRolesEditor = 4;
var LSRolesShell = 8;
var LSRolesAll = -1;

var defaultLaunchServices = null;
var ensureDefaultLaunchServices = function() {
  if (defaultLaunchServices) return;
  defaultLaunchServices = new LaunchServices();
};

var registerURL = function(url, update) {
  ensureDefaultLaunchServices();
  return defaultLaunchServices.registerURL(url, update);
};

var getDefaultRoleHandlerForContentType = function(contentType, rolesMask) {
  ensureDefaultLaunchServices();
  return defaultLaunchServices.getDefaultRoleHandlerForContentType(contentType, rolesMask || LSRolesAll);
};

var setDefaultRoleHandlerForContentType = function(contentType, rolesMask, bundleID) {
  ensureDefaultLaunchServices();
  return defaultLaunchServices.setDefaultRoleHandlerForContentType(contentType, rolesMask || LSRolesAll, bundleID);
};

module.exports = {
  LSRolesNone: LSRolesNone,
  LSRolesViewer: LSRolesViewer,
  LSRolesEditor: LSRolesEditor,
  LSRolesShell: LSRolesShell,
  LSRolesAll: LSRolesAll,

  registerURL: registerURL,
  getDefaultRoleHandlerForContentType: getDefaultRoleHandlerForContentType,
  setDefaultRoleHandlerForContentType: setDefaultRoleHandlerForContentType
};