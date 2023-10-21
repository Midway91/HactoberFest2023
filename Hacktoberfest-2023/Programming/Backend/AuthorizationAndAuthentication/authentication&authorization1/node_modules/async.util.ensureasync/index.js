'use strict';
var setImmediate = require('async.util.setimmediate');
var restParam = require('async.util.restparam');

module.exports = function(fn) {
    return restParam(function(args) {
        var callback = args.pop();
        args.push(function() {
            var innerArgs = arguments;
            if (sync) {
                setImmediate(function() {
                    callback.apply(null, innerArgs);
                });
            } else {
                callback.apply(null, innerArgs);
            }
        });
        var sync = true;
        fn.apply(this, args);
        sync = false;
    });
};
