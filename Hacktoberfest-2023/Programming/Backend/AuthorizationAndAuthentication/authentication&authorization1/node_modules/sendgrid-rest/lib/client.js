'use strict'

require('dotenv').config();
var https = require('https')
var http = require('http')
var queryString = require('querystring')

// request holds the request to an API Call
var request = {
  host: '',
  method: '',
  path: '',
  headers: {},
  body: {},
  queryParams: {},
  test: false, // use this to allow for http calls
  port: ''     // set the port for http calls
}

var emptyRequest = JSON.parse(JSON.stringify(request))

// response holds the response from an API call, use this as an initializer
// like so: JSON.parse(JSON.stringify(response))
var response = {
  'statusCode': '',
  'body': {},
  'headers': {}
}

// Client allows for quick and easy access any REST or REST-like API.
function Client (globalRequest, maxSockets) {
  var emptyResponse = JSON.parse(JSON.stringify(response))
  var body = ''
  var httpAgent = null
  var httpsAgent = null

  if (maxSockets) {
    httpAgent = new http.Agent({ maxSockets: maxSockets })
    httpsAgent = new https.Agent({ maxSockets: maxSockets })
  }

  // utility function to create an empty request object
  this.emptyRequest = function () {
    return JSON.parse(JSON.stringify(request))
  }

  // utility function to detect empty objects
  function isEmpty (obj) {
    for (var key in obj) {
      if (obj.hasOwnProperty(key)) {
        return false
      }
    }
    return true
  }

  // add query paramaters to a URL
  function buildPath (basePath, queryParams) {
    basePath = basePath.concat('?')
    var url = basePath.concat(queryString.stringify(queryParams))
    return url
  }

  function buildRequest (globalRequest, endpointRequest) {
    var request = JSON.parse(JSON.stringify(globalRequest))
    request.host = endpointRequest.host || globalRequest.host
    request.method = endpointRequest.method

    if (endpointRequest.port) {
      request.port = endpointRequest.port
    }

    // build URL
    request.path = !isEmpty(endpointRequest.queryParams)
      ? buildPath(endpointRequest.path, endpointRequest.queryParams)
      : endpointRequest.path

    // add headers
    if (!isEmpty(endpointRequest.headers)) {
      for (var attrname in endpointRequest.headers) {
        request.headers[attrname] = endpointRequest.headers[attrname]
      }
    }

    // add the request body's content length
    if (!isEmpty(endpointRequest.body)) {
      body = JSON.stringify(endpointRequest.body)
      request.headers['Content-Length'] = Buffer.byteLength(body)
      request.headers['Content-Type'] = 'application/json'
    }

    // if maxsockets where provided use the apropriate agent
    if (maxSockets) {
      request.agent = endpointRequest.test === true ? httpAgent : httpsAgent
    }
    return request
  }

  // API is the main interface to the API.
  this.API = function (endpointRequest, callback) {
    var request = buildRequest(globalRequest, endpointRequest)

    var requestProtocol = null;

    if (endpointRequest.test === true) {
      requestProtocol = http
      request.port = endpointRequest.port
    } else {
      requestProtocol = https
    }

    var httpRequest = requestProtocol.request(request, function (httpResponse) {
      var responseBody = ''

      // cature the response from the API
      httpResponse.on('data', function (chunk) {
        responseBody += chunk
      })

      // after the call is complete, build the response object
      httpResponse.on('end', function () {
        var response = JSON.parse(JSON.stringify(emptyResponse))
        response.statusCode = httpResponse.statusCode
        response.body = responseBody
        response.headers = httpResponse.headers
        callback(response)
      })
    })

    httpRequest.on('error', function (e) {
      var response = JSON.parse(JSON.stringify(emptyResponse))
      response.statusCode = e.statusCode || 500
      response.body = JSON.stringify({
        message: e.message,
        name: e.name,
        stack: e.stack
      })
      callback(response)
    })

    // if thre is a request body, sent it
    if (!isEmpty(endpointRequest.body)) {
      httpRequest.write(body)
    }

    httpRequest.end()
  }

  return this
}

module.exports =
{
  Client: Client,
  request: request,
  emptyRequest: emptyRequest
}
