var LaunchServices = require('../lib/launchservices');
var assert = require('assert');

describe('native extension', function() {
  it('should register URL', function() {
    if (process.platform === 'darwin') {
      assert.equal(LaunchServices.registerURL('file:///Applications/TextEdit.app', true), 0);
      assert.equal(LaunchServices.registerURL('file:///notfoundhere', true), -10811);
    }
  });

  it('should get default role handler for content type', function() {
    if (process.platform === 'darwin') {
      assert.equal(LaunchServices.getDefaultRoleHandlerForContentType('public.plain-text', LaunchServices.kLSRolesAll), 'com.apple.TextEdit');
      assert.equal(LaunchServices.getDefaultRoleHandlerForContentType('not-a-valid-type', LaunchServices.kLSRolesAll), undefined);
    }
  });

});
