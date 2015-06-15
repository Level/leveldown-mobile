var binding;

if (process.versions.embedded && process.versions.embedded.leveldown)
	binding = jxcore.embeddedModule.require('leveldown').leveldown;
else
	binding = require('bindings')('leveldown.node').leveldown;

module.exports = binding